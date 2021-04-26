#include "../Controller/FigurasController.h"

// Inicializacion constante estatica para elemento compartido
const int FigurasController::MAX_ITEMS = 10;

void FigurasController::agregarRectagulo(const float largo, const float ancho)
{
    if (listaRectangulo.size() < MAX_ITEMS)
    {
        cout << "Agrego rectangulo" << endl;
        Rectangulo *pRectTemp = new Rectangulo(largo, ancho);
        listaRectangulo.push_back(*pRectTemp);
    }
    else
    {
        //FIXME agregar manejo de excepcion
        std::cout << "\nSe sobrepasa el limite\n"
                  << std::endl;
    }
}

void FigurasController::agregarCirculo(float radio)
{
    if (listaCirculo.size() < MAX_ITEMS)
    {
        cout << "Agrego circulo" << endl;
    }
    else
    {
        //FIXME agregar manejo de excepcion
        std::cout << "\nSe sobrepasa el limite\n"
                  << std::endl;
    }
}

list<Rectangulo> &FigurasController::getListaRectangulo()
{
    // Creo la  referencia
    list<Rectangulo> &lista = listaRectangulo;
    return lista;
}

Rectangulo &FigurasController::encontrarMayorAncho()
{
    bool isFirst = true;
    int mayorAncho = 0;
    Rectangulo *pRectanguloMayor = NULL;
    for (list<Rectangulo>::iterator it = listaRectangulo.begin(); it != listaRectangulo.end(); ++it)
    {
        if (isFirst)
        {
            // Se inicializa el mayor ancho con el primer elemento
            int mayorAncho = listaRectangulo.begin()->getAncho();
            isFirst = false;
            pRectanguloMayor = &(*it); // It es un apuntador, para acceder al rectangulo se tiene que acceder al contenido
        }
        else
        {
            if (it->getAncho() > pRectanguloMayor->getAncho())
            {
                // Actaulizar el mayor
                pRectanguloMayor = &(*it);
            }
        }
    }
    // Se obtien el contenido del apuntador para luego retorar la referencia
    // a fin de facilitar el manejo de los objetos posteriormente
    return *pRectanguloMayor;
}

void FigurasController::llenarListaFiguras()
{
    Rectangulo * pRectangulo = new Rectangulo(10, 20);
    Circulo * pCirculo = new Circulo(5);
    Cuadrado * pCuadrado = new Cuadrado(8);
    Triangulo * pTriangulo = new Triangulo(20, 10);
    
    this->listaFigurasGeometricas.push_back( pRectangulo );
    this->listaFigurasGeometricas.push_back( pCirculo );
    this->listaFigurasGeometricas.push_back( pCuadrado );
    this->listaFigurasGeometricas.push_back( pTriangulo );
}

list<FiguraGeometrica *> &FigurasController::getListaFiguras()
{
    return listaFigurasGeometricas;
}
