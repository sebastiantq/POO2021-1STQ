//
// Created by usuario on 23/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_JEFETROLL_H
#define HERZ_EL_IMPARABLE_JEFETROLL_H

#include "../Troll.h"

class JefeTroll : public Troll{
    private:
    public:
        JefeTroll();
        bool combate(Entidad* jugadorEntidad) override;
        int ataqueUno() override;
        int ataqueDos() override;
        ~JefeTroll();
};


#endif //HERZ_EL_IMPARABLE_JEFETROLL_H
