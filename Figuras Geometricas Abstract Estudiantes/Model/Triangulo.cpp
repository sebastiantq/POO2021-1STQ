#include "Triangulo.h"

//CONSTRUCTORES TRIANGULO

Triangulo::Triangulo()
{
}

Triangulo::Triangulo(float base, float altura)
{
    this->base = base;
    this->altura = altura;
}

//METODOS TRIANGULO

void Triangulo::calcularArea()
{
    float area;
    area = (base * altura) / 2;
    std::cout << "El area del Triangulo es: " << area << std::endl;
}

void Triangulo::calcularPerimetro()
{
    float perimetro, temp;
    temp = base / 2;
    perimetro = 2 * ((sqrt((temp * temp)) + (altura * altura))) + base;
    std::cout << "El perimetro del Triangulo es: " << perimetro << std::endl;
}

void Triangulo::mostrarFigura()
{
    cout << "La base: " << base << " -- "
         << "la altura: " << altura << endl;
}

float Triangulo::getBase() const
{
    return this->base;
}

float Triangulo::getAltura() const
{
    return this->altura;
}

void Triangulo::setBase(float base)
{
    this->base = base;
}

void Triangulo::setAltura(float altura)
{
    this->altura = altura;
}
