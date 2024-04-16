#include "Empresa.h" // Incluye la declaración de la clase Empresa
#include <algorithm> // Se agrega esta línea para usar std::find_if
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip> // Se agrega esta línea para utilizar setw

Empresa::Empresa() {} // Constructor por defecto de la clase Empresa

Empresa::~Empresa() { // Destructor de la clase Empresa
    guardarTrabajadoresEnArchivo("trabajadores3.txt"); // Guarda los trabajadores en el archivo al destruir el objeto
}

void Empresa::cargarTrabajadoresDesdeArchivo(const std::string& nombreArchivo) {
    trabajadores.clear(); // Limpia el vector de trabajadores para cargarlos desde el archivo
    std::ifstream archivo(nombreArchivo); // Abre el archivo para lectura
    if (!archivo) { // Comprueba si se pudo abrir el archivo
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl; // Muestra un mensaje de error si no se pudo abrir
        return; // Sale de la función si no se pudo abrir el archivo
    }

    std::string nombre;
    int id;
    while (archivo >> nombre >> id) { // Lee los datos del archivo y los agrega al vector de trabajadores
        trabajadores.push_back(Trabajador(nombre, id));
    }

    archivo.close(); // Cierra el archivo después de cargar los trabajadores
}

void Empresa::agregarTrabajadorDesdeConsola() {
    std::string nombre;
    int id;

    std::cout << "Ingrese el nombre del nuevo trabajador: ";
    std::cin >> nombre;

    std::cout << "Ingrese el ID del nuevo trabajador: ";
    std::cin >> id;

    trabajadores.push_back(Trabajador(nombre, id)); // Agrega un nuevo trabajador al vector

    guardarTrabajadoresEnArchivo("trabajadores3.txt"); // Guarda los trabajadores en el archivo
}

void Empresa::registrarDatosDiarios() {
    cargarTrabajadoresDesdeArchivo("trabajadores3.txt"); // Carga los trabajadores desde el archivo

    int id;
    std::cout << "Ingrese el ID del trabajador: ";
    std::cin >> id;

    Trabajador* trabajador = nullptr;
    for (auto& t : trabajadores) { // Busca al trabajador por su ID en el vector de trabajadores
        if (t.obtenerID() == id) {
            trabajador = &t;
            break;
        }
    }

    if (trabajador == nullptr) { // Si no se encuentra al trabajador, muestra un mensaje de error y sale de la función
        std::cerr << "Trabajador no encontrado" << std::endl;
        return;
    }

    int dia, mes, anno;
    float temperatura;
    bool tos, fiebre;

    std::cout << "Ingrese la fecha (dia mes anno): ";
    std::cin >> dia >> mes >> anno;
    Fecha fecha(dia, mes, anno); // Crea un objeto Fecha con la fecha ingresada por el usuario

    int semana = fecha.obtenerNumeroSemana(); // Calcula el número de semana correspondiente a la fecha

    std::cout << "Ingrese la temperatura del trabajador: ";
    std::cin >> temperatura;

    std::cout << "¿El trabajador tiene tos? (1 para Si, 0 para No): ";
    std::cin >> tos;

    std::cout << "¿El trabajador tiene fiebre? (1 para Si, 0 para No): ";
    std::cin >> fiebre;

    trabajador->registrarDatosDiarios(fecha, temperatura, tos, fiebre); // Registra los datos diarios del trabajador

    // Guarda los datos en archivos
    std::ofstream archivoDatosSemana("datosSemana3.txt", std::ios_base::app);
    if (!archivoDatosSemana) {
        std::cerr << "Error al abrir el archivo datosSemana3.txt" << std::endl;
        return;
    }
    archivoDatosSemana << id << " " << semana << " " << dia << " " << mes << " " << anno << " " << temperatura << " " << tos << " " << fiebre << std::endl;
    archivoDatosSemana.close();

    std::ofstream archivoDatos("datos3.txt", std::ios_base::app);
    if (!archivoDatos) {
        std::cerr << "Error al abrir el archivo datos3.txt" << std::endl;
        return;
    }
    archivoDatos << id << " " << dia << " " << mes << " " << anno << " " << temperatura << " " << tos << " " << fiebre << std::endl;
    archivoDatos.close();

    guardarTrabajadoresEnArchivo("trabajadores3.txt"); // Guarda los trabajadores en el archivo
}

void Empresa::mostrarTrabajadores() const {
    std::ifstream archivo("trabajadores3.txt"); // Abre el archivo de trabajadores para lectura
    if (!archivo) { // Comprueba si se pudo abrir el archivo
        std::cerr << "Error al abrir el archivo trabajadores3.txt" << std::endl; // Muestra un mensaje de error si no se pudo abrir
        return; // Sale de la función si no se pudo abrir el archivo
    }

    std::string nombre;
    int id;
    while (archivo >> nombre >> id) { // Lee los datos de los trabajadores del archivo y los muestra por consola
        std::cout << "Nombre: " << nombre << ", ID: " << id << std::endl;
    }

    archivo.close(); // Cierra el archivo después de mostrar los trabajadores
}

