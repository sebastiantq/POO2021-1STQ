//
// Created by usuario on 17/05/2021.
//

#include "Espacio.h"

Espacio::Espacio() {
    tipo = ESPACIO;
    interactivo = false;
    checked = false;
    imagen = ' ';
}

bool Espacio::interaccion(){
    cout << endl << "Interaccion con objeto Espacio" << endl;
    return false;
}

void Espacio::setPosicion(tuple <int, int> nuevaPosicion){
    posicion = nuevaPosicion;
}

void Espacio::setTipo(Tipo nuevoTipo){
    tipo = nuevoTipo;
}

void Espacio::setChecked(bool valor){
    checked = valor;
}

void Espacio::setImagen(char nuevaImagen){
    imagen = nuevaImagen;
}

bool Espacio::getChecked(){
    return checked;
}

tuple<int, int> Espacio::getPosicion(){
    return posicion;
}

Tipo Espacio::getTipo(){
    return tipo;
}

char Espacio::getImagen(){
    return imagen;
}

bool Espacio::getInteractivo(){
    return interactivo;
}

Espacio::~Espacio(){

}