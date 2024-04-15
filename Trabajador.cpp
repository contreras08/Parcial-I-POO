#include "Trabajador.h" // Incluye la declaración de la clase Trabajador

// Implementación del constructor de RegistroDiario
RegistroDiario::RegistroDiario(const Fecha& fecha, float temperatura, bool tos, bool fiebre)
    : fecha(fecha), temperatura(temperatura), tos(tos), fiebre(fiebre) {}

// Implementación del método para obtener la fecha del registro
Fecha RegistroDiario::obtenerFecha() const {
    return fecha;
}

// Implementación del método para obtener la temperatura registrada
float RegistroDiario::obtenerTemperatura() const {
    return temperatura;
}

// Implementación del método para comprobar si hay tos registrada
bool RegistroDiario::tieneTos() const {
    return tos;
}

// Implementación del método para comprobar si hay fiebre registrada
bool RegistroDiario::tieneFiebre() const {
    return fiebre;
}

// Implementación del constructor de Trabajador
Trabajador::Trabajador(const std::string& nombre, int id)
    : Persona(nombre), id(id) {}

// Implementación del método para registrar los datos diarios de un trabajador
void Trabajador::registrarDatosDiarios(const Fecha& fecha, float temperatura, bool tos, bool fiebre) {
    registros.push_back(RegistroDiario(fecha, temperatura, tos, fiebre)); // Añade un nuevo registro al vector de registros
}

// Implementación del método para obtener el ID del trabajador
int Trabajador::obtenerID() const {
    return id;
}

// Implementación del método para obtener los registros diarios del trabajador
const std::vector<RegistroDiario>& Trabajador::obtenerRegistros() const {
    return registros;
}

