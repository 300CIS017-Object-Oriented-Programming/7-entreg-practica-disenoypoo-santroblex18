#include "Venta.h"
#include <iostream>
#include "Cliente.h"
#include "Producto.h"


using namespace std;
int Venta::contadorVentas = 0;
Venta::Venta() {
    contadorVentas++;
    this->idVenta = contadorVentas;
    this->cliente = nullptr;
    this->producto = nullptr;
    this->cantidad = 0;
    this->total = 0.0f;
    this->fecha = "";
    cout << "Venta creada (constructor sin parametros)" << endl;
}


Venta::Venta(Cliente* cliente, Producto* producto, int cantidad, string fecha) {
    contadorVentas++;
    this->idVenta = contadorVentas;
    this->cliente = cliente;
    this->producto = producto;
    this->cantidad = cantidad;
    this->fecha = fecha;
    calcularTotal();
    cout << "Venta #" << idVenta << " creada exitosamente" << endl;
}
Venta::~Venta() {
    cout << "Venta #" << idVenta << " destruida" << endl;
}

int Venta::getIdVenta() const {
    return idVenta;
}
Cliente* Venta::getCliente() const {
    return cliente;
}
Producto* Venta::getProducto() const {
    return producto;
}
int Venta::getCantidad() const {
    return cantidad;
}
float Venta::getTotal() const {
    return total;
}
const string& Venta::getFecha() const {
    return fecha;
}
void Venta::setCliente(Cliente* cliente) {
    this->cliente = cliente;
}

void Venta::setProducto(Producto* producto) {
    this->producto = producto;
}
void Venta::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}
void Venta::setFecha(const string& fecha) {
    this->fecha = fecha;
}

void Venta::calcularTotal() {
    if (producto != nullptr) {
        total = producto->getPrecio() * cantidad;
    }
}

bool Venta::procesarVenta() {
    if (producto == nullptr || cliente == nullptr) {
        cout << "Error: Cliente o producto no validos" << endl;
        return false;
    }

    if (!producto->hayStockDisponible(cantidad)) {
        cout << "Error: Stock insuficiente para el producto '"
             << producto->getNombre() << "'" << endl;
        return false;
    }
    producto->actualizarStock(-cantidad);
    cliente->agregarCompra(this);
    calcularTotal();
    cout << "\n¡Venta procesada exitosamente!" << endl;
    return true;
}
void Venta::mostrarDatos() const {
    cout << "ID Venta: " << idVenta << endl;
    cout << "Fecha: " << fecha << endl;
    if (cliente != nullptr) {
        cout << "Cliente: " << cliente->getNombre() << endl;
    }
    if (producto != nullptr) {
        cout << "Producto: " << producto->getNombre() << endl;
        cout << "Codigo: " << producto->getCodigo() << endl;
    }
    cout << "Cantidad: " << cantidad << endl;
    cout << "Total: $" << total << endl;
}