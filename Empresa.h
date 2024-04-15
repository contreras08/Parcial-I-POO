#ifndef EMPRESA_H
#define EMPRESA_H

#include <vector>
#include <string>
#include "Trabajador.h"

class Empresa {
private:
    std::vector<Trabajador> trabajadores;

public:
    Empresa();
    ~Empresa();

    void cargarTrabajadoresDesdeArchivo(const std::string& nombreArchivo);
    void agregarTrabajadorDesdeConsola();
    void registrarDatosDiarios();
    void mostrarTrabajadores() const;
    void eliminarTrabajador(int id);
    void guardarTrabajadoresEnArchivo(const std::string& nombreArchivo) const;
    float obtenerPromedioTemperaturaTrabajador(int id) const;
    void consultarDatosBioseguridadPorFecha(int id, const Fecha& fecha) const;
    void consultarDatosBioseguridadPorSemana(int id, int semana) const;
    int obtenerNumeroSemana() const;
    bool verificarExistenciaTrabajador(int id); // Método para verificar la existencia del trabajador
    std::string obtenerNombreTrabajador(int id); // Método para obtener el nombre del trabajador asociado a un ID
};

#endif // EMPRESA_H

