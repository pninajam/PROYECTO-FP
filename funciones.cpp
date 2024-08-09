#include <iostream>
#include <string>
#include "registro.h"
#include <limits>

using namespace std;

Simple TS[64];
Persona DT[64];

// Validación
int ValidaEntero() {
    int Ent;
    while (true) {
        cin >> Ent;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no válida. Por favor, ingrese un número entero." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return Ent;
        }
    }
}

// Función para registrar jugadores en sistema simple
void Registrar(int &Cupo, int &Jugadores) {
	system("cls");
    if (Cupo >= 64) {
    	cout << "---------------------------------------------------" << endl;
        cout << "El registro está lleno. No se pueden agregar más jugadores." << endl;
        return;
    }

    while (Cupo < 64 && Jugadores > 0) {
        cout << "Ingrese el nombre del jugador " << Cupo + 1 << ": " << endl;
        cout << "---------------------------------------------------" << endl;
        cin >> DT[Cupo].NOMBRE;

        // Ingresar más datos?
        cout << "---------------------------------------------------" << endl;
        cout << "Desea ingresar mas datos para este jugador?" << endl;
        cout << "Pulse 1 para: SI" << endl;
        cout << "Pulse otro numero para: NO" << endl;
        cout << "---------------------------------------------------" << endl;

        int ingresarDatos = ValidaEntero();
        if (ingresarDatos == 1) {
            cout << "---------------------------------------------------" << endl;
            cout << "Ingrese el apellido del jugador: " << endl;
            cin >> DT[Cupo].APELLIDO;

            cout << "Ingrese la edad del jugador: " << endl;
            DT[Cupo].EDAD = ValidaEntero();

            cout << "Ingrese el DNI del jugador: " << endl;
            DT[Cupo].DNI = ValidaEntero();

            cout << "Ingrese el celular del jugador: " << endl;
            DT[Cupo].CELULAR = ValidaEntero();
        }

        TS[Cupo].jugador = DT[Cupo].NOMBRE;
        TS[Cupo].eliminado = false;

        cout << "---------------------------------------------------" << endl;
        cout << "Desea agregar mas jugadores?" << endl;
        cout << "Pulse 1 para: SI" << endl;
        cout << "Pulse 2 para: NO" << endl;
        cout << "---------------------------------------------------" << endl;

        int AgregaJug = ValidaEntero();
        if (AgregaJug == 1) {
            Cupo++;
            Jugadores++;
            if (Cupo >= 64) {
                cout << "El registro está lleno. No se pueden agregar más jugadores." << endl;
                break;
            }
        } else {
            break;
        }
    }

    cout << "---------------------------------------------------" << endl;
    cout << "Registros completos" << endl;
}

void EliminarRegistro(){
}

void LeerDatos(){
}

void SistemaSimple(){
}

void SistemaDoble(){
}
// Aquí puedes agregar las demás funciones como LeerDatos, EliminarRegistro, SistemaSimple, SistemaDoble