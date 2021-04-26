//#ifndef RECTANGULO_H
// Guardas
//#define RECTANGULO_H

//CLASE RECTANGULO
#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

#include "FiguraGeometrica.h"

class Rectangulo : public FiguraGeometrica
{
private:
    float ancho, largo;

public:
    Rectangulo(); //no olvidar
    Rectangulo(float, float);
    void mostrarFigura() const;
    virtual void calcularArea();
    virtual void calcularPerimetro();
    virtual void mostrarFigura();
    float getLargo() const;
    float getAncho() const;
    void setLargo(float);
    void setAncho(float);
};

//#endif /* !RECTANGULO_H */
