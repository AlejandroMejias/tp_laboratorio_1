#include <stdio.h>
#include <stdlib.h>

float numeroUno()
{
    float num1;

    system("cls");
    printf("\n\nIngrese el primer operando: ");
    scanf("%f",&num1);
    return num1;
}
float numeroDos()
{
    float num2;

    system("cls");
    printf("\n\nIngrese el segundo operando: ");
    scanf("%f",&num2);
    return num2;
}
float utn_CalcularSuma(float numeroUno,float numeroDos)
{
    float suma;

    suma = numeroUno + numeroDos;
    return suma;
}
float utn_CalcularResta(float numeroUno, float numeroDos)
{
    float resta;

    resta = numeroUno - numeroDos;
    return resta;
}
float utn_CalcularDivision(float numeroUno, float numeroDos)
{
    float division;
    /*Valido el denominador en caso de que no sea cero*/
    if(numeroDos > 0)
    {
        division = numeroUno / numeroDos;
    }
    else
    {
        if(numeroUno == 0 || numeroDos == 0)
        {
            division = -1;
        }
        else
        {
            division = 0;
        }
    }
    return division;
}

float utn_CalcularMultiplicacion(float numeroUno, float numeroDos)
{
    float multiplicacion;

    multiplicacion = numeroUno * numeroDos;
    return multiplicacion;
}

long long int utn_CalcularFactorialUno(int numeroUno)
{
    long long int factorialUno = 1;
    int i = 0;

    /* Primero valido que el numero ingresado no sea negativo */
    if(numeroUno < 0)
    {
        factorialUno = -1;
    }

    for(i = 1; i <= numeroUno; i++)
    {
        factorialUno*= i;
    }

    return factorialUno;
}

long long int utn_CalcularFactorialDos(int numeroDos)
{
    long long int factorialDos = 1;
    int i = 0;

    /* Primero valido que el numero ingresado no sea negativo */
    if(numeroDos < 0)
    {
        factorialDos = -1;
    }

    for(i = 1; i <= numeroDos; i++)
    {
        factorialDos*= i;
    }

    return factorialDos;
}

