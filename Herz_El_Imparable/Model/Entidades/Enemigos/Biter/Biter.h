//
// Created by usuario on 23/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_BITER_H
#define HERZ_EL_IMPARABLE_BITER_H

#include "../Enemigo.h"

class Biter : public Enemigo {
    private:
    public:
        Biter();
        virtual bool interaccion() override;
        virtual void atacar(int fila, int columna) override;
        ~Biter();
};


#endif //HERZ_EL_IMPARABLE_BITER_H
