//del 1-9999 en numeros romanos
#include <iostream>
#include <string>
using namespace std;

string Convertor_romano(int num) {

    const int valores[] = {9000,8000,7000,6000,5000,4000,1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string sims[] = {"I¯X¯","__\nVMMM","__\nVMM","__\nVM","__\nV","__\nIV","M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string roman_numeral;

    int i = 0;

    while (num > 0) {
        while (num >= valores[i]) {
            roman_numeral += sims[i];
            num -= valores[i];
        }
        i++;
    }
    return roman_numeral;
}

int main() {
    int numero;
    cout << "ingresar numero natural para convertir:";
    cin >> numero;
    string romano = Convertor_romano(numero);
    cout << "Numero natural:\n" << numero << "\nNumero romano:\n" << romano << endl;
    cout<<"x¯"<<"¯";
    return 0;
}