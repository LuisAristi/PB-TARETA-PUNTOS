#include <ctime> //esta libreria permite no tener que pedir el tiempo, lo ingresara de una al sistema
#include <iomanip>
#include <iostream>
#include <locale>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
//#include <windows.h>

using namespace std;

typedef struct Cliente {
  long int id = 0;
  char nombre[50];
  char direccion[50];
  long long telefono = 0;
  int puntosVigentes = 0;
  int puntosRedimidos = 0;
  std::tm fechaRedencion;  // un struct que guardara fecha, muy util
  std::tm fechaAsignacion; // este otro tambien, por lo que nos permitira tener
                           // mas orden
} cliente;

int mostrarMenu() {
  int opcion;

  system("cls");
  std::cout << "SISTEMA DE PUNTOS DEL ALMACEN\n";
  std::cout << "========================\n";
  std::cout << "1. Registrar cliente.\n";
  std::cout << "2. Ingresar puntos.\n";
  std::cout << "3. Consultar Puntos.\n";
  std::cout << "4. Consultar clientes.\n";
  std::cout << "5. Comprar textil usando puntos.\n";
  std::cout << "6. Comprar electrodomesticos usando puntos.\n";
  std::cout << "7. Comprar mercado usando puntos.\n";
  std::cout << "8. Eliminar Clientes.\n";
  std::cout << "9. Salir.\n";
  std::cout << "========================\n";
  std::cout << "Ingrese el número de la opción deseada: ";
  cin >> opcion;
  system("cls");
  return opcion;
}

void horaAsignacion(Cliente cliente[], int x){
    std::time_t tiempoActual = std::time(NULL); // Obtener el tiempo actual en segundos
    std::tm* fechaHora = std::localtime(&tiempoActual); // Convertir el tiempo a una estructura tm
    
    // Crear un struct Fecha y asignar los componentes de la fecha actual
    cliente[x].fechaAsignacion.tm_mday = (*fechaHora).tm_mday;
    cliente[x].fechaAsignacion.tm_mon = (*fechaHora).tm_mon; // Sumamos 1 porque los meses van de 0 a 11
    cliente[x].fechaAsignacion.tm_year = (*fechaHora).tm_year; // Sumamos 1900 porque tm_year representa años desde 1900
}

void horaRedencion(Cliente cliente[], int x){
    std::time_t tiempoActual = std::time(NULL); // Obtener el tiempo actual en segundos
    std::tm* fechaHora = std::localtime(&tiempoActual); // Convertir el tiempo a una estructura tm
    
    // Crear un struct Fecha y asignar los componentes de la fecha actual
    cliente[x].fechaRedencion.tm_mday = (*fechaHora).tm_mday;
    cliente[x].fechaRedencion.tm_mon = (*fechaHora).tm_mon; // Sumamos 1 porque los meses van de 0 a 11
    cliente[x].fechaRedencion.tm_year = (*fechaHora).tm_year; // Sumamos 1900 porque tm_year representa años desde 1900
}

// Busca la id ingresada en el registro de clientes, si lo encuentra retorna
// verdadero.
bool buscarId(long int id, Cliente cliente[], int& n, int x) {
  for (int i = 0; i < x; i++) {
    if (id == cliente[i].id) {
      n = i;
      return true;
    }
  }
  return false;
}

void registrarCliente(Cliente cliente[], int n) {
  int aux;
  int posicion;
  for (int i = 0; i < n; i++) {
    std::cout << "\nIngrese la identificación del cliente #" << i + 1 << ": ";
    cin >> cliente[i].id;

    // Verificar si la identificación ha sido registrada previamente, para
    // evitar que se repita.
    do {
      if (buscarId(cliente[i].id, cliente, n, i)) {
        std::cout << "Identificación repetida, intentelo de nuevo: ";
        cin >> cliente[i].id;
      }
    } while (buscarId(cliente[i].id, cliente, n, i));

    std::cout << "Nombre: ";
    fflush(stdin);
    fgets(cliente[i].nombre, 50, stdin);
    std::cout << "Direccion: ";
    fflush(stdin);
    fgets(cliente[i].direccion, 50, stdin);
    std::cout << "Telefono: ";
    fflush(stdin);
    cin >> cliente[i].telefono;
    std::cout << "Puntos Vigentes: ";
    fflush(stdin);
    cin >> cliente[i].puntosVigentes;
    std::cout << "Puntos redimidos: ";
    fflush(stdin);
    cin >> cliente[i].puntosRedimidos;
    std::cout << "Ingrese el dia de la última Asignacion de puntos: ";
    fflush(stdin);
    cin >> cliente[i].fechaAsignacion.tm_mday;
    std::cout << "Ingrese el mes de la última Asignacion de puntos: ";
    fflush(stdin);
    cin >> aux;
    cliente[i].fechaAsignacion.tm_mon = aux - 1;
    std::cout << "Ingrese el año de la última Asignacion de puntos: ";
    fflush(stdin);
    cin >> aux;
    cliente[i].fechaAsignacion.tm_year = aux - 1900;

    std::cout << "Ingrese el dia de la última Redencioncion de puntos: ";
    fflush(stdin);
    cin >> cliente[i].fechaRedencion.tm_mday;
    std::cout << "Ingrese el mes de la última Redencioncion de puntos: ";
    fflush(stdin);
    cin >> aux;
    cliente[i].fechaRedencion.tm_mon = aux - 1;
    std::cout << "Ingrese el año de la última Redencion de puntos: ";
    fflush(stdin);
    cin >> aux;
    cliente[i].fechaRedencion.tm_year = aux - 1900;

    system("cls");
  }
}

