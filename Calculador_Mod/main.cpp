//Hacer operaciones de modulo en funciones
#include "Calculator_mod.h"


int main() {

    int x;

    cout << "CALCULADORA MODULAR" << endl;
    cout << "Operaciones:\n1) + suma\n2) - resta\n3) * multiplicacion\n4) ^ (inverso))\nIngresar operacion:";
    cin >> x;
    CALCULADORA_MOD Op(x);
    if (x == 4) {
        int inv=Op.inverso();
            if (inv!=-1){
                Op.calcular();
            }
    }else {
        Op.calcular();
    }

}