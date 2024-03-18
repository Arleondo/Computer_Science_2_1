#ifndef CALENDARIO_IMPRIMIR_CALENDARIO_H
#define CALENDARIO_IMPRIMIR_CALENDARIO_H
#include "Imprimir_calendario_tools.h"

// Función para imprimir el calendario
void imprimir_calendario(int Mes,int Year,int Dia_inicio) {

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

    if (Mes%2==1||Mes==8){
        Imprimir_mes(31,contador);
    }
    else if (Mes%2==0&&Mes!=2){
        Imprimir_mes(30,contador);
    }
    else if (Mes==2&& !Bisiesto(Year)){
        Imprimir_mes(28,contador);
    }
    else{
        Imprimir_mes(29,contador);
    }
}

#endif //CALENDARIO_IMPRIMIR_CALENDARIO_H