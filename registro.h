#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>

using namespace std;

struct Entidad {
    string nombre;
    bool eliminado;
    int perdidas;
};

struct Simple {
    string jugador;
    bool eliminado;
};

struct Doble {
    string jugador;
    bool eliminado;
    int perdidas;
};

extern Doble jugadores[64];

struct Persona {
    string NOMBRE;
    string APELLIDO;
    int EDAD;
    int DNI;
    int CELULAR;
};

extern Simple TS[64];
extern Persona DT[64];

// Funciones
int ValidaEntero();
void Registrar(int &Cupo, int &Jugadores);
void LeerDatos();
void EliminarRegistro();
int SistemaSimple();
int SistemaDoble();
int Ronda(Persona JActivos[], int &PActivos); // Declaración de Ronda
void RondaDoble(Doble* participantes, int& numParticipantes, bool esRondaPerdedores = false);
void Barajar(Persona JActivos[], int PActivos); //Barajea

void SistemaDoble2();
void RondaDoble2(Entidad Ent[], int& JoE, bool cuadroPerdedores = false);
void RegistrarJugadores(Entidad Ent[], int Jugadores);


#endif // REGISTRO_H