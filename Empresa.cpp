#include "Empresa.h"
#include <algorithm> // Añadir esta línea para usar std::find_if
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip> // Agregar esta línea para utilizar setw

Empresa::Empresa() {}

Empresa::~Empresa() {
    guardarTrabajadoresEnArchivo("trabajadores3.txt");
}

void Empresa::cargarTrabajadoresDesdeArchivo(const std::string& nombreArchivo) {
    trabajadores.clear();
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    std::string nombre;
    int id;
    while (archivo >> nombre >> id) {
        trabajadores.push_back(Trabajador(nombre, id));
    }

    archivo.close();
}

void Empresa::agregarTrabajadorDesdeConsola() {
    std::string nombre;
    int id;

    std::cout << "Ingrese el nombre del nuevo trabajador: ";
    std::cin >> nombre;

    std::cout << "Ingrese el ID del nuevo trabajador: ";
    std::cin >> id;

    trabajadores.push_back(Trabajador(nombre, id));

    guardarTrabajadoresEnArchivo("trabajadores3.txt");
}

void Empresa::registrarDatosDiarios() {
    cargarTrabajadoresDesdeArchivo("trabajadores3.txt");

    int id;
    std::cout << "Ingrese el ID del trabajador: ";
    std::cin >> id;

    Trabajador* trabajador = nullptr;
    for (auto& t : trabajadores) {
        if (t.obtenerID() == id) {
            trabajador = &t;
            break;
        }
    }

    if (trabajador == nullptr) {
        std::cerr << "Trabajador no encontrado" << std::endl;
        return;
    }

    int dia, mes, anno;
    float temperatura;
    bool tos, fiebre;

    std::cout << "Ingrese la fecha (dia mes anno): ";
    std::cin >> dia >> mes >> anno;
    Fecha fecha(dia, mes, anno);

    // Calculamos la semana correspondiente
    int semana = fecha.obtenerNumeroSemana(); // Implementación necesaria en la clase Fecha

    std::cout << "Ingrese la temperatura del trabajador: ";
    std::cin >> temperatura;

    std::cout << "¿El trabajador tiene tos? (1 para Si, 0 para No): ";
    std::cin >> tos;

    std::cout << "¿El trabajador tiene fiebre? (1 para Si, 0 para No): ";
    std::cin >> fiebre;

    // Registrar los datos diarios del trabajador
    trabajador->registrarDatosDiarios(fecha, temperatura, tos, fiebre);

    // Guardar los datos en el archivo datosSemana.txt
    std::ofstream archivoDatosSemana("datosSemana3.txt", std::ios_base::app);
    if (!archivoDatosSemana) {
        std::cerr << "Error al abrir el archivo datosSemana3.txt" << std::endl;
        return;
    }
    archivoDatosSemana << id << " " << semana << " " << dia << " " << mes << " " << anno << " " << temperatura << " " << tos << " " << fiebre << std::endl;
    archivoDatosSemana.close();

    // Guardar los datos de bioseguridad en el archivo datos2.txt
    std::ofstream archivoDatos("datos3.txt", std::ios_base::app);
    if (!archivoDatos) {
        std::cerr << "Error al abrir el archivo datos3.txt" << std::endl;
        return;
    }
    archivoDatos << id << " " << dia << " " << mes << " " << anno << " " << temperatura << " " << tos << " " << fiebre << std::endl;
    archivoDatos.close();

    // Guardar la lista actualizada de trabajadores en el archivo
    guardarTrabajadoresEnArchivo("trabajadores3.txt");
}



void Empresa::mostrarTrabajadores() const {
    std::ifstream archivo("trabajadores3.txt");
    if (!archivo) {
        std::cerr << "Error al abrir el archivo trabajadores3.txt" << std::endl;
        return;
    }

    std::string nombre;
    int id;
    while (archivo >> nombre >> id) {
        std::cout << "Nombre: " << nombre << ", ID: " << id << std::endl;
    }

    archivo.close();
}

void Empresa::eliminarTrabajador(int id) {
    auto it = std::find_if(trabajadores.begin(), trabajadores.end(), [id](const Trabajador& t) {
        return t.obtenerID() == id; // Cambiado de getId() a obtenerID()
    });

    if (it != trabajadores.end()) {
        trabajadores.erase(it);
        std::cout << "Trabajador con ID " << id << " eliminado exitosamente." << std::endl;

        // Crear un archivo temporal para guardar las entradas de datos que no corresponden al trabajador eliminado
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

        // Cerrar archivos
        archivoDatos.close();
        archivoTemporal.close();

        // Eliminar el archivo original y renombrar el archivo temporal al nombre original
        remove("datos3.txt");
        rename("temp3.txt", "datos3.txt");

    } else {
        std::cout << "No se encontró ningún trabajador con el ID " << id << "." << std::endl;
    }

    // Guardar la lista actualizada de trabajadores en el archivo
    guardarTrabajadoresEnArchivo("trabajadores3.txt");
}


