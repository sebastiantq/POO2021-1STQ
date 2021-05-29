//
// Created by usuario on 20/05/2021.
//

#include "Hacha.h"

Hacha::Hacha(){
    setImagen('H');
    setTipo(ARMA);
    setTipoArma(HACHA);
    dano = 5;
    resistencia = 4;
    interactivo = true;
    checked = true;
}

bool Hacha::interaccion(){
    int opcion;

    do{
        cout << "Has encontrado un hacha, ¿deseas añadirla al inventario? (1. Si, 0. No): ";
        cin >> opcion;
    }while(opcion != 0 && opcion != 1);

    return opcion;
}

Hacha::~Hacha(){

}