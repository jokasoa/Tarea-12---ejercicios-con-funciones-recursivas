#include <iostream>

// Definición de la función recursiva para imprimir la tabla de multiplicar
void imprimirTabla(int tabla, int limite) {
    // Caso base: si el límite es menor o igual a 0, no hacer nada
    if (limite <= 0) {
        return;
    }

    // Llamada recursiva con el límite decreciente
    imprimirTabla(tabla, limite - 1);

    // Imprimir el resultado de la multiplicación actual
    std::cout << tabla << " x " << limite << " = " << tabla * limite << std::endl;
}

int main() {
    int tabla, limite;

    // Ejemplo de uso
    tabla = 5;
    limite = 10;

    std::cout << "Tabla de multiplicar del " << tabla << " hasta " << limite << ":" << std::endl;
    imprimirTabla(tabla, limite);

    return 0;
}
