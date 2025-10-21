#include "Cliente.h"
#include "Venta.h"
#include <iostream>
using namespace std;
Cliente::Cliente() {
    this->identificacion = "";
    this->nombre = "";
    this->telefono = "";
    cout << "Cliente creado (constructor sin parametros)" << endl;
}

Cliente::Cliente(string identificacion, string nombre, string telefono) {
    this->identificacion = identificacion;
    this->nombre = nombre;
    this->telefono = telefono;
    cout << "Cliente '" << nombre << "' creado exitosamente" << endl;
}

Cliente::~Cliente() {
    cout << "Cliente '" << nombre << "' destruido" << endl;

}
const string& Cliente::getIdentificacion() const {
    return identificacion;
}
const string& Cliente::getNombre() const {
    return nombre;
}
const string& Cliente::getTelefono() const {
    return telefono;
}
const vector<Venta*>& Cliente::getHistorialCompras() const {
    return historialCompras;
}
void Cliente::setIdentificacion(const string& identificacion) {
    this->identificacion = identificacion;
}
void Cliente::setNombre(const string& nombre) {
    this->nombre = nombre;
}
void Cliente::setTelefono(const string& telefono) {
    this->telefono = telefono;
}
void Cliente::agregarCompra(Venta* venta) {
    historialCompras.push_back(venta);
}
float Cliente::calcularTotalGastado() const {
    float total = 0.0f;
    for (int i = 0; i < historialCompras.size(); i++) {
        total += historialCompras[i]->getTotal();
    }
    return total;
}
void Cliente::mostrarDatos() const {
    cout << "================================" << endl;
    cout << "Identificacion: " << identificacion << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Total gastado: $" << calcularTotalGastado() << endl;
    cout << "Numero de compras: " << historialCompras.size() << endl;
    cout << "================================" << endl;
}
void Cliente::mostrarHistorial() const {
    cout << "\n=== Historial de compras de " << nombre << " ===" << endl;
    if (historialCompras.empty()) {
        cout << "No hay compras registradas" << endl;
        return;
    }
    for (int i = 0; i < historialCompras.size(); i++) {
        cout << "\nCompra #" << (i + 1) << ":" << endl;
        historialCompras[i]->mostrarDatos();
    }
}