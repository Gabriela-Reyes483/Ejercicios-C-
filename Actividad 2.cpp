#include <iostream> // Librería para entrada y salida estándar

using namespace std;

    //Funcion para realizar la division
void realizarDivision(double numero1, double numero2) {
    if (numero2 != 0) {
        double division = numero1 / numero2;
        cout << "La división es: " << division << endl;
    } else {
        cout << "La división no es posible, ya que no se puede dividir por 0." << endl;
    }
}

int main() {
    // Declaramos dos variables de tipo 'double' para permitir números decimales
    double numero1, numero2;

    // Se pide al usuario que ingrese el primer número
    cout << "Ingresa el primer número: ";
    cin >> numero1;

    // Se pide al usuario que ingrese el segundo número
    cout << "Ingresa el segundo número: ";
    cin >> numero2;

    // Realizamos las operaciones
    double suma = numero1 + numero2;
    double resta = numero1 - numero2;
    double multiplicacion = numero1 * numero2;

    // Mostramos los resultados en la consola
    cout << "La suma es: " << suma << endl;
    cout << "La resta es: " << resta << endl;
    cout << "La multiplicación es: " << multiplicacion << endl;

    realizarDivision(numero1,numero2);
    
    return 0; 
}
