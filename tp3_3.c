#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CLIENTES 5
#define PRODUCTOS 10

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct Producto
{
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
} Producto;

typedef struct Cliente
{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
} Cliente;

Cliente crearCliente();
void insertaClientes(Cliente *clientes, int cantidadClientes);

int main() {
    int cantidadClientes;

    printf("¿Cuantos clientes va a cargar?: ");
    scanf("%d", &cantidadClientes);
    while (cantidadClientes > CLIENTES) {
        printf("La cantidad de cliente no debe superar el limite (%d)", CLIENTES);
        scanf("%d", &cantidadClientes);
    }

    Cliente *clientes = (Cliente * ) malloc(sizeof(Cliente) * cantidadClientes);
    insertaClientes(clientes, cantidadClientes);

    return 0;
}

void insertaClientes(Cliente *clientes, int cantidadClientes) {
    int i;
    char *BuffNombre; //
    fflush(stdin);

    printf("Ingrese los nombres:\n");
    for(i = 0; i < cantidadClientes; i++) {
        BuffNombre = (char *) malloc(100 * sizeof(char));
        clientes[i].ClienteID = 1 + rand() % 100;
        clientes[i].CantidadProductosAPedir = 1 + rand() % PRODUCTOS;

        gets(BuffNombre);
        clientes[i].NombreCliente = (char *)malloc((strlen(BuffNombre) + 1) * sizeof(char));
        strcpy(clientes[i].NombreCliente, BuffNombre);
    }

    for(i = 0; i < cantidadClientes; i++) {
        printf("%d\n", clientes[i].ClienteID);
        printf("%s\n", clientes[i].NombreCliente);
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