void Empresa::eliminarTrabajador(int id) {
    auto it = std::find_if(trabajadores.begin(), trabajadores.end(), [id](const Trabajador& t) {
        return t.obtenerID() == id;
    });

    if (it != trabajadores.end()) {
        trabajadores.erase(it);

        std::cout << "Trabajador con ID " << id << " eliminado exitosamente." << std::endl;

        // Eliminar del archivo datos3.txt
        std::ifstream archivoDatos("datos3.txt");
        if (!archivoDatos) {
            std::cerr << "Error al abrir el archivo datos3.txt" << std::endl;
            return;
        }
        std::ofstream archivoTemporal("temp3.txt");
        if (!archivoTemporal) {
            std::cerr << "Error al crear el archivo temporal" << std::endl;
            archivoDatos.close();
            return;
        }

        // Copiar las entradas de datos que no corresponden al trabajador eliminado al archivo temporal
        int idArchivo;
        int dia, mes, anno;
        float temperatura;
        bool tos, fiebre;
        while (archivoDatos >> idArchivo >> dia >> mes >> anno >> temperatura >> tos >> fiebre) {
            if (idArchivo != id) {
                archivoTemporal << idArchivo << " " << dia << " " << mes << " " << anno << " " << temperatura << " " << tos << " " << fiebre << std::endl;
            }
        }

        archivoDatos.close();
        archivoTemporal.close();
        remove("datos3.txt");
        rename("temp3.txt", "datos3.txt");

        // Eliminar del archivo datosSemana3.txt
        std::ifstream archivoDatosSemana("datosSemana3.txt");
        if (!archivoDatosSemana) {
            std::cerr << "Error al abrir el archivo datosSemana3.txt" << std::endl;
            return;
        }
        std::ofstream archivoTemporalSemana("tempSemana3.txt");
        if (!archivoTemporalSemana) {
            std::cerr << "Error al crear el archivo temporal" << std::endl;
            archivoDatosSemana.close();
            return;
        }

        // Copiar las entradas de datos semanales que no corresponden al trabajador eliminado al archivo temporal
        int idArchivoSemana, semana;
        while (archivoDatosSemana >> idArchivoSemana >> semana >> dia >> mes >> anno >> temperatura >> tos >> fiebre) {
            if (idArchivoSemana != id) {
                archivoTemporalSemana << idArchivoSemana << " " << semana << " " << dia << " " << mes << " " << anno << " " << temperatura << " " << tos << " " << fiebre << std::endl;
            }
        }

        archivoDatosSemana.close();
        archivoTemporalSemana.close();
        remove("datosSemana3.txt");
        rename("tempSemana3.txt", "datosSemana3.txt");

    } else {
        std::cout << "No se encontró ningún trabajador con el ID " << id << "." << std::endl;
    }

    guardarTrabajadoresEnArchivo("trabajadores3.txt");
}


void Empresa::guardarTrabajadoresEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream archivo(nombreArchivo); // Abre el archivo de trabajadores para escritura
    if (!archivo) { // Comprueba si se pudo abrir el archivo
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl; // Muestra un mensaje de error si no se pudo abrir
        return; // Sale de la función si no se pudo abrir el archivo
    }

    for (const auto& trabajador : trabajadores) { // Escribe los datos de los trabajadores en el archivo
        archivo << trabajador.obtenerNombre() << " " << trabajador.obtenerID() << std::endl;
    }

    archivo.close(); // Cierra el archivo después de escribir los datos
}

float Empresa::obtenerPromedioTemperaturaTrabajador(int id) const {
    float sumaTemperaturas = 0;
    int contadorRegistros = 0;

    std::ifstream archivoDatos("datos3.txt"); // Abre el archivo de datos para lectura
    if (!archivoDatos) { // Comprueba si se pudo abrir el archivo
        std::cerr << "Error al abrir el archivo datos3.txt" << std::endl; // Muestra un mensaje de error si no se pudo abrir
        return -1; // Retorna un valor de error si no se pudo abrir el archivo
    }

    int idArchivo;
    int dia, mes, anno;
    float temperatura;
    bool tos, fiebre;

    while (archivoDatos >> idArchivo >> dia >> mes >> anno >> temperatura >> tos >> fiebre) { // Lee los datos del archivo
        if (idArchivo == id) { // Comprueba si el ID del trabajador coincide
            sumaTemperaturas += temperatura; // Suma las temperaturas
            contadorRegistros++; // Incrementa el contador de registros
        }
    }

    archivoDatos.close(); // Cierra el archivo después de leer los datos

    if (contadorRegistros == 0) { // Si no se encontraron registros para el trabajador
        std::cerr << "No hay registros de temperatura para el trabajador con ID " << id << std::endl; // Muestra un mensaje de error
        return -1; // Retorna un valor de error
    }

    return sumaTemperaturas / contadorRegistros; // Retorna el promedio de las temperaturas
}

