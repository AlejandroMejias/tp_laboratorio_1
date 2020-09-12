#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculos.h"


int main()
{
    char seguir = 'N';
    int OpcionesMenu;
    float num1 = 0;
    float num2 = 0;
    int banderaMenu = 0;
    int banderaNUM1 = 0;
    int banderaNUM2 = 0;
    int banderaCalculos = 0;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    long long int factorialUno;
    long long int factorialDos;


    do
    {
        /* Muestra menu de entrada y el ingreso de los operandos*/
        if(banderaMenu == 0)
        {
            printf("\t\t\t\t    ****Calculator XJ 200****    \n");
            printf("\t\t\t\t    =========================\n\n");
            if(banderaNUM1 == 0)
            {
                printf("\n1)Ingrese el primer operando: (A = X)");
            }
            else
            {
                printf("\n1)Ingrese el primer operando: (A = %.1f)",num1);
            }

            if(banderaNUM2 == 0)
            {
                printf("\n2)Ingrese el segundo operando: ( B = Y)");
            }
            else
            {
                printf("\n2)Ingrese el segundo operando: ( B = %.1f)",num2);
            }

            printf("\n3)Calcular operaciones:");
            if(banderaCalculos == 1)
            {
                printf("\n\tA)Calcular la suma %.1f + %.1f",num1,num2);
                printf("\n\tB)Calcular la resta %.1f - %.1f",num1,num2);
                printf("\n\tC)Calcular la division %.1f / %.1f",num1,num2);
                printf("\n\tD)Calcular la multiplicacion %.1f * %.1f",num1,num2);
                printf("\n\tE)Calcular el factorial de A!");
                printf("\n\tF)Calcular el factorial de B!\n");
            }

            printf("\n4)Informar resultados:");
            printf("\n5)Salir");
            printf("\n\n Ingrese su opci%cn a ejecutar: ",162);
            scanf("%d",&OpcionesMenu);
        }
        else
        {
            /* Muestra el menu alternativo con todos los resultados y operandos*/
            printf("\t\t\t\t    ****Calculator XJ 200****    \n");
            printf("\t\t\t\t    =========================\n\n");
            printf("\n1)Ingrese el primer operando: (A = %.1f)",num1);
            printf("\n2)Ingrese el segundo operando: ( B = %.1f)",num2);
            printf("\n3)Calcular operaciones:");
            printf("\n\tA)Calcular la suma %.1f + %.1f",num1,num2);
            printf("\n\tB)Calcular la resta %1.f - %.1f",num1,num2);
            printf("\n\tC)Calcular la division %.1f / %.1f",num1,num2);
            printf("\n\tD)Calcular la multiplicacion %.1f * %.1f",num1,num2);
            printf("\n\tE)Calcular el factorial de A!",num1);
            printf("\n\tF)Calcular el factorial de B!\n",num2);
            printf("\n4)Informar resultados:");
            printf("\n\tA)Calculo de la suma (%.1f) + (%.1f) = %.1f ",num1,num2,suma);
            printf("\n\tB)Calculo de la resta (%.1f) - (%.1f) = %.1f ",num1,num2,resta);
            if(division == -1)
            {
                printf("\n\tC)No es posible divivir entre cero");
            }
            else
            {
                if(division == 0)
                {
                    printf("\n\tC)Calculo de la division (%.1f) / (%.1f) = %.1f ",num1,num2,division);
                }
                else
                {
                    printf("\n\tC)Calculo de la division (%.1f) / (%.1f) = %.1f ",num1,num2,division);
                }
            }
            printf("\n\tD)Calculo de la multiplicacion (%.1f) * (%.1f) = %.1f ",num1,num2,multiplicacion);
            if(factorialUno == -1)
            {
                printf("\n\tE)No es posible calcular factorial de numeros negativos");
            }
            else
            {
                printf("\n\tE)Calculo del factorial de A! es : %lld ",factorialUno);
            }
            if(factorialDos == -1)
            {
                printf("\n\tF)No es posible calcular factorial de numeros negativos");
            }
            else
            {
                printf("\n\tF)Calculo del factorial de B! es : %lld ",factorialDos);
            }

            printf("\n5)Salir");
            printf("\n\n Ingrese su opci%cn a ejecutar: ",162);
            scanf("%d",&OpcionesMenu);
            banderaMenu = 0;
            num1 = 0;
            num2 = 0;
            banderaNUM1 = 0;
            banderaNUM2 = 0;
            banderaCalculos = 0;
        }

        /* Menu de opciones para ingreso, calculo de operandos y salida */
        switch(OpcionesMenu)
        {
            case 1:
                num1 = numeroUno();
                banderaNUM1 = 1;
                break;
            case 2:
                num2 = numeroDos();
                banderaNUM2 = 1;
                break;
            case 3:
                if(banderaNUM1 == 0 || banderaNUM2 == 0)
                {
                    system("cls");
                    printf("\nNo puedes calcular sin antes ingresar ambos operandos\n\n");
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("\nCalculando...\n");
                    system("pause");
                    suma = utn_CalcularSuma(num1,num2);
                    resta = utn_CalcularResta(num1,num2);
                    division = utn_CalcularDivision(num1,num2);
                    multiplicacion = utn_CalcularMultiplicacion(num1,num2);
                    factorialUno = utn_CalcularFactorialUno(num1);
                    factorialDos = utn_CalcularFactorialDos(num2);
                    banderaCalculos = 1;
                }
                break;
            case 4:
                if(banderaCalculos == 1)
                {
                    banderaMenu = 1;
                }
                else
                {
                    system("cls");
                    printf("\nNo puedes informar sin antes calcular las operaciones\n\n");
                    system("pause");
                }
                break;
            case 5:
                system("cls");
                printf("\nEstas seguro que deseas salir? Ingrese S %c N:  ",162);
                fflush(stdin);
                scanf("%c",&seguir);
                seguir = toupper(seguir);
                break;
            default:
                system("cls");
                printf("\nPor favor ingrese una opci%cn valida!\n\n",162);
                system("pause");
       }
        system("cls");
    }
    while(seguir == 'N');

    return 0;
}

