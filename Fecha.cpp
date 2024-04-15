#include "Fecha.h" // Incluye la declaración de la clase Fecha

// Implementación del constructor de Fecha
Fecha::Fecha(int dia, int mes, int anno) : dia(dia), mes(mes), anno(anno) {}

// Implementación del método para obtener el día
int Fecha::getDia() const {
    return dia; // Devuelve el día almacenado en el objeto Fecha
}

// Implementación del método para obtener el mes
int Fecha::getMes() const {
    return mes; // Devuelve el mes almacenado en el objeto Fecha
}

// Implementación del método para obtener el año
int Fecha::getAnno() const {
    return anno; // Devuelve el año almacenado en el objeto Fecha
}

// Implementación de la sobrecarga del operador mayor o igual que
bool Fecha::operator>=(const Fecha& otraFecha) const {
    // Compara los años, si son distintos, retorna true o false dependiendo del año
    if (anno > otraFecha.anno) return true;
    if (anno < otraFecha.anno) return false;
    // Si los años son iguales, compara los meses y luego los días
    if (mes > otraFecha.mes) return true;
    if (mes < otraFecha.mes) return false;
    return dia >= otraFecha.dia;
}

// Implementación de la sobrecarga del operador menor o igual que
bool Fecha::operator<=(const Fecha& otraFecha) const {
    // Compara los años, si son distintos, retorna true o false dependiendo del año
    if (anno < otraFecha.anno) return true;
    if (anno > otraFecha.anno) return false;
    // Si los años son iguales, compara los meses y luego los días
    if (mes < otraFecha.mes) return true;
    if (mes > otraFecha.mes) return false;
    return dia <= otraFecha.dia;
}

// Implementación de la sobrecarga del operador de igualdad
bool Fecha::operator==(const Fecha& otraFecha) const {
    // Compara los días, los meses y los años
    return dia == otraFecha.dia && mes == otraFecha.mes && anno == otraFecha.anno;
}

