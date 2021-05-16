//
// Created by lufe0 on 7/05/2021.
//

#include "View.h"

View::View(){
    setlocale(LC_ALL, "spanish");
    controller = Controller();
}
void View::agregarJugador()
{
    string nombreJugador;
    float dineroPesos;
    long idJugador;
    cout << "Ingrese el nombre del jugador: ";
    cin.ignore(100, '\n');
    getline(cin, nombreJugador);
    // Id del jugador
    do
    {
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
    } while (idJugador < 1);
    // Validacion de los datos del jugador
    do
    {
        cout << "Ingrese el dinero en pesos: ";
        cin >> dineroPesos;
    } while (dineroPesos <= 0);

    // Esta linea de codigo controla la excepcion que lanza el controller y lo muestra en pantalla
    try {
        controller.agregarJugador(idJugador, nombreJugador, dineroPesos);
    } catch (std::domain_error ex) {
        cout << "ERROR: " << ex.what();
    }
}


void View::pedirUsuario(){
    try {
        long idJugador;
        cout << "Ingrese el id del jugador para el que quiere jugar: ";
        cin >> idJugador;
        controller.verInfoJugador(idJugador);

        // LLama a la función que hacer toda la logica de jugar.
        jugarView(idJugador);

    }catch (std::domain_error ex){
        // Se muestra un error si el usuario no existe
        cout << ex.what();
    }
}

void View:: jugarView(long idJugador) {
    int opcion;
    float cantGonzos;
    bool resultado;
    int idJuego;
    do{
        try {
            do {
                cout << "¿Cuantos gonzos desea apostar?: ";
                cin >> cantGonzos;
            } while (cantGonzos <= 0);

            do {
                cout << "¿Que juego desea jugar? (1. Juego mayor a 13, 2. Juego de dos colores, 3. Ruleta): ";
                cin >> idJuego;
            } while (idJuego <= 0);

            resultado = controller.jugar(idJuego, idJugador, cantGonzos);
        } catch (std::domain_error ex){
            cout << ex.what();
        }

        cout << "¿Desea jugar de nuevo? (1. Si, Cualquier número. No): ";
        cin >> opcion;
    }while (opcion == 1);
}

int View::mostrarMenu()
{
    int opcion;
    cout << "Menu\n";
    cout << "1. Agregar jugador " << std::endl;
    cout << "2. Jugar" << std::endl;
    cout << "3. Consultar jugador" << std::endl;
    cout << "4. Retirar jugador" << std::endl;
    cout << "5. Recargar gonzos" << std::endl;
    cout << "0. Salir\n"
         << std::endl;
    cout << "Digita el numero: ";
    cin >> opcion;
    return opcion;
}

void View::verPrincipal()
{
    int opcion;
    do
    {
        opcion = mostrarMenu();
        switch (opcion)
        {
            case 0:
                cout << "Finalizando programa";
                break;
            case 1:
                agregarJugador();
                break;
            case 2:
                pedirUsuario();
                break;
            case 3:
            {
                int id;

                cout << "Id del usuario a mostrar: ";
                cin >> id;

                mostrarJugador(id);
                break;
            }
            case 4:
                retirarJugador();
                break;
            case 5:
            {
                int id;

                cout << "Id del usuario a recargar gonzos: ";
                cin >> id;

                mostrarJugador(id);

                controller.recargarGonzos(id);
                break;
            }
            default:
                cout << "Ingresa una opcion valida\n";
                break;
        }
    } while (opcion != 0);
}

void View::mostrarJugador(long id) {
    // LLama al metodo del controller que muestra los datos
    controller.verInfoJugador(id);
}

void View::retirarJugador() {
    int id;

    cout << "Id del usuario a retirar: ";
    cin >> id;

    controller.retirarJugador(id);
}

