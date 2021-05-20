cmake_minimum_required(VERSION 3.19)
project(Herz_El_Imparable)

set(CMAKE_CXX_STANDARD 20)

add_executable(Herz_El_Imparable main.cpp Controller/Controller.cpp Controller/Controller.h Model/Arma.cpp Model/Arma.h Model/ArtefactoLegendario.cpp Model/ArtefactoLegendario.h Model/Item.cpp Model/Item.h Model/Mazmorra.cpp Model/Mazmorra.h Model/Pocion.cpp Model/Pocion.h View/View.cpp View/View.h Model/Espacio.cpp Model/Espacio.h Model/Jugador.cpp Model/Jugador.h Model/Enemigo.cpp Model/Enemigo.h Model/Pared.cpp Model/Pared.h)