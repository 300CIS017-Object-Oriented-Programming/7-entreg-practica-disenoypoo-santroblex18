#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;

class Producto {
private:
    string codigo;
    string nombre;
    float precio;
    int cantidadStock;

public:
    Producto();
    Producto(string codigo, string nombre, float precio, int cantidadStock);
    ~Producto();
    const string& getCodigo() const;
    const string& getNombre() const;
    float getPrecio() const;
    int getCantidadStock() const;
    void setCodigo(const string& codigo);
    void setNombre(const string& nombre);
    void setPrecio(float precio);
    void setCantidadStock(int cantidad);
    void actualizarStock(int cantidad);
    bool hayStockDisponible(int cantidad) const;
    float calcularValorTotal() const;
    void mostrarDatos() const;
};

#endif