void Empresa::consultarDatosBioseguridadPorFecha(int id, const Fecha& fecha) const {
    std::ifstream archivoDatos("datos3.txt"); // Abre el archivo de datos para lectura
    if (!archivoDatos) { // Comprueba si se pudo abrir el archivo
        std::cerr << "Error al abrir el archivo datos3.txt" << std::endl; // Muestra un mensaje de error si no se pudo abrir
        return; // Sale de la función si no se pudo abrir el archivo
    }

    int idArchivo;
    int dia, mes, anno;
    float temperatura;
    bool tos, fiebre;
    bool encontrado = false;

    while (archivoDatos >> idArchivo >> dia >> mes >> anno >> temperatura >> tos >> fiebre) { // Lee los datos del archivo
        if (idArchivo == id && dia == fecha.getDia() && mes == fecha.getMes() && anno == fecha.getAnno()) { // Comprueba si los datos coinciden con la fecha y el ID del trabajador
            encontrado = true; // Marca como encontrado
            std::cout << "=== Datos de bioseguridad para la fecha " << dia << "/" << mes << "/" << anno << " ===" << std::endl;
            std::cout << "Temperatura: " << temperatura << std::endl; // Muestra la temperatura
            std::cout << "Tos: " << (tos ? "Si" : "No") << std::endl; // Muestra si tiene tos
            std::cout << "Fiebre: " << (fiebre ? "Si" : "No") << std::endl; // Muestra si tiene fiebre
            break;
        }
    }

    if (!encontrado) { // Si no se encontraron datos para la fecha y el trabajador
        std::cout << "No se encontraron datos de bioseguridad para esa fecha y trabajador" << std::endl; // Muestra un mensaje
    }

    archivoDatos.close(); // Cierra el archivo después de leer los datos
}

void Empresa::consultarDatosBioseguridadPorSemana(int id, int semana) const {
    std::ifstream archivoDatosSemana("datosSemana3.txt"); // Abre el archivo de datos para lectura
    if (!archivoDatosSemana) { // Comprueba si se pudo abrir el archivo
        std::cerr << "Error al abrir el archivo datosSemana3.txt" << std::endl; // Muestra un mensaje de error si no se pudo abrir
        return; // Sale de la función si no se pudo abrir el archivo
    }

    int idArchivo, semanaArchivo, dia, mes, anno;
    float temperatura;
    bool tos, fiebre;
    bool encontrado = false;

    while (archivoDatosSemana >> idArchivo >> semanaArchivo >> dia >> mes >> anno >> temperatura >> tos >> fiebre) { // Lee los datos del archivo
        if (idArchivo == id && semanaArchivo == semana) { // Comprueba si los datos coinciden con la semana y el ID del trabajador
            encontrado = true; // Marca como encontrado
            std::cout << "=== Datos de bioseguridad para la semana " << semana << " ===" << std::endl;
            std::cout << std::setw(2) << std::setfill('0') << dia << "/" << std::setw(2) << std::setfill('0') << mes << "/" << anno << std::endl; // Muestra la fecha
            std::cout << "Temperatura: " << temperatura << std::endl; // Muestra la temperatura
            std::cout << "Tos: " << (tos ? "Si" : "No") << std::endl; // Muestra si tiene tos
            std::cout << "Fiebre: " << (fiebre ? "Si" : "No") << std::endl; // Muestra si tiene fiebre
            std::cout << std::endl; // Imprime una línea en blanco para separar los datos de diferentes días
        }
    }

    if (!encontrado) { // Si no se encontraron datos para la semana y el trabajador
        std::cout << "No se encontraron datos de bioseguridad para esa semana y trabajador" << std::endl; // Muestra un mensaje
    }

    archivoDatosSemana.close(); // Cierra el archivo después de leer los datos
}

int Fecha::obtenerNumeroSemana() const {
    std::tm tiempo = {};
    tiempo.tm_year = anno - 1900;
    tiempo.tm_mon = mes - 1;
    tiempo.tm_mday = dia;

    std::mktime(&tiempo);

    // Obtiene el número de semana del año
    int diasDesdePrimerLunes = tiempo.tm_wday ? tiempo.tm_wday - 1 : 6;
    int diasHastaPrimerLunes = tiempo.tm_yday - diasDesdePrimerLunes;
    int numeroSemana = (diasHastaPrimerLunes / 7) + 1;

    return numeroSemana;
}

bool Empresa::verificarExistenciaTrabajador(int id) {
    for (const auto& trabajador : trabajadores) { // Recorre el vector de trabajadores
        if (trabajador.obtenerID() == id) { // Comprueba si el ID del trabajador coincide
            return true; // Retorna true si el trabajador existe
        }
    }
    return false; // Retorna false si el trabajador no existe
}

std::string Empresa::obtenerNombreTrabajador(int id) {
    for (const auto& trabajador : trabajadores) { // Recorre el vector de trabajadores
        if (trabajador.obtenerID() == id) { // Comprueba si el ID del trabajador coincide
            return trabajador.obtenerNombre(); // Retorna el nombre del trabajador si se encuentra
        }
    }
    return "Desconocido"; // Si no se encuentra el trabajador, retorna "Desconocido"
}

