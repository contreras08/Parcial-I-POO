// Persona.cpp

#include "Persona.h"

Persona::Persona(const std::string& nombre) : nombre(nombre) {}

const std::string& Persona::obtenerNombre() const {
    return nombre;
}

