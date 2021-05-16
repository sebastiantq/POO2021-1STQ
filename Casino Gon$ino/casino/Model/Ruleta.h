//
// Created by lufe0 on 8/05/2021.
//

#ifndef CASINO_RULETA_H
#define CASINO_RULETA_H

#include "Juego.h"
#include<cstdlib>
#include<ctime>


class Ruleta:public Juego {

protected:
    float calcularResultado(float gonzosApostar) override;

public:
    float jugar(float gonzosApostar) override;
    virtual ~Ruleta();

};


#endif //CASINO_RULETA_H
