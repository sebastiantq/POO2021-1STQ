#include "Cuadrado.h"

//CONSTRUCTORES CUADRADO

Cuadrado::Cuadrado()
{
}

Cuadrado::Cuadrado(float lado)
{
    this->lado = lado;
}

//METODOS CUADRADO

void Cuadrado::calcularArea()
{
    std::cout << "El area del Cuadrado es: " << lado * lado << std::endl;
}

void Cuadrado::calcularPerimetro()
{
    std::cout << "El perimetro del Cuadrado es: " << lado * 4 << std::endl;
}

void Cuadrado::mostrarFigura()
{
    cout << "Las dimensiones: " << lado << " * " << lado << endl;
}

float Cuadrado::getLado() const
{
    return this->lado;
}

void Cuadrado::setLado(float lado)
{
    this->lado = lado;
}
