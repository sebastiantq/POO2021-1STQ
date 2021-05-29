//
// Created by usuario on 23/05/2021.
//

#include "HauntedWater.h"
#include "../../Jugador/Jugador.h"

HauntedWater::HauntedWater(){
    setImagen('w');
    setTipoEnemigo(HAUNTED_WATER);
    setPuntosVida(6);
    setPuntosVidaMaximos(6);
    setPuntosAtaque(2);
}

bool HauntedWater::combate(Entidad* jugadorEntidad) {
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

void HauntedWater::atacar(int fila, int columna){

}

HauntedWater::~HauntedWater(){

}