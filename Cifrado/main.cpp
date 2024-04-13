#include <fstream>
#include <string>
#include "Calculator_mod.h"

void cifrador(const std::string& textoOriginal, int op1) {
    std::ofstream FileCifrado("Cripta.txt");
    for (char c : textoOriginal) {
        char n_char = (c - 2*op1) % 256;
        FileCifrado << n_char;
    }
    FileCifrado.close();
}

void descifrarTexto(int op1) {
    ifstream FileCifrado("Cripta.txt");
    ofstream FileDescifrado("Salida.txt");
    char caracter;

    while (FileCifrado.get(caracter)) {
        char original_caracter = caracter - op1;
        FileDescifrado << original_caracter;
    }
    FileDescifrado.close();
}

int main() {
    int opcion, Publickey;
    int modulo = 256;

    char continuar;
    bool check = false;

    cout << "ENCRIPTER/DE-ENCRIPTER services by Arnol. Usar solo en caso de apuros :)\n";

    while (!check) {

        cout << "Choose an option:\n";
        cout << "1. Encriptar\n";
        cout << "2. Desencriptar\n";
        cin >> opcion;

        if (opcion == 1) {
            //lectura del archivo
            ifstream archivoEntrada("Entrada.txt");
            if (!archivoEntrada) {
                cout << "Error al abrir el archivo de entrada." << endl;
                return 1;
            }

            // Lee el archivo entero
            string textoOriginal;
            getline(archivoEntrada, textoOriginal);

            cout << "Ingrese el número para calcular su inverso modular (clave pública): ";
            cin >> Publickey;

            CALCULADORA_MOD calculadora;

            // Obtener el inverso modular de la clave con el modulo const
            int inverso = calculadora.inverso(Publickey);

            if (inverso == -1) {
                cout << "El número " << Publickey << " no tiene inverso modular respecto a " << modulo << ". Intente con otro número." << endl;
            } else {
                cout << "Clave Publica: " << Publickey << " Clave privada es: " << inverso << endl;

                // Cifrar el texto original y guardar en archivo Cripta
                cifrador(textoOriginal, inverso);
                cout << "Texto encriptado correctamente.\n";
            }

            archivoEntrada.close();

        } else if (opcion == 2) {
            // Desencriptar el archivo cifrado.txt
            int PrivateKey;
            cout << "Ingrese la clave privada (inverso modular) para desencriptar:";
            cin >> PrivateKey;

            // Descifrar el texto en cifrado.txt y guardar en archivo descifrado.txt
            descifrarTexto(PrivateKey);
            cout << "Texto desencriptado ENJOY :0\n";
        } else {
            for (int i=0;i<1000;i++) {
                cout << "DESOBEDECISTE MANITO AHORA TENES VIRUS :) LOLOLOLOLOLOLOLOLOLOLOLOLOLOLOLOLOLOLOLOLOLOLOLOLOLOLOLOL" << endl;
            }
            return 0;
            //sería un puntero que va modificando directions de memoria pero muy peligroso para mi laptop :/
        }

        //zona de repetition
        cout << "CONTINUAR? (Y/N):";
        cin >> continuar;

        if (continuar == 'Y' || continuar == 'y') {
            continue;
        } else {
            check= true;
        }
    }

    cout << "Gracias Por usar ENCRIPTER/DE-ENCRIPTER services by Arnol , have a good day :) ";

    return 0;
}