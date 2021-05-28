//
// Created by usuario on 21/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_CURACION_H
#define HERZ_EL_IMPARABLE_CURACION_H

#include "../Pocion.h"

class Curacion : public Pocion{
    private:
    public:
        Curacion();
        void consumir(Espacio* jugador) override;
        virtual bool interaccion() override;
        ~Curacion();
};


#endif //HERZ_EL_IMPARABLE_CURACION_H
