#include <iostream>
#include "registro.h"

using namespace std;

// Función principal
int main() {
    int Cup = 0;
    int Jugad = 1;
    int DecisionP;

    for (int i = 0; i < 64; ++i) {
        TS[i].eliminado = true; // Marca todos los jugadores como eliminados inicialmente en caso de ir al case 4 directo
    }
	
    while (true) {
        cout << "Bienvenido al sistema de emparejamiento" << endl;
        cout << "Antes de comenzar, registre a los participantes" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "Pulse 1 para: Registrar jugadores" << endl;
        cout << "Pulse 2 para: Eliminar el registro" << endl;
        cout << "Pulse 3 para: Leer los datos de los jugadores" << endl;
        cout << "Pulse 4 para: Comenzar el torneo simple" << endl;
        cout << "Pulse 5 para: Comenzar el torneo con eliminacion doble" << endl;
        cout << "Pulse 6 para: Comenzar el torneo con eliminacion doble (Propuesta)" << endl;
        cout << "Pulse 7 para: Salir" << endl;
        cout << "---------------------------------------------------" << endl;

        cin >> DecisionP;

        switch (DecisionP) {
            case 1:
                Registrar(Cup, Jugad);
                break;
            case 2:
                EliminarRegistro();
                break;
            case 3:
                LeerDatos();
                break;
            case 4:
                if (SistemaSimple() == -1) {
                    cout << "No se pudo iniciar el torneo simple debido a la falta de jugadores." << endl;
                }
                break;
            case 5:
                SistemaDoble();
                break;
            case 6:
            	SistemaDoble2();
            	break;
            case 7:
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opción no válida. Por favor, intente de nuevo." << endl;
                break;
        }
    }
}