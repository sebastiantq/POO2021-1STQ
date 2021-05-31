//
// Created by usuario on 28/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_POCIONDANO_H
#define HERZ_EL_IMPARABLE_POCIONDANO_H

#include "../Arma.h"

class PocionDano : public Arma {
    private:
    public:
        PocionDano();
        bool interaccion() override;
        ~PocionDano();
};


#endif //HERZ_EL_IMPARABLE_POCIONDANO_H
