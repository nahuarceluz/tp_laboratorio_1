#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
} eEmpleado;

#endif // EMPLEADOS_H_INCLUDED

int altaEmpleado(eEmpleado empleados[], int tam, int id);
int menuEmpleados();
int buscarLibre(eEmpleado empleados[], int tam);
eEmpleado newEmpleado(int id, char nombre[], char apellido[], float salario, int sector);
void inicializarEmpleados(eEmpleado empleados[], int tam);
void mostrarEmpleados(eEmpleado empleados[], int tam);
void mostrarEmpleado(eEmpleado empleados);
int buscarEmpleado(int id, eEmpleado empleados[], int tam);
int bajaEmpleado(eEmpleado empleados[], int tam);
int modificarEmpleado(eEmpleado empleados[], int tam);
void ordenarEmpleados(eEmpleado empleados[], int tam);
void informarEmpleados(eEmpleado empleados[], int tam);
int salarioPromedio(eEmpleado empleados[], int tam);
