//
// Created by usuario on 17/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_JUGADOR_H
#define HERZ_EL_IMPARABLE_JUGADOR_H

#include "../Entidad.h"
#include "../../Items/Pociones/Pocion.h"
#include "../../Items/Armas/Arma.h"

class Jugador: public Entidad {
    private:
        Espacio* inventario[2][5];
        Espacio* armaEquipada;
        void inicializarInventario();
    public:
        Jugador();
        void mostrarInventario();
        void menuInventario(int opcion);
        void actualizarPosicionInventario(int fila, int columna, Espacio* nuevoItem);
        bool muerte(bool dificultadNormal);
        void desplegarMenuInventario();
        void desplegarMenuAtaque();
        void setArmaEquipada(Espacio* nuevaArmaEquipada);
        Espacio* getArmaEquipada();
        Espacio* getItemInventario(int fila, int columna);
        tuple<int, int> getPosicionDisponibleInventario();
        ~Jugador();
};


#endif //HERZ_EL_IMPARABLE_JUGADOR_H
