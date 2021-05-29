//
// Created by usuario on 23/05/2021.
//

#include "Troll.h"
#include "../../Jugador/Jugador.h"

Troll::Troll(){
    setImagen('t');
    setTipoEnemigo(TROLL);
    setPuntosVida(8);
    setPuntosVidaMaximos(8);
    setPuntosAtaque(3);
}

bool Troll::combate(Entidad* jugadorEntidad) {
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

void Troll::atacar(int fila, int columna){

}

Troll::~Troll(){

}