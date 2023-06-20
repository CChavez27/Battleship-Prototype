#pragma once
#include <Barco.hpp>
#include <ColocarBarcos.hpp>
#include <Jugador.hpp>

const int TIPOSDEBARCOS = 5;
const char GOLPE = 'X';
const char BARCO = 'S';
const char FALLAR = '0';

class JuegoBattleship {
    Barco buque[TIPOSDEBARCOS];
    Jugador jugadores[3]; // Ignore player 0, just using players 1 & 2
    bool Juegoiniciado;

public:
    JuegoBattleship() {
        Juegoiniciado = false;
    }

    void cargandoBarcos() {
        // Establece los datos predeterminados para los barcos
        // planeamos incluir en el juego
        // ¡¡IMPORTANTE!! > DEBE COINCIDIR CON TIPOSDEBARCOS -Predeterminado=5 (0-4)
        buque[0] = { "Lancha", 2 };
        buque[1] = { "Crucero", 3 };
        buque[2] = { "Submarino", 3 };
        buque[3] = { "Buque", 4 };
        buque[4] = { "Portaaviones", 5 };
    }

    void reiniciarTablero(Jugador& jugador) {
        jugador.iniciarCuadricula();
    }

    void dibujoDelTablero(const Jugador& jugador) {
        cout << "TABLERO DE JUEGO DEL JUGADOR\n";
        cout << "----------------------\n";

        cout << "   ";
        for (int w = 0; w < ANCHOTABLERO; ++w) {
            if (w < 10)
                cout << w << "  ";
            else if (w >= 10)
                cout << w << " ";
        }
        cout << "\n";

        for (int h = 0; h < ALTURATABLERO; ++h) {
            for (int w = 0; w < ANCHOTABLERO; ++w) {
                if (w == 0) cout << h << " ";
                if (w < 10 && w == 0) cout << " ";

                char gridValue = jugador.colocarValorCuadricula(w, h);
                if (Juegoiniciado == false)
                    cout << gridValue << "  ";
                else if (Juegoiniciado == true && gridValue != BARCO)
                    cout << gridValue << "  ";
                else if (Juegoiniciado == true && gridValue == BARCO)
                    cout << AGUA << "  ";

                if (w == ANCHOTABLERO - 1) cout << "\n";
            }
        }
    }

    void colocacionDelBarcoPorelUsuario(ColocarBarcos& posicionBarco) {
        int d, x, y;
        cin >> d >> x >> y;
        posicionBarco.direccion = static_cast<Direccion>(d);
        posicionBarco.TipoDeBarco.enCuadricula[0] = { x, y };
    }

    bool LugarValidoBarco(const ColocarBarcos& posicionBarco) {
        const int x = posicionBarco.TipoDeBarco.enCuadricula[0].x;
        const int y = posicionBarco.TipoDeBarco.enCuadricula[0].y;
        const int alturabarco = posicionBarco.TipoDeBarco.largo;
        const Direccion direccion = posicionBarco.direccion;

        if (direccion != HORIZONTAL && direccion != VERTICAL)
            return false;

        if (x < 0 || x >= ANCHOTABLERO || y < 0 || y >= ALTURATABLERO)
            return false;

        if (direccion == HORIZONTAL && (x + alturabarco) > ANCHOTABLERO)
            return false;

        if (direccion == VERTICAL && (y + alturabarco) > ALTURATABLERO)
            return false;

        return true;
    }

    void lugarDelBarcoEnElTablero(Jugador& jugador, const ColocarBarcos& posicionBarco) {
        const int x = posicionBarco.TipoDeBarco.enCuadricula[0].x;
        const int y = posicionBarco.TipoDeBarco.enCuadricula[0].y;
        const int alturabarco = posicionBarco.TipoDeBarco.largo;
        const Direccion direccion = posicionBarco.direccion;

        jugador.colocarValorCuadricula(x, y, BARCO);

        for (int i = 1; i < alturabarco; ++i) {
            if (direccion == HORIZONTAL)
                jugador.colocarValorCuadricula(x + i, y, BARCO);
            if (direccion == VERTICAL)
                jugador.colocarValorCuadricula(x, y + i, BARCO);
        }
    }
            bool UserInputAttack(int&,int&,int);
            bool GameOverCheck(int);
    void jugar() {
        cargandoBarcos();
        reiniciarTablero(jugadores[1]);
        reiniciarTablero(jugadores[2]);
        

        for (int aplicar = 1; aplicar < 3; ++aplicar) {
            for (int esteBarco = 0; esteBarco < TIPOSDEBARCOS; ++esteBarco) {
                system("cls");
                dibujoDelTablero(jugadores[aplicar]);
                cout << "\n";
                cout << "INSTRUCTIONES (JUGADOR " << aplicar << ")\n\n";
                cout << "Estas a punto de colocar tus barcos. El formato debe ser:\n";
                cout << "Orientación (0:Horizontal,1:Vertical), coordenadas X (fila arriba), coordenadas Y (lado izquierdo)\n";
                cout << "Ejemplo: 0 7 2 Esto colocaria un barco comenzando en X:7 Y:2 yendo horizontal\n\n";
                cout << "Coloca la posicion de: " << buque[esteBarco].nombre << " que tiene una longitud de " << buque[esteBarco].largo << "\n";
                cout << "¿Donde quieres que se coloque? ";

                ColocarBarcos lugarDelBarco;
                colocacionDelBarcoPorelUsuario(lugarDelBarco);

                while (!LugarValidoBarco(lugarDelBarco)) {
                    cout << "Colocacion invalida, intentalo de nuevo: ";
                    colocacionDelBarcoPorelUsuario(lugarDelBarco);
                }

                lugarDelBarco.TipoDeBarco.largo = buque[esteBarco].largo;
                lugarDelBarco.TipoDeBarco.nombre = buque[esteBarco].nombre;

                lugarDelBarcoEnElTablero(jugadores[aplicar], lugarDelBarco);
            }
        }
        bool UserInputAttack(int&,int&,int);
        bool GameOverCheck(int);
        Juegoiniciado = true;
        int elJugador = 1;
        do {
            int jugadorEnemigo = (elJugador == 1) ? 2 : 1;
            system("cls");
            dibujoDelTablero(jugadores[jugadorEnemigo]);

            bool buentiro = false;
            int x, y;
            while (!buentiro) {
                buentiro = UserInputAttack(x, y, elJugador);
            }

            if (jugadores[jugadorEnemigo].colocarValorCuadricula(x, y) == BARCO)
                jugadores[jugadorEnemigo].colocarValorCuadricula(x, y, GOLPE);
            if (jugadores[jugadorEnemigo].colocarValorCuadricula(x, y) == AGUA)
                jugadores[jugadorEnemigo].colocarValorCuadricula(x, y, FALLAR);

            int ganador = GameOverCheck(jugadorEnemigo);
            if (ganador != 0) {
                Juegoiniciado = false;
                break;
            }

            elJugador = (elJugador == 1) ? 2 : 1;
        } while (Juegoiniciado);

        system("cls");
        cout << "\n\nFelicitaciones!!!  jugador " << elJugador << " ha ganado el combate!\n\n\n\n";

        system("pause");
    }
};
