//
// Created by usuario on 17/05/2021.
//

#include "Arma.h"

Arma::Arma(){

}

float Arma::getDano(){
    return 0;
}

bool Arma::interaccion(){
    cout << endl << "Interaccion con arma" << endl;
    return false;
}

float Arma::getResistencia(){
    return 0;
}

void Arma::setTipoArma(TipoArma nuevoTipoArma){
    tipoArma = nuevoTipoArma;
}

Arma::~Arma(){

}