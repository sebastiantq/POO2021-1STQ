//
// Created by usuario on 21/05/2021.
//

#include "Fuerza.h"

Fuerza::Fuerza(){
    setImagen('F');
    setTipo(POCION);
    setTipoPocion(FUERZA);
    interactivo = true;
    checked = true;
}

void Fuerza::consumir(Espacio* jugador){

}

bool Fuerza::interaccion(){
    int opcion;

    do{
        cout << "Has encontrado una pocion de fuerza, ¿deseas añadirla al inventario? (1. Si, 0. No): ";
        cin >> opcion;
    }while(opcion != 0 && opcion != 1);

    return opcion;
}

Fuerza::~Fuerza(){

}