void Empresa::guardarTrabajadoresEnArchivo(const std::string& nombreArchivo) const {
    std::ofstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    for (const auto& trabajador : trabajadores) {
        archivo << trabajador.obtenerNombre() << " " << trabajador.obtenerID() << std::endl; // Cambiado de getNombre() a obtenerNombre(), getId() a obtenerID()
    }

    archivo.close();
}

// Implementar la función para calcular el promedio de temperatura para un trabajador específico
float Empresa::obtenerPromedioTemperaturaTrabajador(int id) const {
    float sumaTemperaturas = 0;
    int contadorRegistros = 0;

    std::ifstream archivoDatos("datos3.txt");
    if (!archivoDatos) {
        std::cerr << "Error al abrir el archivo datos3.txt" << std::endl;
        return -1; // Valor de error
    }

    int idArchivo;
    int dia, mes, anno;
    float temperatura;
    bool tos, fiebre;

    while (archivoDatos >> idArchivo >> dia >> mes >> anno >> temperatura >> tos >> fiebre) {
        if (idArchivo == id) {
            sumaTemperaturas += temperatura;
            contadorRegistros++;
        }
    }

    archivoDatos.close();

    if (contadorRegistros == 0) {
        std::cerr << "No hay registros de temperatura para el trabajador con ID " << id << std::endl;
        return -1; // Valor de error
    }

    return sumaTemperaturas / contadorRegistros;
}

void Empresa::consultarDatosBioseguridadPorFecha(int id, const Fecha& fecha) const {
    std::ifstream archivoDatos("datos3.txt");
    if (!archivoDatos) {
        std::cerr << "Error al abrir el archivo datos3.txt" << std::endl;
        return;
    }

    int idArchivo;
    int dia, mes, anno;
    float temperatura;
    bool tos, fiebre;
    bool encontrado = false;

    while (archivoDatos >> idArchivo >> dia >> mes >> anno >> temperatura >> tos >> fiebre) {
        if (idArchivo == id && dia == fecha.getDia() && mes == fecha.getMes() && anno == fecha.getAnno()) {
            encontrado = true;
            std::cout << "=== Datos de bioseguridad para la fecha " << dia << "/" << mes << "/" << anno << " ===" << std::endl;
            std::cout << "Temperatura: " << temperatura << std::endl;
            std::cout << "Tos: " << (tos ? "Si" : "No") << std::endl;
            std::cout << "Fiebre: " << (fiebre ? "Si" : "No") << std::endl;
            break;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron datos de bioseguridad para esa fecha y trabajador" << std::endl;
    }

    archivoDatos.close();
}


void Empresa::consultarDatosBioseguridadPorSemana(int id, int semana) const {
    std::ifstream archivoDatosSemana("datosSemana3.txt");
    if (!archivoDatosSemana) {
        std::cerr << "Error al abrir el archivo datosSemana3.txt" << std::endl;
        return;
    }

    int idArchivo, semanaArchivo, dia, mes, anno;
    float temperatura;
    bool tos, fiebre;
    bool encontrado = false;

    while (archivoDatosSemana >> idArchivo >> semanaArchivo >> dia >> mes >> anno >> temperatura >> tos >> fiebre) {
        if (idArchivo == id && semanaArchivo == semana) {
            encontrado = true;
            std::cout << "=== Datos de bioseguridad para la semana " << semana << " ===" << std::endl;
            std::cout << std::setw(2) << std::setfill('0') << dia << "/" << std::setw(2) << std::setfill('0') << mes << "/" << anno << std::endl;
            std::cout << "Temperatura: " << temperatura << std::endl;
            std::cout << "Tos: " << (tos ? "Si" : "No") << std::endl;
            std::cout << "Fiebre: " << (fiebre ? "Si" : "No") << std::endl;
            std::cout << std::endl;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron datos de bioseguridad para esa semana y trabajador" << std::endl;
    }

    archivoDatosSemana.close();
}



int Fecha::obtenerNumeroSemana() const {
    std::tm tiempo = {};
    tiempo.tm_year = anno - 1900;
    tiempo.tm_mon = mes - 1;
    tiempo.tm_mday = dia;

    std::mktime(&tiempo);

    // Obtener el número de semana del año
    int diasDesdePrimerLunes = tiempo.tm_wday ? tiempo.tm_wday - 1 : 6;
    int diasHastaPrimerLunes = tiempo.tm_yday - diasDesdePrimerLunes;
    int numeroSemana = (diasHastaPrimerLunes / 7) + 1;

    return numeroSemana;
}



bool Empresa::verificarExistenciaTrabajador(int id) {
    for (const auto& trabajador : trabajadores) {
        if (trabajador.obtenerID() == id) {
            return true;
        }
    }
    return false;
}

std::string Empresa::obtenerNombreTrabajador(int id) {
    for (const auto& trabajador : trabajadores) {
        if (trabajador.obtenerID() == id) {
            return trabajador.obtenerNombre();
        }
    }
    return "Desconocido"; // Si no se encuentra el trabajador, devolvemos "Desconocido"
}


