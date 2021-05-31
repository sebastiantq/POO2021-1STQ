//
// Created by usuario on 17/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_ENEMIGO_H
#define HERZ_EL_IMPARABLE_ENEMIGO_H

#include "../Entidad.h"

enum TipoEnemigo {TROLL, HAUNTED_WATER, BITER, JEFE_TROLL, JEFE_HAUNTED_WATER, JEFE_BITER};

class Enemigo: public Entidad {
    private:
        TipoEnemigo tipoEnemigo;
    public:
        Enemigo();
        virtual bool combate(Entidad* jugadorEntidad) = 0;
        virtual int ataqueUno() = 0;
        virtual int ataqueDos() = 0;
        void setTipoEnemigo(TipoEnemigo nuevoTipoEnemigo);
        TipoEnemigo getTipoEnemigo();
        ~Enemigo();
};


#endif //HERZ_EL_IMPARABLE_ENEMIGO_H
