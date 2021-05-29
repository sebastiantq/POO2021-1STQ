//
// Created by usuario on 28/05/2021.
//

#include "PocionDano.h"

PocionDano::PocionDano(){
    setImagen('D');
    setTipo(ARMA);
    setTipoArma(POCION_DANO);
    dano = 2;
    resistencia = 1;
    interactivo = true;
    checked = true;
}

bool PocionDano::interaccion(){
    int opcion;

    do{
        cout << "Has encontrado una pocion de daño, ¿deseas añadirla al inventario? (1. Si, 0. No): ";
        cin >> opcion;
    }while(opcion != 0 && opcion != 1);

    return opcion;
}

PocionDano::~PocionDano() {

}