//
// Created by usuario on 17/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_MAZMORRA_H
#define HERZ_EL_IMPARABLE_MAZMORRA_H

#include "Espacio.h"
#include "Pared.h"
#include "Enemigo.h"
#include "Item.h"
#include "Jugador.h"

enum Dificultades {FACIL, NORMAL};

class Mazmorra {
    private:
        Espacio mazmorra[15][15];
        Dificultades dificultad;
        void algoritmoDeRelleno(int tamanoMaximo);
        void limpiarMazmorra();
    public:
        Mazmorra();
        void inicializarMazmorra(Dificultades dificultadMazmorra);
        void actualizarPosicionMazmorra(int fila, int columna, Espacio tipoEspacio);
        void mostrarMazmorra(int desdeFila);
        bool todoCheckeado();
        Espacio* getEspacio(int fila, int columna);
        Dificultades getDificultad();
        tuple<int, int> getPosicionJugador();
        void setDificultad(Dificultades nuevaDificultad);
};


#endif //HERZ_EL_IMPARABLE_MAZMORRA_H
