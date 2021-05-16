//
// Created by lufe0 on 7/05/2021.
//

#include "Controller.h"
#include "../Model/Mayor13.h"
#include "../Model/DosColores.h"
#include "../Model/Ruleta.h"

Controller::Controller() {
  this->casino = Casino();
  // Se agregan los juegos disponibles para el casino
  Mayor13 * juego1 = new Mayor13();
  DosColores * juego2 = new DosColores();
  Ruleta * juego3 = new Ruleta();
  casino.agregarJuego(juego1);
  casino.agregarJuego(juego2);
  casino.agregarJuego(juego3);
}
void Controller::agregarJugador(long id, string nombreJugador, double dinero)
{
    // Se agrega jugador solo si no existe con anticipacion
    if (!casino.verExisteJugador(id)){
        // Se convierte el dinero a Gonzos
        float cantGonzos = casino.convertirPesosAGonzos(dinero);
        Jugador * pJugador = new Jugador (id, nombreJugador, cantGonzos);
        casino.agregarJugador(pJugador);

    }else {
        throw std::domain_error("El jugador con la identificacion recibida ya existe\n");
    }
}

bool Controller::jugar(int idJuego, long idJugador, float gonzosApostar) {
    if (!casino.verExisteJugador(idJugador)){
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    if (idJuego > casino.consultarJuegos().size()){
        throw std::domain_error("NO existe el juego que desea jugar\n");
    }
    if (gonzosApostar > casino.consultarJugador(idJugador)->getCantGonzos()){
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }
    // Si no hay errores se inicia el juego
    int posJuego = idJuego - 1; // Se corrige la posicion para acceder al juego
    float gonzosResultado;
    Juego * pJuegoAJugar = casino.consultarJuegos().at(posJuego);

    // Consutlta al jugador, consulta los gonzos iniciales, juega y obtiene el resultado
    // ¿Para que consultar gonzos y jugador?

    gonzosResultado = pJuegoAJugar->jugar(gonzosApostar);

    if(gonzosResultado > gonzosApostar){
        cout << "Felicidades, ha ganado " << gonzosResultado - gonzosApostar << " gonzos\n";
        cout << "Estos serían $" << casino.convertirGonzosPesos(gonzosResultado - gonzosApostar) << " pesos\n";
    }else if(gonzosResultado < gonzosApostar){
        cout << "Lo sentimos, ha perdido " << gonzosApostar - gonzosResultado << " gonzos\n";
        cout << "Estos serían $" << casino.convertirGonzosPesos(gonzosResultado - gonzosApostar) << " pesos\n";
    }else{
        cout << "Vaya, no ganas ni pierdes\n";
    }

    casino.consultarJugador(idJugador)->actualizarGonzos(gonzosResultado - gonzosApostar); // Actualiza el saldo del jugador con el resultado

    casino.consultarJugador(idJugador)->aumentarJuegos();

    // Retorna verdadero si el jugador ganó y false si el jugador perdio
    // ¿Que retorna si no pierde ni gana?
    if(gonzosResultado > gonzosApostar){
        return true;
    }else{
        return false;
    }
}

void Controller::verInfoJugador(long idJugador){
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (!casino.verExisteJugador(idJugador)){
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    Jugador * pJugador = casino.consultarJugador(idJugador);
    pJugador->mostrarInfo();
}

bool Controller::verPuedeContinuar(int idJugador) { // Personalmente creo que no es necesaria la función
                                                    // Además tiene un fallo de seguridad, no puede comprobar si
                                                    // la cantidad de gonzos a apostar es menor a la disponible
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (!casino.verExisteJugador(idJugador)) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe");
    }
    Jugador *pJugador = casino.consultarJugador(idJugador);
    if (pJugador->getCantGonzos() <= 0) {
        return false;
    }
    return true;
}

void Controller::retirarJugador(long idJugador) {
    if(!casino.verExisteJugador(idJugador)) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }

    verInfoJugador(idJugador);
    casino.retirarJugador(idJugador);
}

void Controller::recargarGonzos(long idJugador) {
    float cantidad;
    int probabilidadPremio;

    srand(time(NULL));

    if(!casino.verExisteJugador(idJugador)) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }

    do {
        cout << "¿Cuanto dinero en pesos desea recargar?: ";
        cin >> cantidad;
    } while (cantidad <= 0);

    // para calcular numero aleatorio variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    probabilidadPremio = 1 + rand() % 10; // numeros de 1 a 13

    if(probabilidadPremio > 5){
        cantidad *= 2;
        cout << "Felicidades, has ganado el doble de gonzos gracias a nuestra ruleta de la suerte, ponle 5 a todos los estudiantes y verás como te suben el sueldo\n";
    }

    casino.consultarJugador(idJugador)->actualizarGonzos(casino.convertirPesosAGonzos(cantidad));

    cout << "Se han agregado " << casino.convertirPesosAGonzos(cantidad) << " gonzos a su cuenta\n";
}