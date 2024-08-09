#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>

using namespace std;

struct Simple {
    string jugador;
    bool eliminado;
};

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
void SistemaSimple();
void SistemaDoble();

#endif // REGISTRO_H