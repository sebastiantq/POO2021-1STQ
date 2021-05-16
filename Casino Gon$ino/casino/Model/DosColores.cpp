//
// Created by lufe0 on 8/05/2021.
//

#include "DosColores.h"

float DosColores::jugar(float gonzosApostar) {
    srand(time(NULL));
    // para calcular numero aleatorio variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    numeroJugador = 1 + rand() % 13;// numeros de 1 a 13
    numeroCasino = 1 + rand() % 13;// numeros de 1 a 13

    do {
        cout << "Escoja un color (0. Blanco, 1. Negro): ";
        cin >> colorJugador; // Numero entre 0 y 1
    } while (colorJugador != 0 && colorJugador != 1);

    colorCasino = rand() % 2; // Numero entre 0 y 1
    cout << "Tu numero aleatorio es: " << numeroJugador << "\n" << "Tu color: " <<colorJugador << "\n";
    cout << "Numero casino: " << numeroCasino << "\n" << "Color casino: " <<colorCasino << "\n";
    float gonzosResulado = calcularResultado(gonzosApostar);
    return gonzosResulado;
}

float DosColores::calcularResultado(float gonzosApostar) {
    if(colorJugador == colorCasino  && numeroJugador == numeroCasino){
        return gonzosApostar * 4;
    }else if(colorJugador != colorCasino  && numeroJugador == numeroCasino){
        return gonzosApostar + (gonzosApostar / 2);
    }else if(colorJugador == colorCasino  && numeroJugador != numeroCasino){
        return gonzosApostar;
    }else{
        return 0;
    }
}

DosColores::~DosColores() {

}
