//
// Created by usuario on 17/05/2021.
//

#include "Mazmorra.h"

Mazmorra::Mazmorra(): mazmorra() {
    dificultad = FACIL;
}

void Mazmorra::inicializarMazmorra(Dificultades dificultadMazmorra){
    int tamanoMaximo;
    tuple <int, int> posicionActual;

    limpiarMazmorra();

    if(dificultadMazmorra == FACIL){
        tamanoMaximo = 10;

        // Se crea un cuadrado de 10 * 10  partiendo de la esquina inferior izquierda
        for (int fila = 0; fila < tamanoMaximo; fila++) {
            for (int columna = 0; columna < tamanoMaximo; columna++) {
                actualizarPosicionMazmorra(fila, columna, Pared());

                get<0>(posicionActual) = fila;
                get<1>(posicionActual) = columna;
                mazmorra[fila][columna].setPosicion(posicionActual);

                if(fila == 0 || fila == 9 || columna == 0 || columna == 9){
                    mazmorra[fila][columna].setChecked(true);
                }else{
                    mazmorra[fila][columna].setChecked(false);
                }
            }
        }

        setDificultad(dificultadMazmorra);
    }else{
        tamanoMaximo = 15;

        // Se crea un cuadrado de 15 * 15
        for (int fila = 0; fila < tamanoMaximo; fila++) {
            for (int columna = 0; columna < tamanoMaximo; columna++) {
                actualizarPosicionMazmorra(fila, columna, Pared());

                get<0>(posicionActual) = fila;
                get<1>(posicionActual) = columna;
                mazmorra[fila][columna].setPosicion(posicionActual);

                if(fila == 0 || fila == 14 || columna == 0 || columna == 14){
                    mazmorra[fila][columna].setChecked(true);
                }else{
                    mazmorra[fila][columna].setChecked(false);
                }
            }
        }

        setDificultad(dificultadMazmorra);
    }

    algoritmoDeRelleno(tamanoMaximo);
}

