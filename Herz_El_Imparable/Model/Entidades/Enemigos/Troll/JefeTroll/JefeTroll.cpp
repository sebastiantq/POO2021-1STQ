//
// Created by usuario on 23/05/2021.
//

#include "JefeTroll.h"
#include "../../../Jugador/Jugador.h"

JefeTroll::JefeTroll(){
    setImagen('T');
    setTipoEnemigo(JEFE_TROLL);
    setPuntosVida(11);
    setPuntosVidaMaximos(11);
    setPuntosAtaque(4);
}

bool JefeTroll::combate(Entidad* jugadorEntidad) {
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

void JefeTroll::atacar(int fila, int columna){

}

JefeTroll::~JefeTroll(){

}