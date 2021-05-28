//
// Created by usuario on 23/05/2021.
//

#include "HauntedWater.h"

HauntedWater::HauntedWater(){
    setImagen('w');
    setTipoEnemigo(HAUNTED_WATER);
}

bool HauntedWater::combate(Entidad* jugador) {
    return false;
}

void HauntedWater::atacar(int fila, int columna){

}

HauntedWater::~HauntedWater(){

}