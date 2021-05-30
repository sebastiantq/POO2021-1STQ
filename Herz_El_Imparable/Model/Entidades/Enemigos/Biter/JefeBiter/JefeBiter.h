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
        bool combate(Entidad* jugadorEntidad) override;
        int ataqueUno() override;
        int ataqueDos() override;
        ~JefeBiter();
};


#endif //HERZ_EL_IMPARABLE_JEFEBITER_H
