//Crear calendario que imprima la forma del calendario de windows
#include "Imprimir_calendario.h"

int main (){
    int day,month,year;

    cout<<"Ingresar Fecha\n"<<"Dia:";
    cin>>day;
    cout<<"Mes:";
    cin>>month;
    cout<<"Year:";
    cin>>year;
    cout<<endl;
    
    imprimir_calendario(month,4);
    return 0;
}