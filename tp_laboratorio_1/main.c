#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int a;
    int b;
    int respuesta;
    char letra;

    printf("Bienvendido a la calculadora virtual.\n");
    printf("Para mostrar el menu de opciones, ingrese la tecla m: ");
    scanf("%c", &letra);
    system("cls");
    if(letra == 'm')
    {
        do
            {
                system("cls");
                printf("---Menu de opciones---\n");
                printf("1- Ingresar primer operando (A=x)\n");
                printf("2- Ingresar segundo operando (B=y)\n");
                printf("3- Calcular la suma (A+B)\n");
                printf("4- Calcular la resta (A-B)\n");
                printf("5- Calcular la division (A/B)\n");
                printf("6- Calcular la multiplicacion (A*B)\n");
                printf("7- Calcular el factorial (A!)\n");
                printf("8- Calcular todas las operaciones\n");
                printf("9- Salir\n");

                printf("Ingrese opcion: ");
                scanf("%d", &opcion);


                switch(opcion)
                {
                case 1:
                    printf("Primer operando:\n");
                    printf("Ingrese numero: ");
                    scanf("%d", &a);
                    printf("A = %d\n", a);
                    system("pause");
                    break;
                case 2:
                    printf("Segundo operando:\n");
                    printf("Ingrese numero: ");
                    scanf("%d", &b);
                    printf("B = %d\n", b);
                    system("pause");
                    break;
                case 3:
                    printf("Operacion Suma:\n");
                    printf("Ingrese el primer numero: ");
                    scanf("%d", &a);
                    printf("Ingrese el segundo numero: ");
                    scanf("%d", &b);
                    respuesta = suma(a, b);
                    printf("El resultado de la suma es: %d\n", respuesta);
                    system("pause");
                    break;
                case 4:
                    printf("Operacion Resta:\n");
                    printf("Ingrese el primer numero: ");
                    scanf("%d", &a);
                    printf("Ingrese el segundo numero: ");
                    scanf("%d", &b);
                    respuesta = resta(a, b);
                    printf("El resultado de la resta es: %d\n", respuesta);
                    system("pause");
                    break;
                case 5:
                    printf("Operacion Division:\n");
                    printf("Ingrese el primer numero: ");
                    scanf("%d", &a);
                    printf("Ingrese el segundo numero: ");
                    scanf("%d", &b);
                    respuesta = division(a, b);
                    if(respuesta == 0)
                    {
                        printf("Error. Ingrese nuevamente los operando.\n");
                        system("pause");
                        break;
                    }
                    printf("El resultado de la division es: %d\n", respuesta);
                    system("pause");
                    break;
                case 6:
                    printf("Operacion Multiplicacion:\n");
                    printf("Ingrese el primer numero: ");
                    scanf("%d", &a);
                    printf("Ingrese el segundo numero: ");
                    scanf("%d", &b);
                    respuesta  = multiplicacion(a, b);
                    printf("El resultado de la multiplicacion es: %d\n", respuesta);
                    system("pause");
                    break;
                case 7:
                    printf("Operacion Factorial:\n");
                    printf("Ingrese el numero: ");
                    scanf("%d", &a);
                    respuesta = factorial(a);
                    printf("El factorial de %d es %d\n", a, respuesta);
                    system("pause");
                    break;
                case 8:
                    break;
                   case 9:
                    printf("Usted eligio salir.\n");
                    seguir = 'n';
                    break;
                default:
                    printf("Opcion invalida\n");
                }
            }while(seguir == 's');
        }
        else
        {
            printf("Error. reinicie la calculadora..\n");
        }
}
