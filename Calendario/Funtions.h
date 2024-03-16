#ifndef CALENDARIO_FUNTIONS_H
#define CALENDARIO_FUNTIONS_H
#include <iostream>
#include <ctime>
using namespace std;

// Función para imprimir el calendario

void imprimir_calendario(){
    cout<<"D\t"<<"L\t"<<"M\t"<<"M\t"<<"J\t"<<"V\t"<<"S\t"<<endl;
    int y=1;
    for (;y<5;y++) {
        int x=1;
        for (; x < 8; x++) {
            cout << x <<"\t";
        }
        cout << endl;
    }
}
 string obtener_Dia_Semana(int day, int month, int year) {
    // Crear una estructura tm con la fecha proporcionada
    tm fecha = {};
    fecha.tm_year = year - 1900; // Ajusta el año
    fecha.tm_mon = month - 1;      // Ajusta el mes
    fecha.tm_mday = day ;

    mktime(&fecha);

    const string dias_Semana[] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

    return dias_Semana[fecha.tm_wday];
}


#endif //CALENDARIO_FUNTIONS_H
