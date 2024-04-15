#include "Persona.h" // Incluye la declaraci�n de la clase Persona

// Implementaci�n del constructor de Persona
Persona::Persona(const std::string& nombre) : nombre(nombre) {}

// Implementaci�n del m�todo para obtener el nombre de la persona
const std::string& Persona::obtenerNombre() const {
    return nombre; // Devuelve el nombre de la persona
}

