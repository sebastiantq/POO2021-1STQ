//
// Created by usuario on 17/05/2021.
//

#include "Pocion.h"

Pocion::Pocion(){

}

void Pocion::consumir(){

}

bool Pocion::interaccion(){
    cout << endl << "Interaccion con pocion" << endl;
    return false;
}

void Pocion::setTipoPocion(TipoPocion nuevoTipoPocion){
    tipoPocion = nuevoTipoPocion;
}

TipoPocion Pocion::getTipoPocion(){
    return tipoPocion;
}

Pocion::~Pocion(){

}