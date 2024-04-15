#include "Persona.h" // Incluye la declaración de la clase Persona

// Implementación del constructor de Persona
Persona::Persona(const std::string& nombre) : nombre(nombre) {}

// Implementación del método para obtener el nombre de la persona
const std::string& Persona::obtenerNombre() const {
    return nombre; // Devuelve el nombre de la persona
}

