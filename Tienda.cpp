#include "Tienda.h"
#include "Producto.h"
#include "Cliente.h"
#include "Venta.h"
#include <iostream>
using namespace std;
Tienda::Tienda() {
    this->nombreTienda = "Tienda Ecologica";
    cout << "Tienda creada (constructor sin parametros)" << endl;
}
Tienda::Tienda(string nombreTienda) {
    this->nombreTienda = nombreTienda;
    cout << "Tienda '" << nombreTienda << "' creada exitosamente" << endl;
}
Tienda::~Tienda() {
    cout << "\nLiberando memoria de la tienda..." << endl;
    for (int i = 0; i < ventas.size(); i++) {
        delete ventas[i];
    }
    for (int i = 0; i < clientes.size(); i++) {
        delete clientes[i];
    }
    for (int i = 0; i < inventario.size(); i++) {
        delete inventario[i];
    }
    cout << "Memoria de la tienda liberada correctamente" << endl;
}
const string& Tienda::getNombreTienda() const {
    return nombreTienda;
}
const vector<Producto*>& Tienda::getInventario() const {
    return inventario;
}
const vector<Cliente*>& Tienda::getClientes() const {
    return clientes;
}
const vector<Venta*>& Tienda::getVentas() const {
    return ventas;
}
void Tienda::agregarProducto(Producto* producto) {
    inventario.push_back(producto);
    cout << "Producto agregado al inventario" << endl;
}

Producto* Tienda::buscarProductoPorCodigo(const string& codigo) {
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i]->getCodigo() == codigo) {
            return inventario[i];
        }
    }
    return nullptr;
}

void Tienda::actualizarStockProducto(const string& codigo, int cantidad) {
    Producto* producto = buscarProductoPorCodigo(codigo);
    if (producto != nullptr) {
        producto->actualizarStock(cantidad);
        cout << "Stock actualizado correctamente" << endl;
    } else {
        cout << "Producto no encontrado" << endl;
    }
}
void Tienda::eliminarProducto(const string& codigo) {
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i]->getCodigo() == codigo) {
            delete inventario[i];
            inventario.erase(inventario.begin() + i);
            cout << "Producto eliminado del inventario" << endl;
            return;
        }
    }
    cout << "Producto no encontrado" << endl;
}
void Tienda::mostrarInventario() const {
    cout << "\n======== INVENTARIO DE " << nombreTienda << " ========" << endl;
    if (inventario.empty()) {
        cout << "No hay productos en el inventario" << endl;
        return;
    }

    for (int i = 0; i < inventario.size(); i++) {
        cout << "\nProducto #" << (i + 1) << ":" << endl;
        inventario[i]->mostrarDatos();
    }
    cout << "\nValor total del inventario: $" << calcularValorTotalInventario() << endl;
}
void Tienda::agregarCliente(Cliente* cliente) {
    clientes.push_back(cliente);
    cout << "Cliente agregado al sistema" << endl;
}
Cliente* Tienda::buscarClientePorId(const string& identificacion) {
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i]->getIdentificacion() == identificacion) {
            return clientes[i];
        }
    }
    return nullptr;
}
void Tienda::mostrarClientes() const {
    cout << "\n======== CLIENTES DE " << nombreTienda << " ========" << endl;
    if (clientes.empty()) {
        cout << "No hay clientes registrados" << endl;
        return;
    }
    for (int i = 0; i < clientes.size(); i++) {
        cout << "\nCliente #" << (i + 1) << ":" << endl;
        clientes[i]->mostrarDatos();
    }
}
bool Tienda::registrarVenta(const string& idCliente, const string& codigoProducto,
                            int cantidad, const string& fecha) {
    Cliente* cliente = buscarClientePorId(idCliente);
    Producto* producto = buscarProductoPorCodigo(codigoProducto);

    if (cliente == nullptr) {
        cout << "Error: Cliente no encontrado" << endl;
        return false;
    }
    if (producto == nullptr) {
        cout << "Error: Producto no encontrado" << endl;
        return false;
    }
    Venta* nuevaVenta = new Venta(cliente, producto, cantidad, fecha);
    if (nuevaVenta->procesarVenta()) {
        ventas.push_back(nuevaVenta);
        return true;
    } else {
        delete nuevaVenta;
        return false;
    }
}
void Tienda::mostrarVentas() const {
    cout << "\n======== VENTAS DE " << nombreTienda << " ========" << endl;
    if (ventas.empty()) {
        cout << "No hay ventas registradas" << endl;
        return;
    }
    for (int i = 0; i < ventas.size(); i++) {
        ventas[i]->mostrarDatos();
    }
    cout << "\nTotal de ventas: $" << calcularTotalVentas() << endl;
}
void Tienda::mostrarVentasPorCliente(const string& idCliente) const {
    Cliente* cliente = nullptr;
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i]->getIdentificacion() == idCliente) {
            cliente = clientes[i];
            break;
        }
    }
    if (cliente != nullptr) {
        cliente->mostrarHistorial();
    } else {
        cout << "Cliente no encontrado" << endl;
    }
}
float Tienda::calcularValorTotalInventario() const {
    float total = 0.0f;
    for (int i = 0; i < inventario.size(); i++) {
        total += inventario[i]->calcularValorTotal();
    }
    return total;
}

