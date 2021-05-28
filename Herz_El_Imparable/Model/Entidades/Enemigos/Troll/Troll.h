//
// Created by usuario on 23/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_TROLL_H
#define HERZ_EL_IMPARABLE_TROLL_H

#include "../Enemigo.h"

class Troll : public Enemigo {
    private:
    public:
        Troll();
        virtual bool combate(Entidad* jugadorEntidad) override;
        virtual void atacar(int fila, int columna) override;
        ~Troll();
};


#endif //HERZ_EL_IMPARABLE_TROLL_H
