#include <iostream>
#include <string>
#include "registro.h"
#include <limits>
#include <algorithm>
#include <random>

using namespace std;

Simple TS[64];
Persona DT[64];

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

void Registrar(int &Cupo, int &Jugadores) {
    system("cls");
    if (Cupo >= 64) {
        cout << "---------------------------------------------------" << endl;
        cout << "El registro está lleno. No se pueden agregar más jugadores." << endl;
        return;
    }

    while (Cupo < 64 && Jugadores < 64) {
        cout << "Ingrese el nombre del jugador " << Cupo + 1 << ": " << endl;
        cout << "---------------------------------------------------" << endl;
        cin >> TS[Cupo].jugador;
        DT[Cupo].NOMBRE = TS[Cupo].jugador;  // Actualizar DT con el nombre

        TS[Cupo].eliminado = false;
        DT[Cupo].APELLIDO = "";
        DT[Cupo].EDAD = 0;
        DT[Cupo].DNI = 0;
        DT[Cupo].CELULAR = 0;

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

void Barajar(Persona JActivos[], int PActivos) {
    // Crear un generador de números aleatorios basado en la semilla del reloj
    random_device rd;
    mt19937 g(rd());

    // Barajar el array de jugadores activos
    shuffle(JActivos, JActivos + PActivos, g);
}

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
        return -1;
    }

    // Barajar los jugadores para asegurar emparejamientos aleatorios
    Barajar(JActivos, PActivos);

    // Crear un array para los ganadores de esta ronda
    Persona* Ganadores = new Persona[(PActivos + 1) / 2];
    int NewJoE = 0;

    // Mostrar emparejamientos de esta ronda
    cout << "Emparejamientos de esta ronda:" << endl;
    for (int i = 0; i < PActivos; i += 2) {
        if (i + 1 < PActivos) {
            cout << JActivos[i].NOMBRE << " vs " << JActivos[i + 1].NOMBRE << endl;
        } else {
            cout << JActivos[i].NOMBRE << " avanza automáticamente" << endl;
        }
    }
    cout << endl;

    // Pedir el nombre del ganador de cada emparejamiento
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
                i -= 2; // Volver a pedir el ganador
                continue;
            }
            NewJoE++;
        } else {
            // Si hay un número impar de jugadores, el último jugador avanza automáticamente
            Ganadores[NewJoE] = JActivos[i];
            NewJoE++;
        }
    }

    // Actualizar el array de jugadores activos con los ganadores
    for (int i = 0; i < NewJoE; i++) {
        JActivos[i] = Ganadores[i];
    }

    // Liberar memoria
    delete[] Ganadores;

    // Actualizar el número de jugadores activos
    PActivos = NewJoE;

    return 0;
}




void EliminarRegistro() {
    // Implementar según necesidades
}

void LeerDatos() {
    // Implementar según necesidades
}

void SistemaDoble() {
    // Implementar según necesidades
}