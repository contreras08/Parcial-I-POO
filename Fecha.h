#ifndef FECHA_H // Directiva de preprocesador: Evita la inclusión múltiple del archivo
#define FECHA_H

#include <string> // Incluye la librería para usar cadenas de texto

// Definición de la clase Fecha
class Fecha {
private:
    int dia; // Día
    int mes; // Mes
    int anno; // Año

public:
    // Constructor de Fecha
    Fecha(int dia, int mes, int anno);

    // Métodos para obtener el día, el mes y el año
    int getDia() const;
    int getMes() const;
    int getAnno() const;

    // Sobrecarga de operadores
    bool operator>=(const Fecha& otraFecha) const; // Operador mayor o igual que
    bool operator<=(const Fecha& otraFecha) const; // Operador menor o igual que
    bool operator==(const Fecha& otraFecha) const; // Operador de igualdad

    // Método para obtener el número de semana del año
    int obtenerNumeroSemana() const;
};

#endif // FECHA_H // Fin de la directiva de preprocesador

