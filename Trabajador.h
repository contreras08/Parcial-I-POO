#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include <vector>
#include <string>
#include "Fecha.h"
#include "Persona.h"

class RegistroDiario {
private:
    Fecha fecha;
    float temperatura;
    bool tos;
    bool fiebre;

public:
    RegistroDiario(const Fecha& fecha, float temperatura, bool tos, bool fiebre);
    Fecha obtenerFecha() const;
    float obtenerTemperatura() const;
    bool tieneTos() const;
    bool tieneFiebre() const;
};

class Trabajador : public Persona {
private:
    int id;
    std::vector<RegistroDiario> registros;

public:
    Trabajador(const std::string& nombre, int id);
    void registrarDatosDiarios(const Fecha& fecha, float temperatura, bool tos, bool fiebre);
    int obtenerID() const;
    const std::vector<RegistroDiario>& obtenerRegistros() const;
};

#endif // TRABAJADOR_H

