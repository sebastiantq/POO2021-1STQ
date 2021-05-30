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

            cout << endl << "Turno del jefe Troll" << endl;

            cout << endl << "Vida del jefe Troll: " << getPuntosVida() << endl << endl;

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

int JefeTroll::ataqueUno(){
    int dano = getPuntosAtaque() + (rand() % 2), chiste = rand() + 2;

    cout << "El jefe Troll despliega todo su arsenal: " << endl << endl;

    if(chiste == 0){
        cout << "   — Niño, sal del coche y mira si funciona el intermitente" << endl;
        cout << "   — Ahora sí, ahora no, ahora sí, ahora no, ahora sí, ahora no…" << endl << endl;
    }else if(chiste == 1){
        cout << "   — ¿Qué le dice la foca a su madre?" << endl;
        cout << "   — I love you, mother foca." << endl << endl;
    }else{
        cout << "   El otro día tu mujer me contó un chiste tan bueno que de la risa me caí de la cama." << endl;
        // Es tan brutal que se merece aumentar 1 punto de daño
        dano++;
    }

    cout << "Te ha quitado un total de " << dano << " puntos de vida" << endl;

    return dano;
}

int JefeTroll::ataqueDos(){
    cout << "El jefe Troll te ha metido un porrazo que te dejado andando para atras, te ha quitado " << getPuntosAtaque() << " puntos de vida" << endl;
    return getPuntosAtaque();
}

JefeTroll::~JefeTroll(){

}