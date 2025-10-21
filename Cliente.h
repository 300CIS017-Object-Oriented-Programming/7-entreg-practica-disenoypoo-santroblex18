#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
using namespace std;

class Venta;
class Cliente {
    string identificacion;
    string nombre;
    string telefono;
    vector<Venta*> historialCompras;

public:
    Cliente();
    Cliente(string identificacion, string nombre, string telefono);
    ~Cliente();
    const string& getIdentificacion() const;
    const string& getNombre() const;
    const string& getTelefono() const;
    const vector<Venta*>& getHistorialCompras() const;
    void setIdentificacion(const string& identificacion);
    void setNombre(const string& nombre);
    void setTelefono(const string& telefono);
    void agregarCompra(Venta* venta);
    float calcularTotalGastado() const;
    void mostrarDatos() const;
    void mostrarHistorial() const;
};

#endif