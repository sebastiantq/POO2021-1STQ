//
// Created by usuario on 17/05/2021.
//

#include "Controller.h"

Controller::Controller() {
    mazmorra = Mazmorra();
    estadoJuego = MENU_PRINCIPAL;
}

void Controller::inicializarMazmorra(Dificultades dificultad){
    if(dificultad != FACIL && dificultad != NORMAL){
        throw std::domain_error("La dificultad seleccionada es incorrecta\n");
    }else{
        mazmorra.inicializarMazmorra(dificultad);
        setEstadoJuego(JUGANDO);
    }

    cout << endl;
}

void Controller::mostrarMazmorra(int desdeFila){
    int tamanoMaximo;

    if(mazmorra.getDificultad() == FACIL){
        tamanoMaximo = 10;
    }else{
        tamanoMaximo = 15;
    }

    if(desdeFila >= 0 && desdeFila < tamanoMaximo){
        mazmorra.mostrarMazmorra(desdeFila);
    }else{
        throw std::domain_error("Lo sentimos, ha habido un error, debemos reiniciar");
    }
}

void Controller::setEstadoJuego(EstadoJuego nuevoEstadoJuego){
    estadoJuego = nuevoEstadoJuego;
}

Mazmorra Controller::getMazmorra(){
    return mazmorra;
}

EstadoJuego Controller::getEstadoJuego(){
    return estadoJuego;
}

void Controller::interactuar(int fila, int columna){
    tuple<int, int>posicionJugador = mazmorra.getPosicionJugador(), posicionDisponibleInventario, posicionItem;
    Espacio*  espacioJugador = mazmorra.getEspacio(get<0>(posicionJugador), get<1>(posicionJugador));
    Jugador* jugador = (Jugador*)(espacioJugador); // Downcasting exitoso
    int randomNumber = rand() % 2; // Para frases al final del juego

    if(mazmorra.getEspacio(fila, columna)->getTipo() == ARMA || mazmorra.getEspacio(fila, columna)->getTipo() == POCION || mazmorra.getEspacio(fila, columna)->getTipo() == ARTEFACTO_LEGENDARIO){
        // Es un Item
        jugador->mostrarInventario();

        if(mazmorra.getEspacio(fila, columna)->interaccion()){
            posicionDisponibleInventario = jugador->getPosicionDisponibleInventario();
            if(get<0>(posicionDisponibleInventario) == 5 && get<1>(posicionDisponibleInventario) == 5){
                cout << "El inventario está lleno, debes eliminar algun item primero" << endl;
            }else{
                // Añade el item al inventario del jugador
                jugador->actualizarPosicionInventario(get<0>(posicionDisponibleInventario), get<1>(posicionDisponibleInventario), mazmorra.getEspacio(fila, columna));
                mazmorra.actualizarPosicionMazmorra(fila, columna, new Espacio());
            }
        }
    }else if(mazmorra.getEspacio(fila, columna)->getTipo() == ARTEFACTO_LEGENDARIO) {
        // Has ganado, encontraste el objeto legendario
        mazmorra.abrirPuerta();
        cout << endl << "¡Lo has conseguido! Una puerta ha sido abierta en la mazmorra, sal y salva a tu reino, honorable Herz" << endl;
    }else if(mazmorra.getEspacio(fila, columna)->getTipo() == SALIDA) {
        // Herz ha salido
        if(randomNumber == 0){
            cout << endl << "Felicidades, Herz ha conseguido llevar el artefacto y ha curado a una damicela peculiarmente bella, ¿será este el fin del hombre araña?" << endl;
        }else if(randomNumber == 1){
            cout << endl << "¡Oh no! Herz ha encontrado un troll de camino a casa, se están riendo mucho, el troll se hace llamar sonzo, goncho, o algo así, bahh, seguro se hacen amigos y se lo lleva al reino" << endl;
        }else if(randomNumber == 2){
            cout << endl << "*sonido de gallo* oh no, te ha llegado una carta diciendo que debes ir a salvar a tu pueblo luchando en una mazmorra, ve por ello" << endl;
            setEstadoJuego(ESCOGIENDO_DIFICULTAD);
            return;
        }
        setEstadoJuego(MENU_PRINCIPAL);
    }else if(mazmorra.getEspacio(fila, columna)->getTipo() == ENEMIGO || mazmorra.getEspacio(fila, columna)->getTipo() == JEFE){
        // Es un Enemigo
        Enemigo* enemigoACombatir = (Enemigo*)(mazmorra.getEspacio(fila, columna)); // Downcasting para acceder a metodos de enemigo

        if(enemigoACombatir->combate(jugador)){
            // Herz ha ganado el combate
            cout << endl << "¡Has ganado el combate! bien hecho" << endl;

            if(!mazmorra.artefactoLegendarioSpawneado()){
                if(mazmorra.getEspacio(fila, columna)->getTipo() == JEFE){
                    // Dependiendo de la cantidad de jefes vivos tiene mas o menos probabilidad de obtener el artefacto legendario
                    if(mazmorra.getCantidadJefes() == 3){
                        if(rand() % 1 == 0){
                            mazmorra.actualizarPosicionMazmorra(fila, columna, new ArtefactoLegendario());
                        }else{
                            mazmorra.actualizarPosicionMazmorra(fila, columna, new Espacio());
                        }
                    }else if(mazmorra.getCantidadJefes() == 2){
                        if(rand() % 2 == 2){
                            mazmorra.actualizarPosicionMazmorra(fila, columna, new ArtefactoLegendario());
                        }else{
                            mazmorra.actualizarPosicionMazmorra(fila, columna, new Espacio());
                        }
                    }else{
                        mazmorra.actualizarPosicionMazmorra(fila, columna, new ArtefactoLegendario());
                    }
                }else{
                    mazmorra.actualizarPosicionMazmorra(fila, columna, new Espacio());
                }
            }
        }else{
            // Ha muerto Herz
            if(jugador->muerte(mazmorra.getDificultad())){
                setEstadoJuego(ESCOGIENDO_DIFICULTAD);
            }else{
                setEstadoJuego(MENU_PRINCIPAL);
            }
        }
    }
}

