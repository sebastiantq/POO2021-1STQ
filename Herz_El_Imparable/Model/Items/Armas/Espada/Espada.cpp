//
// Created by usuario on 20/05/2021.
//

#include "Espada.h"

Espada::Espada(){
    setImagen('E');
    setTipo(ARMA);
    setTipoArma(ESPADA);
    interactivo = true;
    checked = true;
}

bool Espada::interaccion(){
    int opcion;

    do{
        cout << "Has encontrado una espada, ¿deseas añadirla al inventario? (1. Si, 0. No): ";
        cin >> opcion;
    }while(opcion != 0 && opcion != 1);

    return opcion;
}

Espada::~Espada(){

}