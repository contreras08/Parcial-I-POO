#include "Trabajador.h" // Incluye la declaraci�n de la clase Trabajador

// Implementaci�n del constructor de RegistroDiario
RegistroDiario::RegistroDiario(const Fecha& fecha, float temperatura, bool tos, bool fiebre)
    : fecha(fecha), temperatura(temperatura), tos(tos), fiebre(fiebre) {}

// Implementaci�n del m�todo para obtener la fecha del registro
Fecha RegistroDiario::obtenerFecha() const {
    return fecha;
}

// Implementaci�n del m�todo para obtener la temperatura registrada
float RegistroDiario::obtenerTemperatura() const {
    return temperatura;
}

// Implementaci�n del m�todo para comprobar si hay tos registrada
bool RegistroDiario::tieneTos() const {
    return tos;
}

// Implementaci�n del m�todo para comprobar si hay fiebre registrada
bool RegistroDiario::tieneFiebre() const {
    return fiebre;
}

// Implementaci�n del constructor de Trabajador
Trabajador::Trabajador(const std::string& nombre, int id)
    : Persona(nombre), id(id) {}

// Implementaci�n del m�todo para registrar los datos diarios de un trabajador
void Trabajador::registrarDatosDiarios(const Fecha& fecha, float temperatura, bool tos, bool fiebre) {
    registros.push_back(RegistroDiario(fecha, temperatura, tos, fiebre)); // A�ade un nuevo registro al vector de registros
}

// Implementaci�n del m�todo para obtener el ID del trabajador
int Trabajador::obtenerID() const {
    return id;
}

// Implementaci�n del m�todo para obtener los registros diarios del trabajador
const std::vector<RegistroDiario>& Trabajador::obtenerRegistros() const {
    return registros;
}

