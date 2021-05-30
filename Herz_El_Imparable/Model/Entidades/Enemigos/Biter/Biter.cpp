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

            cout << endl << "Turno de la mordelona" << endl;

            cout << endl << "Vida de la Biter: " << getPuntosVida() << endl << endl;

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

int Biter::ataqueUno(){
    int dano = getPuntosAtaque() + (rand() % 2);

    cout << "La Biter te ha chuzado con un colmillo, te ha quitado un total de " << dano << " puntos de vida" << endl;
    return dano;
}

int Biter::ataqueDos(){
    cout << "La Biter te ha mostrado tus colmillos, te has asustado y te has golpeado con una roca, te ha quitado un total de " << getPuntosAtaque() << " puntos de vida" << endl;
    return getPuntosAtaque();
}

Biter::~Biter(){

}