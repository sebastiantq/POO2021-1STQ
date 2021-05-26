//
// Created by usuario on 17/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_CONTROLLER_H
#define HERZ_EL_IMPARABLE_CONTROLLER_H

#include "../Model/Mazmorra/Mazmorra.h"
#include <cstdio>
#include <conio.h>

enum EstadoJuego {MENU_PRINCIPAL, JUGANDO, PAUSA};

class Controller {
    private:
        Mazmorra mazmorra;
        EstadoJuego estadoJuego;
    public:
        Controller();
        void inicializarMazmorra(Dificultades dificultad);
        void mostrarMazmorra(int desdeFila);
        void teclaArriba();
        void teclaIzquierda();
        void teclaDerecha();
        void teclaAbajo();
        void interactuar(int fila, int columna);
        void setEstadoJuego(EstadoJuego nuevoEstadoJuego);
        EstadoJuego getEstadoJuego();
};


#endif //HERZ_EL_IMPARABLE_CONTROLLER_H
