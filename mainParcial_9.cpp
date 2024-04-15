#include <iostream>
#include "Empresa.h" // Incluye la declaraci�n de la clase Empresa

int main() {
    Empresa empresa; // Crea una instancia de la clase Empresa
    empresa.cargarTrabajadoresDesdeArchivo("trabajadores3.txt"); // Carga los datos de los trabajadores desde un archivo

    int opcion; // Variable para almacenar la opci�n seleccionada por el usuario
    std::string nombre; // Variable para almacenar el nombre
    int dia, mes, anno; // Variables para almacenar el d�a, mes y a�o
    int id; // Variable para almacenar el ID del trabajador

    do {
        // Men� de opciones
        std::cout << "===== Menu =====" << std::endl;
        std::cout << "1. Registrar datos diarios" << std::endl;
        std::cout << "2. Consultar promedio de temperatura semanal" << std::endl;
        std::cout << "3. Mostrar trabajadores" << std::endl;
        std::cout << "4. Agregar trabajador" << std::endl;
        std::cout << "5. Consultar datos de bioseguridad por fecha" << std::endl;
        std::cout << "6. Eliminar trabajador" << std::endl;
        std::cout << "7. Consultar datos de Bioseguridad por semana" << std::endl;
        std::cout << "8. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion; // Lee la opci�n seleccionada por el usuario

        switch (opcion) {
            case 1:
                empresa.registrarDatosDiarios(); // Registra los datos diarios de los trabajadores
                break;
            case 2:
                std::cout << "Ingrese el ID del trabajador: ";
                std::cin >> id; // Solicita al usuario que ingrese el ID del trabajador
                if (empresa.verificarExistenciaTrabajador(id)) { // Verifica si el trabajador existe
                    std::string nombreTrabajador = empresa.obtenerNombreTrabajador(id); // Obtiene el nombre del trabajador
                    std::cout << "Promedio de temperatura del trabajador " << nombreTrabajador << " (ID " << id << "): " << empresa.obtenerPromedioTemperaturaTrabajador(id) << std::endl; // Muestra el promedio de temperatura del trabajador
                } else {
                    std::cout << "No se encontr� ning�n trabajador con el ID proporcionado." << std::endl; // Mensaje si el trabajador no existe
                }
                break;
            case 3:
                empresa.mostrarTrabajadores(); // Muestra la informaci�n de los trabajadores
                break;
            case 4:
                empresa.agregarTrabajadorDesdeConsola(); // Agrega un trabajador ingresando los datos desde la consola
                break;
            case 5:
                std::cout << "Ingrese el ID del trabajador: ";
                std::cin >> id; // Solicita al usuario que ingrese el ID del trabajador
                if (empresa.verificarExistenciaTrabajador(id)) { // Verifica si el trabajador existe
                    std::string nombreTrabajador = empresa.obtenerNombreTrabajador(id); // Obtiene el nombre del trabajador
                    std::cout << "Ingrese la fecha para consultar los datos de bioseguridad del trabajador " << nombreTrabajador << " (ID " << id << "): ";
                    std::cin >> dia >> mes >> anno; // Lee la fecha ingresada por el usuario
                    empresa.consultarDatosBioseguridadPorFecha(id, Fecha(dia, mes, anno)); // Consulta los datos de bioseguridad por fecha
                } else {
                    std::cout << "No se encontr� ning�n trabajador con el ID proporcionado." << std::endl; // Mensaje si el trabajador no existe
                }
                break;
            case 6:
                std::cout << "Ingrese el ID del trabajador que desea eliminar: ";
                std::cin >> id; // Solicita al usuario que ingrese el ID del trabajador que desea eliminar
                empresa.eliminarTrabajador(id); // Elimina al trabajador
                break;
            case 7:
                std::cout << "Ingrese el ID del trabajador: ";
                std::cin >> id; // Solicita al usuario que ingrese el ID del trabajador
                if (empresa.verificarExistenciaTrabajador(id)) { // Verifica si el trabajador existe
                    std::string nombreTrabajador = empresa.obtenerNombreTrabajador(id); // Obtiene el nombre del trabajador
                    std::cout << "Ingrese el n�mero de semana para consultar los datos de bioseguridad del trabajador " << nombreTrabajador << " (ID " << id << "): ";
                    int semana;
                    std::cin >> semana; // Lee el n�mero de semana ingresado por el usuario
                    empresa.consultarDatosBioseguridadPorSemana(id, semana); // Consulta los datos de bioseguridad por semana
                } else {
                    std::cout << "No se encontr� ning�n trabajador con el ID proporcionado." << std::endl; // Mensaje si el trabajador no existe
                }
                break;
            case 8:
                std::cout << "Guardando trabajadores en el archivo..." << std::endl; // Mensaje indicando que se est�n guardando los trabajadores en el archivo
                empresa.guardarTrabajadoresEnArchivo("trabajadores3.txt"); // Guarda los trabajadores en un archivo
                std::cout << "Saliendo del programa..." << std::endl; // Mensaje indicando que el programa est� saliendo
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl; // Mensaje si se ingresa una opci�n no v�lida
                break;
        }
    } while (opcion != 8); // Contin�a mostrando el men� hasta que se seleccione la opci�n de salir

    return 0;
}

