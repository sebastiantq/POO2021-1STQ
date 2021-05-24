//
// Created by usuario on 17/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_ENEMIGO_H
#define HERZ_EL_IMPARABLE_ENEMIGO_H

#include "../Entidad.h"

enum TipoEnemigo {TROLL, HAUNTED_WATER, BITER};

class Enemigo: public Entidad {
    private:
        TipoEnemigo tipoEnemigo;
    public:
        Enemigo();
        void setTipoEnemigo(TipoEnemigo nuevoTipoEnemigo);
        ~Enemigo();
};


#endif //HERZ_EL_IMPARABLE_ENEMIGO_H
