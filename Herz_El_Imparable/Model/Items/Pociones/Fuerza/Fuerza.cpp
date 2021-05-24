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

void Fuerza::interaccion(){

}

Fuerza::~Fuerza(){

}