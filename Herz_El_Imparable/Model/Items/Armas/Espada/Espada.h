//
// Created by usuario on 20/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_ESPADA_H
#define HERZ_EL_IMPARABLE_ESPADA_H

#include "../Arma.h"

class Espada : public Arma{
    private:
    public:
        Espada();
        void interaccion() override;
        ~Espada();
};


#endif //HERZ_EL_IMPARABLE_ESPADA_H
