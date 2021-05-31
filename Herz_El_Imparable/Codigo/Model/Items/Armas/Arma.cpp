//
// Created by usuario on 17/05/2021.
//

#include "Arma.h"

Arma::Arma(){

}

int Arma::getDano(){
    return dano;
}

int Arma::getResistencia(){
    return resistencia;
}

void Arma::setTipoArma(TipoArma nuevoTipoArma){
    tipoArma = nuevoTipoArma;
}

Arma::~Arma(){

}