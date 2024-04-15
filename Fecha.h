#ifndef FECHA_H // Directiva de preprocesador: Evita la inclusi�n m�ltiple del archivo
#define FECHA_H

#include <string> // Incluye la librer�a para usar cadenas de texto

// Definici�n de la clase Fecha
class Fecha {
private:
    int dia; // D�a
    int mes; // Mes
    int anno; // A�o

public:
    // Constructor de Fecha
    Fecha(int dia, int mes, int anno);

    // M�todos para obtener el d�a, el mes y el a�o
    int getDia() const;
    int getMes() const;
    int getAnno() const;

    // Sobrecarga de operadores
    bool operator>=(const Fecha& otraFecha) const; // Operador mayor o igual que
    bool operator<=(const Fecha& otraFecha) const; // Operador menor o igual que
    bool operator==(const Fecha& otraFecha) const; // Operador de igualdad

    // M�todo para obtener el n�mero de semana del a�o
    int obtenerNumeroSemana() const;
};

#endif // FECHA_H // Fin de la directiva de preprocesador

