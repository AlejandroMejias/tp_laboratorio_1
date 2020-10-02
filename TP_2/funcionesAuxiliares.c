#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"


int Menu()
{
    int opcion;

    printf("\t MENU DE OPCIONES");
    printf("\n1) Dar de alta a un empleado");
    printf("\n2) Modificar a un empleado");
    printf("\n3) Dar de baja a un empleado");
    printf("\n4) Informar empleados");
    printf("\n5) Salir");
    printf("\nIngrese su acci%cn a ejecutar: ",162);
    scanf("%d",&opcion);

    /* Valido la opcion */

    while(opcion < 1 || opcion > 5)
    {
        printf("\nOpcion invalida! Ingrese correctamente para ingresar al menu: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    system("cls");
    return opcion;
}

void ordenarDescendente(Employee* list, int len)
{
    int i;
    int j;
    Employee Aux;

    if(list != NULL && len > 0)
    {
        for(i = 0; i < len - 1; i++)
        {
            for(j = i + 1; j < len; j++)
            {
                if((list[i].sector < list[j].sector) || (list[i].sector == list[j].sector && (strcmp(list[i].lastName,list[j].lastName) < 0)))
                {
                    Aux = list[i];
                    list[i] = list[j];
                    list[j] = Aux;
                }
            }
        }
    }
}
void ordenarAscendente(Employee* list, int len)
{
    int i;
    int j;
    Employee Aux;

    if(list != NULL && len > 0)
    {
        for(i = 0; i < len - 1; i++)
        {
            for(j = i + 1; j < len; j++)
            {
                if((list[i].sector > list[j].sector) || (list[i].sector == list[j].sector && (strcmp(list[i].lastName,list[j].lastName) > 0)))
                {
                    Aux = list[i];
                    list[i] = list[j];
                    list[j] = Aux;
                }
            }
        }
    }
}
int validarCadenas(char cadena[], int len)
{
    int i;
    int retorno = -1;
    int largoCadena = strlen(cadena);


    for( i = 0; i <= largoCadena - 1; i++)
    {
        if((cadena[i] >= 65 && cadena[i] <=90) || (cadena[i]>= 97 && cadena[i]<= 122))
        {
            retorno = 0;
        }
        else
        {
            retorno = -1;
            break;
        }
    }
    if(retorno == -1)
    {
        printf("\n\nERROR! Este campo no puede estar vacio ni contener valores numericos. Intente nuevamente\n\n ");
        system("pause");
    }
    return retorno;
}
void editEmployee(Employee* list, int len, int busqueda)
{
    int index;
    int i;
    int respuesta;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int modificarValor;

    /* Busco el id dentro del array para tomar su posicion en el indice del array*/
    for(i = 0; i < len; i++)
    {
        if(list[i].id == busqueda)
        {
            index = i;
            break;
        }
    }

    printf("\n\nQue valor necesita modificar?: ");
    printf("\n1)Nombre\n2)Apellido\n3)Salario\n4)Sector");
    printf("\nIngrese su accion a ejecutar: ");
    scanf("%d",&modificarValor);

    /*Valido el valor a modificar*/

    while(modificarValor < 1 || modificarValor > 4)
    {
        printf("\nOpcion invalida!! Por favor seleccione una opcion correcta: \n\n");
        fflush(stdin);
        scanf("%d",&modificarValor);
    }

    switch(modificarValor)
    {
    case 1:
        do
        {
            printf("\nIngrese el nombre: ");
            fflush(stdin);
            gets(name);
            respuesta = validarCadenas(name, 51);
        }
        while(respuesta == -1);
        strcpy(list[index].name,name);
        break;
    case 2:
        do
        {
            system("cls");
            printf("\nIngrese el apellido: ");
            fflush(stdin);
            gets(lastName);
            respuesta = validarCadenas(lastName, 51);
            system("cls");
        }
        while(respuesta == -1);
        strcpy(list[index].lastName,lastName);
        break;
    case 3:
        printf("\nIngrese el nuevo salario: ");
        scanf("%f",&salary);
        list[index].salary = salary;
        break;
    case 4:
        printf("\nIngrese el nuevo sector: ");
        scanf("%d",&sector);
        list[index].sector = sector;
    }
}

int calcularPromedios(Employee* list, int len)
{
    int i;
    int retorno = -1;
    float promedioSalarios;
    float salarios;
    int contadorSalarios = 0;
    int contadorSalarioPromedio = 0;


    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                salarios += list[i].salary;
                contadorSalarios++;
                if(list[i].salary > 30000)
                {
                    contadorSalarioPromedio++;
                }
                retorno = 0;
            }
        }
    }

    promedioSalarios = salarios / contadorSalarios;

    printf("======================================================================");
    printf("\nSalarios totales: %.2f",salarios);
    printf("\nPromedio total de salarios: %.2f",promedioSalarios);
    printf("\nEmpleados por encima del salario promedio: %d\n\n",contadorSalarioPromedio);

    return retorno;
}
