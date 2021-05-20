//
// Created by usuario on 17/05/2021.
//

#include "View.h"

View::View() {
    controller = Controller();
}

void View::nuevaPartida(){
    int dificultad;

    do{
        cout << endl << "-- Dificultad --" << endl << endl;
        cout << "1. Facil" << endl;
        cout << "2. Normal" << endl;
        cout << "0. Atras" << endl << endl;

        cout << "Opcion: ";
        cin >> dificultad;
    } while (dificultad != 0 && dificultad != 1 && dificultad != 2);

    switch (dificultad) {
        case 0:
            desplegarMenuInicial();
            break;
        case 1:
            controller.inicializarMazmorra(FACIL);
            escucharTeclas();

            if(controller.getEstadoJuego() == PAUSA){
                desplegarMenuPausa();
            }
            break;
        case 2:
            controller.inicializarMazmorra(NORMAL);
            escucharTeclas();

            if(controller.getEstadoJuego() == PAUSA){
                desplegarMenuPausa();
            }
            break;
        default:
            cout << endl << "Opcion erronea" << endl;
            nuevaPartida();
            break;
    }
}

void View::cargarPartida(){
    cout << endl << "Opcion disponible en una proxima actualizacion" << endl;
}

void View::guardarPartida(){
    cout << endl << "Opcion disponible en una proxima actualizacion" << endl;
}

void View::salir(){
    int guardar;

    do {
        cout << endl << "¿Desea guardar los cambios antes de salir? (0. No, 1. Si): ";
        cin >> guardar;
    }while(guardar != 0 && guardar != 1);

    switch (guardar) {
        case 0:
            break;
        case 1:
            guardarPartida();
            break;
        default:
            cout << endl << "Opcion erronea" << endl;
            break;
    }

    exit(0);
}

void View::desplegarMenuInicial(){
    int opcion;

    controller.setEstadoJuego(MENU_PRINCIPAL);

    do{
        cout << endl << "-- Menu principal --" << endl << endl;
        cout << "1. Nueva partida" << endl;
        cout << "2. Cargar partida" << endl;
        cout << "0. Salir" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        menuInicial(opcion);
    } while (opcion != 0);
}

void View::menuInicial(int opcion){
    switch (opcion) {
        case 0:
            salir();
            break;
        case 1:
            nuevaPartida();
            break;
        case 2:
            cargarPartida();
            break;
        default:
            cout << endl << "Opcion erronea" << endl ;
            break;
    }
}

void View::desplegarMenuPausa() {
    int opcion;

    controller.setEstadoJuego(PAUSA);

    do{
        cout << endl << "-- Menu pausa --" << endl << endl;
        cout << "1. Continuar" << endl;
        cout << "2. Menu principal" << endl;
        cout << "3. Guardar partida" << endl;
        cout << "0. Salir" << endl << endl;

        cout << "Opcion: ";
        cin >> opcion;

        menuPausa(opcion);
    } while (opcion != 1);
}

void View::menuPausa(int opcion){
    switch (opcion) {
        case 0:
            salir();
            break;
        case 1:
            controller.setEstadoJuego(JUGANDO);
            break;
        case 2:
            desplegarMenuInicial();
            break;
        case 3:
            guardarPartida();
            break;
        default:
            cout << endl << "Opcion erronea" << endl ;
            break;
    }
}

void View::escucharTeclas(){
    char teclaPresionada;

    do {
        teclaPresionada = getch();

        if (teclaPresionada == 0){
            teclaPresionada = getch();
        }else {
            switch (teclaPresionada) {
                case 9:
                    // TAB
                    break;
                case 13:
                    // ENTER
                    break;
                case 27:
                    // ESC
                    cout << endl << "ESCAPE" << endl;
                    desplegarMenuPausa();
                    controller.mostrarMazmorra(0);
                    break;
                case 'H':
                    // ARRIBA
                    cout << endl << "ARRIBA" << endl;
                    controller.teclaArriba();
                    controller.mostrarMazmorra(0);
                    break;
                case 'K':
                    // IZQUIERDA
                    cout << endl << "IZQUIERDA" << endl;
                    controller.teclaIzquierda();
                    controller.mostrarMazmorra(0);
                    break;
                case 'M':
                    // DERECHA
                    cout << endl << "DERECHA" << endl;
                    controller.teclaDerecha();
                    controller.mostrarMazmorra(0);
                    break;
                case 'P':
                    // ABAJO
                    cout << endl << "ABAJO" << endl;
                    controller.teclaAbajo();
                    controller.mostrarMazmorra(0);
                    break;
            }
        }
    } while (controller.getEstadoJuego() == JUGANDO);
}
