#ifndef TIENDA_H
#define TIENDA_H
#include <vector>
#include <string>

using namespace std;

class Producto;
class Cliente;
class Venta;

class Tienda {
    string nombreTienda;
    vector<Producto*> inventario;
    vector<Cliente*> clientes;
    vector<Venta*> ventas;

public:
    Tienda();
    Tienda(string nombreTienda);
    ~Tienda();
    const string& getNombreTienda() const;
    const vector<Producto*>& getInventario() const;
    const vector<Cliente*>& getClientes() const;
    const vector<Venta*>& getVentas() const;

    void agregarProducto(Producto* producto);
    Producto* buscarProductoPorCodigo(const string& codigo);
    void actualizarStockProducto(const string& codigo, int cantidad);
    void eliminarProducto(const string& codigo);
    void mostrarInventario() const;

    void agregarCliente(Cliente* cliente);
    Cliente* buscarClientePorId(const string& identificacion);
    void mostrarClientes() const;

    bool registrarVenta(const string& idCliente, const string& codigoProducto,
                       int cantidad, const string& fecha);
    void mostrarVentas() const;
    void mostrarVentasPorCliente(const string& idCliente) const;

    float calcularValorTotalInventario() const;
    float calcularTotalVentas() const;

    void inicializarDatos();

    void generarReporteInventario() const;
    void generarReporteVentas() const;
};

#endif