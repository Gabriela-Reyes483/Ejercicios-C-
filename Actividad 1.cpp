#include <iostream> // Librería para manejar entrada y salida estándar

/*Utilizamos el namespace para evitar escribir std:: cada vez
que queramos utilizar una función de la librería estándar de C++ */
using namespace std; 

// Función principal del programa
int main() {
    int edad; // Aqui almacenamos la edad

    // Se pide al usuario que ingrese su edad
    cout << "Por favor, ingrese su edad: ";
    cin >> edad; // Se lee el valor ingresado por el usuario

    // Condición para determinar si la persona es mayor o menor de edad
    if (edad >= 18) {
        // Si tiene 18 o más años, se muestra este mensaje
        cout << "Eres mayor de edad." << endl; 
    } else {
        // Si tiene menos de 18 años, se muestra este mensaje
        cout << "Eres menor de edad." << endl; 
    }

    // Regresar 0 indica que el programa finalizó correctamente
    return 0; 
}