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

    cout << endl << "El pacífico reino de Cyradil fue golpeado por una maldición que hizo "
                    "que la gente cayera enferma, esto pone al reino en un terrible peligro "
                    "de ser invadido por reinos enemigos. El caballero Herz, que en el momento "
                    "de la maldición se encontraba por fuera del reino, es el único capaz de "
                    "salvar el reino de la perdición, para esto deberá buscar un legendario "
                    "artefacto perdido en las mazmorras del norte para purificar al reino de "
                    "Cyradil de la maldición." << endl;

    if(dificultadMazmorra == FACIL){
        tamanoMaximo = 10;

        // Se crea un cuadrado de 10 * 10  partiendo de la esquina inferior izquierda
        for (int fila = 0; fila < tamanoMaximo; fila++) {
            for (int columna = 0; columna < tamanoMaximo; columna++) {
                actualizarPosicionMazmorra(fila, columna, new Pared());

                get<0>(posicionActual) = fila;
                get<1>(posicionActual) = columna;
                mazmorra[fila][columna]->setPosicion(posicionActual);

                if(fila == 0 || fila == 9 || columna == 0 || columna == 9){
                    mazmorra[fila][columna]->setChecked(true);
                }else{
                    mazmorra[fila][columna]->setChecked(false);
                }
            }
        }

        setDificultad(dificultadMazmorra);
    }else{
        tamanoMaximo = 15;

        // Se crea un cuadrado de 15 * 15
        for (int fila = 0; fila < tamanoMaximo; fila++) {
            for (int columna = 0; columna < tamanoMaximo; columna++) {
                actualizarPosicionMazmorra(fila, columna, new Pared());

                get<0>(posicionActual) = fila;
                get<1>(posicionActual) = columna;
                mazmorra[fila][columna]->setPosicion(posicionActual);

                if(fila == 0 || fila == 14 || columna == 0 || columna == 14){
                    mazmorra[fila][columna]->setChecked(true);
                }else{
                    mazmorra[fila][columna]->setChecked(false);
                }
            }
        }

        setDificultad(dificultadMazmorra);
    }

    algoritmoDeRelleno(tamanoMaximo);
    algoritmoDePosicionamientoDeEntidades(dificultadMazmorra);
    algoritmoDePosicionamientoDeItems(dificultadMazmorra);
    mostrarMazmorra(0);
}