float Tienda::calcularTotalVentas() const {
    float total = 0.0f;
    for (int i = 0; i < ventas.size(); i++) {
        total += ventas[i]->getTotal();
    }
    return total;
}

// Método para inicializar datos de ejemplo
void Tienda::inicializarDatos() {
    cout << "\n=== Inicializando datos de ejemplo ===" << endl;
    Producto* prod1 = new Producto("P001", "Jabon Ecologico", 5000, 50);
    Producto* prod2 = new Producto("P002", "Shampoo Natural", 15000, 30);
    Producto* prod3 = new Producto("P003", "Bolsas Reutilizables", 8000, 100);
    Producto* prod4 = new Producto("P004", "Cepillo de Bambu", 12000, 40);
    Producto* prod5 = new Producto("P005", "Detergente Biodegradable", 20000, 25);

    agregarProducto(prod1);
    agregarProducto(prod2);
    agregarProducto(prod3);
    agregarProducto(prod4);
    agregarProducto(prod5);
    Cliente* cliente1 = new Cliente("1234567890", "Maria Rodriguez", "3001234567");
    Cliente* cliente2 = new Cliente("0987654321", "Juan Perez", "3109876543");
    Cliente* cliente3 = new Cliente("1122334455", "Ana Lopez", "3201122334");

    agregarCliente(cliente1);
    agregarCliente(cliente2);
    agregarCliente(cliente3);

    cout << "\nDatos de ejemplo inicializados correctamente" << endl;
}
void Tienda::generarReporteInventario() const {
    cout << " REPORTE DE INVENTARIO - " << nombreTienda << " " << endl;
    cout << "\nTotal de productos: " << inventario.size() << endl;
    cout << "Valor total del inventario: $" << calcularValorTotalInventario() << endl;
    cout << "\n--- Productos con bajo stock (< 20 unidades) ---" << endl;
    bool hayBajoStock = false;
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i]->getCantidadStock() < 20) {
            cout << "  - " << inventario[i]->getNombre()
                 << " (Stock: " << inventario[i]->getCantidadStock() << ")" << endl;
            hayBajoStock = true;
        }
    }
    if (!hayBajoStock) {
        cout << "  Todos los productos tienen stock suficiente" << endl;
    }
}

void Tienda::generarReporteVentas() const {
    cout << "   REPORTE DE VENTAS - " << nombreTienda << "  " << endl;
    cout << "\nTotal de ventas realizadas: " << ventas.size() << endl;
    cout << "Ingresos totales: $" << calcularTotalVentas() << endl;
    if (!clientes.empty()) {
        cout << "\n--- Top clientes por monto gastado ---" << endl;
        for (int i = 0; i < clientes.size(); i++) {
            cout << "  " << (i + 1) << ". " << clientes[i]->getNombre()
                 << " - $" << clientes[i]->calcularTotalGastado() << endl;
        }
    }
}