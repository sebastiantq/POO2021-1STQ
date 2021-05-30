//
// Created by usuario on 23/05/2021.
//

#include "Troll.h"
#include "../../Jugador/Jugador.h"
#include "../../../Items/Armas/Arma.h"

Troll::Troll(){
    setImagen('t');
    setTipoEnemigo(TROLL);
    setPuntosVida(8);
    setPuntosVidaMaximos(8);
    setPuntosAtaque(3);
}

bool Troll::combate(Entidad* jugadorEntidad) {
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

            cout << endl << "Turno del payaso este" << endl;

            cout << endl << "Vida del troll: " << getPuntosVida() << endl << endl;

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

int Troll::ataqueUno(){
    int dano = getPuntosAtaque() + (rand() % 2), chiste = rand() + 1;

    cout << "El Troll despliega todo su arsenal: " << endl << endl;

    if(chiste == 0){
        cout << "   — A las 10 te pito y bajas." << endl;
        cout << "   — ¿Te has comprado un coche?" << endl;
        cout << "   — No, un pito." << endl << endl;
    }else{
        cout << "   ¿Qué hay peor que encontrarse un gusano en una manzana?." << endl;
        cout << "   Encontrarse medio." << endl << endl;
    }

    cout << "Te ha quitado un total de " << dano << " puntos de vida" << endl;

    return dano;
}

int Troll::ataqueDos(){
    cout << "El Troll te esta haciendo ojitos... Oh no, estaba solo parpadeando, que pena, te ha quitado " << getPuntosAtaque() << " puntos de vida" << endl;
    return getPuntosAtaque();
}

Troll::~Troll(){

}