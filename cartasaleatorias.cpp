//Autor:Jeremy novoa
//fecha:19/06/2024
// Diseñe el programa que permita generar 3 cartas aleatorias, con las siguientes consideraciones:
//- Se puede comenzar a jugar, si luego de generar las 3 cartas, las 3 son diferentes, es decir, si salen, por ejemplo dos cartas K de brillo, no se puede continuar. 
//- El jugador gana si la sumatoria de sus cartas es 21. La carta A se la considera como 1, las cartas J, Q, K se las considera como 10.
//- Si al generar las 3 primeras cartas el jugador no ha ganado, tiene la posibilidad de cambiar hasta 2 cartas.
//Se debe preguntar al usuario: Cuántas cartas desea cambiar 1 o 2 ?
//Luego de este cambio se vuelven a sumar y si suman 21 , ya hay ganador. También gana cuando salen 3 cartas iguales. Por ejemplo  A de brillo, A de trébol, A de corazón.
//Después de cada partida, debe preguntar al usuario: Desea seguir Jugando (S/N) ?

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;
struct Carta
{
    int valor;
    string simbolo;
};

void ImprCartas(Carta carta)
{
    string simbolo = carta.simbolo;
    int valor = carta.valor;

    if (valor == 1)
    {
        cout << "╔═════════════╗" << endl;
        cout << "║             ║" << endl;
        cout << "║             ║" << endl;
        cout << "║      A" << simbolo << "     ║" << endl;
        cout << "║             ║" << endl;
        cout << "║             ║" << endl;
        cout << "╚═════════════╝" << endl;
    } else if (valor == 11)
    {
        cout << "╔═════════════╗" << endl;
        cout << "║             ║" << endl;
        cout << "║             ║" << endl;
        cout << "║      J" << simbolo << "     ║" << endl;
        cout << "║             ║" << endl;
        cout << "║             ║" << endl;
        cout << "╚═════════════╝" << endl;
    } else if (valor == 12)
    {
        cout << "╔═════════════╗" << endl;
        cout << "║             ║" << endl;
        cout << "║             ║" << endl;
        cout << "║      Q" << simbolo << "     ║" << endl;
        cout << "║             ║" << endl;
        cout << "║             ║" << endl;
        cout << "╚═════════════╝" << endl;
    } else if (valor == 13)
    {
        cout << "╔═════════════╗" << endl;
        cout << "║             ║" << endl;
        cout << "║             ║" << endl;
        cout << "║      K" << simbolo << "     ║" << endl;
        cout << "║             ║" << endl;
        cout << "║             ║" << endl;
        cout << "╚═════════════╝" << endl;
    } else {
        cout << "╔═════════════╗" << endl;
        cout << "║             ║" << endl;
        cout << "║             ║" << endl;
        cout << "║     " << valor << simbolo << "      ║" << endl;
        cout << "║             ║" << endl;
        cout << "║             ║" << endl;
        cout << "╚═════════════╝" << endl;
    }
}

Carta generarCarta()
{
    Carta carta;
    int valor = rand() % 13 + 1; // Generar valor entre 1 y 13
    int simboloIndex = rand() % 4; // Generar índice de símbolo entre 0 y 3
    string simbolos[] = {"♦", "♠", "♥", "♣"};

    carta.valor = valor;
    carta.simbolo = simbolos[simboloIndex];

    return carta;
}

bool cartasDiferentes(vector<Carta>& cartas)
{
    for (int i = 0; i < cartas.size(); ++i) {
        for (int j = i + 1; j < cartas.size(); ++j)
        {
            if (cartas[i].valor == cartas[j].valor && cartas[i].simbolo == cartas[j].simbolo)
            {
                return false;
            }
        }
    }
    return true;
}

int valorCarta(int valor)
{
    if (valor > 10) return 10;
    return valor;
}

bool sumarCartas(vector<Carta>& cartas)
{
    int suma = 0;
    for (Carta& carta : cartas)
    {
        suma += valorCarta(carta.valor);
    }
    return suma == 21;
}

bool tresCartasIguales(vector<Carta>& cartas)
{
    return cartas[0].valor == cartas[1].valor && cartas[1].valor == cartas[2].valor;
}

void jugar() {
    srand(time(0));
    char seguirJugando = 'S';

    while (seguirJugando == 'S' || seguirJugando == 's') {
        vector<Carta> cartas;

        for (int i = 0; i < 3; ++i) {
            cartas.push_back(generarCarta());
        }

        if (!cartasDiferentes(cartas)) {
            cout << "Las cartas no son diferentes. No se puede continuar." << endl;
        } else {
            cout << "Cartas generadas:" << endl;
            for (Carta& carta : cartas) {
                ImprCartas(carta);
            }

            if (sumarCartas(cartas) || tresCartasIguales(cartas)) {
                cout << "¡Ganaste!" << endl;
            } else {
                int numCambios;
                cout << "¿Cuántas cartas desea cambiar (1 o 2)? ";
                cin >> numCambios;

                for (int i = 0; i < numCambios; ++i) {
                    int indice;
                    cout << "¿Cuál carta desea cambiar (1, 2, 3)? ";
                    cin >> indice;
                    cartas[indice - 1] = generarCarta();
                }

                cout << "Nuevas cartas:" << endl;
                for (Carta& carta : cartas) {
                    ImprCartas(carta);
                }

                if (sumarCartas(cartas) || tresCartasIguales(cartas)) {
                    cout << "¡Ganaste!" << endl;
                } else {
                    cout << "No ganaste." << endl;
                }
            }
        }

        cout << "¿Desea seguir jugando (S/N)? ";
        cin >> seguirJugando;
    }
}

int main() {
    jugar();
    return 0;
}
