#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "empleados.h"

int menuEmpleados()
{
    int opcion;

    system("cls");
    printf("Bienvenido al menu de empleados! Seleccione una opcion..\n");
    printf("1. Alta Empleado.\n");
    printf("2. Modificar Empleado.\n");
    printf("3. Baja Empleado.\n");
    printf("4. Informar.\n");
    printf("5. Salir\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eEmpleado empleados[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(empleados[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void inicializarEmpleados(eEmpleado empleados[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        empleados[i].isEmpty = 1;
    }
}

int altaEmpleado(eEmpleado empleados[], int tam, int id)
{

    int todoOk = 0;
    int indice;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;

    system("cls");
    printf("Alta Empleados! Ingrese sus datos.\n");

    indice = buscarLibre(empleados, tam);

    if( indice == -1)
    {
        printf("Lista llena, no se ha podido dar el alta de este empleado.\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(apellido);

        printf("Ingrese salario: ");
        scanf("%f", &salario);

        printf("Ingrese sector: ");
        fflush(stdin);
        scanf("%d", &sector);

        empleados[indice] = newEmpleado(id, nombre, apellido, salario, sector);
        todoOk = 1;
    }

    return todoOk;
}

eEmpleado newEmpleado(int id, char nombre[], char apellido[], float salario, int sector)
{
    eEmpleado nuevoEmpleado;
    nuevoEmpleado.id = id;
    strcpy(nuevoEmpleado.nombre, nombre);
    strcpy(nuevoEmpleado.apellido, apellido);
    nuevoEmpleado.salario = salario;
    nuevoEmpleado.sector = sector;
    nuevoEmpleado.isEmpty = 0;

    return nuevoEmpleado;
}

void mostrarEmpleado(eEmpleado empleados)
{
    printf("% 2d%10s     %10s        %.2f        %2d\n", empleados.id, empleados.nombre, empleados.apellido, empleados.salario, empleados.sector);
}

void mostrarEmpleados(eEmpleado empleados[], int tam)
{
    int flag = 0;
    system("cls");
    printf(" Id      Nombre       Apellido      Salario      Sector\n");
    for(int i=0; i < tam; i++)
    {
        if(empleados[i].isEmpty == 0)
        {
            mostrarEmpleado(empleados[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("No hay empleados para mostrar.\n");
    }
}
int bajaEmpleado(eEmpleado empleados[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    system("cls");
    printf("**** Baja Empleado ****\n\n");

    printf("Ingrese Id del Empleado: ");
    scanf("%d", &id);

    indice = buscarEmpleado(id, empleados, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese id registrado\n");
    }
    else
    {
        mostrarEmpleado(empleados[indice]);
        printf("\nConfirma eliminacion?: ");
        fflush(stdin);
        confirma = getchar();
        if( confirma == 's')
        {
            empleados[indice].isEmpty = 1;
            printf("\n\nSe ha eliminado el empleado del sistema\n");
            todoOk = 1;
        }
        else
        {
            printf("\n\nSe ha cancelado la baja\n");
        }
    }
    return todoOk;
}

int buscarEmpleado(int id, eEmpleado empleados[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( empleados[i].isEmpty == 0 && empleados[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int modificarEmpleado(eEmpleado empleados[], int tam)
{

    int todoOk = 0;
    int indice;
    int opcion;
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    eEmpleado nuevoEmpleado;


    system("cls");
    printf("**** Modificar Alumno ****\n\n");

    printf("Ingrese id del Empleado: ");
    scanf("%d", &id);

    indice = buscarEmpleado(id, empleados, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado a ese empleado\n");
    }
    else
    {
        mostrarEmpleado(empleados[indice]);

        printf("Modificar\n\n");
        printf("1. Id\n");
        printf("2. Nombre\n");
        printf("3. Apellido\n");
        printf("4. Salario\n");
        printf("5. Sector\n");

        printf("Ingrese opcion:");
        scanf("%d", &opcion);

        if(opcion == 1)
        {
            printf("Ingrese id: ");
            scanf("%d", &id);
            empleados[indice].id = id;
            printf("El id del empleado ha sido actualizado correctamente.\n");
            todoOk = 1;
        }
        else if(opcion == 2)
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);
            strcpy(empleados[indice].nombre, nombre);
            printf("El nombre del empleado se ha actualizado correctamente.\n");
            todoOk = 1;

        }
        else if(opcion == 3)
        {
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(apellido);
            strcpy(empleados[indice].apellido, apellido);
            printf("El apellido del empleado se ha actualizado correctamente.\n");
            todoOk = 1;
        }
        else if(opcion == 4)
        {
            printf("Ingrese salario: ");
            scanf("%.2f", &salario);
            empleados[indice].salario = salario;
            printf("El salario del empleado se ha actualizado correctamente.\n");
            todoOk = 1;
        }
        else if(opcion == 5)
        {
            printf("Ingrese sector: ");
            scanf("%d", &sector);
            empleados[indice].sector = sector;
            printf("El sector del empleado se ha actualizado correctamente.\n");
            todoOk = 1;
        }
        else
        {
            printf("No es una opcion valida\n");
        }
    }
    return todoOk;
}

void ordenarEmpleados(eEmpleado empleados[], int tam)
{
    eEmpleado aux;
    int sector;


    for(int i=0; i < tam-1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {
            if(strcmp(empleados[i].apellido, empleados[j].apellido) > 0 && empleados[i].sector > empleados[j].sector)
            {
                aux = empleados[i];
                empleados[i] = empleados[j];
                empleados[j] = aux;
            }
        }
    }
}

/*void ordenarEmpleados(eEmpleado empleados[], int tam)
{
    eEmpleado aux;
    eEmpleado auxA[100];

    for(int i= 0; i<tam-1; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if(empleados[i].sector > empleados[j].sector)
            {
                aux = empleados[j];
                empleados[j] = empleados[i];
                empleados[i] = aux;
            }
        }
    }
}*/

int subMenu()
{
    int opcion;

    system("cls");
    printf("1. Listado de Empleados(ordenados alfabeticamente y por Sector)\n");
    printf("2. Total y promedio de los salarios. Empleados que superan el salario promedio\n");
    printf("3. Salir.\n");

    printf("Ingresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void informarEmpleados(eEmpleado empleados[], int tam)
{
    char salir = 'n';
    system("cls");
    printf("**Listado de empleados**\n\n");

    do
    {
        switch(subMenu())
        {
        case 1:
            printf("\nEmpleados ordenados: alfabeticamente - sector\n\n");
            ordenarEmpleados(empleados, tam);
            mostrarEmpleados(empleados, tam);
            system("pause");
            break;
        case 2:
            salarioPromedio(empleados, tam);
            system("pause");
            break;
        case 3:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getchar();
            break;
        default:
            printf("\nOpcion Invalida!\n\n");
            system("pause");
            break;
        }
    }
    while(salir == 'n');
}



int salarioPromedio(eEmpleado empleados[], int tam)
{
    eEmpleado salary;
    int acumulador = 0;
    float promedio;

    for(int i=0; i<tam; i++)
    {
        acumulador = acumulador + empleados[i].salario;
    }

    promedio = acumulador / tam;

    printf("El total es %d y el promedio es %.2f\n", acumulador, promedio);
}
