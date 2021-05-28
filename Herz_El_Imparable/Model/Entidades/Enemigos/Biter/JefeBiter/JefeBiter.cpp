//
// Created by usuario on 23/05/2021.
//

#include "JefeBiter.h"

JefeBiter::JefeBiter(){
    setImagen('B');
    setTipoEnemigo(JEFE_BITER);
}

bool JefeBiter::combate(Entidad* jugadorEntidad) {
    return false;
}

void JefeBiter::atacar(int fila, int columna){

}

JefeBiter::~JefeBiter(){

}