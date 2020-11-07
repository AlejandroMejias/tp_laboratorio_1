#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param Puntero File
 * \param pArrayListEmployee LinkedList*
 * \return int  1 si se ejecutó correctamente, 0 si error
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char buffer[4][30];
    int respuesta;
    Employee* auxEmpleado = NULL;

    if( pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while( !feof(pFile))
        {
            respuesta = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if( respuesta == 4)
            {
                auxEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

                if(auxEmpleado != NULL)
                {
                    ll_add(pArrayListEmployee, auxEmpleado);
                    retorno = 1;
                }
            }
            else
            {
                break;
            }
        }
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param Puntero File
 * \param pArrayListEmployee LinkedList*
 * \return int  1 si se ejecutó correctamente, 0 si error
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int retorno = 0;
    int respuesta;
    Employee* auxEmpleado = NULL;

    if( pFile != NULL && pArrayListEmployee != NULL)
    {
        while( !feof(pFile))
        {
            auxEmpleado = employee_new();
            if( auxEmpleado != NULL)
            {
                respuesta = fread(auxEmpleado, sizeof(Employee), 1, pFile);
                if(respuesta == 1)
                {
                    ll_add(pArrayListEmployee, auxEmpleado);
                    retorno = 1;
                }
                else
                {
                    break;
                }
            }
        }
    }

    return retorno;
}