void Mazmorra::algoritmoDeRelleno(int tamanoMaximo) {
    srand(time(NULL));

    int spawn = 1 + rand() % (tamanoMaximo - 2), bloque;
    tuple <int, int> posicionSpawn(1, spawn), posicionActual(1, spawn);

    actualizarPosicionMazmorra(get<0>(posicionSpawn), get<1>(posicionSpawn), new Jugador());
    mazmorra[get<0>(posicionSpawn)][get<1>(posicionSpawn)]->setPosicion(posicionSpawn);
    mazmorra[get<0>(posicionSpawn)][get<1>(posicionSpawn)]->setChecked(true);

    // Multiple iteracion (tamañoMaximo^2 + tamañoMaximo) veces del algoritmo de generacion de laberintos Aldous-broder
    for (int iteracion = 0; iteracion < pow(tamanoMaximo, 2) + tamanoMaximo; iteracion++) {
        bloque = 1 + rand() % 4;

        try {
            switch (bloque) {
                // Arriba
                case 1:
                    // Verifica que la casilla a verificar no exceda los límites de la mazmorra
                    if(get<0>(posicionActual) + 2 > tamanoMaximo - 2){
                        break;
                    }else{
                        if(!mazmorra[get<0>(posicionActual) + 2][get<1>(posicionActual)]->getChecked() || mazmorra[get<0>(posicionActual) + 2][get<1>(posicionActual)]->getTipo() == ESPACIO){
                            actualizarPosicionMazmorra(get<0>(posicionActual) + 1, get<1>(posicionActual), new Espacio());
                            mazmorra[get<0>(posicionActual) + 1][get<1>(posicionActual)]->setChecked (true);
                            mazmorra[get<0>(posicionActual) + 1][get<1>(posicionActual)]->setPosicion(posicionActual);

                            actualizarPosicionMazmorra(get<0>(posicionActual) + 2, get<1>(posicionActual), new Espacio());
                            mazmorra[get<0>(posicionActual) + 2][get<1>(posicionActual)]->setChecked (true);
                            mazmorra[get<0>(posicionActual) + 2][get<1>(posicionActual)]->setPosicion(posicionActual);

                            get<0>(posicionActual) += 2;
                        }

                        break;
                    }
                // Derecha
                case 2:
                    // Verifica que la casilla a verificar no exceda los límites de la mazmorra
                    if(get<1>(posicionActual) + 2 > tamanoMaximo - 2){
                        break;
                    }else{
                        if(!mazmorra[get<0>(posicionActual)][get<1>(posicionActual) + 2]->getChecked() || mazmorra[get<0>(posicionActual)][get<1>(posicionActual) + 2]->getTipo() == ESPACIO){
                            actualizarPosicionMazmorra(get<0>(posicionActual), get<1>(posicionActual) + 1, new Espacio());
                            mazmorra[get<0>(posicionActual) ][get<1>(posicionActual) + 1]->setChecked (true);
                            mazmorra[get<0>(posicionActual)][get<1>(posicionActual) + 1]->setPosicion(posicionActual);

                            actualizarPosicionMazmorra(get<0>(posicionActual), get<1>(posicionActual) + 2, new Espacio());
                            mazmorra[get<0>(posicionActual)][get<1>(posicionActual) + 2]->setChecked (true);
                            mazmorra[get<0>(posicionActual)][get<1>(posicionActual) + 2]->setPosicion(posicionActual);

                            get<1>(posicionActual) += 2;
                        }

                        break;
                    }
                // Abajo
                case 3:
                    // Verifica que la casilla a verificar no exceda los límites de la mazmorra
                    if(get<0>(posicionActual) - 2 < 1){
                        break;
                    }else{
                        if(!mazmorra[get<0>(posicionActual) - 2][get<1>(posicionActual)]->getChecked() || mazmorra[get<0>(posicionActual) - 2][get<1>(posicionActual)]->getTipo() == ESPACIO){
                            actualizarPosicionMazmorra(get<0>(posicionActual) - 1, get<1>(posicionActual), new Espacio());
                            mazmorra[get<0>(posicionActual) - 1][get<1>(posicionActual)]->setChecked (true);
                            mazmorra[get<0>(posicionActual) - 1][get<1>(posicionActual)]->setPosicion(posicionActual);

                            actualizarPosicionMazmorra(get<0>(posicionActual) - 2, get<1>(posicionActual), new Espacio());
                            mazmorra[get<0>(posicionActual) - 2][get<1>(posicionActual)]->setChecked (true);
                            mazmorra[get<0>(posicionActual) - 2][get<1>(posicionActual)]->setPosicion(posicionActual);

                            get<0>(posicionActual) -= 2;
                        }

                        break;
                    }
                // Izquierda
                case 4:
                    // Verifica que la casilla a verificar no exceda los límites de la mazmorra
                    if(get<1>(posicionActual) - 2 < 1){
                        break;
                    }else{
                        if(!mazmorra[get<0>(posicionActual)][get<1>(posicionActual) - 2]->getChecked() || mazmorra[get<0>(posicionActual)][get<1>(posicionActual) - 2]->getTipo() == ESPACIO){
                            actualizarPosicionMazmorra(get<0>(posicionActual), get<1>(posicionActual) - 1, new Espacio());
                            mazmorra[get<0>(posicionActual) ][get<1>(posicionActual) - 1]->setChecked (true);
                            mazmorra[get<0>(posicionActual)][get<1>(posicionActual) - 1]->setPosicion(posicionActual);

                            actualizarPosicionMazmorra(get<0>(posicionActual), get<1>(posicionActual) - 2, new Espacio());
                            mazmorra[get<0>(posicionActual)][get<1>(posicionActual) - 2]->setChecked (true);
                            mazmorra[get<0>(posicionActual)][get<1>(posicionActual) - 2]->setPosicion(posicionActual);

                            get<1>(posicionActual) -= 2;
                        }

                        break;
                    }
                default:
                    break;
            }
        }catch(int error){
            continue;
        }
    }
}

