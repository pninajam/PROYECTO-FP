#include <iostream>
#include "registro.h"

using namespace std;

// Función principal
int main() {
    int Cup = 0;
    int Jugad = 1;
    int DecisionP;

    while (true) {
        cout << "Bienvenido al sistema de emparejamiento" << endl;
        cout << "Antes de comenzar, registre a los participantes" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "Pulse 1 para: Registrar jugadores" << endl;
        cout << "Pulse 2 para: Eliminar el registro" << endl;
        cout << "Pulse 3 para: Leer los datos de los jugadores" << endl;
        cout << "Pulse 4 para: Comenzar el torneo simple" << endl;
        cout << "Pulse 5 para: Comenzar el torneo con eliminacion doble" << endl;
        cout << "Pulse 6 para: Salir" << endl;
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
                SistemaSimple();
                break;
            case 5:
                SistemaDoble();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opción no válida. Por favor, intente de nuevo." << endl;
                break;
        }
    }
}