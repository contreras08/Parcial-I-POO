#include "Fecha.h"

Fecha::Fecha(int dia, int mes, int anno) : dia(dia), mes(mes), anno(anno) {}

int Fecha::getDia() const {
    return dia;
}

int Fecha::getMes() const {
    return mes;
}

int Fecha::getAnno() const {
    return anno;
}

bool Fecha::operator>=(const Fecha& otraFecha) const {
    if (anno > otraFecha.anno) return true;
    if (anno < otraFecha.anno) return false;
    if (mes > otraFecha.mes) return true;
    if (mes < otraFecha.mes) return false;
    return dia >= otraFecha.dia;
}

bool Fecha::operator<=(const Fecha& otraFecha) const {
    if (anno < otraFecha.anno) return true;
    if (anno > otraFecha.anno) return false;
    if (mes < otraFecha.mes) return true;
    if (mes > otraFecha.mes) return false;
    return dia <= otraFecha.dia;
}

bool Fecha::operator==(const Fecha& otraFecha) const {
    return dia == otraFecha.dia && mes == otraFecha.mes && anno == otraFecha.anno;
}

