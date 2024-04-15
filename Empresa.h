#ifndef EMPRESA_H
#define EMPRESA_H

#include <vector>
#include <string>
#include "Trabajador.h" // Incluye la declaración de la clase Trabajador

class Empresa {
private:
    std::vector<Trabajador> trabajadores; // Vector que almacena objetos de la clase Trabajador

public:
    Empresa(); // Constructor de la clase Empresa
    ~Empresa(); // Destructor de la clase Empresa

    // Métodos de la clase Empresa
    void cargarTrabajadoresDesdeArchivo(const std::string& nombreArchivo); // Carga los datos de los trabajadores desde un archivo
    void agregarTrabajadorDesdeConsola(); // Agrega un trabajador ingresando los datos desde la consola
    void registrarDatosDiarios(); // Registra los datos diarios de los trabajadores
    void mostrarTrabajadores() const; // Muestra la información de los trabajadores
    void eliminarTrabajador(int id); // Elimina un trabajador por su ID
    void guardarTrabajadoresEnArchivo(const std::string& nombreArchivo) const; // Guarda los trabajadores en un archivo
    float obtenerPromedioTemperaturaTrabajador(int id) const; // Obtiene el promedio de temperatura de un trabajador por su ID
    void consultarDatosBioseguridadPorFecha(int id, const Fecha& fecha) const; // Consulta los datos de bioseguridad de un trabajador por fecha
    void consultarDatosBioseguridadPorSemana(int id, int semana) const; // Consulta los datos de bioseguridad de un trabajador por semana
    int obtenerNumeroSemana() const; // Obtiene el número de semana actual
    bool verificarExistenciaTrabajador(int id); // Verifica la existencia de un trabajador por su ID
    std::string obtenerNombreTrabajador(int id); // Obtiene el nombre de un trabajador por su ID
};

#endif // EMPRESA_H

