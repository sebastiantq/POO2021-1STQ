//
// Created by usuario on 23/05/2021.
//

#include "JefeBiter.h"
#include "../../../Jugador/Jugador.h"

JefeBiter::JefeBiter(){
    setImagen('B');
    setTipoEnemigo(JEFE_BITER);
    setPuntosVida(15);
    setPuntosVidaMaximos(15);
    setPuntosAtaque(5);
}

bool JefeBiter::combate(Entidad* jugadorEntidad) {
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

void JefeBiter::atacar(int fila, int columna){

}

JefeBiter::~JefeBiter(){

}