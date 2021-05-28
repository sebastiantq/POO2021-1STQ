//
// Created by usuario on 17/05/2021.
//

#include "Arma.h"

Arma::Arma(){

}

float Arma::getDano(){
    return 0;
}

float Arma::getResistencia(){
    return 0;
}

void Arma::setTipoArma(TipoArma nuevoTipoArma){
    tipoArma = nuevoTipoArma;
}

Arma::~Arma(){

}