#ifndef FIGURA_GEOMETRICA_H
// Guardas
#define FIGURA_GEOMETRICA_H

#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//CLASE FIGURA_GEOMETRICA

class FiguraGeometrica
{
private: //atributos
    string color;

protected:
    float area, perimetro;

public:
    FiguraGeometrica(); //NO OLVIDAR
    FiguraGeometrica(string color);
    string getColor() const;
    void setColor(string);
    float getArea() const;
    float getPerimetro() const;
    virtual void calcularArea() = 0;
    virtual void calcularPerimetro() = 0;
    virtual void mostrarFigura() = 0;
};

#endif /* !FIGURA_GEOMETRICA_H */