void ingresarPuntos(struct Cliente cliente[], int n) {
  long int id;
  std::cout << "Ingrese una identificación: ";
  cin >> id;

  // Se busca si la id ingresada esta registrada, si lo esta pide el dinero
  // gastado y calcula en base a el la cantidad de puntos a almacenar.
  int aux; // Entra por referencia a la función para guardar la posicion del
         // cliente en el arreglo.
  if (buscarId(id, cliente, aux, n)){
    int dinero = 0;
    std::cout << "Ingrese la cantidad de dinero gastado: ";
    cin >> dinero;
    // Por cada 100$ gastados se suma 1 punto vigente.
    cliente[aux].puntosVigentes += (dinero / 100);
    std::cout << "\nSus puntos actuales son: " << cliente[aux].puntosVigentes;
    horaAsignacion(cliente, aux);

  } else {
    std::cout << "\nIdentificación no encontrada...\n";
  }
}

void consultarPuntos(struct Cliente cliente[], int n) {
  int id;
  std::cout << "Ingrese una identificación: ";
  cin >> id;

  // Se busca si la id ingresada esta registrada, si lo esta muestra el nombre
  // del cliente, la cantidad de puntos vigentes, puntos redimidos, fecha de la
  // última asignación de puntos, fecha de la última redención de puntos.
  int x;
  if (buscarId(id, cliente, x, n)) {
    std::cout << "\nNombre: " << cliente[x].nombre<<std::endl;
    std::cout << "Puntos vigentes: " << cliente[x].puntosVigentes<<std::endl;
    std::cout << "Puntos redimidos: " << cliente[x].puntosRedimidos<<std::endl;

    // deberia crear una funcion para esto pero quiero corregir los errores de
    // compilacion --luis Aristi
    int dia = cliente[x].fechaAsignacion.tm_mday;
    int mes = cliente[x].fechaAsignacion.tm_mon +
              1; // Sumamos 1 porque los meses van de 0 a 11
    int anio = cliente[x].fechaAsignacion.tm_year +
               1900; // Sumamos 1900 porque tm_year representa años desde 1900

    int diaR = cliente[x].fechaRedencion.tm_mday;
    int mesR = cliente[x].fechaRedencion.tm_mon +
              1; // Sumamos 1 porque los meses van de 0 a 11
    int anioR = cliente[x].fechaRedencion.tm_year +
               1900; // Sumamos 1900 porque tm_year representa años desde 1900

    std::cout << "Fecha de la última asignación de puntos: " << dia << "/"
              << mes << "/" << anio<<std::endl;
    std::cout
        << "Fecha de la última redención de puntos: " << diaR << "/"
              <<mesR<< "/" << anioR<<std::endl; 
  } else {
    std::cout << "\nIdentificación no encontrada...\n";
  }
}

void listarClientes(struct Cliente cliente[], int n) {
  // Algoritmo de ordenamiento de burbuja
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strcmp(cliente[j].nombre, cliente[j + 1].nombre) > 0) {
        // Intercambiar nombres[j] y nombres[j + 1]
        char temp[50];
        strcpy(temp, cliente[j].nombre);
        strcpy(cliente[j].nombre, cliente[j + 1].nombre);
        strcpy(cliente[j + 1].nombre, temp);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << "Identificación: " << cliente[i].id << endl
              << "Nombre: " << cliente[i].nombre << endl
              << "Puntos vigentes: " << cliente[i].puntosVigentes << endl;
  }
}

