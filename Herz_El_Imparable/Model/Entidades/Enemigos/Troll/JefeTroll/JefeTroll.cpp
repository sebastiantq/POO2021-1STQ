//
// Created by usuario on 23/05/2021.
//

#include "JefeTroll.h"

JefeTroll::JefeTroll(){
    setImagen('T');
    setTipoEnemigo(JEFE_TROLL);
}

bool JefeTroll::combate(Entidad* jugadorEntidad) {
    return false;
}

void JefeTroll::atacar(int fila, int columna){

}

JefeTroll::~JefeTroll(){

}