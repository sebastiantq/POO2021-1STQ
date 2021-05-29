//
// Created by usuario on 17/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_ARMA_H
#define HERZ_EL_IMPARABLE_ARMA_H

#include "../Item.h"

enum TipoArma {HACHA, ESPADA, POCION_DANO};

class Arma: public Item {
    protected:
        TipoArma tipoArma;
        int dano, resistencia;
    public:
        Arma();
        void setTipoArma(TipoArma nuevoTipoArma);
        int getDano();
        int getResistencia();
        ~Arma();
};


#endif //HERZ_EL_IMPARABLE_ARMA_H
