//
// Created by usuario on 17/05/2021.
//

#include "Jugador.h"

Jugador::Jugador(){
    setImagen('O');
    setTipo(JUGADOR);
    interactivo = false;
    checked = false;
    inicializarInventario();
}

void Jugador::inicializarInventario(){
    for (int fila = 0; fila < 2; fila++) {
        for (int columna = 0; columna < 5; columna++) {
            actualizarPosicionInventario(fila, columna, Espacio());
        }
    }
}

void Jugador::atacar(int fila, int columna){

}

void Jugador::mostrarInventario(){
    cout << endl << "-- Inventario --" << endl << endl;

    for (int fila = 0; fila < 2; fila++) {
        for (int columna = 0; columna < 5; columna++) {
            cout << "|"  << inventario[fila][columna].getImagen() << "|";
        }

        cout << endl;
    }
}

tuple<int, int> Jugador::getPosicionDisponibleInventario(){
    tuple<int, int>posicionDisponible;

    for (int fila = 0; fila < 2; fila++) {
        for (int columna = 0; columna < 5; columna++) {
            cout << " 1 ";
            if(!inventario[fila][columna].getChecked()){
                get<0>(posicionDisponible) = fila;
                get<1>(posicionDisponible) = columna;
                cout << "Es verdad, es verdad, estamos bien cachon3" << endl;
                return posicionDisponible;
            }
        }
    }

    // No encontró ningun lugar disponible
    get<0>(posicionDisponible) = 5;
    get<1>(posicionDisponible) = 5;
    return posicionDisponible;
}

void Jugador::actualizarPosicionInventario(int fila, int columna, Espacio nuevoItem){
    inventario[fila][columna] = nuevoItem;
}

Jugador::~Jugador(){

}