#ifndef PERSONA_H // Directiva de preprocesador: Evita la inclusi�n m�ltiple del archivo
#define PERSONA_H

#include <string> // Incluye la librer�a para usar cadenas de texto

// Definici�n de la clase Persona
class Persona {
protected:
    std::string nombre; // Nombre de la persona

public:
    // Constructor de Persona
    Persona(const std::string& nombre);
    
    // M�todo para obtener el nombre de la persona
    const std::string& obtenerNombre() const;
};

#endif // PERSONA_H // Fin de la directiva de preprocesador

