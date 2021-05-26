//
// Created by usuario on 17/05/2021.
//

#include "ArtefactoLegendario.h"

ArtefactoLegendario::ArtefactoLegendario(){
    setImagen('A');
    setTipo(ARTEFACTO_LEGENDARIO);
    interactivo = true;
    checked = true;
}

bool ArtefactoLegendario::interaccion(){
    cout << "¡Lo has logrado! Escapa por la nueva puerta que se ha generado para regresar a salvar a tu pueblo";

    return true;
}

ArtefactoLegendario::~ArtefactoLegendario(){

}