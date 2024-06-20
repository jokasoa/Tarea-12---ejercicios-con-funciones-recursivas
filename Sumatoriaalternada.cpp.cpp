#include <iostream>

// Definición de la función recursiva
int sumatoriaAlternada(int n) {
    if (n == 1) {
        return 1; // Caso base: el primer término es 1
    } else {
        if (n % 2 == 0) {
            return -n + sumatoriaAlternada(n - 1); // Restar si el número es par
        } else {
            return n + sumatoriaAlternada(n - 1); // Sumar si el número es impar
        }
    }
}

int main() {
    int n;

    // Ejemplo de uso
    n = 7;
    std::cout << "La sumatoria alternada hasta " << n << " es: " << sumatoriaAlternada(n) << std::endl;

    return 0;
}
