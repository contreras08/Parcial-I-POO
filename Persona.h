#ifndef PERSONA_H // Directiva de preprocesador: Evita la inclusión múltiple del archivo
#define PERSONA_H

#include <string> // Incluye la librería para usar cadenas de texto

// Definición de la clase Persona
class Persona {
protected:
    std::string nombre; // Nombre de la persona

public:
    // Constructor de Persona
    Persona(const std::string& nombre);
    
    // Método para obtener el nombre de la persona
    const std::string& obtenerNombre() const;
};

#endif // PERSONA_H // Fin de la directiva de preprocesador

