#include <iostream>
#include <unistd.h>
#include <locale>
//#include <windows.h>

using namespace std;

struct Cliente {
    long id;
    char nombre[100];
    char direccion[50];
    long telefono;
    float puntosVigentes = 0;
    float puntosRedimidos = 0;
    long fechaRedencion;
    long fechaAsignacion;
};

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

void registrarCliente(struct Cliente cliente[], int n) {
    for(int i=0; i<n; i++) {
        cout << "\nIngrese la identificación del cliente #" << i+1 << ": "; cin >> cliente[i].id;
        
        // Verificar que la identificación no halla sido registrada previamente.
        for(int j=0; j<n; j++) {
            if(cliente[i].id == cliente[j].id && j != i) {
                do {
                    cout << "Identificación repetida, intentelo de nuevo: "; cin >> cliente[i].id;
                }while(cliente[i].id == cliente[j].id);
            }
            break;
        }

        cout << "Nombre: "; fflush(stdin); fgets(cliente[i].nombre, 100, stdin);
        cout << "Dirección: "; cin >> cliente[i].telefono;
        cout << "Número de contacto: "; cin >> cliente[i].telefono;
        //Función incompleta, faltan los datos: puntos vigentes, puntos redimidos, fecha ultima redención puntos, fecha últimos puntos asignados.
    }
}

void ingresarPuntos(struct Cliente cliente[], int n) {
    int id2;
    cout << "Ingrese una identificación: "; cin >> id2;

    // Se busca si la id ingresada esta registrada, si lo esta pide el dinero gastado y calcula en base a el la cantidad de puntos a almacenar.
    for(int i=0; i<n; i++) {
        if(id2 == cliente[i].id) {
            int dinero;
            cout << "Ingrese el monto del dinero gastado en compras: "; cin >> dinero;
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
            cout << "Fecha de la última asignación de puntos: " << cliente[i].fechaAsignacion;
            cout << "Fecha de la última redención de puntos: " << cliente[i].fechaRedencion;
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
