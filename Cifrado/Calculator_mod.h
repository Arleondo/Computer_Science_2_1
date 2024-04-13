#include <iostream>
using namespace std;


class CALCULADORA_MOD {

private:

    const int modulo=256;

public:

        [[nodiscard]] int inverso(int  op1) const {
            //Logica detras del inverso
            int U0 = 0, U1 = 1, Un;
            int num2 = op1, num1 = modulo;
            int cociente_o_q, residuo;

            while (num1 > 1) {
                cociente_o_q = num1 / num2;
                residuo = num1 % num2;
                num1 = num2;
                num2 = residuo;
                Un = U0 - cociente_o_q * U1;
                U0 = U1;
                U1 = Un;

                if (residuo == 0) {
                    break;
                }
            }

            if (num1 == 1) {

                if (U0 < 0) {
                    U0 += modulo;
                }
                return U0;

            } else {
                cout << "No se puede calcular el inverso modular para " << op1 << " modulo " << modulo << endl;
                return -1; // Valor el cual es que no existe inverso
            }
        }
};