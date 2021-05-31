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

        if(getPuntosVida() > 0) {
            ataque = 1 + rand() % 2;

            cout << endl << "Turno de la Haunted Water" << endl;

            cout << endl << "Vida de la Haunted Water: " << getPuntosVida() << endl << endl;

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

int HauntedWater::ataqueUno(){
    int dano = getPuntosAtaque() + (rand() % 2);

    cout << "Has tragado algo de la jefe Haunted Water, no queremos saber que es, te ha quitado un total de " << dano << " puntos de vida" << endl;
    return dano;
}

int HauntedWater::ataqueDos(){
    cout << "Que maleducada, la Haunted Water te ha escupido un poco mientras hablaba, te ha quitado un total de " << getPuntosAtaque() << " puntos de vida" << endl;
    return getPuntosAtaque();
}

HauntedWater::~HauntedWater(){

}