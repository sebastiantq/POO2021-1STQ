//
// Created by usuario on 17/05/2021.
//

#include "Jugador.h"

Jugador::Jugador(){
    setImagen('O');
    setTipo(JUGADOR);
    interactivo = false;
    checked = false;
}

Jugador::~Jugador(){

}