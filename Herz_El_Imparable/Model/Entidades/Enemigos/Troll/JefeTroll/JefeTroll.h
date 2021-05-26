//
// Created by usuario on 23/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_JEFETROLL_H
#define HERZ_EL_IMPARABLE_JEFETROLL_H

#include "../Troll.h"

class JefeTroll : public Troll{
    public:
    private:
        JefeTroll();
        virtual bool interaccion() override;
        virtual void atacar(int fila, int columna) override;
        ~JefeTroll();
};


#endif //HERZ_EL_IMPARABLE_JEFETROLL_H
