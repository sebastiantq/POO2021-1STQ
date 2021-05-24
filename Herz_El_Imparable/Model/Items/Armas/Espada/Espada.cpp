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

void Espada::interaccion(){

}

Espada::~Espada(){

}