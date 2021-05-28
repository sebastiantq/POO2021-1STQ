//
// Created by usuario on 23/05/2021.
//

#include "JefeHauntedWater.h"

JefeHauntedWater::JefeHauntedWater(){
    setImagen('W');
    setTipoEnemigo(JEFE_HAUNTED_WATER);
}

bool JefeHauntedWater::combate(Entidad* jugadorEntidad){
    return false;
}

void JefeHauntedWater::atacar(int fila, int columna){

}

JefeHauntedWater::~JefeHauntedWater(){

}