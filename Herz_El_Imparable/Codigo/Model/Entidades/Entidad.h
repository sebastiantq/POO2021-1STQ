//
// Created by usuario on 20/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_ENTIDAD_H
#define HERZ_EL_IMPARABLE_ENTIDAD_H

#include "../Espacio.h"
#include "../Items/Item.h"

class Entidad: public Espacio {
    private:
        int puntosVida;
        int puntosVidaMaximos;
        int puntosAtaque;
    public:
        Entidad();
        int getPuntosVida();
        int getPuntosVidaMaximos();
        int getPuntosAtaque();
        void setPuntosVida(int nuevosPuntosDeVida);
        void setPuntosVidaMaximos(int nuevosPuntosDeVidaMaximos);
        void setPuntosAtaque(int nuevoPuntosAtaque);
};


#endif //HERZ_EL_IMPARABLE_ENTIDAD_H
