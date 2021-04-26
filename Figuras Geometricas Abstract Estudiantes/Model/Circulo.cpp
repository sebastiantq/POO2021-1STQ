#include "Circulo.h"

//Inicializa la variable PI que es estática y constante
const float Circulo::PI = 3.1416;

//CONSTRUCTORES CIRCULO
Circulo::Circulo()
{
}

Circulo::Circulo(float radio) : Circulo()
{

    this->radio = radio;
}

//METODOS CIRCULO

void Circulo::calcularArea()
{
    float area;
    area = PI * (radio * radio);
    cout << "El area del circulo es: " << area << endl;
}

void Circulo::calcularPerimetro()
{
    float perimetro;
    perimetro = (2 * PI) * radio;
    cout << "El perimetro del circulo es: " << perimetro << endl;
}

void Circulo::mostrarFigura()
{
    cout << "El radio: " << radio << endl;
}

float Circulo::getRadio() const
{

    return this->radio;
}

void Circulo::setRadio(float radio)
{

    this->radio = radio;
}