void Controller::teclaArriba() {
    tuple <int, int>posicion = mazmorra.getPosicionJugador(), posicionNueva(get<0>(posicion) + 1, get<1>(posicion));
    Jugador* jugador = (Jugador*)mazmorra.getEspacio(get<0>(posicion), get<1>(posicion));

    if(!mazmorra.getEspacio(get<0>(posicion) + 1, get<1>(posicion))->getInteractivo()){
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion) + 1, get<1>(posicion), jugador);
        mazmorra.getEspacio(get<0>(posicion) + 1, get<1>(posicion))->setPosicion(posicionNueva);
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion), new Espacio());
    }else{
        // Realiza una interaccion con el objeto
        interactuar(get<0>(posicion) + 1, get<1>(posicion));
    }
}

void Controller::teclaIzquierda() {
    tuple <int, int>posicion = mazmorra.getPosicionJugador(), posicionNueva(get<0>(posicion), get<1>(posicion) - 1);
    Jugador* jugador = (Jugador*)mazmorra.getEspacio(get<0>(posicion), get<1>(posicion));

    if(!mazmorra.getEspacio(get<0>(posicion), get<1>(posicion) - 1)->getInteractivo()){
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion) - 1, jugador);
        mazmorra.getEspacio(get<0>(posicion), get<1>(posicion) - 1)->setPosicion(posicionNueva);
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion), new Espacio());
    }else{
        // Realiza una interaccion con el objeto
        interactuar(get<0>(posicion), get<1>(posicion) - 1);
    }
}

void Controller::teclaDerecha() {
    tuple <int, int>posicion = mazmorra.getPosicionJugador(), posicionNueva(get<0>(posicion), get<1>(posicion) + 1);
    Jugador* jugador = (Jugador*)mazmorra.getEspacio(get<0>(posicion), get<1>(posicion));

    if(!mazmorra.getEspacio(get<0>(posicion), get<1>(posicion) + 1)->getInteractivo()){
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion) + 1, jugador);
        mazmorra.getEspacio(get<0>(posicion), get<1>(posicion) + 1)->setPosicion(posicionNueva);
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion), new Espacio());
    }else{
        // Realiza una interaccion con el objeto
        interactuar(get<0>(posicion), get<1>(posicion) + 1);
    }
}

void Controller::teclaAbajo() {
    tuple <int, int>posicion = mazmorra.getPosicionJugador(), posicionNueva(get<0>(posicion) - 1, get<1>(posicion));
    Jugador* jugador = (Jugador*)mazmorra.getEspacio(get<0>(posicion), get<1>(posicion));

    if(!mazmorra.getEspacio(get<0>(posicion) - 1, get<1>(posicion))->getInteractivo()){
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion) - 1, get<1>(posicion), jugador);
        mazmorra.getEspacio(get<0>(posicion) - 1, get<1>(posicion))->setPosicion(posicionNueva);
        mazmorra.actualizarPosicionMazmorra(get<0>(posicion), get<1>(posicion), new Espacio());
    }else{
        // Realiza una interaccion con el objeto
        interactuar(get<0>(posicion) - 1, get<1>(posicion));
    }
}