void Mazmorra::algoritmoDePosicionamientoDeEntidades(Dificultades dificultadMazmorra){
    int enemigosMaximos, enemigoActual = 0, jefesMaximos, jefeActual = 0, tamanoMaximo, probabilidadEnemigo, tipoEnemigo;
    bool actualizado = false;

    if(dificultadMazmorra == FACIL){
        tamanoMaximo = 10;
        enemigosMaximos = 12;
        jefesMaximos = 1;
    }else{
        tamanoMaximo = 15;
        enemigosMaximos = 22;
        jefesMaximos = 3;
    }

    while (jefeActual < jefesMaximos) {
        for (int fila = tamanoMaximo - 1; fila >= 0; fila--) {
            for (int columna = 0; columna < tamanoMaximo; columna++) {
                if (!actualizado) {
                    if(mazmorra[fila][columna]->getTipo() == ESPACIO){
                        probabilidadEnemigo = 1 + rand() % 100;
                        if(probabilidadEnemigo < 25){
                            tipoEnemigo = 1 + rand() % 3;

                            if(tipoEnemigo == 1){
                                actualizarPosicionMazmorra(fila, columna, new JefeBiter());
                            }else if(tipoEnemigo == 2){
                                actualizarPosicionMazmorra(fila, columna, new JefeHauntedWater());
                            }else{
                                actualizarPosicionMazmorra(fila, columna, new JefeTroll());
                            }

                            jefeActual++;
                            actualizado = true;
                        }
                    }
                }
            }
        }

        actualizado = false;
    }

    actualizado = false;

    while (enemigoActual < enemigosMaximos){
        for (int fila = tamanoMaximo - 1; fila >= 0; fila--) {
            for (int columna = 0; columna < tamanoMaximo; columna++) {
                if(!actualizado){
                    if(mazmorra[fila][columna]->getTipo() == ESPACIO){
                        probabilidadEnemigo = 1 + rand() % 100;
                        if(probabilidadEnemigo < 10){
                            tipoEnemigo = 1 + rand() % 3;

                            if(tipoEnemigo == 1){
                                actualizarPosicionMazmorra(fila, columna, new Biter());
                            }else if(tipoEnemigo == 2){
                                actualizarPosicionMazmorra(fila, columna, new HauntedWater());
                            }else{
                                actualizarPosicionMazmorra(fila, columna, new Troll());
                            }

                            enemigoActual++;
                            actualizado = true;
                        }
                    }
                }
            }
        }

        actualizado = false;
    }
}

void Mazmorra::algoritmoDePosicionamientoDeItems(Dificultades dificultadMazmorra){
    int tamanoMaximo, probabilidadItem, tipoItem, tipoArma, tipoPocion;

    if(dificultadMazmorra == FACIL){
        tamanoMaximo = 10;
    }else{
        tamanoMaximo = 15;
    }

    for (int fila = tamanoMaximo - 1; fila >= 0; fila--) {
        for (int columna = 0; columna < tamanoMaximo; columna++) {
            if (mazmorra[fila][columna]->getTipo() == ESPACIO) {
                probabilidadItem = 1 + rand() % 100;
                if (probabilidadItem < 15) {
                    tipoItem = 1 + rand() % 2;

                    if (tipoItem == 1) {
                        // Arma
                        tipoArma = 1 + rand() % 2;

                        if(tipoArma == 1) {
                            // Espada
                            actualizarPosicionMazmorra(fila, columna, new Espada());
                        }else{
                            // Hacha
                            actualizarPosicionMazmorra(fila, columna, new Hacha());
                        }
                    } else if (tipoItem == 2) {
                        // Pocion
                        tipoPocion = 1 + rand() % 2;

                        if(tipoPocion == 1) {
                            // Curacion
                            actualizarPosicionMazmorra(fila, columna, new Curacion());
                        }else{
                            // Fuerza
                            actualizarPosicionMazmorra(fila, columna, new Fuerza());
                        }
                    }
                }
            }
        }
    }
}

void Mazmorra::actualizarPosicionMazmorra(int fila, int columna, Espacio* tipoEspacio){
    mazmorra[fila][columna] = tipoEspacio;
    mazmorra[fila][columna]->setPosicion(tuple<int, int>(fila, columna));
}

