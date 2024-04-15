#ifndef TRABAJADOR_H // Directiva de preprocesador: Evita la inclusi�n m�ltiple del archivo
#define TRABAJADOR_H

#include <vector> // Incluye la librer�a para usar vectores
#include <string> // Incluye la librer�a para usar cadenas de texto
#include "Fecha.h" // Incluye la definici�n de la clase Fecha
#include "Persona.h" // Incluye la definici�n de la clase Persona

// Definici�n de la clase RegistroDiario
class RegistroDiario {
private:
    Fecha fecha; // Fecha del registro
    float temperatura; // Temperatura registrada
    bool tos; // Indicador de tos
    bool fiebre; // Indicador de fiebre

public:
    // Constructor de RegistroDiario
    RegistroDiario(const Fecha& fecha, float temperatura, bool tos, bool fiebre);
    
    // M�todos para obtener informaci�n del registro diario
    Fecha obtenerFecha() const; // Devuelve la fecha del registro
    float obtenerTemperatura() const; // Devuelve la temperatura registrada
    bool tieneTos() const; // Devuelve true si hay tos registrada
    bool tieneFiebre() const; // Devuelve true si hay fiebre registrada
};

// Definici�n de la clase Trabajador que hereda de Persona
class Trabajador : public Persona {
private:
    int id; // Identificador del trabajador
    std::vector<RegistroDiario> registros; // Vectores de registros diarios

public:
    // Constructor de Trabajador
    Trabajador(const std::string& nombre, int id);
    
    // M�todo para registrar los datos diarios de un trabajador
    void registrarDatosDiarios(const Fecha& fecha, float temperatura, bool tos, bool fiebre);
    
    // M�todos para obtener informaci�n del trabajador
    int obtenerID() const; // Devuelve el ID del trabajador
    const std::vector<RegistroDiario>& obtenerRegistros() const; // Devuelve los registros diarios del trabajador
};

#endif // TRABAJADOR_H // Fin de la directiva de preprocesador

