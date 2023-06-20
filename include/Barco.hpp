#pragma once
#include <iostream>
#include<Punto.hpp>

using namespace std;

    struct Barco {
    // Nombre del Barco
    string nombre;
    // Puntos totales en la red
    int largo;
    // Cordenadas de esos puntos
    Punto enCuadricula[5]; // 0-4 longitud máxima del barco más grande
    // Si esos puntos son o no un "golpe"
    bool señaldegolpe[5];
};
