#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "funcionesAuxiliares.h"
#define LEN 1000

int main()
{
    int id = 0;
    int menu;
    int order;
    int respuesta;
    int busqueda;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int banderaIngreso = 1;
    Employee ArrEmployee[LEN];
    initEmployees(ArrEmployee,LEN);
    do
    {
        menu = Menu();


        switch(menu)
        {
        case 1:
            printf("\tEspecifique los datos del empleado:\n\n");
            do
            {
                printf("Ingrese el nombre: ");
                fflush(stdin);
                gets(name);
                respuesta = validarCadenas(name, 51);
            }
            while(respuesta == -1);

            do
            {
                system("cls");
                printf("Ingrese el apellido: ");
                fflush(stdin);
                gets(lastName);
                respuesta = validarCadenas(lastName, 51);
                system("cls");
            }
            while(respuesta == -1);

            printf("\nIngrese el salario: ");
            scanf("%f",&salary);

            /* Valido salario */
            while(salary < 1 || salary > 200000)
            {
                system("cls");
                printf("ERROR! Solo se admiten numeros y salarios no mayores a 200000\n");
                printf("Ingrese correctamente el salario: ");
                fflush(stdin);
                scanf("%f",&salary);
            }

            system("cls");
            printf("\nIngrese el sector: ");
            scanf("%d",&sector);

            /*Valido sector */

            while(sector < 1 || sector > 9)
            {
                printf("ERROR! Solo se admiten numeros y el sector no puede ser mayor a 9\n");
                printf("Ingrese correctamente el sector: ");
                fflush(stdin);
                scanf("%d",&sector);
            }
            id++;
            respuesta = addEmployee(ArrEmployee,LEN,name,lastName,id,salary,sector);
            if(respuesta == 0)
            {

                printf("\nCarga de datos exitosa!!\n\n");
                banderaIngreso = 0;
                system("pause");
            }
            else
            {
                printf("\nHubo problemas al cargar los datos, intente nuevamente!!\n\n");
                system("pause");
            }
            break;
        case 2:
            if(banderaIngreso == 0)
            {
                system("cls");
                printEmployees(ArrEmployee,LEN);
                printf("Ingrese el id del empleado para su busqueda: ");
                fflush(stdin);
                scanf("%d",&busqueda);
                respuesta = findEmployeeById(ArrEmployee,LEN,busqueda);
                if(respuesta == -1)
                {
                    printf("No existe un empleado con ese id\n\n");
                    system("pause");
                }
                else
                {
                    editEmployee(ArrEmployee,LEN,busqueda);
                }
            }
            else
            {
                printf("\nNo puedes ingresar a este campo sin haber cargado al menos un empleado\n\n");
                system("pause");
            }

            break;
        case 3:
            if(banderaIngreso == 0)
            {
                printEmployees(ArrEmployee,LEN);
                printf("Ingrese el id del empleado para su busqueda: ");
                fflush(stdin);
                scanf("%d",&busqueda);
                respuesta = removeEmployee(ArrEmployee,LEN,busqueda);
                id = busqueda - 1;

                if(respuesta == -1)
                {
                    system("cls");
                    printf("\n\nERROR! No existe un empleado con ese id\n\n");
                    system("pause");
                }
            }
            else
            {
                printf("\nNo puedes ingresar a este campo sin haber cargado al menos un empleado\n\n");
                system("pause");
            }

            break;
        case 4:
            if(banderaIngreso == 0)
            {
                system("cls");
                printf("\nSe mostrar%c el listado de empleados ordenado por apellido y sector, desea ordenarlo de forma:\n\n0) Descendente\n1) Ascendente",160);
                printf("\n\nIngrese el formato correspondiente: ");
                fflush(stdin);
                scanf("%d",&order);

                /* Valido el criterio de ordenamiento */
                while(order < 0 || order > 1)
                {
                    printf("\nPor favor ingrese una opcion de ordenamiento valida: \n");
                    fflush(stdin);
                    scanf("%d",&order);
                }
                sortEmployees(ArrEmployee,LEN,order);
                respuesta = printEmployees(ArrEmployee,LEN);
                if(respuesta == 0)
                {
                    calcularPromedios(ArrEmployee,LEN);
                    system("pause");
                }
                else
                {
                    printf("\n\nNo se registraron empleados en la lista, pruebe ingresando al menos un empleado\n\n");
                    system("pause");
                }

            }
            else
            {
                printf("\nNo puedes ingresar a este campo sin haber cargado al menos un empleado\n\n");
                system("pause");
            }
        }
        fflush(stdin);
        system("cls");
    }
    while(menu != 5);

    return 0;
}
