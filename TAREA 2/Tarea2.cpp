#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

// Función para leer el archivo con manejo de excepciones
void leerInventario() {
    try {
        ifstream archivo("inventario.inv");
        
        // Si el archivo no existe o no se puede abrir, lanzamos la excepción
        if (!archivo.is_open()) {
            throw runtime_error("No se pudo leer el archivo. Verifique que 'inventario.inv' exista en la carpeta.");
        }

        cout << "\n--- Contenido de inventario.inv ---\n";
        string linea;
        
        // Leemos línea por línea usando métodos de la librería fstream
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        cout << "-----------------------------------\n";
        
        archivo.close();

    } catch (const exception& e) {
        // El catch atrapa el error, lo muestra y el programa puede continuar
        cout << "\n[ERROR]: " << e.what() << "\n";
    }
}

// Función principal que maneja el menú interactivo
int main() {
    string opcion;

    do {
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Leer archivo.inv e imprimir su contenido.\n";
        cout << "2. Salir.\n";
        cout << "Seleccione una opcion: ";
        
        cin >> opcion;
        
        if (opcion == "1") {
            leerInventario();
        } else if (opcion == "2") {
            cout << "Saliendo del programa. ¡Exitos!\n";
        } else {
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
        
    // El ciclo continúa hasta que el usuario elige exactamente la opción 2
    } while (opcion != "2");

    return 0;
}