//#ifndef RECTANGULO_H
// Guardas
//#define RECTANGULO_H

//CLASE RECTANGULO
#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

class Rectangulo
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
    float getLargo();
    float getAncho();
    void setLargo(float);
    void setAncho(float);
};

//#endif /* !RECTANGULO_H */