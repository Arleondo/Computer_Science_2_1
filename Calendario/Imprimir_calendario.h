#ifndef CALENDARIO_IMPRIMIR_CALENDARIO_H
#define CALENDARIO_IMPRIMIR_CALENDARIO_H
#include "Imprimir_calendario_tools.h"

// Función para imprimir el calendario
void imprimir_calendario(int Mes,int Dia_inicio) {

    if (Dia_inicio>6||Dia_inicio<0){
        cout<<"Error\n"<<"Dia_inicio no valido";
        return;
    }else if(Mes<0||Mes>12){
        cout<<"Error\n"<<"Mes no valido";
        return;
    }

    string Meses[12] = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SETIEMBRE",
                        "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};

    cout << Meses[Mes - 1] << endl;
    cout << "D\t" << "L\t" << "M\t" << "M\t" << "J\t" << "V\t" << "S\t" << endl;

    int y = 1,x = 1, contador = 0;
    switch (Dia_inicio) {
        case 0:
            break;
        case 1:
            contador = 1;
            loop_cout_tabs(contador);
            break;
        case 2:
            contador = 2;
            loop_cout_tabs(contador);
            break;
        case 3:
            contador = 3;
            loop_cout_tabs(contador);
            break;
        case 4:
            contador = 4;
            loop_cout_tabs(contador);
            break;
        case 5:
            contador = 5;
            loop_cout_tabs(contador);
            break;
        case 6:
            contador = 6;
            loop_cout_tabs(contador);
            break;
        default:
            break;
    }

    while (true) {
        if (x <= 31) {
            for (; contador < 7; contador++) {
                if (x <= 31){
                    cout << x << '\t';
                x++;
                }
                else{
                    break;
                }
            }

            cout << endl;
            contador = 0;
        }
        else{
            break;
        }
    }
}

#endif //CALENDARIO_IMPRIMIR_CALENDARIO_H