//
// Created by usuario on 21/05/2021.
//

#include "Curacion.h"

Curacion::Curacion(){
    setImagen('C');
    setTipo(POCION);
    setTipoPocion(CURACION);
    interactivo = true;
    checked = true;
}

void Curacion::consumir(Espacio* jugador){

}

bool Curacion::interaccion(){
    int opcion;

    do{
        cout << "Has encontrado una pocion de curacion, ¿deseas añadirla al inventario? (1. Si, 0. No): ";
        cin >> opcion;
    }while(opcion != 0 && opcion != 1);

    return opcion;
}

Curacion::~Curacion(){

}