/*
hacer el cocktail_sort el cual son bubble hacia arriba y hacia abajo
void cocktail (int * ini, int * fin)
Hacerlo con arithmetic de punteros
El pare se hace cuando no hay swap o ini>fin
*/
#include <iostream>
using namespace std;

void cocktail (int * ini, int * fin){

    //variable para hacer el cambio de datos
    int temp;
    //chekeador que haya swaps
    int swap_check=1;

    //loop principal
    while (ini<fin) {

        //condicionador para parar
        if (swap_check==0){
            break;
        }
        swap_check = 0;

        //Bubble hacia arriba
        for (int *p=ini ; p < fin ; p++) {

            if (*p > *(p + 1)) {
                temp = *(p + 1);
                *(p + 1) = *p;
                *p = temp;
                swap_check++;
            }

        }
        fin--;

        //condicionador para parar
        if (swap_check==0){
            break;
        }

        swap_check = 0;

        //Bubble hacia abajo
        for (int *p=fin ; p > ini ; p--) {

            if (*p < *(p - 1)) {
                temp = *(p - 1);
                *(p - 1) = *p;
                *p = temp;
                swap_check++;
            }

        }
        ini++;

    }
}

int main(){
    int a []={5,7,3,4,2,10,15,1,
              8,6,14,11,9,13,12};

    //forma de declarar puntero para cualquier array
    int *f = a + size(a) - 1;
    cocktail(a,f);

    //check para que el ordenamiento esté bien hecho
    for (int i : a){
        cout << i << " ";
    }
}