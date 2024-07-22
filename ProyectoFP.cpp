#include <iostream>
using namespace std;

struct Entidad {
    string nombre;
    bool eliminado;
};

void Partida(){

}

void RegistrarJugadores(){

}

void SistemaSimple(){
    int JoE;
    cout<<"Ingrese el numero de participantes:"<<endl;
    cout<<"Nota: SOlO DISPONIBLES 2, 4, 8, 16, 32..."<<endl;
    cin>>JoE;
    if ((JoE&(JoE-1))!=0||JoE<2){
        cout<<"Debe ser una potencia de 2 y mayor o igual a 2";
    }    
    Entidad Ent[JoE];
    for (int R=0;R<JoE-1; R++) {
        cout<<"Ronda "<<R+1<<endl;
        for (int i=0;i<JoE-1-R;i+=2){
            Partida();
        }

    } 
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
            cout<<"Este sistema aun no esta disponible";
            break;
        case 3:
            cout<<"Este sistema aun no esta disponible";
            break;
        case 4:
            cout<<"SALIENDO DEL PROGRAMA";
            SI--;
            break;
        default:
            cout<<"VALOR NO IDENTIFICADO";
            break;
        }    
    }
    
}