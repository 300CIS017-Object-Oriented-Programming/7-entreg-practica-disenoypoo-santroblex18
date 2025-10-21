#ifndef VENTA_H
#define VENTA_H
#include <string>
using namespace std;

class Producto;
class Cliente;

class Venta {
private:
    static int contadorVentas;
    int idVenta;
    Cliente* cliente;
    Producto* producto;
    int cantidad;
    float total;
    string fecha;

public:
    Venta();
    Venta(Cliente* cliente, Producto* producto, int cantidad, string fecha);
    ~Venta();
    int getIdVenta() const;
    Cliente* getCliente() const;
    Producto* getProducto() const;
    int getCantidad() const;
    float getTotal() const;
    const string& getFecha() const;
    void setCliente(Cliente* cliente);
    void setProducto(Producto* producto);
    void setCantidad(int cantidad);
    void setFecha(const string& fecha);
    void calcularTotal();
    bool procesarVenta();
    void mostrarDatos() const;
};

#endif