#include <iostream>
#include <string>
#include "registro.h"
#include <limits>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;

Simple TS[64];
Doble jugadores[64];
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
    cout << "---------------------------------------------------" << endl;
    if (Cupo >= 64) {
        cout << "El registro esta lleno. No se pueden agregar mas jugadores." << endl;
        cout << "---------------------------------------------------" << endl;
        return;
    }

    while (Cupo < 64 && Jugadores < 64) {
        cout << "Ingrese el nombre del jugador " << Cupo + 1 << ": " << endl;
        cout << "---------------------------------------------------" << endl;
        cin >> DT[Cupo].NOMBRE;
        
        TS[Cupo].jugador = DT[Cupo].NOMBRE;
        TS[Cupo].eliminado = false;
        
        jugadores[Cupo].jugador = DT[Cupo].NOMBRE;
        jugadores[Cupo].eliminado = false;
        jugadores[Cupo].perdidas = 0;
        
        DT[Cupo].APELLIDO = "";
        DT[Cupo].EDAD = 0;
        DT[Cupo].DNI = 0;
        DT[Cupo].CELULAR = 0;
        
                // Preguntar si se deben ingresar más datos
        cout << "---------------------------------------------------" << endl;
        cout << "Desea ingresar mas datos para este jugador?" << endl;
        cout << "Pulse 1 para: SI" << endl;
        cout << "Pulse otro numero para: NO" << endl;
        cout << "---------------------------------------------------" << endl;

        int Datos = ValidaEntero();
        if (Datos == 1) {
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
                cout << "El registro esta lleno. No se pueden agregar mas jugadores." << endl;
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
                cout << "Nombre no valido. Intente nuevamente." << endl;
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

void LeerDatos() {
    cout << "---------------------------------------------------" << endl;
    cout << "Datos de los jugadores registrados:" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << setw(20) << left << "Nombre" 
         << setw(15) << left << "Apellido" 
         << setw(5) << left << "Edad" 
         << setw(10) << left << "DNI" 
         << setw(10) << left << "Celular" << endl;
    cout << "---------------------------------------------------" << endl;

    for (int i = 0; i < 64; ++i) {
        if (!TS[i].jugador.empty()) { // Solo mostrar jugadores registrados
            cout << setw(20) << left << DT[i].NOMBRE 
                 << setw(15) << left << DT[i].APELLIDO 
                 << setw(5) << left << DT[i].EDAD 
                 << setw(10) << left << DT[i].DNI 
                 << setw(10) << left << DT[i].CELULAR << endl;
        }
    }
    cout << "---------------------------------------------------" << endl;
}

void EliminarRegistro() {
    int index;
    cout << "Ingrese el indice del jugador a eliminar (1-64): ";
    cin >> index;
    
    // Validar que el índice esté dentro del rango
    if (index < 1 || index > 64) {
        cout << "Indice no valido. Debe estar entre 1 y 64." << endl;
        return;
    }
    
    // Convertir el índice a 0 basado
    index -= 1;

    if (TS[index].jugador.empty()) { // Ajusta esto según la estructura de Simple
        cout << "No hay jugador registrado en la posicion " << (index + 1) << "." << endl;
        return;
    }

    // Eliminar el registro
    TS[index] = Simple(); // Limpiar el registro de Simple
    DT[index] = Persona(); // Restablecer el struct Persona a sus valores predeterminados

    // Reorganizar los arreglos para cerrar el hueco
    for (int i = index; i < 63; ++i) {
        TS[i] = TS[i + 1];
        DT[i] = DT[i + 1];
    }
    TS[63] = Simple(); // Limpiar el último elemento
    DT[63] = Persona(); // Limpiar el último elemento

    cout << "Registro eliminado y arreglos reorganizados exitosamente." << endl;
}

int SistemaDoble() {
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

    Doble JActivos[64];
    int PActivos = 0;
    for (int i = 0; i < 64; ++i) {
        if (!TS[i].eliminado) {
            JActivos[PActivos++] = jugadores[i];
        }
    }

    while (PActivos > 1) {
        RondaDoble(JActivos, PActivos);
    }

    if (PActivos == 1) {
        cout << "El ganador del torneo es: " << JActivos[0].jugador << endl;
    } else {
        cout << "El torneo no pudo determinar un ganador." << endl;
    }

    return 0;
}


void RondaDoble(Doble* Ent, int& JoE, bool cuadroPerdedores) {
    if (JoE < 2) {
        cout << "No hay suficientes jugadores para iniciar la ronda." << endl;
        return;
    }

    Doble* Ganadores = new Doble[(JoE + 1) / 2];
    int NewJoE = 0;

    cout << "Ronda de ganadores:" << endl;
    cout << "Emparejamientos de esta ronda:" << endl;

    for (int i = 0; i < JoE; i += 2) {
        if (i + 1 < JoE) {
            cout << Ent[i].jugador << " vs " << Ent[i + 1].jugador << endl;
        } else {
            cout << Ent[i].jugador << " avanza automáticamente" << endl;
        }
    }
    cout << endl;

    for (int i = 0; i < JoE; i += 2) {
        if (i + 1 < JoE) {
            string Gan;
            bool nombreValido = false;

            while (!nombreValido) {
                cout << "Ingrese el nombre del ganador de " << Ent[i].jugador << " vs " << Ent[i + 1].jugador << ": ";
                cin >> Gan;

                if (Gan == Ent[i].jugador) {
                    if (cuadroPerdedores) {
                        Ent[i + 1].eliminado = true;
                    } else {
                        Ent[i + 1].perdidas++;
                        if (Ent[i + 1].perdidas == 2) {
                            Ent[i + 1].eliminado = true;
                        }
                    }
                    Ganadores[NewJoE++] = Ent[i];
                    nombreValido = true;
                } else if (Gan == Ent[i + 1].jugador) {
                    if (cuadroPerdedores) {
                        Ent[i].eliminado = true;
                    } else {
                        Ent[i].perdidas++;
                        if (Ent[i].perdidas == 2) {
                            Ent[i].eliminado = true;
                        }
                    }
                    Ganadores[NewJoE++] = Ent[i + 1];
                    nombreValido = true;
                } else {
                    cout << "Nombre no válido. Intente nuevamente." << endl;
                }
            }
        } else {
            Ganadores[NewJoE++] = Ent[i];
        }
    }

    for (int i = 0; i < NewJoE; i++) {
        Ent[i] = Ganadores[i];
    }

    delete[] Ganadores;

    JoE = NewJoE;
}

void SistemaDoble2() {
    int JoE;
    cout<<"Ingrese el numero de participantes:"<<endl;
    cin>>JoE;
    if (JoE < 4) {
        cout <<"Debe haber al menos 4 participantes"<<endl;
        return;
    }

    Entidad jugadores[JoE];
    RegistrarJugadores(jugadores, JoE);

    int numGanadores = JoE;
    int numPerdedores = 0;
    Entidad ganadores[JoE];
    Entidad perdedores[JoE];

    for (int i = 0; i < JoE; ++i) {
        ganadores[i] = jugadores[i];
    }

    while (numGanadores > 1 || (numGanadores == 1 && numPerdedores > 0)) {
        cout << "Ronda de ganadores:" << endl;
        RondaDoble2(ganadores, numGanadores);

        if (numPerdedores > 0) {
            cout << "Ronda de perdedores:" << endl;
            RondaDoble2(perdedores, numPerdedores, true);
        }

        for (int i = 0; i < JoE; ++i) {
            if (ganadores[i].perdidas == 1 && !ganadores[i].eliminado) {
                perdedores[numPerdedores++] = ganadores[i];
                ganadores[i].eliminado = true;
            }
        }

        int index = 0;
        for (int i = 0; i < JoE; ++i) {
            if (!ganadores[i].eliminado) {
                ganadores[index++] = ganadores[i];
            }
        }
        numGanadores = index;
    }

    if (numGanadores == 1 && numPerdedores == 0) {
        cout << "El ganador del torneo es: " << ganadores[0].nombre << endl;
    } else if (numGanadores == 1 && numPerdedores == 1) {
        cout << "Final: " << ganadores[0].nombre << " vs " << perdedores[0].nombre << endl;
        string Gan;
        cout << "Ingrese el nombre del ganador de esta ronda: ";
        cin >> Gan;
        if (Gan == ganadores[0].nombre) {
            cout << "El ganador del torneo es: " << ganadores[0].nombre << endl;
        } else {
            cout << "El ganador del torneo es: " << perdedores[0].nombre << endl;
        }
    }
}

void RondaDoble2(Entidad Ent[], int& JoE, bool cuadroPerdedores) {
    int NewJoE = 0;
    for (int i = 0; i < JoE; i += 2) {
        if (!Ent[i].eliminado && !Ent[i + 1].eliminado) {
            cout << Ent[i].nombre << " vs " << Ent[i + 1].nombre << endl;
            string Gan;
            cout << "Ingrese el nombre del ganador de esta ronda: ";
            cin >> Gan;
            if (Gan == Ent[i].nombre) {
                if (cuadroPerdedores) {
                    Ent[i + 1].eliminado = true;
                } else {
                    Ent[i + 1].perdidas++;
                    if (Ent[i + 1].perdidas == 2) {
                        Ent[i + 1].eliminado = true;
                    }
                }
            } else {
                if (cuadroPerdedores) {
                    Ent[i].eliminado = true;
                } else {
                    Ent[i].perdidas++;
                    if (Ent[i].perdidas == 2) {
                        Ent[i].eliminado = true;
                    }
                }
            }
            NewJoE++;
        }
    }
    JoE = NewJoE;
}

void RegistrarJugadores(Entidad Ent[], int Jugadores) {
    for (int i = 0; i < Jugadores; ++i) {
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> Ent[i].nombre;
        Ent[i].eliminado = false;
        Ent[i].perdidas = 0;
    }
    cout << "Registros completos" << endl;
}




