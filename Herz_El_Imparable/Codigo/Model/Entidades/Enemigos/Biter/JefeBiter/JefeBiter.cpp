//
// Created by usuario on 23/05/2021.
//

#include "JefeBiter.h"
#include "../../../Jugador/Jugador.h"

JefeBiter::JefeBiter(){
    setImagen('B');
    setTipo(JEFE);
    setTipoEnemigo(JEFE_BITER);
    setPuntosVida(15);
    setPuntosVidaMaximos(15);
    setPuntosAtaque(5);
}

bool JefeBiter::combate(Entidad* jugadorEntidad) {
    int ataque;
    Jugador* jugador = (Jugador*)(jugadorEntidad);
    Arma* armaHerz = (Arma*)(jugador->getArmaEquipada());

    // Se realiza el combate hasta que uno de los dos pierda la vida
    while (jugador->getPuntosVida() > 0 && getPuntosVida() > 0){
        cout << endl << "Turno de Herz" << endl;

        cout << endl << "Vida de Herz: " << jugador->getPuntosVida() << endl;

        jugador->desplegarMenuAtaque();

        if(jugador->getArmaEquipada()->getTipo() != ARMA){
            // Herz ataca con su mano
            setPuntosVida(getPuntosVida() - jugador->getPuntosAtaque());

            cout << endl << "Herz ataca con su mano y hace un total de " << jugador->getPuntosAtaque() << " puntos de dano" << endl;
        }else{
            // Herz ataca y le disminuye en n puntos la vida del enemigo dependiendo de los puntos de ataque del arma
            setPuntosVida(getPuntosVida() - armaHerz->getDano());

            cout << endl << "Herz ataca y hace un total de " << jugador->getPuntosAtaque() << " puntos de dano" << endl;
        }

        if(getPuntosVida() > 0){
            ataque = 1 + rand() % 2;

            cout << endl << "Turno de la jefe Biter" << endl;

            cout << endl << "Vida de la jefe Biter: " << getPuntosVida() << endl << endl;

            if(ataque == 1){
                jugador->setPuntosVida(jugador->getPuntosVida() - ataqueUno());
            }else{
                jugador->setPuntosVida(jugador->getPuntosVida() - ataqueDos());
            }
        }
    }

    if(getPuntosVida() <= 0){
        return true;
    }else if(jugador->getPuntosVida() <= 0){
        return false;
    }
}

int JefeBiter::ataqueUno(){
    int dano = getPuntosAtaque() + (rand() % 2);

    cout << "La jefe Biter te ha metido un mordisco en un brazo, te ha quitado un total de " << dano << " puntos de vida" << endl;
    return dano;
}

int JefeBiter::ataqueDos(){
    cout << "La jefe Biter te ha lanzado veneno, te ha quitado un total de " << getPuntosAtaque() << " puntos de vida" << endl;
    return getPuntosAtaque();
}

JefeBiter::~JefeBiter(){

}