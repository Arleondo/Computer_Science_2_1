#include <iostream>
using namespace std;
//Hacer la multiplicacion de matrizes DE 3x3 con punteros

int Multiplicacion_Matrix(int (*M)[3][3]){
    int *r=**(M+2);
    for (int *p=**M ;p<**(M+1) ;p++){
        for (int *q=**(M+1) ;q<**(M+2) ;q++) {
            if(){}
        }
    }
}
}

int main() {
    int a[3][3][3]={{{3,3,3},{3,3,3},{3,3,3}},
                    {{5,5,5},{5,5,5},{5,5,5}},
                    {{0,0,0},{0,0,0},{0,0,0}}};


}