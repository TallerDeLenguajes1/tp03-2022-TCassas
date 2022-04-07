#include <stdio.h>
#define CLIENTES 5
#define PRODUCTOS 10

char *TiposProductos[]={"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct Producto {
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
} Producto;

typedef struct Cliente {
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
} Cliente;

Cliente crearCliente();
void insertaClientes(Cliente * clientes, int cantidadClientes);

int main() {
    int cantidadClientes;
    Cliente clientes[CLIENTES];

    printf("¿Cuantos clientes va a cargar?: ");
    scanf("%d", &cantidadClientes);
    while(cantidadClientes > CLIENTES) {
        printf("La cantidad de cliente no debe superar el limite (%d)", CLIENTES);
        scanf("%d", &cantidadClientes);
    }

    insertaClientes(clientes, cantidadClientes);
    
    return 0;
}

void insertaClientes(Cliente * clientes, int cantidadClientes) {
    int i;
    for(i = 0; i < cantidadClientes; i++) {
        clientes[i] = crearCliente();
    }
}

Cliente crearCliente() {
    Cliente nuevoCliente;
    printf("Ingrese los siguientes datos \n");
    printf("Id del cliente: \n");
    scanf("%d", nuevoCliente.ClienteID);
    printf("%d", nuevoCliente.ClienteID);
    return nuevoCliente;
}