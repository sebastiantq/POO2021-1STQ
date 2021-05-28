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

Mazmorra Controller::getMazmorra(){
    return mazmorra;
}

EstadoJuego Controller::getEstadoJuego(){
    return estadoJuego;
}

void Controller::interactuar(int fila, int columna){
    tuple<int, int>posicionJugador = mazmorra.getPosicionJugador(), posicionDisponibleInventario, posicionItem;
    Espacio*  espacioJugador = mazmorra.getEspacio(get<0>(posicionJugador), get<1>(posicionJugador));
    Jugador* jugador = (Jugador*)(espacioJugador); // Downcasting exitoso

    if(mazmorra.getEspacio(fila, columna)->getTipo() == ARMA || mazmorra.getEspacio(fila, columna)->getTipo() == POCION || mazmorra.getEspacio(fila, columna)->getTipo() == ARTEFACTO_LEGENDARIO){
        // Es un Item
        jugador->mostrarInventario();

        if(mazmorra.getEspacio(fila, columna)->interaccion()){
            posicionDisponibleInventario = jugador->getPosicionDisponibleInventario();
            if(get<0>(posicionDisponibleInventario) == 5 && get<1>(posicionDisponibleInventario) == 5){
                cout << "El inventario está lleno, debes eliminar algun item primero" << endl;
            }else{
                // Añade el item al inventario del jugador
                jugador->actualizarPosicionInventario(get<0>(posicionDisponibleInventario), get<1>(posicionDisponibleInventario), mazmorra.getEspacio(fila, columna));
                mazmorra.actualizarPosicionMazmorra(fila, columna, new Espacio());
            }
        }
    }else if(mazmorra.getEspacio(fila, columna)->getTipo() == ENEMIGO || mazmorra.getEspacio(fila, columna)->getTipo() == JEFE){
        // Es un Enemigo
        Enemigo* enemigoACombatir = (Enemigo*)(mazmorra.getEspacio(fila, columna)); // Downcasting para acceder a metodos de enemigo

        if(enemigoACombatir->combate(jugador)){
            // Inicia el combate
            jugador->actualizarPosicionInventario(get<1>(posicionDisponibleInventario), get<1>(posicionDisponibleInventario), mazmorra.getEspacio(fila, columna));
            mazmorra.actualizarPosicionMazmorra(fila, columna, new Espacio());
        }else{
            // Ha muerto Herz
            if(jugador->muerte(mazmorra.getDificultad())){
                setEstadoJuego(ESCOGIENDO_DIFICULTAD);
            }else{
                setEstadoJuego(MENU_PRINCIPAL);
            }
        }
    }
}

void Controller::teclaArriba() {
    tuple <int, int>posicion = mazmorra.getPosicionJugador(), posicionNueva(get<0>(posicion) + 1, get<1>(posicion));
    Jugador* jugador = (Jugador*)mazmorra.getEspacio(get<0>(posicion), get<1>(posicion));

    if(!mazmorra.getEspacio(get<0>(posicion) + 1, get<1>(posicion))->getInteractivo()){
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion) + 1, get<1>(posicion), jugador);
        mazmorra.getEspacio(get<0>(posicion) + 1, get<1>(posicion))->setPosicion(posicionNueva);
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion), new Espacio());
    }else{
        // Realiza una interaccion con el objeto
        interactuar(get<0>(posicion) + 1, get<1>(posicion));
    }
}

void Controller::teclaIzquierda() {
    tuple <int, int>posicion = mazmorra.getPosicionJugador(), posicionNueva(get<0>(posicion), get<1>(posicion) - 1);
    Jugador* jugador = (Jugador*)mazmorra.getEspacio(get<0>(posicion), get<1>(posicion));

    if(!mazmorra.getEspacio(get<0>(posicion), get<1>(posicion) - 1)->getInteractivo()){
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion) - 1, jugador);
        mazmorra.getEspacio(get<0>(posicion), get<1>(posicion) - 1)->setPosicion(posicionNueva);
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion), new Espacio());
    }else{
        // Realiza una interaccion con el objeto
        interactuar(get<0>(posicion), get<1>(posicion) - 1);
    }
}

void Controller::teclaDerecha() {
    tuple <int, int>posicion = mazmorra.getPosicionJugador(), posicionNueva(get<0>(posicion), get<1>(posicion) + 1);
    Jugador* jugador = (Jugador*)mazmorra.getEspacio(get<0>(posicion), get<1>(posicion));

    if(!mazmorra.getEspacio(get<0>(posicion), get<1>(posicion) + 1)->getInteractivo()){
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion) + 1, jugador);
        mazmorra.getEspacio(get<0>(posicion), get<1>(posicion) + 1)->setPosicion(posicionNueva);
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion), new Espacio());
    }else{
        // Realiza una interaccion con el objeto
        interactuar(get<0>(posicion), get<1>(posicion) + 1);
    }
}

void Controller::teclaAbajo() {
    tuple <int, int>posicion = mazmorra.getPosicionJugador(), posicionNueva(get<0>(posicion) - 1, get<1>(posicion));
    Jugador* jugador = (Jugador*)mazmorra.getEspacio(get<0>(posicion), get<1>(posicion));

    if(!mazmorra.getEspacio(get<0>(posicion) - 1, get<1>(posicion))->getInteractivo()){
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion) - 1, get<1>(posicion), jugador);
        mazmorra.getEspacio(get<0>(posicion) - 1, get<1>(posicion))->setPosicion(posicionNueva);
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion), new Espacio());
    }else{
        // Realiza una interaccion con el objeto
        interactuar(get<0>(posicion) - 1, get<1>(posicion));
    }
}