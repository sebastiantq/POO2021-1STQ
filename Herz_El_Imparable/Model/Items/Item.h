//
// Created by usuario on 17/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_ITEM_H
#define HERZ_EL_IMPARABLE_ITEM_H

#include "../Espacio.h"

class Item : public Espacio {
    private:
    public:
        Item();
        virtual bool interaccion() override;
        ~Item();
};


#endif //HERZ_EL_IMPARABLE_ITEM_H