void Mazmorra::abrirPuerta(){
    int tamanoMaximo;
    bool abierta = false;

    if(getDificultad() == FACIL){
        tamanoMaximo = 10;
    }else{
        tamanoMaximo = 15;
    }

    while(!abierta){
        for (int fila = tamanoMaximo - 1; fila >= 0; fila--) {
            for (int columna = 0; columna < tamanoMaximo; columna++) {
                if(fila == tamanoMaximo - 1 || fila == 0 || columna == tamanoMaximo - 1 || columna == 0){
                    if(!abierta){
                        try {
                            if(getEspacio(fila + 1, columna)->getTipo() == ESPACIO){
                                // Arriba
                                actualizarPosicionMazmorra(fila, columna, new Espacio());
                                getEspacio(fila, columna)->setTipo(SALIDA);
                                getEspacio(fila, columna)->setInteractivo(true);
                                abierta = true;
                            }else if(getEspacio(fila, columna + 1)->getTipo() == ESPACIO){
                                // Derecha
                                actualizarPosicionMazmorra(fila, columna, new Espacio());
                                getEspacio(fila, columna)->setTipo(SALIDA);
                                getEspacio(fila, columna)->setInteractivo(true);
                                abierta = true;
                            }else if(getEspacio(fila - 1, columna)->getTipo() == ESPACIO){
                                // Abajo
                                actualizarPosicionMazmorra(fila, columna, new Espacio());
                                getEspacio(fila, columna)->setTipo(SALIDA);
                                getEspacio(fila, columna)->setInteractivo(true);
                                abierta = true;
                            }else if(getEspacio(fila, columna - 1)->getTipo() == ESPACIO){
                                // Izquierda
                                actualizarPosicionMazmorra(fila, columna, new Espacio());
                                getEspacio(fila, columna)->setTipo(SALIDA);
                                getEspacio(fila, columna)->setInteractivo(true);
                                abierta = true;
                            }
                        }catch(int error){
                            // El espacio inspeccionado excede los limites del array
                        }
                    }
                }
            }
        }
    }
}

void Mazmorra::mostrarMazmorra(int desdeFila){
    int tamanoMaximo;
    Jugador* jugador = (Jugador*)(getEspacio(get<0>(getPosicionJugador()), get<1>(getPosicionJugador())));

    if(getDificultad() == FACIL){
        tamanoMaximo = 10;
    }else{
        tamanoMaximo = 15;
    }

    cout << endl;

    for (int fila = tamanoMaximo - 1; fila >= desdeFila; fila--) {
        for (int columna = 0; columna < tamanoMaximo; columna++) {
            cout << " " << mazmorra[fila][columna]->getImagen() << " ";
        }

        cout << endl << endl;
    }

    cout << "Vida: " << jugador->getPuntosVida() << endl;
    cout << "Ataque: " << jugador->getPuntosAtaque() << endl;
}

void Mazmorra::limpiarMazmorra(){
    for (int fila = 0; fila < 15; fila++) {
        for (int columna = 0; columna < 15; columna++) {
            actualizarPosicionMazmorra(fila, columna, new Pared());
        }
    }
}

Espacio* Mazmorra::getEspacio(int fila, int columna){
    return mazmorra[fila][columna];
}

Dificultades Mazmorra::getDificultad(){
    return dificultad;
}

tuple<int, int> Mazmorra::getPosicionJugador(){
    for (int fila = 0; fila < 15; fila++) {
        for (int columna = 0; columna < 15; columna++) {
            if(mazmorra[fila][columna]->getTipo() == JUGADOR){
                return mazmorra[fila][columna]->getPosicion();
            }
        }
    }

    return mazmorra[0][0]->getPosicion();
}

bool Mazmorra::artefactoLegendarioSpawneado(){
    Jugador* jugador = (Jugador*)(getEspacio(get<0>(getPosicionJugador()), get<1>(getPosicionJugador())));

    // Se verifica primero todo el mapa
    for (int fila = 0; fila < 15; fila++) {
        for (int columna = 0; columna < 15; columna++) {
            if(mazmorra[fila][columna]->getTipo() == ARTEFACTO_LEGENDARIO){
                return true;
            }
        }
    }

    // Se verifica luego el inventario del jugador
    for (int fila = 0; fila < 2; fila++) {
        for (int columna = 0; columna < 5; columna++) {
            if(jugador->getItemInventario(fila, columna)->getTipo() == ARTEFACTO_LEGENDARIO){
                return true;
            }
        }
    }

    return false;
}

int Mazmorra::getCantidadJefes(){
    int cantidadDeJefes = 0;

    for (int fila = 0; fila < 15; fila++) {
        for (int columna = 0; columna < 15; columna++) {
            if(mazmorra[fila][columna]->getTipo() == JEFE){
                cantidadDeJefes++;
            }
        }
    }

    return cantidadDeJefes;
}

void Mazmorra::setDificultad(Dificultades nuevaDificultad){
    dificultad = nuevaDificultad;
}
