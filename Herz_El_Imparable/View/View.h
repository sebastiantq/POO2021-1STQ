//
// Created by usuario on 17/05/2021.
//

#ifndef HERZ_EL_IMPARABLE_VIEW_H
#define HERZ_EL_IMPARABLE_VIEW_H

#include "../Controller/Controller.h"

class View {
    private:
        Controller controller;
        void nuevaPartida();
        void cargarPartida();
        void guardarPartida();
        void salir();
    public:
        View();
        void desplegarMenuInicial();
        void menuInicial(int opcion);
        void desplegarMenuPausa();
        void menuPausa(int opcion);
        void escucharTeclas();
};


#endif //HERZ_EL_IMPARABLE_VIEW_H
