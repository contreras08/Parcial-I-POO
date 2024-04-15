#include "Trabajador.h"

RegistroDiario::RegistroDiario(const Fecha& fecha, float temperatura, bool tos, bool fiebre)
    : fecha(fecha), temperatura(temperatura), tos(tos), fiebre(fiebre) {}

Fecha RegistroDiario::obtenerFecha() const {
    return fecha;
}

float RegistroDiario::obtenerTemperatura() const {
    return temperatura;
}

bool RegistroDiario::tieneTos() const {
    return tos;
}

bool RegistroDiario::tieneFiebre() const {
    return fiebre;
}

Trabajador::Trabajador(const std::string& nombre, int id)
    : Persona(nombre), id(id) {}

void Trabajador::registrarDatosDiarios(const Fecha& fecha, float temperatura, bool tos, bool fiebre) {
    registros.push_back(RegistroDiario(fecha, temperatura, tos, fiebre));
}

int Trabajador::obtenerID() const {
    return id;
}

const std::vector<RegistroDiario>& Trabajador::obtenerRegistros() const {
    return registros;
}

