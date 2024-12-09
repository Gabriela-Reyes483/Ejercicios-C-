#include <iostream>
#include <string>
using namespace std;

// Clase para representar un empleado
class Empleado {
    // Atributos privados de la clase Empleado
    private:
        string nombre;
        string apellidoPaterno;
        string apellidoMaterno;
        string fechaNacimiento; 

    // Métodos y atributos públicos
    public:
        // Constructor
        //Asignamos los valores de los atributos a partir de los parámetros recibidos
        Empleado(string nombre, string apellidoPaterno, string apellidoMaterno, string fechaNacimiento)
        {
            this->nombre = nombre;
            this->apellidoPaterno = apellidoPaterno;
            this->apellidoMaterno = apellidoMaterno;
            this->fechaNacimiento = fechaNacimiento;
        }

        // Método para calcular el RFC
        string calcularRFC() const {
            //validar que los atributos no estén vacíos
            if (nombre.empty() || apellidoPaterno.empty() || fechaNacimiento.empty()) {
                return "No se puede calcular el RFC, faltan datos obligatorios.";
            }

            string rfc;

            // 1. Primera letra del apellido paterno
            if (!apellidoPaterno.empty()) {
                rfc += toupper(apellidoPaterno[0]);
            }

            // 2. Primera vocal interna del apellido paterno
            bool vocalEncontrada = false;
            // Recorrer el apellido paterno desde la segunda letra
            for (size_t i = 1; i < apellidoPaterno.size(); ++i) {
                char c = toupper(apellidoPaterno[i]);
                // Verificar si la letra es una vocal
                if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    rfc += c;
                    vocalEncontrada = true;
                    break;
                }
            }
            if (!vocalEncontrada) {
                // Si no se encontró vocal, se agrega una 'X'
                rfc += 'X'; 
            }

            // 3. Primera letra del apellido materno
            if (!apellidoMaterno.empty()) {
                rfc += toupper(apellidoMaterno[0]);
            } else {
                // Si no hay apellido materno, se agrega una 'X'
                rfc += 'X'; 
            }

            // 4. Primera letra del nombre
            if (!nombre.empty()) {
                rfc += toupper(nombre[0]);
            }

            // 5. Agregar la fecha de nacimiento (AAMMDD)
            if (fechaNacimiento.size() == 8) {
                rfc += fechaNacimiento.substr(2); // Tomar AAMMDD
            }

            // 6. Agregar la homoclave (RFC genérico)
            rfc += "XXX";

            return rfc;
        }
};

string convertirFechaNacimiento(const string& fecha) {
    // Convertir fecha de formato DD/MM/AAAA a AAAAMMDD
    if (fecha.size() == 10 && fecha[2] == '/' && fecha[5] == '/') {
        string dia = fecha.substr(0, 2);
        string mes = fecha.substr(3, 2);
        string anio = fecha.substr(6, 4);
        return anio + mes + dia;
    }
    return ""; // Retornar vacío si el formato no es válido
}

int main() {
    string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;

    // Solicitar datos al usuario
    cout << "Introduce el nombre (Obligatorio): ";
    getline(cin, nombre);
    cout << "Introduce el apellido paterno (Obligatorio): ";
    getline(cin, apellidoPaterno);
    cout << "Introduce el apellido materno: ";
    getline(cin, apellidoMaterno);
    cout << "Introduce la fecha de nacimiento (DD/MM/AAAA) (Obligatirio)): ";
    getline(cin, fechaNacimiento);

    // Convertir la fecha de nacimiento al formato AAAAMMDD
    string fechaFormateada = convertirFechaNacimiento(fechaNacimiento);
    //Si la fecha de nacimiento no es válida, mostrar un mensaje de error y terminar el programa
    if (fechaFormateada.empty()) {
        cerr << "Error: El formato de la fecha de nacimiento es incorrecto." << endl;
        return 1;
    }

    // Crear objeto Empleado
    Empleado persona(nombre, apellidoPaterno, apellidoMaterno, fechaFormateada);

    // Calcular y mostrar el RFC
    cout << "El RFC calculado es: " << persona.calcularRFC() << endl;

    return 0;
}
