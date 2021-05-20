//
// Created by usuario on 17/05/2021.
//

#include "Controller.h"

Controller::Controller() {
    mazmorra = Mazmorra();
    estadoJuego = MENU_PRINCIPAL;
}

void Controller::inicializarMazmorra(Dificultades dificultad){
    if(dificultad != FACIL && dificultad != NORMAL){
        throw std::domain_error("La dificultad seleccionada es incorrecta\n");
    }else{
        mazmorra.inicializarMazmorra(dificultad);
        setEstadoJuego(JUGANDO);
    }

    cout << endl;
}

void Controller::mostrarMazmorra(int desdeFila){
    int tamanoMaximo;

    if(mazmorra.getDificultad() == FACIL){
        tamanoMaximo = 10;
    }else{
        tamanoMaximo = 15;
    }

    if(desdeFila >= 0 && desdeFila < tamanoMaximo){
        mazmorra.mostrarMazmorra(desdeFila);
    }else{
        throw std::domain_error("Lo sentimos, ha habido un error, debemos reiniciar");
    }
}

void Controller::setEstadoJuego(EstadoJuego nuevoEstadoJuego){
    estadoJuego = nuevoEstadoJuego;
}

EstadoJuego Controller::getEstadoJuego(){
    return estadoJuego;
}

void Controller::teclaArriba() {
    tuple <int, int>posicion = mazmorra.getPosicionJugador(), posicionNueva(get<0>(posicion) + 1, get<1>(posicion));

    if(mazmorra.getEspacio(get<0>(posicion) + 1, get<1>(posicion))->getInteractivo()){
        cout << "1" << endl;
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion), Espacio());
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion) + 1, get<1>(posicion), Jugador());
        mazmorra.getEspacio(get<0>(posicion) + 1, get<1>(posicion))->setPosicion(posicionNueva);
    }else{
        // Realiza una interaccion con el objeto
        cout << "2" << endl;
        return;
    }
}

void Controller::teclaIzquierda() {
    tuple <int, int>posicion = mazmorra.getPosicionJugador(), posicionNueva(get<0>(posicion), get<1>(posicion) - 1);

    if(mazmorra.getEspacio(get<0>(posicion), get<1>(posicion) - 1)->getInteractivo()){
        cout << "1" << endl;
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion), Espacio());
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion) - 1, Jugador());
        mazmorra.getEspacio(get<0>(posicion), get<1>(posicion) - 1)->setPosicion(posicionNueva);
    }else{
        // Realiza una interaccion con el objeto
        cout << "2" << endl;
        return;
    }
}

void Controller::teclaDerecha() {
    tuple <int, int>posicion = mazmorra.getPosicionJugador(), posicionNueva(get<0>(posicion), get<1>(posicion) + 1);

    if(mazmorra.getEspacio(get<0>(posicion), get<1>(posicion) + 1)->getInteractivo()){
        cout << "1" << endl;
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion), Espacio());
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion) + 1, Jugador());
        mazmorra.getEspacio(get<0>(posicion), get<1>(posicion) + 1)->setPosicion(posicionNueva);
    }else{
        // Realiza una interaccion con el objeto
        cout << "2" << endl;
        return;
    }
}

void Controller::teclaAbajo() {
    tuple <int, int>posicion = mazmorra.getPosicionJugador(), posicionNueva(get<0>(posicion) - 1, get<1>(posicion));

    if(mazmorra.getEspacio(get<0>(posicion) - 1, get<1>(posicion))->getInteractivo()){
        cout << "1" << endl;
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion), Espacio());
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion) - 1, get<1>(posicion), Jugador());
        mazmorra.getEspacio(get<0>(posicion) - 1, get<1>(posicion))->setPosicion(posicionNueva);
    }else{
        // Realiza una interaccion con el objeto
        cout << "2" << endl;
        return;
    }
}