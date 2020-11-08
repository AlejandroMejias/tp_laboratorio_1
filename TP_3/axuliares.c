#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "auxiliares.h"


/** \brief Se encarga de mostrar el menu de opciones
 *
 * \return Caracter introducido por el usuario
 *
 */

char menu()
{
    char opcion;

    printf("        ****       Nomina de empleados        *****");
    printf("\n     ----------------------------------------------\n\n");
    printf("A)Cargar los datos de los empleados desde el archivo data.csv (modo texto)\nB)Cargar los datos de los empleados desde el archivo data.bin (modo binario)\nC)Alta de empleado\nD)Modificar datos de empleado\nE)Baja de empleado\nF)Listar empleados\nG)Ordenar empleados\nH)Guardar los datos de los empleados en el archivo data.csv (modo texto)\nI)Guardar los datos de los empleados en el archivo data.bin (modo binario)\nX)Salir del sistema\n\n");
    printf("Ingrese su accion a ejecutar: ");

    opcion = tolower(getchar());
    fflush(stdin);
    opcion = validarCaracter(opcion);

    return opcion;
}
/** \brief Se encarga de validar un caracter
 *
 * \param Caracter a validar
 * \return Caracter validado
 *
 */
char validarCaracter(char caracter)
{

    while(caracter < 97 || caracter > 122 )
    {
        printf("\nERROR! Ingresa una opcion correcta: ");
        fflush(stdin);
        caracter = tolower(getchar());
    }
    return caracter;
}
/** \brief Se encarga de capturar y validar un nombre valido
 *
 * \param Cadena vacia
 * \return cadena validada
 * 1 Si esta todo ok
 * 0 si hubo error
 *
 */

int capturarNombre(char* cadena)
{
    int retorno = 0;
    int tam;
    int i;
    int aux;
    char auxCadena[100];

    do
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(auxCadena);

        tam = strlen(auxCadena);

        for(i = 0; auxCadena[i] != '\0' && tam > 0 && tam < 20; i++)
        {
            aux = auxCadena[i];
            if((aux >= 97 && aux <= 122) || (aux >= 65 && aux <= 90))
            {
                retorno = 1;
            }
            else
            {
                retorno = 0;
                break;
            }
        }

        if(retorno == 1)
        {
            strcpy(cadena,auxCadena);
        }
        else
        {
            printf("\nERROR!! Campo demasiado largo o con valores numericoos.Vuela a ingresar...\n\n");
            system("pause");
            system("cls");
        }
    }
    while(retorno == 0);

    return retorno;
}
/** \brief Se encarga de capturar y validar las hors trabajadas
 *
 * \param Cadena vacia
 * \return cadena validada
 * 1 Si esta todo ok
 * 0 si hubo error
 *
 */

int capturarHorasTrabajadas(char* cadena)
{
    int retorno = 0;
    int tam;
    int i;
    int aux;
    char auxCadena[100];



    do
    {
        printf("Ingrese las horas trabajadas: ");
        fflush(stdin);
        gets(auxCadena);
        tam = strlen(auxCadena);
        for(i = 0; auxCadena[i] != '\0' && tam > 0 && tam < 20; i++)
        {
            aux = auxCadena[i];
            if(aux >= 48 && aux <= 57)
            {
                retorno = 1;
            }
            else
            {
                retorno = 0;
                break;
            }
        }

        if(retorno == 1)
        {
            strcpy(cadena,auxCadena);
        }
        else
        {
            printf("\nERROR! Este campo no puede contener letras, ni tampoco ser negativo.Vuelva a ingresar...\n\n");
            system("pause");
            system("cls");
        }

    }while(retorno == 0);

    return retorno;
}
/** \brief Se encarga de capturar y validar el sueldo
 *
 * \param Cadena vacia
 * \return cadena validada
 * 1 Si esta todo ok
 * 0 si hubo error
 *
 *
 */

int capturarSueldo(char* cadena)
{
    int retorno = 0;
    int tam;
    int i;
    int aux;
    char auxCadena[100];



    do
    {
        printf("Ingrese el sueldo: ");
        fflush(stdin);
        gets(auxCadena);
        tam = strlen(auxCadena);
        for(i = 0; auxCadena[i] != '\0' && tam > 0 && tam < 20; i++)
        {
            aux = auxCadena[i];
            if(aux >= 48 && aux <= 57)
            {
                retorno = 1;
            }
            else
            {
                retorno = 0;
                break;
            }
        }

        if(retorno == 1)
        {
            strcpy(cadena,auxCadena);
        }
        else
        {
            printf("\nERROR! Este campo no puede contener letras, ni tampoco ser negativo.Vuelva a ingresar...\n\n");
            system("pause");
            system("cls");
        }

    }while(retorno == 0);
    return retorno;
}
/** \brief Se encarga de mostrar el menu de opciones para hacer modificaciones
 *
 * \return Opcion elegida por el usuario
 */
char menuModificacion()
{
    char opcion;
    system("cls");
    printf("        ****       Nomina de empleados        *****");
    printf("\n     ----------------------------------------------\n\n");
    printf("A)Modificar nombre\nB)Modificar horas trabajadas\nC)Modificar sueldo\nX)Salir\n");
    printf("Ingrese su accion a ejecutar: ");

    fflush(stdin);
    opcion = tolower(getchar());
    fflush(stdin);
    opcion = validarCaracter(opcion);

    return opcion;
}
/** \brief Se encarga de mostrar el menu de opciones para gestionar ordenamientos
 *
 * \return Opcion elegida por el usuario
 */
char menuOrdenamiento()
{
    char opcion;
    printf("        ****       Menu para ordenar empleados        *****");
    printf("\n     -------------------------------------------------\n\n");
    printf("A)Ordenar por ID \nB)Ordenar por NOMBRE\nC)Ordenar por horas trabajadas\nD)Ordenar por SUELDO\nX)Salir\n");
    printf("Ingrese su accion a ejecutar: ");
    opcion = tolower(getchar());
    fflush(stdin);
    opcion = validarCaracter(opcion);
    return opcion;
}
