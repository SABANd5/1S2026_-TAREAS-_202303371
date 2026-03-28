#include <iostream>
#include <string>

using namespace std;

class CuentaBancaria
{
private:
    // ATRIBUTOS
    string titular;
    string numeroCuenta;
    double saldo;

public:
    // CONSTRUCTOR
    CuentaBancaria(string _titular, string _numero, double _saldoInicial)
    {
        titular = _titular;
        numeroCuenta = _numero;
        // Validamos que no inicie en negativo
        if (_saldoInicial < 0)
        {
            saldo = 0;
        }
        else
        {
            saldo = _saldoInicial;
        }
    }

    // MÉTODOS
    void depositar(double cantidad)
    {
        cout << "[" << titular << "] Intentando depositar Q" << cantidad << "..." << endl;
        if (cantidad > 0)
        {
            saldo += cantidad;
            cout << "-> Deposito realizado. Nuevo saldo: Q" << saldo << endl;
        }
        else
        {
            cout << "-> Error: Cantidad invalida." << endl;
        }
        cout << "--------------------------------" << endl;
    }

    void retirar(double cantidad)
    {
        cout << "[" << titular << "] Intentando retirar Q" << cantidad << "..." << endl;
        if (cantidad > saldo)
        {
            cout << "-> Error: Fondos insuficientes. Saldo actual: Q" << saldo << endl;
        }
        else
        {
            saldo -= cantidad;
            cout << "-> Retiro realizado. Te quedan: Q" << saldo << endl;
        }
        cout << "--------------------------------" << endl;
    }

    void mostrarInfo()
    {
        cout << "ESTADO DE CUENTA: " << numeroCuenta << endl;
        cout << "Titular: " << titular << endl;
        cout << "Saldo: Q" << saldo << endl;
        cout << "--------------------------------" << endl;
    }
};

int main()
{
    // Instancia 1
    CuentaBancaria cuenta1("Julio Ramirez", "GT-001", 700.00);

    // Instancia 2 
    CuentaBancaria cuenta2("José García", "GT-002", 50.00);

    // PRUEBAS CUENTA 1
    cuenta1.mostrarInfo();
    cuenta1.retirar(200);
    cuenta1.depositar(100);

    cout << endl; 

    // PRUEBAS CUENTA 2
    cuenta2.mostrarInfo();
    cuenta2.retirar(100);
    cuenta2.depositar(500);
    cuenta2.retirar(100);

    return 0;
}