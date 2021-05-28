//
// Created by usuario on 21/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_FUERZA_H
#define HERZ_EL_IMPARABLE_FUERZA_H

#include "../Pocion.h"

class Fuerza : public Pocion{
    private:
    public:
        Fuerza();
        void consumir(Espacio* jugador) override;
        virtual bool interaccion() override;
        ~Fuerza();
};


#endif //HERZ_EL_IMPARABLE_FUERZA_H
