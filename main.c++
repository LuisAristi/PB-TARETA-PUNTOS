#include<iostream>
#include"cliente.h"
#include"tecnico.h"
using namespace std;

//prototypes

int main(){
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout<<"Ha elegido la opción 1.\n";
                // Aquí puedes colocar la lógica para la opción 1
                break;
            case 2:
                cout<<"Ha elegido la opción 2.\n";
                // Aquí puedes colocar la lógica para la opción 2
                break;
            case 3:
                cout<<"Ha elegido la opción 3.\n";
                // Aquí puedes colocar la lógica para la opción 3
                break;
            case 4:
                cout<<"Ha elegido la opción 4.\n";
                // Aquí puedes colocar la lógica para la opción 3
                break;
            case 5:
                cout<<"Ha elegido la opción 5.\n";
                // Aquí puedes colocar la lógica para la opción 3
                break;
            case 6:
                cout<<"Ha elegido la opción 6.\n";
                // Aquí puedes colocar la lógica para la opción 3
                break;
            case 7:
                cout<<"Ha elegido la opción 7.\n";
                // Aquí puedes colocar la lógica para la opción 3
                break;
            case 8:
                cout<<"Ha elegido la opción 8.\n";
                break;
            case 9:
                cout<<"Saliendos";
            default:
                cout<<"Opción no válida. Por favor, seleccione una opción válida.\n";
                break;
        }
    } while (opcion != 8);
}

//functions
