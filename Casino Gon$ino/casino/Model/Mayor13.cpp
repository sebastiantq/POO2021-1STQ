//
// Created by lufe0 on 7/05/2021.
//

#include "Mayor13.h"

float Mayor13::jugar(float gonzosApostar) {
    int continuar;

    srand(time(NULL));

    // para calcular numero aleatorio variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    numeroJugador = 1 + rand() % 13;// numeros de 1 a 13
    cout << "Tu numero aleatorio es: " << numeroJugador << "\n";

    do {
        cout << "¿Deseas continuar? (0. No, 1. Si): ";
        cin >> continuar;
    } while (continuar != 0 && continuar != 1);

    if(continuar == 1){
        numeroCasino = 1 + rand() % 13;// numeros de 1 a 13
        cout << "Numero casino: " << numeroCasino << "\n";
        float gonzosResulado = calcularResultado(gonzosApostar);
        return gonzosResulado;
    }else{
        return -(gonzosApostar / 2);
    }
}


float Mayor13::calcularResultado(float gonzosApostar) {
    if(numeroJugador <= numeroCasino){
        return 0;
    }else{
        return gonzosApostar * 2;
    }
}

Mayor13::~Mayor13() {

}
