#include <iostream>
#include <limits>

#include "Cliente.h"
#include "Producto.h"
#include "Tienda.h"
using namespace std;

void mostrarMenuPrincipal() {

    cout << "SISTEMA DE GESTION - TIENDA ECOLOGICA" << endl;
    cout << "1.  Agregar producto" << endl;
    cout << "2.  Mostrar inventario" << endl;
    cout << "3.  Actualizar stock de producto" << endl;
    cout << "4.  Eliminar producto" << endl;
    cout << "5.  Agregar cliente" << endl;
    cout << "6.  Mostrar clientes" << endl;
    cout << "7.  Registrar venta" << endl;
    cout << "8.  Mostrar todas las ventas" << endl;
    cout << "9.  Mostrar ventas de un cliente" << endl;
    cout << "10. Calcular valor total del inventario" << endl;
    cout << "11. Generar reporte de inventario" << endl;
    cout << "12. Generar reporte de ventas" << endl;
    cout << "13. Inicializar datos de ejemplo" << endl;
    cout << "0.  Salir" << endl;
    cout << "Seleccione una opcion: ";
}
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void agregarProducto(Tienda* tienda) {
    string codigo, nombre;
    float precio;
    int cantidad;
    cout << "\n--- Agregar Nuevo Producto ---" << endl;
    cout << "Codigo: ";
    cin >> codigo;
    limpiarBuffer();
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Precio: ";
    cin >> precio;
    cout << "Cantidad inicial: ";
    cin >> cantidad;
    Producto* nuevoProducto = new Producto(codigo, nombre, precio, cantidad);
    tienda->agregarProducto(nuevoProducto);
}
void actualizarStock(Tienda* tienda) {
    string codigo;
    int cantidad;
    cout << "\n--- Actualizar Stock ---" << endl;
    cout << "Codigo del producto: ";
    cin >> codigo;

    cout << "Cantidad a agregar (negativo para restar): ";
    cin >> cantidad;

    tienda->actualizarStockProducto(codigo, cantidad);
}

void eliminarProducto(Tienda* tienda) {
    string codigo;

    cout << "\n--- Eliminar Producto ---" << endl;
    cout << "Codigo del producto: ";
    cin >> codigo;

    tienda->eliminarProducto(codigo);
}

void agregarCliente(Tienda* tienda) {
    string identificacion, nombre, telefono;

    cout << "\n--- Agregar Nuevo Cliente ---" << endl;
    cout << "Identificacion: ";
    cin >> identificacion;
    limpiarBuffer();

    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Telefono: ";
    getline(cin, telefono);

    Cliente* nuevoCliente = new Cliente(identificacion, nombre, telefono);
    tienda->agregarCliente(nuevoCliente);
}

void registrarVenta(Tienda* tienda) {
    string idCliente, codigoProducto, fecha;
    int cantidad;

    cout << "\n--- Registrar Nueva Venta ---" << endl;
    cout << "ID del cliente: ";
    cin >> idCliente;

    cout << "Codigo del producto: ";
    cin >> codigoProducto;

    cout << "Cantidad: ";
    cin >> cantidad;

    limpiarBuffer();
    cout << "Fecha (DD/MM/AAAA): ";
    getline(cin, fecha);

    tienda->registrarVenta(idCliente, codigoProducto, cantidad, fecha);
}

void mostrarVentasCliente(Tienda* tienda) {
    string idCliente;

    cout << "\n--- Historial de Ventas ---" << endl;
    cout << "ID del cliente: ";
    cin >> idCliente;

    tienda->mostrarVentasPorCliente(idCliente);
}
int main() {
    Tienda* miTienda = new Tienda("Tienda Ecologica Verde");
    int opcion;
    bool continuar = true;
    cout << "\n¡Bienvenido al Sistema de Gestion de la Tienda Ecologica!" << endl;

    while (continuar) {
        mostrarMenuPrincipal();
        cin >> opcion;

        if (cin.fail()) {
            limpiarBuffer();
            cout << "\nError: Ingrese un numero valido" << endl;
            continue;
        }
        switch (opcion) {
            case 1:
                agregarProducto(miTienda);
            break;
            case 2:
                miTienda->mostrarInventario();
            break;
            case 3:
                actualizarStock(miTienda);
            break;
            case 4:
                eliminarProducto(miTienda);
            break;
            case 5:
                agregarCliente(miTienda);
            break;
            case 6:
                miTienda->mostrarClientes();
            break;
            case 7:
                registrarVenta(miTienda);
            break;
            case 8:
                miTienda->mostrarVentas();
            break;
            case 9:
                mostrarVentasCliente(miTienda);
            break;
            case 10:
                cout << "\nValor total del inventario: $"
                     << miTienda->calcularValorTotalInventario() << endl;
            break;
            case 11:
                miTienda->generarReporteInventario();
            break;
            case 12:
                miTienda->generarReporteVentas();
            break;
            case 13:
                miTienda->inicializarDatos();
            break;
            case 0:
                cout << "\n¡Gracias por usar el sistema!" << endl;
            continuar = false;
            break;

            default:
                cout << "\nOpcion invalida. Intente de nuevo." << endl;
            break;
        }
        if (continuar) {
            cout << "\nPresione Enter para continuar...";
            limpiarBuffer();
            cin.get();
        }
    }
    delete miTienda;
    return 0;
}