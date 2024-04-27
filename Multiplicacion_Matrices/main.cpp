#include <iostream>
using namespace std;
//Hacer la multiplicacion de matrizes DE 3x3 con punteros

int Multiplicacion_Matrix(int (*M)[3][3]){

    int *resultado=**(M + 2);

    for (int *ptr_M1=**M ; ptr_M1 < **(M + 1);){
                        //Igual que (*control)[3]=*(M+1)
        for (int *ptr_M2=**(M + 1), *control = (**(M + 1))+3 ; ptr_M2 < **(M + 2) ; ptr_M2++ , resultado++) {

            // Puntero control [3] el cual hace que se resetee resultado y ptr_M1 se sume
            if ( control == ptr_M2 ){
                resultado -= 3;
                control += 3;
                ptr_M1++;
            }
            //La multiplicacion
            *resultado = *resultado + *ptr_M1 * *ptr_M2;
        }
        ptr_M1++;
    }
    return 0;
}

int main() {
    int a[3][3][3]={{{1,2,3},{4,5,6},{7,8,9}},
                    {{9,8,7},{6,5,4},{3,2,1}},
                    {{0,0,0},{0,0,0},{0,0,0}}};
    Multiplicacion_Matrix(a);
    cout << "Matrix A[3] :"<<endl;

    for (int j=0; j<3; j++){
        for (int i=0; i<3; i++){
        cout << a[2][j][i] << "\t";
        }
        cout<<endl;
    }

}