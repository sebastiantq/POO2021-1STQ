//
// Created by usuario on 23/05/2021.
//

#include "JefeHauntedWater.h"
#include "../../../Jugador/Jugador.h"

JefeHauntedWater::JefeHauntedWater(){
    setImagen('W');
    setTipoEnemigo(JEFE_HAUNTED_WATER);
    setPuntosVida(13);
    setPuntosVidaMaximos(13);
    setPuntosAtaque(4);
}

bool JefeHauntedWater::combate(Entidad* jugadorEntidad){
    Jugador* jugador = (Jugador*)(jugadorEntidad);

    while (jugador->getPuntosVida() > 0 && getPuntosVida() > 0){
        // Se realiza el combate hasta que uno de los dos pierda la vida
    }

    if(getPuntosVida() <= 0){
        return true;
    }else if(jugador->getPuntosVida() <= 0){
        return false;
    }
}

void JefeHauntedWater::atacar(int fila, int columna){

}

JefeHauntedWater::~JefeHauntedWater(){

}