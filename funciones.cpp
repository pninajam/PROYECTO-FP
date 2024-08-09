#include <iostream>
#include <string>
#include "registro.h"
#include <limits>

using namespace std;

Simple TS[64];
Persona DT[64];

int SistemaSimple() {
    int JoE = 0;

    for (int i = 0; i < 64; ++i) {
        if (!TS[i].eliminado) {
            JoE++;
        }
    }

    if (JoE < 2) {
        cout << "No hay suficientes jugadores para iniciar el torneo." << endl;
        return -1;
    }

    Persona JActivos[64];
    int PActivos = 0;
    for (int i = 0; i < 64; ++i) {
        if (!TS[i].eliminado) {
            JActivos[PActivos++] = DT[i];
        }
    }

    while (PActivos > 1) {
        Ronda(JActivos, PActivos);
    }

    if (PActivos == 1) {
        cout << "El ganador del torneo es: " << JActivos[0].NOMBRE << endl;
    } else {
        cout << "El torneo no pudo determinar un ganador." << endl;
    }

    return 0;
}


int Ronda(Persona JActivos[], int &PActivos) {
	if (PActivos < 2) {
        cout << "No hay suficientes jugadores para iniciar la ronda." << endl;
        return -1; // Termina la función si no hay suficientes jugadores
    }
    
    Persona* Ganadores = new Persona[(PActivos + 1) / 2];
    int NewJoE = 0;

    cout << "Emparejamientos de esta ronda:" << endl;
    for (int i = 0; i < PActivos; i += 2) {
        if (i + 1 < PActivos) {
            cout << JActivos[i].NOMBRE << " vs " << JActivos[i + 1].NOMBRE << endl;
        } else {
            cout << JActivos[i].NOMBRE << " avanza automáticamente" << endl;
        }
    }
    cout << endl;

    for (int i = 0; i < PActivos; i += 2) {
        if (i + 1 < PActivos) {
            cout << "Ingrese el nombre del ganador de " << JActivos[i].NOMBRE << " vs " << JActivos[i + 1].NOMBRE << ": ";
            string Gan;
            cin >> Gan;

            if (Gan == JActivos[i].NOMBRE) {
                Ganadores[NewJoE] = JActivos[i];
            } else if (Gan == JActivos[i + 1].NOMBRE) {
                Ganadores[NewJoE] = JActivos[i + 1];
            } else {
                cout << "Nombre no válido. Intente nuevamente." << endl;
                i -= 2;
                continue;
            }
            NewJoE++;
        } else {
            Ganadores[NewJoE] = JActivos[i];
            NewJoE++;
        }
    }

    for (int i = 0; i < NewJoE; i++) {
        JActivos[i] = Ganadores[i];
    }

    delete[] Ganadores;

    PActivos = NewJoE;
    
    return 0;
}



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
        cin >> TS[Cupo].jugador;

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

void SistemaDoble(){
}
// Aquí puedes agregar las demás funciones como LeerDatos, EliminarRegistro, SistemaSimple, SistemaDobl