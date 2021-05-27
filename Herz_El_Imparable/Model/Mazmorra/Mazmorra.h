//
// Created by usuario on 17/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_MAZMORRA_H
#define HERZ_EL_IMPARABLE_MAZMORRA_H

#define TAMANO 15

#include "../Espacio.h"
#include "Pared.h"
#include "../Entidades/Enemigos/Enemigo.h"
#include "../Entidades/Enemigos/Biter/Biter.h"
#include "../Entidades/Enemigos/HauntedWater/HauntedWater.h"
#include "../Entidades/Enemigos/Troll/Troll.h"
#include "../Items/Item.h"
#include "../Items/Armas/Hacha/Hacha.h"
#include "../Items/Armas/Espada/Espada.h"
#include "../Items/Pociones/Curacion/Curacion.h"
#include "../Items/Pociones/Fuerza/Fuerza.h"
#include "../Entidades/Jugador/Jugador.h"

enum Dificultades {FACIL, NORMAL};

class Mazmorra {
    private:
        Espacio* mazmorra[TAMANO][TAMANO];
        Dificultades dificultad;
        void algoritmoDeRelleno(int tamanoMaximo);
        void algoritmoDePosicionamientoDeEntidades(Dificultades dificultadMazmorra);
        void algoritmoDePosicionamientoDeItems(Dificultades dificultadMazmorra);
        void limpiarMazmorra();
    public:
        Mazmorra();
        void inicializarMazmorra(Dificultades dificultadMazmorra);
        void actualizarPosicionMazmorra(int fila, int columna, Espacio* tipoEspacio);
        void mostrarMazmorra(int desdeFila);
        Espacio* getEspacio(int fila, int columna);
        Dificultades getDificultad();
        tuple<int, int> getPosicionJugador();
        void setDificultad(Dificultades nuevaDificultad);
};


#endif //HERZ_EL_IMPARABLE_MAZMORRA_H
