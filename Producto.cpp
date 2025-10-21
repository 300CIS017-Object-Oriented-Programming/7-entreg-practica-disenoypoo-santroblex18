#include "Producto.h"
#include <iostream>
using namespace std;
Producto::Producto() {
    this->codigo = "";
    this->nombre = "";
    this->precio = 0.0f;
    this->cantidadStock = 0;
    cout << "Producto creado (constructor sin parametros)" << endl;
}
Producto::Producto(string codigo, string nombre, float precio, int cantidadStock) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->precio = precio;
    this->cantidadStock = cantidadStock;
    cout << "Producto '" << nombre << "' creado exitosamente" << endl;
}
Producto::~Producto() {
    cout << "Producto '" << nombre << "' destruido" << endl;
}
const string& Producto::getCodigo() const {
    return codigo;
}
const string& Producto::getNombre() const {
    return nombre;
}
float Producto::getPrecio() const {
    return precio;
}
int Producto::getCantidadStock() const {
    return cantidadStock;
}
void Producto::setCodigo(const string& codigo) {
    this->codigo = codigo;
}
void Producto::setNombre(const string& nombre) {
    this->nombre = nombre;
}
void Producto::setPrecio(float precio) {
    this->precio = precio;
}
void Producto::setCantidadStock(int cantidad) {
    this->cantidadStock = cantidad;
}
void Producto::actualizarStock(int cantidad) {
    cantidadStock += cantidad;
}
bool Producto::hayStockDisponible(int cantidad) const {
    return cantidadStock >= cantidad;
}
float Producto::calcularValorTotal() const {
    return precio * cantidadStock;
}
void Producto::mostrarDatos() const {
    cout << "Codigo: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: $" << precio << endl;
    cout << "Stock: " << cantidadStock << " unidades" << endl;
    cout << "Valor total: $" << calcularValorTotal() << endl;
}