void comprarTextil(struct Cliente cliente[], int n) {
  int id;
  std::cout << "Ingrese una identificación: ";
  cin >> id;

  // Se busca si la id ingresada esta registrada, si lo esta, se pide el valor
  // de la compra.
  int x; // Entra por referencia a la función para guardar la posicion del
         // cliente en el arreglo.
  if (buscarId(id, cliente, x, n)) {
    float precio;
    std::cout << "Ingrese el precio de la compra: ";
    cin >> precio;

    // verifica si tiene suficientes puntos.
    if (cliente[x].puntosVigentes < 5000) {
      std::cout << "No tiene suficientes puntos para redimir.";
      return;
    }

    // Se calcula el descuento. (el descuento es del 40% si el valor de la
    // compra es mayor a $100.000)
    if (precio > 100000) {
      int descuento = precio * 0.4;
      precio -= descuento;
      cliente[x].puntosVigentes -= 5000;
      cliente[x].puntosRedimidos += 5000;
      std::cout << "Has redimido 5000 puntos. Tu nuevo total de compra es: $"
                << precio << endl;
      horaRedencion(cliente, x);
    } else {
      std::cout
          << "El valor de la compra debe ser mayor a $100.000 para redimir "
             "puntos."
          << endl;
    }
  }
}

void comprarElectrodomestico(struct Cliente cliente[], int n) {
  int id;
  std::cout << "Ingrese una identificación: ";
  cin >> id;

  // Se busca si la id ingresada esta registrada, si lo esta, se pide el valor
  // de la compra.
  int x;
  if (buscarId(id, cliente, x, n)) {
    float precio;
    std::cout << "Ingrese el precio de la compra: ";
    cin >> precio;

    // verifica si tiene suficientes puntos.
    if (cliente[x].puntosVigentes < 8000) {
      std::cout << "No tiene suficientes puntos para redimir.";
      return;
    }

    // Se calcula el descuento. (el descuento es del 25% si el valor de la
    // compra es mayor a $500.000)
    if (precio > 500000) {
      int descuento = precio * 0.25;
      precio -= descuento;
      cliente[x].puntosVigentes -= 8000;
      cliente[x].puntosRedimidos += 8000;
      std::cout << "Has redimido 8000 puntos. Tu nuevo total de compra es: $"
                << precio << endl;
      horaRedencion(cliente, x);
    } else {
      std::cout
          << "El valor de la compra debe ser mayor a $500.000 para redimir "
             "puntos."
          << endl;
    }
  }
}

void comprarMercado(struct Cliente cliente[], int n) {
  int id;
  std::cout << "Ingrese una identificación: ";
  cin >> id;

  // Se busca si la id ingresada esta registrada, si lo esta, se pide el valor
  // de la compra.
  int x;
  if (buscarId(id, cliente, x, n)) {
    float precio;
    std::cout << "Ingrese el precio de la compra: ";
    cin >> precio;

    // verifica si tiene suficientes puntos.
    if (cliente[x].puntosVigentes < 8000) {
      std::cout << "No tiene suficientes puntos para redimir.";
      return;
    }

    // Se calcula el descuento. (el descuento es del 10% si el valor de la
    // compra es mayor a $100.000)
    if (precio > 100000) {
      int descuento = precio * 0.1;
      precio -= descuento;
      cliente[x].puntosVigentes -= 10000;
      cliente[x].puntosRedimidos += 10000;
      std::cout << "Has redimido 8000 puntos. Tu nuevo total de compra es: $"
                << precio << endl;
      horaRedencion(cliente, x);
    } else {
      std::cout
          << "El valor de la compra debe ser mayor a $100.000 para redimir "
             "puntos."
          << endl;
    }
  }
}

void eliminarClientes(struct Cliente cliente[], int n) {
  long cod_2;
  std::cout << "Digite la identificacion del cliente que quiere eliminar: "
            << endl;
  cin >> cod_2;

  int a = 0;

  for (int x = 0; x < n; x++) {
    if (cliente[x].id == cod_2) {
      std::cout << "Se ha eliminado al cliente " << cliente[x].nombre << endl;
      cliente[x].id = 0;
      cliente[x].telefono = 0;
      cliente[x].puntosVigentes = 0;
      cliente[x].puntosRedimidos = 0;
      cliente[x].fechaRedencion.tm_mday = 0;
      cliente[x].fechaRedencion.tm_mon = 0;
      cliente[x].fechaRedencion.tm_year = 0;
      cliente[x].fechaAsignacion.tm_mday = 0;
      cliente[x].fechaAsignacion.tm_mon = 0;
      cliente[x].fechaAsignacion.tm_year = 0;
      for (int i = 0; i < 50; i++) {
        cliente[x].nombre[i] = '\0';
        cliente[x].direccion[i] = '\0';
      }
      a = 1;
      break;
    }
  }

  if (a == 0) {
    std::cout << "No se ha encontrado al cliente, intentelo denuevo" << endl;
  }
}
