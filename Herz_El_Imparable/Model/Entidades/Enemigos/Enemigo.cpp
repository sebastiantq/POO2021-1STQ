//
// Created by usuario on 17/05/2021.
//

#include "Enemigo.h"

Enemigo::Enemigo(){
    setImagen('E');
    setTipo(ENEMIGO);
    interactivo = true;
    checked = true;
}

void Enemigo::setTipoEnemigo(TipoEnemigo nuevoTipoEnemigo){

}

Enemigo::~Enemigo(){

}