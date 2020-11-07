#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "auxiliares.h"
#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se ejecut� correctamente, 0 si error
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* pFile;

    system("cls");

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(parser_EmployeeFromText(pFile,pArrayListEmployee))
            {
                retorno = 1;
            }
            fclose(pFile);
        }
    }

    if(retorno == 1)
    {
        printf("Datos guardados en data.csv exitosamente...\n");
    }
    else
    {
        printf("No se pudo guardar los datos en data.csv...\n");
    }

    system("pause");

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se ejecut� correctamente, 0 si error
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* pFile;

    system("cls");

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");

        if(pFile != NULL)
        {
            if(parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                retorno = 1;
            }
        }
    }

    if(retorno == 1)
    {
        printf("Datos guardados en data.bin exitosamente...\n");
    }
    else
    {
        printf("No se pudo guardar los datos en data.bin...\n");
    }
    fclose(pFile);

    system("pause");

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se ejecut� correctamente, 0 si error en la carga del empleado, -1 si aun no se carg� ning�n archivo
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int auxId = 0;
    int auxHoras;
    int auxSueldo;
    char nombreAux[200];
    char idStr[20];
    char horasTrabajadasStr[20];
    char sueldoStr[20];
    Employee* new_Employee = NULL;

    system("cls");

    if(pArrayListEmployee != NULL && !(ll_isEmpty(pArrayListEmployee)))
    {
        new_Employee = employee_new();

        printf("*****Nuevo empleado*****\n\n");

        idMaximo(pArrayListEmployee,&auxId);
        auxId++;
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombreAux);
        while(!(strlen(nombreAux)<128))
        {
            printf("Nombre demasiado largo. Reingrese: ");
            fflush(stdin);
            gets(nombreAux);
        }

        printf("Ingrese cantidad de horas trabajadas: ");
        fflush(stdin);
        scanf("%d", &auxHoras);
        while(auxHoras <= 0)
        {
            printf("La cantidad de horas trabajadas debe ser igual o menor a 0(cero). Reingrese: ");
            fflush(stdin);
            scanf("%d", &auxHoras);
        }

        printf("Ingrese sueldo: ");
        fflush(stdin);
        scanf("%d", &auxSueldo);
        while(auxSueldo <= 0)
        {
            printf("El sueldo debe ser igual o menor a 0(cero). Reingrese: ");
            fflush(stdin);
            scanf("%d", &auxSueldo);
        }

        itoa(auxId, idStr, 10);
        itoa(auxHoras,horasTrabajadasStr, 10);
        itoa(auxSueldo,sueldoStr, 10);

        new_Employee = employee_newParametros(idStr,nombreAux,horasTrabajadasStr,sueldoStr);

        if(new_Employee != NULL)
        {
            ll_add(pArrayListEmployee, new_Employee);
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }

    if(retorno == 1)
    {
        printf("Empleado agregado exitosamente...\n");
        system("pause");
    }
    else if(retorno == 0)
    {
        printf("No se pudo agregar el empleado... \n");
        system("pause");
    }
    else
    {
        printf("Cargue un archivo antes de agregar nuevos empleados. \n");
        system("pause");
    }
    return retorno;
}

