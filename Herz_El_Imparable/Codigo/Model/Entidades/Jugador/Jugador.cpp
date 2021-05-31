//
// Created by usuario on 17/05/2021.
//

#include "Jugador.h"
#include "../../Items/Armas/Arma.h"

Jugador::Jugador(){
    setImagen('O');
    setTipo(JUGADOR);
    interactivo = false;
    checked = false;
    inicializarInventario();
    setPuntosVida(10);
    setPuntosVidaMaximos(10);
    setPuntosAtaque(2);
    setArmaEquipada(new Espacio());
}

void Jugador::inicializarInventario(){
    for (int fila = 0; fila < 2; fila++) {
        for (int columna = 0; columna < 5; columna++) {
            actualizarPosicionInventario(fila, columna, new Espacio());
        }
    }
}

void Jugador::mostrarInventario(){
    cout << endl << "-- Inventario --" << endl << endl;

    for (int fila = 0; fila < 2; fila++) {
        for (int columna = 0; columna < 5; columna++) {
            cout << "|"  << inventario[fila][columna]->getImagen() << "|";
        }

        // Muestra el arma equipada
        if(fila == 0){
            cout << "     |"  << getArmaEquipada()->getImagen() << "|";
        }

        cout << endl;
    }

    cout << endl;
}

void Jugador::actualizarPosicionInventario(int fila, int columna, Espacio* nuevoItem){
    inventario[fila][columna] = nuevoItem;
}

bool Jugador::muerte(bool dificultadNormal){
    int opcion;

    if(dificultadNormal){
        cout << endl << "Has muerto, bajale un poco la dificultad si lo precisas"<< endl;
    }else{
        cout << endl << "Has muerto, ponte a jugar a los Sims"<< endl;
    }

    do {
        cout << endl << "¿Deseas iniciar una nueva partida? (1. Si, 0. No): ";
        cin >> opcion;
    }while(opcion != 0 && opcion != 1);

    return opcion;
}

void Jugador::desplegarMenuInventario(){
    int opcion;

    do{
        mostrarInventario();

        cout << endl << "-- Menu inventario --" << endl << endl;
        cout << "1. Soltar item" << endl;
        cout << "2. Consumir pocion" << endl;
        cout << "3. Equipar arma" << endl;
        cout << "0. Regresar" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        menuInventario(opcion);
    } while (opcion != 0);
}

void Jugador::desplegarMenuAtaque(){
    int opcion;

    do{
        mostrarInventario();

        cout << endl << "-- Menu ataque --" << endl << endl;
        cout << "1. Atacar" << endl;
        cout << "2. Consumir pocion" << endl;
        cout << "3. Cambiar arma" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        if(opcion != 1){
            menuInventario(opcion);
        }
    } while (opcion != 1);
}

void Jugador::menuInventario(int opcion){
    switch (opcion) {
        case 0:
            break;
        case 1:
        {
            int fila, columna;

            do {
                cout << endl << "Ingrese la fila del item a soltar: ";
                cin >> fila;
            }while(fila < 0 || fila > 4);

            do{
                cout << "Ingrese la columna del item a soltar: ";
                cin >> columna;
            }while(columna < 0 || columna > 4);

            if(getItemInventario(fila, columna)->getTipo() == ESPACIO){
                cout << endl << "Tu pueblo muriendo y tu perdiendo el tiempo en soltar un espacio vacio" << endl;
            }else{
                actualizarPosicionInventario(fila, columna, new Espacio());
                cout << endl << "Item soltado" << endl;
            }

            break;
        }
        case 2:
        {
            int fila, columna;

            do {
                cout << endl << "Ingrese la fila de la pocion a consumir: ";
                cin >> fila;
            }while(fila < 0 || fila > 4);

            do{
                cout << "Ingrese la columna de la pocion a consumir: ";
                cin >> columna;
            }while(columna < 0 || columna > 4);

            if(getItemInventario(fila, columna)->getTipo() == ESPACIO){
                cout << endl << "Supongo que eso significa que quieres tomar aire" << endl;
            }else{
                Pocion* pocion = dynamic_cast<Pocion*>(getItemInventario(fila, columna));

                if(pocion){
                    pocion->consumir(this);
                    actualizarPosicionInventario(fila, columna, new Espacio());
                    cout << endl << "Pocion consumida" << endl;
                }else{
                    cout << endl << "El elemento seleccionado no es una pocion" << endl;
                }
            }

            break;
        }
        case 3:
        {
            int fila, columna;

            cout << endl << "Al equipar un arma se sustituira la actual por la equipada y se guardara la anterior en el lugar de la nueva" << endl << endl;

            do {
                cout << "Ingrese la fila del arma a equipar: ";
                cin >> fila;
            }while(fila < 0 || fila > 4);

            do{
                cout << "Ingrese la columna del arma a equipar: ";
                cin >> columna;
            }while(columna < 0 || columna > 4);

            if(getItemInventario(fila, columna)->getTipo() == ARMA){
                Arma* armaAEquipar = (Arma*)(getItemInventario(fila, columna));
                Arma* armaADesequipar = (Arma*)(getArmaEquipada());

                actualizarPosicionInventario(fila, columna, armaADesequipar);
                setArmaEquipada(armaAEquipar);

                if(armaADesequipar->getTipo() == ARMA){
                    // Añade los puntos de ataque del arma a los puntos de ataque de Herz
                    setPuntosAtaque(getPuntosAtaque() + armaAEquipar->getDano() - armaADesequipar->getDano());

                    // Añade los puntos de resistencia del arma a los puntos de vida de Herz
                    setPuntosVidaMaximos(getPuntosVidaMaximos() + armaAEquipar->getResistencia() - armaADesequipar->getResistencia());
                }else{
                    // Añade los puntos de ataque del arma a los puntos de ataque de Herz
                    setPuntosAtaque(getPuntosAtaque() + armaAEquipar->getDano());

                    // Añade los puntos de resistencia del arma a los puntos de vida de Herz
                    setPuntosVidaMaximos(getPuntosVidaMaximos() + armaAEquipar->getResistencia());
                }

                cout << endl << "Arma equipada" << endl;
            }else{
                throw std::domain_error("El elemento seleccionado no es un arma\n");
            }

            break;
        }
        default:
            cout << "Opcion erronea" << endl;
            break;
    }
}

void Jugador::setArmaEquipada(Espacio* nuevaArmaEquipada){
    armaEquipada = nuevaArmaEquipada;
}

Espacio* Jugador::getArmaEquipada(){
    return armaEquipada;
}


Espacio* Jugador::getItemInventario(int fila, int columna){
    return inventario[fila][columna];
}

tuple<int, int> Jugador::getPosicionDisponibleInventario(){
    tuple<int, int>posicionDisponible;

    for (int fila = 0; fila < 2; fila++) {
        for (int columna = 0; columna < 5; columna++) {
            if(!inventario[fila][columna]->getChecked()){
                get<0>(posicionDisponible) = fila;
                get<1>(posicionDisponible) = columna;
                return posicionDisponible;
            }
        }
    }

    // No encontró ningun lugar disponible
    get<0>(posicionDisponible) = 5;
    get<1>(posicionDisponible) = 5;
    return posicionDisponible;
}

Jugador::~Jugador(){

}