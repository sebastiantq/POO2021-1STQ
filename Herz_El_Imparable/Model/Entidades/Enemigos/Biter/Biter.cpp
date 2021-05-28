//
// Created by usuario on 23/05/2021.
//

#include "Biter.h"

Biter::Biter(){
    setImagen('b');
    setTipoEnemigo(BITER);
}

bool Biter::combate(Entidad* jugadorEntidad) {
    return false;
}

void Biter::atacar(int fila, int columna){

}

Biter::~Biter(){

}