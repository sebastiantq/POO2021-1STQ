//
// Created by usuario on 23/05/2021.
//

#include "Biter.h"
#include "../../Jugador/Jugador.h"

Biter::Biter(){
    setImagen('b');
    setTipoEnemigo(BITER);
    setPuntosVida(9);
    setPuntosVidaMaximos(9);
    setPuntosAtaque(5);
}

bool Biter::combate(Entidad* jugadorEntidad) {
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

void Biter::atacar(int fila, int columna){

}

Biter::~Biter(){

}