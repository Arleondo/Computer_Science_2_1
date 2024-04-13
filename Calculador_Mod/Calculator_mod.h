#include <iostream>
using namespace std;


class CALCULADORA_MOD {

private:

    int op1 ,op2 ,modulo ,operacion ;

public:

    explicit CALCULADORA_MOD(int operacion){
        this->operacion =operacion;
        if ( operacion==4 ){

            cout << "Op:";
            cin >> op1;
            cout << "Modulo:";
            cin >> modulo;

        } else if ( operacion==1 || operacion==2 || operacion==3 ){

            cout << "Op 1:";
            cin >> op1;
            cout << "Op 2:";
            cin >> op2;
            cout << "Modulo:";
            cin >> modulo;

        } else {

            throw invalid_argument("Argumento invalido para la clase");

        }
    }

    [[nodiscard]] int inverso() const {

        //Logica detras del inverso

        int U0 = 0, U1 = 1, Un ;
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

    void calcular() const {

        cout<<"La respuesta seria:"<<endl;
        int caso=operacion;

        switch (caso){
            case 1:{
                int x = op1 + op2;
                int y = x % modulo;

                if (y <= 0) {
                    y += modulo;
                }

                cout << y << " modulo " << modulo << " = " << y << endl;
                break;

            } case 2: {
                int x = op1 - op2;
                int y = x % modulo;

                if (y < 0) {
                    y += modulo;
                }

                cout << y << " modulo " << modulo << " = " << y << endl;
                break;
            } case 3: {

                int x = op1 * op2;
                int y = x % modulo;

                if (y < 0) {
                    y += modulo;
                }
                cout << y << " modulo " << modulo << " = " << y << endl;

                break;
            } case 4: {

                int inverso_mod = inverso();

                if (inverso_mod != -1) {
                    cout << op1 << " modulo " << modulo << " = " << inverso_mod << endl;
                }

                break;
            }

            default:
                cout << "Operacion no valida" << endl;
        }
    }
};