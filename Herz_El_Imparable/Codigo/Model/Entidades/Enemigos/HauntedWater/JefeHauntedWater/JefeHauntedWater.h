//
// Created by usuario on 23/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_JEFEHAUNTEDWATER_H
#define HERZ_EL_IMPARABLE_JEFEHAUNTEDWATER_H

#include "../HauntedWater.h"

class JefeHauntedWater : public HauntedWater{
    private:
    public:
        JefeHauntedWater();
        bool combate(Entidad* jugadorEntidad) override;
        int ataqueUno() override;
        int ataqueDos() override;
        ~JefeHauntedWater();
};


#endif //HERZ_EL_IMPARABLE_JEFEHAUNTEDWATER_H
