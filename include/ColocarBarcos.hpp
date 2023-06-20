#pragma once
#include <iostream>
#include<Barco.hpp>

enum Direccion { HORIZONTAL, VERTICAL };
struct ColocarBarcos {
    Direccion direccion;
    Barco TipoDeBarco;
};
