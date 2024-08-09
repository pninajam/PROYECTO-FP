#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_JUGADORES = 64;

struct Entidad {
    string nombre;
    bool eliminado;
    int perdidas;
};

struct Simple {
    std::string jugador;
    bool eliminado;
};

struct Persona {
    std::string NOMBRE;
    std::string APELLIDO;
    int EDAD;
    int DNI;
    int CELULAR;
};

Simple TS[MAX_JUGADORES];
Persona DT[MAX_JUGADORES];

//Funciones
void Registrar(int &Cupo, int &Jugadores);
int ValidaEntero();
void LeerDatos();
void EliminarRegistro();
void SistemaSimple();
void Ronda(Persona Ent[], int &JoE);
void RondaDoble(Entidad Ent[], int& JoE, bool cuadroPerdedores = false);
void RegistrarJugadores(Entidad Ent[], int Jugadores);

void RegistrarJugadores(Entidad Ent[], int Jugadores) {
    for (int i = 0; i < Jugadores; ++i) {
        cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        cin >> Ent[i].nombre;
        Ent[i].eliminado = false;
        Ent[i].perdidas = 0;
    }
    cout << "Registros completos" << endl;
}

void RondaDoble(Entidad Ent[], int& JoE, bool cuadroPerdedores) {
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

void SistemaDoble() {
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
        RondaDoble(ganadores, numGanadores);

        if (numPerdedores > 0) {
            cout << "Ronda de perdedores:" << endl;
            RondaDoble(perdedores, numPerdedores, true);
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

//Función para registrar jugadores en sistema simple
void Registrar(int &Cupo, int &Jugadores) {
    if (Cupo >= MAX_JUGADORES) {
        std::cout << "El registro está lleno. No se pueden agregar más jugadores." << std::endl;
        return;
    }

    while (Cupo < MAX_JUGADORES && Jugadores > 0) {
        std::cout << "Ingrese el nombre del jugador " << Cupo + 1 << ": " << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        std::cin >> DT[Cupo].NOMBRE;

        //Ingresar más datos?
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "Desea ingresar más datos para este jugador?" << std::endl;
        std::cout << "Pulse 1 para: SI" << std::endl;
        std::cout << "Pulse otro número para: NO" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;

        int ingresarDatos = ValidaEntero();
        if (ingresarDatos == 1) {
            std::cout << "---------------------------------------------------" << std::endl;
            std::cout << "Ingrese el apellido del jugador: " << std::endl;
            std::cin >> DT[Cupo].APELLIDO;

            std::cout << "Ingrese la edad del jugador: " << std::endl;
            DT[Cupo].EDAD = ValidaEntero();

            std::cout << "Ingrese el DNI del jugador: " << std::endl;
            DT[Cupo].DNI = ValidaEntero();

            std::cout << "Ingrese el celular del jugador: " << std::endl;
            DT[Cupo].CELULAR = ValidaEntero();
        }

        TS[Cupo].jugador = DT[Cupo].NOMBRE;
        TS[Cupo].eliminado = false;

        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "Desea agregar más jugadores?" << std::endl;
        std::cout << "Pulse 1 para: SI" << std::endl;
        std::cout << "Pulse 2 para: NO" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;

        int AgregaJug = ValidaEntero();
        if (AgregaJug == 1) {
            Cupo++;
            Jugadores++;
            if (Cupo >= MAX_JUGADORES) {
                std::cout << "El registro está lleno. No se pueden agregar más jugadores." << std::endl;
                break;
            }
        } else {
            break;
        }
    }
    
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Registros completos" << std::endl;
}

//Validacion
int ValidaEntero() {
    int Ent;
    while (true) {
        std::cin >> Ent;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada no válida. Por favor, ingrese un número entero." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return Ent;
        }
    }
}

//Leer Registro
void LeerDatos() {
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Datos de los jugadores registrados:" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << std::setw(20) << std::left << "Nombre" 
              << std::setw(15) << std::left << "Apellido" 
              << std::setw(5) << std::left << "Edad" 
              << std::setw(10) << std::left << "DNI" 
              << std::setw(10) << std::left << "Celular" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;

    for (int i = 0; i < MAX_JUGADORES; ++i) {
        if (!TS[i].jugador.empty()) { // Mostrar jugadores registrados
            std::cout << std::setw(20) << std::left << DT[i].NOMBRE 
                      << std::setw(15) << std::left << DT[i].APELLIDO 
                      << std::setw(5) << std::left << DT[i].EDAD 
                      << std::setw(10) << std::left << DT[i].DNI 
                      << std::setw(10) << std::left << DT[i].CELULAR << std::endl;
        }
    }
    std::cout << "---------------------------------------------------" << std::endl;
}

//Función para eliminar un registro
void EliminarRegistro() {
    int index;
    std::cout << "Ingrese el índice del jugador a eliminar (1-64): ";
    std::cin >> index;

    //Validacion
    if (index < 1 || index > MAX_JUGADORES) {
        std::cout << "Índice no válido. Debe estar entre 1 y 64." << std::endl;
        return;
    }

    //Convertir el índice a 0 basado
    index -= 1;

    if (TS[index].jugador.empty()) {
        std::cout << "No hay jugador registrado en la posición " << (index + 1) << "." << std::endl;
        return;
    }

    //Eliminar el registro
    TS[index].jugador = "";
    TS[index].eliminado = true;
    DT[index] = Persona(); //Restablecer el struct Persona a sus valores predeterminados

    //Reorganizar los arreglos para cerrar el hueco
    for (int i = index; i < MAX_JUGADORES - 1; ++i) {
        TS[i] = TS[i + 1];
        DT[i] = DT[i + 1];
    }
    TS[MAX_JUGADORES - 1] = Simple(); //Limpiar el último elemento
    DT[MAX_JUGADORES - 1] = Persona(); //Limpiar el último elemento

    std::cout << "Registro eliminado y arreglos reorganizados exitosamente." << std::endl;
}

//Función para gestionar el torneo
void SistemaSimple() {
    int JoE = 0;
    //Crear un array de jugadores activos basado en TS
    Persona activos[MAX_JUGADORES];
    int contador = 0;

    //Copiar jugadores activos a un nuevo array
    for (int i = 0; i < MAX_JUGADORES; ++i) {
        if (!TS[i].jugador.empty() && !TS[i].eliminado) {
            activos[contador++] = DT[i];
        }
    }
    JoE = contador;

    //Llamar a la función de rondas
    while (JoE > 1) {
        Ronda(activos, JoE);
    }

    if (JoE == 1) {
        std::cout << "El ganador del torneo es: " << activos[0].NOMBRE << std::endl;
    } else {
        std::cout << "No hay ganadores debido a un error en el número de jugadores." << std::endl;
    }
}

//Función para gestionar una ronda
void Ronda(Persona Ent[], int &JoE) {
    //Crear un nuevo array para los ganadores
    Persona* Ganadores = new Persona[(JoE + 1) / 2];
    int NewJoE = 0;

    //Mostrar emparejamientos de la ronda actual
    std::cout << "Emparejamientos de esta ronda:" << std::endl;
    for (int i = 0; i < JoE; i += 2) {
        if (i + 1 < JoE) {
            std::cout << Ent[i].NOMBRE << " vs " << Ent[i + 1].NOMBRE << std::endl;
        } else {
            //Caso de número impar de jugadores, el último avanza automáticamente
            std::cout << Ent[i].NOMBRE << " avanza automáticamente" << std::endl;
        }
    }
    std::cout << std::endl;

    //Pedir el nombre del ganador de cada emparejamiento
    for (int i = 0; i < JoE; i += 2) {
        if (i + 1 < JoE) {
            std::cout << "Ingrese el nombre del ganador de " << Ent[i].NOMBRE << " vs " << Ent[i + 1].NOMBRE << ": ";
            std::string Gan;
            std::cin >> Gan;

            if (Gan == Ent[i].NOMBRE) {
                Ganadores[NewJoE] = Ent[i]; //Guardar ganador
            } else if (Gan == Ent[i + 1].NOMBRE) {
                Ganadores[NewJoE] = Ent[i + 1]; //Guardar ganador
            } else {
                std::cout << "Nombre no válido. Intente nuevamente." << std::endl;
                i -= 2; //Volver a pedir el ganador
                continue;
            }
            NewJoE++;
        } else {
            //Si hay un número impar de jugadores, el último jugador avanza automáticamente
            Ganadores[NewJoE] = Ent[i];
            NewJoE++;
        }
    }

    //Actualiza array original con los ganadores
    for (int i = 0; i < NewJoE; i++) {
        Ent[i] = Ganadores[i];
    }

    //Liberar memoria
    delete[] Ganadores;

    //Actualizar
    JoE = NewJoE;
}

//Función principal
int main() {
    int Cupo=0;
    int Jugadores=1;
    int DecisionP;

    while (true) {
        std::cout << "Bienvenido al sistema de emparejamiento" << std::endl;
        std::cout << "Antes de comenzar, registre a los participantes" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "Pulse 1 para: Registrar jugadores" << std::endl;
        std::cout << "Pulse 2 para: Eliminar el registro" << std::endl;
        std::cout << "Pulse 3 para: Leer los datos de los jugadores" << std::endl;
        std::cout << "Pulse 4 para: Comenzar el torneo simple" << std::endl;
        std::cout << "Pulse 5 para: Comenzar el torneo con eliminacion doble" << std::endl;
        std::cout << "Pulse 6 para: Salir" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;

        std::cin >> DecisionP;

        switch (DecisionP) {
            case 1:
                Registrar(Cupo, Jugadores);
                break;
            case 2:
                EliminarRegistro();
                break;
            case 3:
                LeerDatos();
                break;
            case 4:
                SistemaSimple();
                break;
            case 5:
                SistemaDoble();
                break;
            case 6:
                std::cout << "Saliendo del programa..." << std::endl;
                return 0;
            default:
                std::cout << "Opción no válida. Por favor, intente de nuevo." << std::endl;
                break;
        }
    }
}