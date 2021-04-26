//#ifndef CUADRADO_H
// Guardas
//#define CUADRADO_H

//CLASE TRIANGULO

#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

#include "FiguraGeometrica.h"

class Cuadrado : public FiguraGeometrica
{
private:
    float lado;

public:
    Cuadrado();
    Cuadrado(float lado);
    virtual void calcularArea();
    virtual void calcularPerimetro();
    virtual void mostrarFigura();
    float getLado() const;
    void setLado(float);
};

//#endif /* !CUADRADO_H */
