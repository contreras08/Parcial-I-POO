// main.cpp
#include <iostream>
#include "Empresa.h"

int main() {
    Empresa empresa;
    empresa.cargarTrabajadoresDesdeArchivo("trabajadores3.txt");

    int opcion;
    std::string nombre;
    int dia, mes, anno;
    int id;

    do {
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
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                empresa.registrarDatosDiarios();
                break;
            // Agregar un nuevo case en el switch para consultar el promedio de temperatura del trabajador
		case 2:
		    std::cout << "Ingrese el ID del trabajador: ";
		    std::cin >> id;
		    if (empresa.verificarExistenciaTrabajador(id)) {
		        std::string nombreTrabajador = empresa.obtenerNombreTrabajador(id);
		        std::cout << "Promedio de temperatura del trabajador " << nombreTrabajador << " (ID " << id << "): " << empresa.obtenerPromedioTemperaturaTrabajador(id) << std::endl;
		    } else {
		        std::cout << "No se encontró ningún trabajador con el ID proporcionado." << std::endl;
		    }
		    break;
            case 3:
                empresa.mostrarTrabajadores();
                break;
            case 4:
                empresa.agregarTrabajadorDesdeConsola();
                break;
			case 5:
			    std::cout << "Ingrese el ID del trabajador: ";
			    std::cin >> id;
			    if (empresa.verificarExistenciaTrabajador(id)) {
			        std::string nombreTrabajador = empresa.obtenerNombreTrabajador(id);
			        std::cout << "Ingrese la fecha para consultar los datos de bioseguridad del trabajador " << nombreTrabajador << " (ID " << id << "): ";
			        std::cin >> dia >> mes >> anno;
			        empresa.consultarDatosBioseguridadPorFecha(id, Fecha(dia, mes, anno));
			    } else {
			        std::cout << "No se encontró ningún trabajador con el ID proporcionado." << std::endl;
			    }
			    break;
            case 6:
                std::cout << "Ingrese el ID del trabajador que desea eliminar: ";
                std::cin >> id;
                empresa.eliminarTrabajador(id);
                break;
                
			case 7:
			    std::cout << "Ingrese el ID del trabajador: ";
			    std::cin >> id;
			    if (empresa.verificarExistenciaTrabajador(id)) {
			        std::string nombreTrabajador = empresa.obtenerNombreTrabajador(id);
			        std::cout << "Ingrese el número de semana para consultar los datos de bioseguridad del trabajador " << nombreTrabajador << " (ID " << id << "): ";
			        int semana;
			        std::cin >> semana;
			        empresa.consultarDatosBioseguridadPorSemana(id, semana);
			    } else {
			        std::cout << "No se encontró ningún trabajador con el ID proporcionado." << std::endl;
			    }
			    break;
            case 8:
                std::cout << "Guardando trabajadores en el archivo..." << std::endl;
                empresa.guardarTrabajadoresEnArchivo("trabajadores3.txt");
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
                break;
        }
    } while (opcion != 8);

    return 0;
}

