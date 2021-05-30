//
// Created by usuario on 23/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_HAUNTEDWATER_H
#define HERZ_EL_IMPARABLE_HAUNTEDWATER_H

#include "../Enemigo.h"

class HauntedWater : public Enemigo {
    private:
    public:
        HauntedWater();
        bool combate(Entidad* jugadorEntidad) override;
        int ataqueUno() override;
        int ataqueDos() override;
        ~HauntedWater();
};


#endif //HERZ_EL_IMPARABLE_HAUNTEDWATER_H
