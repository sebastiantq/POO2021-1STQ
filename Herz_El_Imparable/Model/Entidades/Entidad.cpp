//
// Created by usuario on 20/05/2021.
//

#include "Entidad.h"


Entidad::Entidad(){

}

int Entidad::getPuntosVida(){
    return puntosVida;
}

int Entidad::getPuntosVidaMaximos(){
    return puntosVidaMaximos;
}

int Entidad::getPuntosAtaque(){
    return puntosAtaque;
}

void Entidad::setPuntosVida(int nuevosPuntosDeVida){
    puntosVida = nuevosPuntosDeVida;
}

void Entidad::setPuntosVidaMaximos(int nuevosPuntosDeVidaMaximos){
    puntosVidaMaximos = nuevosPuntosDeVidaMaximos;
}

void Entidad::setPuntosAtaque(int nuevosPuntosAtaque){
    puntosAtaque = nuevosPuntosAtaque;
}