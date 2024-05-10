#include <iostream>
#include <windows.h>
#include <locale>

#include "cliente.h"
#include "tecnico.h"

using namespace std; 

int main(){
    setlocale(LC_ALL, "spanish");

    //Ventana de presentación.
    cout << "BIENVENIDO A NUESTRO SOFTWARE, ESTE PROGRAMA HA SIDO DESARROLLADO POR:" << endl; Sleep(1000);
    cout << "\nJulian Rojas: 0222320040        Eduardo Tuñon: 0222320052        Luis Aristizaval: \nEstudiantes de Ingenieria de sistemas.\n\n" << endl;

    cout << "Este programa imita el manejo de un sistema de puntos acumulables por cada compra en un almacen.\n" << endl;
    cout << "Con opciónes para: \n";

    cout << "\n    1. Registrar un cliente: Almacenando los datos de documento de identificación (id), nombre,\n    dirección, teléfono, puntos vigentes, puntos redimidos, fecha ultima redención puntos,\n    fecha últimos puntos asignados.\n";

    cout << "\n    2. Ingresar puntos: Se pide el id del usuario, luego se busca y se agregan los puntos actuales,\n    que se calculan tal que; por cada 100$ gastados se le sumaran al comprador 1 punto, es decir\n    que si gasta 5500$ se le sumaran 55 puntos.\n";

    cout << "\n    3. Consultar, con dos funciones: \n";
    cout << "        a. Consultar puntos: Al ingresar el id del cliente se visualizará el nombre del cliente,\n        la cantidad de puntos vigentes, puntos redimidos, fecha de la última asignación de puntos,\n        fecha de la última redención de puntos.\n";
    cout << "        b. Listar Clientes: Genera un listado de todos los clientes con su respectivo\n        documento de identificación (id), nombre y sus puntos vigentes.\n";

    cout << "\n    4. Redimir Puntos:";
    cout << "\n    En esta opción se debe ingresar el documento de identificación, buscar cliente y verificar\n    si tiene suficientes puntos para poder redimir, en caso afirmativo descontar los puntos redimidos\n    y actualizar en el registro del cliente.\n";
    cout << "\n        a. Compra Textil: será equivalente a un descuento del 40% del valor de la compra\n        si esta es mayor a $100.000. Para este caso se redimirán 5.000 puntos.\n";
    cout << "\n        b. Compra Electrodomésticos: será equivalente a un descuento del 25% del valor de la compra,\n        si esta es mayor a $500.000. Para este caso se redimirán 8.000 puntos\n";
    cout << "\n        c. Compra Mercado: será equivalente a un descuento del 10% del valor de la compra\n        si está es mayor a $100.000. Para este caso se redimirán 10.000 puntos\n";

    cout << "\n    5. Eliminar Clientes: Al ingresar el documento de identificación de un cliente se debe\n    eliminar el registro correspondiente a ese cliente.\n\n";

    system("pause");

    int opcion;

    do {
        system("cls");
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");
                cout<<"Ha elegido la opción 1.\n\n";
                system("pause");
                break;

            case 2:
                system("cls");
                cout<<"Ha elegido la opción 2.\n\n";
                system("pause");
                break;

            case 3:
                system("cls");
                cout<<"Ha elegido la opción 3.\n\n";
                system("pause");
                break;
            case 4:
                system("cls");
                cout<<"Ha elegido la opción 4.\n\n	";
                system("pause");
                break;

            case 5:
                system("cls");
                cout<<"Ha elegido la opción 5.\n\n";
                system("pause");
                break;

            case 6:
                system("cls");
                cout<<"Ha elegido la opción 6.\n\n";
                system("pause");
                break;

            case 7:
                system("cls");
                cout<<"Ha elegido la opción 7.\n\n";
                system("pause");
                break;

            case 8:
                system("cls");
                cout<<"Ha elegido la opción 8.\n\n";
                system("pause");
                break;

            case 9:
                system("cls");
                cout<<"Saliendo...\n\n";
                system("pause");
                break;

            default:
                cout<<"\nOpción invalida...\n\n";
                system("pause");
                break;
        }
    } while (opcion != 9);
}

//Funciones
