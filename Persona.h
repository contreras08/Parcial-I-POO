#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
protected:
    std::string nombre;

public:
    Persona(const std::string& nombre);
    const std::string& obtenerNombre() const;
};

#endif // PERSONA_H

