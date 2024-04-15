#include "Fecha.h" // Incluye la declaraci�n de la clase Fecha

// Implementaci�n del constructor de Fecha
Fecha::Fecha(int dia, int mes, int anno) : dia(dia), mes(mes), anno(anno) {}

// Implementaci�n del m�todo para obtener el d�a
int Fecha::getDia() const {
    return dia; // Devuelve el d�a almacenado en el objeto Fecha
}

// Implementaci�n del m�todo para obtener el mes
int Fecha::getMes() const {
    return mes; // Devuelve el mes almacenado en el objeto Fecha
}

// Implementaci�n del m�todo para obtener el a�o
int Fecha::getAnno() const {
    return anno; // Devuelve el a�o almacenado en el objeto Fecha
}

// Implementaci�n de la sobrecarga del operador mayor o igual que
bool Fecha::operator>=(const Fecha& otraFecha) const {
    // Compara los a�os, si son distintos, retorna true o false dependiendo del a�o
    if (anno > otraFecha.anno) return true;
    if (anno < otraFecha.anno) return false;
    // Si los a�os son iguales, compara los meses y luego los d�as
    if (mes > otraFecha.mes) return true;
    if (mes < otraFecha.mes) return false;
    return dia >= otraFecha.dia;
}

// Implementaci�n de la sobrecarga del operador menor o igual que
bool Fecha::operator<=(const Fecha& otraFecha) const {
    // Compara los a�os, si son distintos, retorna true o false dependiendo del a�o
    if (anno < otraFecha.anno) return true;
    if (anno > otraFecha.anno) return false;
    // Si los a�os son iguales, compara los meses y luego los d�as
    if (mes < otraFecha.mes) return true;
    if (mes > otraFecha.mes) return false;
    return dia <= otraFecha.dia;
}

// Implementaci�n de la sobrecarga del operador de igualdad
bool Fecha::operator==(const Fecha& otraFecha) const {
    // Compara los d�as, los meses y los a�os
    return dia == otraFecha.dia && mes == otraFecha.mes && anno == otraFecha.anno;
}

