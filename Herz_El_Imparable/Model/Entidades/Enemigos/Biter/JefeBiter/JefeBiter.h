//
// Created by usuario on 23/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_JEFEBITER_H
#define HERZ_EL_IMPARABLE_JEFEBITER_H

#include "../Biter.h"

class JefeBiter : public Biter{
    private:
    public:
        JefeBiter();
        virtual bool interaccion() override;
        virtual void atacar(int fila, int columna) override;
        ~JefeBiter();
};


#endif //HERZ_EL_IMPARABLE_JEFEBITER_H
