#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CLIENTES 5
#define PRODUCTOS 10

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

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
    char *BuffNombreCliente, *BuffNombreProducto;
    fflush(stdin);

    //Setea clienteId, cantidadProductosAPedir y NombreCliente
    printf("Ingrese los nombres:\n");
    for(i = 0; i < cantidadClientes; i++) {
        clientes[i].ClienteID = 1 + rand() % cantidadClientes;
        clientes[i].CantidadProductosAPedir = 1 + rand() % PRODUCTOS;

        BuffNombreCliente = (char *) malloc(100 * sizeof(char));
        gets(BuffNombreCliente);
        clientes[i].NombreCliente = (char *)malloc((strlen(BuffNombreCliente) + 1) * sizeof(char));
        strcpy(clientes[i].NombreCliente, BuffNombreCliente);

        //Setea Productos
        int j;
        clientes[i].Productos = (Producto * ) malloc(sizeof(Producto) * clientes[i].CantidadProductosAPedir);
        for(j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].Cantidad = 1 + rand() % 10;
            clientes[i].Productos[j].PrecioUnitario = 1 + rand() % 100;
            clientes[i].Productos[j].ProductoID = 1 + rand() % PRODUCTOS;

            BuffNombreProducto = (char *) malloc(100 * sizeof(char));
            strcpy(BuffNombreProducto, TiposProductos[rand() % 5]);
            clientes[i].Productos[j].TipoProducto = (char *)malloc((strlen(BuffNombreProducto) + 1) * sizeof(char));
            strcpy(clientes[i].Productos[j].TipoProducto, BuffNombreProducto);
        }
    }

    printf("\n");

    for(i = 0; i < cantidadClientes; i++) {
        printf("Id: %d\n", clientes[i].ClienteID);
        printf("Nombre: %s\n", clientes[i].NombreCliente);
        printf("Cantidad de productos: %d\n", clientes[i].CantidadProductosAPedir);

        printf("Productos--\n");
        printf("\t Cantidad \t ID Producto \t Tipo \t Precio/u");
        int j;
        for(j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            printf("\t %d \t %d \t %s \t %d");
            printf("%s\n",
                clientes[i].Productos[j].TipoProducto,
                clientes[i].Productos[j].ProductoID,
                clientes[i].Productos[j].TipoProducto,
                clientes[i].Productos[j].PrecioUnitario
            );
        }
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