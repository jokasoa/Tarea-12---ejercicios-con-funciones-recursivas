#include <iostream>

// Definición de la función recursiva para contar las cifras de un número
int contarCifras(int numero) {
    // Caso base: si el número es 0, el número tiene 0 cifras (o 1 cifra si se considera el número 0 como válido)
    if (numero == 0) {
        return 0;
    }

    // Caso recursivo: dividir el número por 10 y sumar 1
    return 1 + contarCifras(numero / 10);
}

int main() {
    int numero;

    // Ejemplo de uso
    numero = 12345;

    int totalCifras = contarCifras(numero);
    std::cout << "El número " << numero << " tiene " << totalCifras << " cifras." << std::endl;

    return 0;
}
