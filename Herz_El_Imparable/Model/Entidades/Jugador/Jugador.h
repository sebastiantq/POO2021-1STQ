//
// Created by usuario on 17/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_JUGADOR_H
#define HERZ_EL_IMPARABLE_JUGADOR_H

#include "../Entidad.h"

class Jugador: public Entidad {
    private:
        Espacio inventario[2][5];
        void inicializarInventario();
    public:
        Jugador();
        virtual void atacar(int fila, int columna) override;
        void mostrarInventario();
        tuple<int, int> getPosicionDisponibleInventario();
        void actualizarPosicionInventario(int fila, int columna, Espacio nuevoItem);
        ~Jugador();
};


#endif //HERZ_EL_IMPARABLE_JUGADOR_H
