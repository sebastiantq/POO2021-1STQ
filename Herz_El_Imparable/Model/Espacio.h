//
// Created by usuario on 17/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_ESPACIO_H
#define HERZ_EL_IMPARABLE_ESPACIO_H

#include <iostream>
#include <string>
#include <tuple>
#include <cwchar>
#include <clocale>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::tuple;
using std::get;

enum Tipo { ESPACIO, PARED, ENEMIGO, JEFE, JUGADOR, ARMA, POCION, ARTEFACTO_LEGENDARIO };

class Espacio {
    protected:
        tuple <int, int> posicion;
        Tipo tipo;
        bool interactivo;
        char imagen;
        bool checked;
    public:
        Espacio();
        virtual bool interaccion();
        void setPosicion(tuple <int, int>);
        void setTipo(Tipo nuevoTipo);
        void setImagen(char nuevaImagen);
        void setChecked(bool valor);
        tuple<int, int> getPosicion();
        Tipo getTipo();
        char getImagen();
        bool getChecked();
        bool getInteractivo();
        ~Espacio();
};


#endif //HERZ_EL_IMPARABLE_ESPACIO_H
