//
// Created by usuario on 17/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_ARMA_H
#define HERZ_EL_IMPARABLE_ARMA_H

#include "../Item.h"

enum TipoArma {HACHA, ESPADA};

class Arma: public Item {
private:
    TipoArma tipoArma;
    float dano, resistencia;
public:
    Arma();
    void setTipoArma(TipoArma nuevoTipoArma);
    float getDano();
    float getResistencia();
    ~Arma();
};


#endif //HERZ_EL_IMPARABLE_ARMA_H