/** \brief Modifica datos de un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se ejecut� correctamente, 0 si error, -1 si se cancel� la modificaci�n
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int tam = ll_len(pArrayListEmployee);
    int auxId;
    char option;
    char auxNombre[200];
    int auxHoras;
    int auxSueldo;
    Employee* auxEmpleado = NULL;

    system("cls");
    printf("*****Modificar empleado*****\n");
    printf("-------------------------------\n\n");
    controller_ListEmployee(pArrayListEmployee);

    if(pArrayListEmployee != NULL && !(ll_isEmpty(pArrayListEmployee)))
    {
        printf("\n\nIngrese id de empleado a modificar: ");
        fflush(stdin);
        scanf("%d", &auxId);
        while(auxId > tam || auxId < 0)
        {
            printf("No hay empleados con ese numero de id, reingrese: ");
            fflush(stdin);
            scanf("%d", &auxId);
        }

        auxEmpleado = ll_get(pArrayListEmployee, (auxId-1));
        option = menuModificacion();

        switch(option)
        {
        case 'a':
            system("cls");
            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            gets(auxNombre);
            while(!(strlen(auxNombre) < 128))
            {
                printf("Nombre demasiado largo.Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxNombre);
            }

            if(employee_setNombre(auxEmpleado, auxNombre))
            {
                retorno = 1;
            }
            break;

        case 'b':
            system("cls");
            printf("Ingrese nueva cantidad de horas trabajadas: ");
            fflush(stdin);
            scanf("%d", &auxHoras);
            while(auxHoras <= 0)
            {
                printf("La cantidad de horas trabajadas no puede ser menor a cero.Ingrese nuevamente: ");
                fflush(stdin);
                scanf("%d", &auxHoras);
            }
            if(employee_setHorasTrabajadas(auxEmpleado, auxHoras))
            {
                retorno = 1;
            }
            break;
        case 'c':
            system("cls");
            printf("Ingrese nuevo sueldo: ");
            fflush(stdin);
            scanf("%d", &auxSueldo);
            while(auxSueldo < 0)
            {
                printf("El salario no puede ser menor a cero.Ingrese nuevamente: ");
                fflush(stdin);
                scanf("%d", &auxSueldo);
            }
            if(employee_setSueldo(auxEmpleado, auxSueldo))
            {
                retorno = 1;
            }
            break;

        case 'x':
            retorno = -1;
            break;

        default:
            printf("Opcion invalida.\n");
        }
    }

    if(retorno == 1)
    {
        printf("Empleado modificado exitosamente...\n");
    }
    else if(retorno == 0)
    {
        system("cls");
        printf("No se pudo modificar el empleado. Debe cargar un archivo si aun no lo hizo...\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("La modificacion fue cancelada...\n");
        system("pause");
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int  1 si se ejecut� correctamente, 0 si error, -1 si se cancel� la eliminacion
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int tam = ll_len(pArrayListEmployee);
    int auxId;
    Employee* auxEmpleado = NULL;
    char option;

    system("cls");

    if(pArrayListEmployee != NULL && !(ll_isEmpty(pArrayListEmployee)))
    {
        printf("*****Eliminar empleado*****\n");
        printf("---------------------------\n\n");

        controller_ListEmployee(pArrayListEmployee);
        printf("\n\nIngrese id de empleado a eliminar: ");
        fflush(stdin);
        scanf("%d", &auxId);
        while(auxId > tam || auxId < 0)
        {
            printf("No hay empleados con ese numero de id, reingrese: ");
            fflush(stdin);
            scanf("%d", &auxId);
        }

        auxEmpleado = ll_get(pArrayListEmployee, (auxId-1));
        system("cls");
        printf("\nSe eliminara al siguiente empleado\n");
        printEmployee(auxEmpleado);
        printf("\n\n");
        printf("\n\nDesea continuar? Ingrese S(SI) / N(NO): ");
        fflush(stdin);
        option = tolower(getchar());
        while(option != 's' && option != 'n')
        {
            printf("\nERROR!Ingrese S(SI) para eliminar el empleado, N(NO) para cancelar: ");
            fflush(stdin);
            option = tolower(getchar());
        }
        if(option == 's')
        {
            ll_remove(pArrayListEmployee, (auxId-1));
            retorno = 1;
            printf("\nEl empleado se elimino correctamente. \n");
        }
        if(option == 'n')
        {
            retorno = -1;
            printf("Se ha cancelado la eliminacion...\n");
        }
    }

    if(ll_isEmpty(pArrayListEmployee))
    {
        printf("No hay empleados cargados todavia.\n");
        system("pause");
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int  1 si se ejecut� correctamente, 0 si error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int i;
    int tam = ll_len(pArrayListEmployee);
    Employee* auxEmpleado = NULL;


    if(pArrayListEmployee != NULL && tam > 0)
    {
        printf("  ID                NOMBRE      HORAS TRABAJADAS    SUELDO\n");
        printf("------------------------------------------------------------\n\n");
        for(i = 0; i < tam; i++)
        {
            auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
            if(auxEmpleado != NULL)
            {
                printEmployee(auxEmpleado);

            }
        }
        retorno = 1;
    }
    else
    {
        system("cls");
        printf("\nNo se encontraron empleados en la lista,debes cargarlos primero\n");
    }
    printf("\n\n");
    system("pause");
    return retorno;
}

/** \brief Ordenar empleados Segun criterio
 *
 * \param pArrayListEmployee LinkedList*
 * \return int  1 si se ejecut� correctamente, 0 si error, -1 si desea salir del menu directamente
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char option;
    char orden;

    system("cls");

    if(pArrayListEmployee != NULL && !(ll_isEmpty(pArrayListEmployee)))
    {
        system("cls");
        option = menuOrdenamiento();


        switch(option)
        {

        case 'a':
            system("cls");
            printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente");
            printf("\nIngrese opcion: ");
            fflush(stdin);
            orden = tolower(getchar());
            while(orden != 'm' && orden != 'n')
            {
                printf("\ERROR!.Ingresa una opcion correcta...");
                system("cls");
                printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente");
                printf("\nIngrese opcion: ");
                fflush(stdin);
                orden = tolower(getchar());
            }
            if(orden == 'm')
            {
                ll_sort(pArrayListEmployee, employee_sortId, 1);
            }
            else
            {
                ll_sort(pArrayListEmployee, employee_sortId, 0);
            }
            retorno = 1;
            break;

        case 'b':
            system("cls");
            printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente");
            printf("\nIngrese opcion: ");
            fflush(stdin);
            orden = tolower(getchar());
            while(orden != 'm' && orden != 'n')
            {
                printf("\ERROR!.Ingresa una opcion correcta...");
                system("cls");
                printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente");
                printf("\nIngrese opcion: ");
                fflush(stdin);
                orden = tolower(getchar());
            }
            if(orden == 'm')
            {
                ll_sort(pArrayListEmployee, employee_sortNombre, 1);
            }
            else
            {
                ll_sort(pArrayListEmployee, employee_sortNombre, 0);
            }
            retorno = 1;
            break;

        case 'c':
            system("cls");
            printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente");
            printf("\nIngrese opcion: ");
            fflush(stdin);
            orden = tolower(getchar());
            while(orden != 'm' && orden != 'n')
            {
                printf("\ERROR!.Ingresa una opcion correcta...");
                system("cls");
                printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente");
                printf("\nIngrese opcion: ");
                fflush(stdin);
                orden = tolower(getchar());
            }
            if(orden == 'm')
            {
                ll_sort(pArrayListEmployee, employee_sortHorasTrabajadas, 1);
            }
            else
            {
                ll_sort(pArrayListEmployee, employee_sortHorasTrabajadas, 0);
            }
            retorno = 1;
            break;

        case 'd':
            system("cls");
            printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente");
            printf("\nIngrese opcion: ");
            fflush(stdin);
            orden = tolower(getchar());
            while(orden != 'm' && orden != 'n')
            {
                printf("\ERROR!.Ingresa una opcion correcta...");
                system("cls");
                printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente");
                printf("\nIngrese opcion: ");
                fflush(stdin);
                orden = tolower(getchar());
            }
            if(orden == 'm')
            {
                ll_sort(pArrayListEmployee, employee_sortSueldo, 1);
            }
            else
            {
                ll_sort(pArrayListEmployee, employee_sortSueldo, 0);
            }
            retorno = 1;
            break;

        case 'x':
            retorno = -1;
            break;

        default:
            printf("Opcion invalida.\n");
        }
    }

    if(ll_isEmpty(pArrayListEmployee))
    {
        printf("No se puede ordenar sin haber cargado empleados previamente...\n");
    }

    if(retorno == 1)
    {
        printf("\n\nEmpleados ordenados satisfactoriamente...\n\n");
    }
    system("pause");

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int  1 si se ejecut� correctamente, 0 si error
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int i;
    int tam = ll_len(pArrayListEmployee);
    int auxId;
    char auxNombre[200];
    int auxHoras;
    int auxSueldo;
    FILE* pFile;
    Employee* auxEmpleado;

    system("cls");

    if(pArrayListEmployee != NULL && path != NULL && tam > 0)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            for(i = 0; i < tam; i++)
            {
                auxEmpleado= (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(auxEmpleado,&auxId);
                employee_getNombre(auxEmpleado,auxNombre);
                employee_getHorasTrabajadas(auxEmpleado,&auxHoras);
                employee_getSueldo(auxEmpleado,&auxSueldo);

                fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
            }
            fclose(pFile);
            retorno = 1;
        }
    }

    if(retorno == 1)
    {
        printf("Datos guardados en data.csv exitosamente.\n");
    }
    else
    {
        printf("No se pudo guardar los datos en data.csv.\n");
    }

    system("pause");

    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 si se ejecut� correctamente, 0 si error
 *
 */

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int i;
    int tam = ll_len(pArrayListEmployee);
    FILE* pFile;
    Employee* auxEmpleado;

    system("cls");

    if(pArrayListEmployee != NULL && path != NULL && tam > 0)
    {
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            for(i = 0; i < tam; i++)
            {
                auxEmpleado = ll_get(pArrayListEmployee,i);

                if(auxEmpleado != NULL)
                {
                    fwrite(auxEmpleado,sizeof(Employee),1,pFile);
                }
            }
            fclose(pFile);
            retorno = 1;
        }
    }

    if(retorno == 1)
    {
        printf("Datos guardados en el archivo data.csv exitosamente...\n");
    }
    else
    {
        printf("No se pudo guardar los datos en el archivo data.csv...\n");
    }

    system("pause");

    return retorno;
}
