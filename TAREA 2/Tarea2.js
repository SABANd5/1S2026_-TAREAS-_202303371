// Importamos los módulos nativos requeridos
const fs = require('fs');
const readline = require('readline');

// Configuramos readline para la entrada y salida en consola
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// Función para mostrar el menú interactivo
function mostrarMenu() {
    console.log("\n=== MENÚ PRINCIPAL ===");
    console.log("1. Leer archivo.inv e imprimir su contenido.");
    console.log("2. Salir.");
    
    rl.question("Seleccione una opción: ", (opcion) => {
        if (opcion === '1') {
            leerInventario();
        } else if (opcion === '2') {
            console.log("Saliendo del programa. ¡Éxitos!");
            rl.close(); // Esta es la única forma de terminar el programa
        } else {
            console.log("Opción no válida. Intente de nuevo.");
            mostrarMenu(); // Vuelve a mostrar el menú si hay un error de tipeo
        }
    });
}

// Función para leer el archivo con manejo de excepciones
function leerInventario() {
    try {
        // Leemos el archivo de forma síncrona
        const data = fs.readFileSync('inventario.inv', 'utf8');
        console.log("\n--- Contenido de inventario.inv ---");
        console.log(data);
        console.log("-----------------------------------");
    } catch (error) {
        // Si el archivo no existe o hay error, entra al catch
        console.log("\n[ERROR]: No se pudo leer el archivo. Verifique que 'inventario.inv' exista en la carpeta.");
    }
    
    // Tanto si lee correctamente como si falla, el programa NO termina y vuelve al menú
    mostrarMenu(); 
}

// Iniciamos la ejecución del programa llamando al menú por primera vez
mostrarMenu();