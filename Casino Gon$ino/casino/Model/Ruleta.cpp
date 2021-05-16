//
// Created by sebastianq.ds on 15/05/2021.
//

#include "Ruleta.h"

float Ruleta::jugar(float gonzosApostar) {
    srand(time(NULL));

    do {
        // La ruleta paga 35X si cae 0, 17X si cae el numero exacto, y sino 2X si cae al menos el color
        cout << "Ingrese un número de 0 a 36 (0 = Verde, Impares = Negro, Pares = Rojo): ";
        cin >> numeroJugador;
    } while (numeroJugador < 0 && numeroJugador > 36);

    // para calcular numero aleatorio variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    numeroCasino = rand() % 37;// numeros de 1 a 13

    cout << "El numero de la ruleta es " << numeroCasino << "\n" << "El tuyo: " << numeroJugador << "\n";
    float gonzosResulado = calcularResultado(gonzosApostar);
    return gonzosResulado;
}

float Ruleta::calcularResultado(float gonzosApostar) {
    if(numeroJugador == 0){
        if(numeroCasino == numeroJugador){
            return gonzosApostar * 35;
        }else{
            return 0;
        }
    }else{
        if(numeroCasino == numeroJugador){
            return gonzosApostar * 17;
        }else if(numeroJugador % 2 == 0 && numeroCasino % 2 == 0){
            return gonzosApostar * 2;
        }else if(numeroJugador % 2 != 0 && numeroCasino % 2 != 0){
            return gonzosApostar * 2;
        }else{
            return 0;
        }
    }
}

Ruleta::~Ruleta() {

}
