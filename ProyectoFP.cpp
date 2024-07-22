#include <iostream>
#include <string>
using namespace std;

void SistemaSimple(){
}
void SistemaDoble(){
}
void SistemaSuizo(){
}

int main(){
    int N, SI=1;
    cout<<"Ingrese una OPCION:"<<endl;
    cout<<"*** 1 -------- REALIZAR TORNEO CON SISTEMA DE ELIMINACION SIMPLE"<<endl;
    cout<<"*** 2 -------- REALIZAR TORNEO CON SISTEMA DE ELIMINACION DOBLE (No disponible)"<<endl;
    cout<<"*** 3 -------- REALIZAR TORNEO CON SISTEMA SUIZO (No disponible)"<<endl;
    cout<<"*** 4 -------- SALIR DEL PROGRAMA"<<endl;
    cin>>N;
    while (SI=1)
    {
        switch (N)
        {
        case 1:
            void SistemaSimple();
            break;
        case 2:
            void SistemaDoble();
            break;
        case 3:
            void SistemaSuizo();
            break;
        case 4:
            cout<<"SALIENDO DEL PROGRAMA";
            --SI;
            break;
        default:
            cout<<"VALOR NO IDENTIFICADO";
            break;
        }    
    }
    
}