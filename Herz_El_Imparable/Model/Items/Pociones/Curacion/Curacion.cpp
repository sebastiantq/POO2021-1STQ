//
// Created by usuario on 21/05/2021.
//

#include "Curacion.h"
#include "../../../Entidades/Jugador/Jugador.h"

Curacion::Curacion(){
    setImagen('C');
    setTipo(POCION);
    setTipoPocion(CURACION);
    interactivo = true;
    checked = true;
}

// Restaura la vida al maximo
void Curacion::consumir(Espacio* jugadorEntidad){
    Jugador* jugador = (Jugador*)(jugadorEntidad);
    jugador->setPuntosVida(jugador->getPuntosVidaMaximos());

    cout << endl << "Tu vida ha sido restaurada al maximo" << endl;
}

bool Curacion::interaccion(){
    int opcion;

    do{
        cout << "Has encontrado una pocion de curacion, ¿deseas añadirla al inventario? (1. Si, 0. No): ";
        cin >> opcion;
    }while(opcion != 0 && opcion != 1);

    return opcion;
}

Curacion::~Curacion(){

}