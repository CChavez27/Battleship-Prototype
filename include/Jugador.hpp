#pragma once

const int ANCHOTABLERO = 15;
const int ALTURATABLERO = 10;
const char AGUA = 247; //ASCII Character Code
class Jugador {
    char cuadricula[ANCHOTABLERO][ALTURATABLERO];

public:
    void iniciarCuadricula() {
        for (int w = 0; w < ANCHOTABLERO; ++w) {
            for (int h = 0; h < ALTURATABLERO; ++h) {
                cuadricula[w][h] = AGUA;
            }
        }
    }

    char colocarValorCuadricula(int x, int y) const {
        return cuadricula[x][y];
    }

    void colocarValorCuadricula(int x, int y, char value) {
        cuadricula[x][y] = value;
    }
};