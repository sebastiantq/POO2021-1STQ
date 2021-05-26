//
// Created by usuario on 17/05/2021.
//

#include "Item.h"

Item::Item(){
    setImagen('_');
}

bool Item::interaccion(){
    cout << endl << "Interaccion con item" << endl;
    return false;
}

Item::~Item(){

}