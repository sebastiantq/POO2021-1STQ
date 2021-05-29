//
// Created by usuario on 21/05/2021.
//

#include "Fuerza.h"
#include "../../../Entidades/Jugador/Jugador.h"

Fuerza::Fuerza(){
    setImagen('F');
    setTipo(POCION);
    setTipoPocion(FUERZA);
    interactivo = true;
    checked = true;
}

// Otorga el doble de puntos de ataque
void Fuerza::consumir(Espacio* jugadorEntidad){
    Jugador* jugador = (Jugador*)(jugadorEntidad);
    jugador->setPuntosAtaque(jugador->getPuntosAtaque() * 2);

    cout << endl << "Tu ataque se ha duplicado, hazlos trizas" << endl;
}

bool Fuerza::interaccion(){
    int opcion;

    do{
        cout << "Has encontrado una pocion de fuerza, ¿deseas añadirla al inventario? (1. Si, 0. No): ";
        cin >> opcion;
    }while(opcion != 0 && opcion != 1);

    return opcion;
}

Fuerza::~Fuerza(){

}