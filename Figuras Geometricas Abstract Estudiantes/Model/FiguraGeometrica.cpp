#include "FiguraGeometrica.h"

FiguraGeometrica::FiguraGeometrica()
    : color("Rojo"), area(0.0), perimetro(0.0)
{
}
FiguraGeometrica::FiguraGeometrica(string color)
    : FiguraGeometrica()
{
    this->color = color;
}

// Getters y setters
string FiguraGeometrica::getColor() const
{
    return this->color;
}
void FiguraGeometrica::setColor(string color)
{
    this->color = color;
}

float FiguraGeometrica::getArea() const
{
    return this->area;
}

float FiguraGeometrica::getPerimetro() const
{
    return this->perimetro;
}
