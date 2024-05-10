#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <ctime> //esta libreria permite no tener que pedir el tiempo, lo ingresara de una al sistema
#include <iomanip>
#include <locale>
//#include <windows.h>

using namespace std;

typedef struct Cliente {
    long id;
    char nombre[100];
    char direccion[50];
    long telefono;
    float puntosVigentes = 0;
    float puntosRedimidos = 0;
    std::tm fechaRedencion; //un struct que guardara fecha, muy util
    std::tm fechaAsignacion; //este otro tambien, por lo que nos permitira tener mas orden
}cliente;

/* Documentacion de ctime en codigo

std::tm fecha;
fecha.tm_year = 123; | 2023 - 1900 = 123
fecha.tm_mon = 4;    | Mayo es el quinto mes, pero se representa como 4
fecha.tm_mday = 10;
*/

/* cosas utiles

// Obtener la fecha y hora actual
    std::time_t now = std::time(nullptr);
    
    // Convertir la fecha y hora actual a una estructura tm
    std::tm* localTime = std::localtime(&now);
    
    // Extraer el día, mes y año
    int dia = localTime->tm_mday;
    int mes = localTime->tm_mon + 1; // Sumamos 1 porque los meses van de 0 a 11
    int anio = localTime->tm_year + 1900; // Sumamos 1900 porque tm_year representa años desde 1900

    // Mostrar la fecha actual
    std::cout << "Fecha actual: " << dia << "/" << mes << "/" << anio << std::endl;
*/


int mostrarMenu() {
    int opcion;
    
    system("cls");
    cout << "SISTEMA DE PUNTOS DEL ALMACEN\n";
    cout << "========================\n";
    cout << "1. Registrar cliente.\n";
    cout << "2. Ingresar puntos.\n";
    cout << "3. Consultar Puntos.\n";
    cout << "4. Consultar clientes.\n";
    cout << "5. Comprar textil usando puntos.\n";
    cout << "6. Comprar electrodomesticos usando puntos.\n";
    cout << "7. Comprar mercado usando puntos.\n";
    cout << "8. Eliminar Clientes.\n";
    cout << "9. Salir.\n";
    cout << "========================\n";
    cout << "Ingrese el número de la opción deseada: ";
    cin >> opcion;
    system("cls");
    return opcion;
}

void registrarCliente(Cliente cliente[], int n) {
    int aux;
    for(int i=0; i<n; i++) {
        cout << "\nIngrese la identificación del cliente #" << i+1 << ": "; cin >> cliente[i].id;
        
        // Verificar que la identificación no halla sido registrada previamente.
        //seria mejor que una funcion se encargara de esto en tecnico.h --luis Aristi
        //y retornara un booleano aqui para verificar --luis aristi
        for(int j=0; j<n; j++) {
            if(cliente[i].id == cliente[j].id && j != i) {
                do {
                    cout << "Identificación repetida, intentelo de nuevo: "; cin >> cliente[i].id;
                }while(cliente[i].id == cliente[j].id);
            }
            break;
        }

		std::cout<<"Nombre: "; fflush(stdin); fgets(cliente[i].nombre, 50, stdin);
		std::cout<<"Direccion: "; fflush(stdin); fgets(cliente[i].direccion, 20, stdin);
		std::cout<<"Telefono: "; fflush(stdin); std::cin>>cliente[i].telefono;
        std::cout<<"Puntos Vigentes: "; fflush(stdin); std::cin>>cliente[i].puntosVigentes;
        std::cout<<"Puntos Redimidos: "; fflush(stdin); std::cin>>cliente[i].puntosRedimidos;
        std::cout<<"Ingrese Dia Ultima Redencion de Puntos: "; fflush(stdin); std::cin>>cliente[i].fechaAsignacion.tm_mday;
        std::cout<<"Ingrese Mes Ultima Redencion de Puntos: "; fflush(stdin); std::cin>>cliente[i].fechaAsignacion.tm_mon;
        std::cout<<"Ingrese Fecha Anual Ultima Redencion de Puntos: "; fflush(stdin); std::cin>>aux;
        aux = aux - 1900;
        cliente[i].fechaAsignacion.tm_mon = aux;
        system("cls");

    }
}

void ingresarPuntos(struct Cliente cliente[], int n) {
    int id2;
    cout << "Ingrese una identificación: "; cin >> id2;

    // Se busca si la id ingresada esta registrada, si lo esta pide el dinero gastado y calcula en base a el la cantidad de puntos a almacenar.
    for(int i=0; i<n; i++) {
        if(id2 == cliente[i].id) {
            int dinero;
            cout << "Ingrese el monto de la compra: "; cin >> dinero;
            // Por cada 100$ gastados se suma 1 punto vigente.
            cliente[i].puntosVigentes += dinero/100;

        }else {
            cout << "\nIdentificación no encontrada...\n";
            break;
        }

        cout << "\nSus puntos actuales son: " << cliente[i].puntosVigentes;
    }
}

void consultarPuntos(struct Cliente cliente[], int n) {
    int id2;
    cout << "Ingrese una identificación: "; cin >> id2;

    // Se busca si la id ingresada esta registrada, si lo esta muestra el nombre del cliente, la cantidad de puntos vigentes, puntos redimidos, fecha de la última asignación de puntos, fecha de la última redención de puntos.
    for(int i=0; i<n; i++) {
        if(id2 == cliente[i].id) {
            cout << "\nNombre: " << cliente[i].nombre;
            cout << "Puntos vigentes: " << cliente[i].puntosVigentes;
            cout << "Puntos redimidos: " << cliente[i].puntosRedimidos;

            //deberia crear una funcion para esto pero quiero corregir los errores de compilacion --luis Aristi
            int dia = cliente[i].fechaAsignacion.tm_mday;
            int mes = cliente[i].fechaAsignacion.tm_mon + 1; // Sumamos 1 porque los meses van de 0 a 11
            int anio = cliente[i].fechaAsignacion.tm_year + 1900; // Sumamos 1900 porque tm_year representa años desde 1900


            cout << "Fecha de la última asignación de puntos: " <<dia<<"/"<<mes<<"/"<<anio;
            cout << "Fecha de la última redención de puntos: "; //cliente[i].fechaRedencion; sera corregido lo prometo --luis Aristi
        }else {
            cout << "\nIdentificación no encontrada...\n";
            break;
        }
    }
}

void listarClientes(struct Cliente cliente[], int n){
    cout<<"hola";
}

void comprarTextil(struct Cliente cliente[], int n) {
    cout<<"hola";
}

void comprarElectrodomestico(struct Cliente cliente[], int n) {
    cout<<"hola";
}

void comprarMercado(struct Cliente cliente[], int n) {
    cout<<"hola";
}

void eliminarClientes(struct Cliente cliente[], int n) {
    cout<<"hola";
}
