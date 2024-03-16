//Crear calendario que imprima la forma del calendario de windows
#include "Funtions.h"

int main (){

    imprimir_calendario();
    int dia=16,
        mes=03,
        year=1960;
    string dia_semana = obtener_Dia_Semana(dia,mes,year);
    cout<<dia_semana;
    return 0;
}