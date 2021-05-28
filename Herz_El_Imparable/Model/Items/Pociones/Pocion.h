//
// Created by usuario on 17/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_POCION_H
#define HERZ_EL_IMPARABLE_POCION_H

#include "../Item.h"

enum TipoPocion {FUERZA, CURACION};

class Pocion: public Item {
    private:
        TipoPocion tipoPocion;
    public:
        Pocion();
        virtual void consumir(Espacio* jugador) = 0;
        void setTipoPocion(TipoPocion nuevoTipoPocion);
        TipoPocion getTipoPocion();
        ~Pocion();
};


#endif //HERZ_EL_IMPARABLE_POCION_H
