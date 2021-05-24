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

void Curacion::interaccion(){

}

Curacion::~Curacion(){

}