#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "funcionesAuxiliares.h"


int initEmployees(Employee* list,int len)
{
    int i;

    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
    }

    return 0;
}

int addEmployee(Employee* list, int len,char name[],char lastName[],int id,float salary, int sector)
{
    int retorno = -1;
    int i;

    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                strcpy(list[i].name, name);
                strcpy(list[i].lastName, lastName);
                list[i].id = id;
                list[i].salary = salary;
                list[i].sector = sector;
                list[i].isEmpty = 0;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int findEmployeeById(Employee* list,int len,int busqueda)
{
    int i;
    int retorno = -1;

    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].id == busqueda)
            {
                system("cls");
                printf("\nResultado de busqueda:");
                printf("\n\nID: %d \nNombre: %s \nApellido: %s \nSalario: %.2f\nSector: %d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
                printf("===================================");
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int removeEmployee(Employee* list, int len, int busqueda)
{
    int i;
    int retorno = -1;
    char eliminar;

    printf("\n\nEstas seguro que deseas eliminar este empleado?\nS (SI)\nN (NO)");
    printf("\nConfirme: ");
    fflush(stdin);
    scanf("%c",&eliminar);
    eliminar = toupper(eliminar);

    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].id == busqueda && list[i].isEmpty == 0 && eliminar == 'S')
            {
                list[i].isEmpty = 1;
                retorno = 0;
                printf("\n\nEliminando...\n\n");
                system("pause");
                break;
            }
        }
    }

    return retorno;
}

int sortEmployees(Employee* list, int len,int order)
{
    if(list != NULL && len > 0)
    {
        if(order == 0)
        {
            ordenarDescendente(list,len);
        }
        else
        {
            ordenarAscendente(list,len);
        }
    }

    return 0;
}


int printEmployees(Employee* list, int len)
{
    int i;
    int retorno = -1;
    system("cls");
    printf("ID\t    NOMBRE      \tAPELLIDO       \tSALARIO      \tSECTOR\n");
    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printf("\n%d\t    %s\t    \t%s        \t%.2f       \t%d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
                retorno = 0;
            }
        }
    }

    printf("\n\n");
    return retorno;
}