void Mazmorra::algoritmoDeRelleno(int tamanoMaximo) {
    srand(time(NULL));

    int spawn = 1 + rand() % (tamanoMaximo - 2), bloque;
    tuple <int, int> posicionSpawn(1, spawn), posicionActual(1, spawn);

    actualizarPosicionMazmorra(get<0>(posicionSpawn), get<1>(posicionSpawn), Jugador());
    mazmorra[get<0>(posicionSpawn)][get<1>(posicionSpawn)].setPosicion(posicionSpawn);
    mazmorra[get<0>(posicionSpawn)][get<1>(posicionSpawn)].setChecked(true);

    // Multiple iteracion (tamañoMaximo^2 + tamañoMaximo) veces del algoritmo de generacion de laberintos Aldous-broder
    for (int iteracion = 0; iteracion < pow(tamanoMaximo, 2) + tamanoMaximo; iteracion++) {
        bloque = 1 + rand() % 4;

        try {
            switch (bloque) {
                case 1:
                    // Verifica que la casilla a verificar no exceda los límites de la mazmorra
                    if(get<0>(posicionActual) + 2 > tamanoMaximo - 2){
                        break;
                    }else{
                        if(!mazmorra[get<0>(posicionActual) + 2][get<1>(posicionActual)].getChecked() || mazmorra[get<0>(posicionActual) + 2][get<1>(posicionActual)].getTipo() == ESPACIO){
                            actualizarPosicionMazmorra(get<0>(posicionActual) + 1, get<1>(posicionActual), Espacio());
                            mazmorra[get<0>(posicionActual) + 1][get<1>(posicionActual)].setChecked (true);
                            mazmorra[get<0>(posicionActual) + 1][get<1>(posicionActual)].setPosicion(posicionActual);

                            actualizarPosicionMazmorra(get<0>(posicionActual) + 2, get<1>(posicionActual), Espacio());
                            mazmorra[get<0>(posicionActual) + 2][get<1>(posicionActual)].setChecked (true);
                            mazmorra[get<0>(posicionActual) + 2][get<1>(posicionActual)].setPosicion(posicionActual);

                            get<0>(posicionActual) += 2;
                        }
                    }
                    break;
                case 2:
                    // Verifica que la casilla a verificar no exceda los límites de la mazmorra
                    if(get<1>(posicionActual) + 2 > tamanoMaximo - 2){
                        break;
                    }else{
                        if(!mazmorra[get<0>(posicionActual)][get<1>(posicionActual) + 2].getChecked() || mazmorra[get<0>(posicionActual)][get<1>(posicionActual) + 2].getTipo() == ESPACIO){
                            actualizarPosicionMazmorra(get<0>(posicionActual), get<1>(posicionActual) + 1, Espacio());
                            mazmorra[get<0>(posicionActual) ][get<1>(posicionActual) + 1].setChecked (true);
                            mazmorra[get<0>(posicionActual)][get<1>(posicionActual) + 1].setPosicion(posicionActual);

                            actualizarPosicionMazmorra(get<0>(posicionActual), get<1>(posicionActual) + 2, Espacio());
                            mazmorra[get<0>(posicionActual)][get<1>(posicionActual) + 2].setChecked (true);
                            mazmorra[get<0>(posicionActual)][get<1>(posicionActual) + 2].setPosicion(posicionActual);

                            get<1>(posicionActual) += 2;
                        }
                    }
                    break;
                case 3:
                    // Verifica que la casilla a verificar no exceda los límites de la mazmorra
                    if(get<0>(posicionActual) - 2 < 1){
                        break;
                    }else{
                        if(!mazmorra[get<0>(posicionActual) - 2][get<1>(posicionActual)].getChecked() || mazmorra[get<0>(posicionActual) - 2][get<1>(posicionActual)].getTipo() == ESPACIO){
                            actualizarPosicionMazmorra(get<0>(posicionActual) - 1, get<1>(posicionActual), Espacio());
                            mazmorra[get<0>(posicionActual) - 1][get<1>(posicionActual)].setChecked (true);
                            mazmorra[get<0>(posicionActual) - 1][get<1>(posicionActual)].setPosicion(posicionActual);

                            actualizarPosicionMazmorra(get<0>(posicionActual) - 2, get<1>(posicionActual), Espacio());
                            mazmorra[get<0>(posicionActual) - 2][get<1>(posicionActual)].setChecked (true);
                            mazmorra[get<0>(posicionActual) - 2][get<1>(posicionActual)].setPosicion(posicionActual);

                            get<0>(posicionActual) -= 2;
                        }
                    }
                    break;
                case 4:
                    // Verifica que la casilla a verificar no exceda los límites de la mazmorra
                    if(get<1>(posicionActual) - 2 < 1){
                        break;
                    }else{
                        if(!mazmorra[get<0>(posicionActual)][get<1>(posicionActual) - 2].getChecked() || mazmorra[get<0>(posicionActual)][get<1>(posicionActual) - 2].getTipo() == ESPACIO){
                            actualizarPosicionMazmorra(get<0>(posicionActual), get<1>(posicionActual) - 1, Espacio());
                            mazmorra[get<0>(posicionActual) ][get<1>(posicionActual) - 1].setChecked (true);
                            mazmorra[get<0>(posicionActual)][get<1>(posicionActual) - 1].setPosicion(posicionActual);

                            actualizarPosicionMazmorra(get<0>(posicionActual), get<1>(posicionActual) - 2, Espacio());
                            mazmorra[get<0>(posicionActual)][get<1>(posicionActual) - 2].setChecked (true);
                            mazmorra[get<0>(posicionActual)][get<1>(posicionActual) - 2].setPosicion(posicionActual);

                            get<1>(posicionActual) -= 2;
                        }
                    }
                    break;
                default:
                    break;
            }

            iteracion++;
        }catch(int error){
            continue;
        }
    }

    mostrarMazmorra(0);
}

void Mazmorra::actualizarPosicionMazmorra(int fila, int columna, Espacio tipoEspacio){
    mazmorra[fila][columna] = tipoEspacio;
}

void Mazmorra::mostrarMazmorra(int desdeFila){
    int tamanoMaximo;

    if(getDificultad() == FACIL){
        tamanoMaximo = 10;
    }else{
        tamanoMaximo = 15;
    }

    cout << endl;

    for (int fila = tamanoMaximo - 1; fila >= desdeFila; fila--) {
        for (int columna = 0; columna < tamanoMaximo; columna++) {
            cout << " " << mazmorra[fila][columna].getImagen() << " ";
        }

        cout << endl;
    }
}

Espacio* Mazmorra::getEspacio(int fila, int columna){
    return &mazmorra[fila][columna];
}

void Mazmorra::limpiarMazmorra(){
    for (int fila = 0; fila < 15; fila++) {
        for (int columna = 0; columna < 15; columna++) {
            actualizarPosicionMazmorra(fila, columna, Pared());
        }
    }
}

Dificultades Mazmorra::getDificultad(){
    return dificultad;
}

tuple<int, int> Mazmorra::getPosicionJugador(){
    for (int fila = 0; fila < 15; fila++) {
        for (int columna = 0; columna < 15; columna++) {
            if(mazmorra[fila][columna].getTipo() == JUGADOR){
                return mazmorra[fila][columna].getPosicion();
            }
        }
    }

    return mazmorra[0][0].getPosicion();
}

void Mazmorra::setDificultad(Dificultades nuevaDificultad){
    dificultad = nuevaDificultad;
}
