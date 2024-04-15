#ifndef FECHA_H
#define FECHA_H

#include <string>

class Fecha {
private:
    int dia;
    int mes;
    int anno;

public:
    Fecha(int dia, int mes, int anno);

    int getDia() const;
    int getMes() const;
    int getAnno() const;

    // Sobrecarga de operadores
    bool operator>=(const Fecha& otraFecha) const;
    bool operator<=(const Fecha& otraFecha) const;
    bool operator==(const Fecha& otraFecha) const;
    
    int obtenerNumeroSemana() const;
};

#endif // FECHA_H
