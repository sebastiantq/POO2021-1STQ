//
// Created by usuario on 20/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_HACHA_H
#define HERZ_EL_IMPARABLE_HACHA_H

#include "../Arma.h"

class Hacha : public Arma {
    private:
    public:
        Hacha();
        virtual bool interaccion() override;
        ~Hacha();
};


#endif //HERZ_EL_IMPARABLE_HACHA_H
