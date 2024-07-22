#include <iostream>
#include <string>
using namespace std;

struct Entidad {
    string nombre;
    bool eliminado;
};

void Ronda(Entidad Ent[], int& JoE){
int NewJoE=0;
for (int i=0;i<JoE;i+=2){
        cout<<Ent[i].nombre<<" vs "<<Ent[i + 1].nombre<<endl;    
    }
    cout<<endl;
for (int i=0;i<JoE;i+=2){
    if (!Ent[i].eliminado&&!Ent[i+1].eliminado){
    cout<<Ent[i].nombre<<" vs "<<Ent[i + 1].nombre<<endl;
    string Gan;
    cout<<"Ingrese el nombre del ganador de esta ronda: ";
    cin>>Gan;
    if (Gan==Ent[i].nombre){
        Ent[i+1].eliminado=true;
    } else {
        Ent[i].eliminado=true;
        }
    NewJoE++;
        }
    }
    JoE=NewJoE;
}

void RegistrarJugadores(Entidad Ent[], int Jugadores){
    for (int i=0;i<Jugadores; ++i){
        cout<<"Ingrese el nombre del jugador "<<i+1<<": ";
        cin>>Ent[i].nombre;
        Ent[i].eliminado=false;
    }
    cout << "Registros completos"<<endl;
}

void SistemaSimple(){
    int JoE;
    cout<<"Ingrese el numero de participantes:"<<endl;
    cout<<"Nota: SOlO DISPONIBLES 2, 4, 8, 16, 32..."<<endl;
    cin>>JoE;
    //Verifica en base a binarios
    if ((JoE&(JoE-1))!=0||JoE<2){
        cout<<"Debe ser una potencia de 2 y mayor o igual a 2";
        return;
    }
    Entidad Ent[JoE];
    RegistrarJugadores(Ent, JoE);
    while (JoE>1){
        Ronda(Ent, JoE);
    }
    for (int i=0;i<JoE;++i) {
        if (!Ent[i].eliminado) {
            cout << "El ganador del torneo es: " << Ent[i].nombre << endl;
        }
    }
}
void SistemaDoble(){
}
void SistemaSuizo(){
}

int main(){
    int N, SI=1;
    while (SI==1){
        cout<<"Ingrese una OPCION:"<<endl;
        cout<<"*** 1 -------- REALIZAR TORNEO CON SISTEMA DE ELIMINACION SIMPLE"<<endl;
        cout<<"*** 2 -------- REALIZAR TORNEO CON SISTEMA DE ELIMINACION DOBLE (No disponible)"<<endl;
        cout<<"*** 3 -------- REALIZAR TORNEO CON SISTEMA SUIZO (No disponible)"<<endl;
        cout<<"*** 4 -------- SALIR DEL PROGRAMA"<<endl;
        cin>>N;
        switch (N)
        {
        case 1:
            SistemaSimple();
            break;
        case 2:
            void SistemaDoble();
            break;
        case 3:
            void SistemaSuizo();
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
    return 0;
}