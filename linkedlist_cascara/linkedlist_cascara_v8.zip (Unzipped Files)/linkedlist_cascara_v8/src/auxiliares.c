#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/auxiliares.h"


/** \brief Se encarga de mostrar el menu de opciones
*
* \return Caracter introducido por el usuario
*
*/

char menu()
{
    char opcion;

    printf("        ****       Lista de competidores        *****");
    printf("\n     ----------------------------------------------\n\n");
    printf("A)Cargar los datos de los competidores desde el archivo data.csv (modo texto)\nB)Alta de competidor\nC)Modificar datos de un competidor\nD)Baja de competidor\nE)Listar competidores\nF)Ordenar competidores\nH)Generar un sub-listado\nI)Generar listado de ganadores\nJ)Reubicar competidor\nK)Generar una copia de seguridad\nL)Guardar los datos de los competidores en el archivo data.csv (modo texto)\nX)Salir del sistema\n\n");
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
        printf("Ingrese el nombre del competidor: ");
        fflush(stdin);
        gets(auxCadena);

        tam = strlen(auxCadena);

        for(i = 0; auxCadena[i] != '\0' && tam > 0 && tam < 25; i++)
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
            printf("\nERROR!! Campo demasiado largo o con valores numericos.Vuela a ingresar...\n\n");
            system("pause");
            system("cls");
        }
    }
    while(retorno == 0);

    return retorno;
}

/** \brief Se encarga de capturar y validar el pais del competidor
*
* \param Cadena vacia
* \return cadena validada
* 1 Si esta todo ok
* 0 si hubo error
*
*/
int capturarPaisOrigen(char* cadena)
{
    int retorno = 0;
    int tam;
    int i;
    int aux;
    char auxCadena[100];

    do
    {
        printf("Ingrese el pais de origen del competidor: ");
        fflush(stdin);
        gets(auxCadena);

        tam = strlen(auxCadena);

        for(i = 0; auxCadena[i] != '\0' && tam > 0 && tam < 50; i++)
        {
            aux = auxCadena[i];
            if((aux >= 97 && aux <= 122) || (aux >= 65 && aux <= 90) || (aux == 32))
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
            printf("\nERROR!! Campo demasiado largo o con valores numericos.Vuela a ingresar...\n\n");
            system("pause");
            system("cls");
        }
    }
    while(retorno == 0);

    return retorno;
}
/** \brief Se encarga de capturar y validar las medallas ganadas por el competidor
*
* \param Cadena vacia
* \return cadena validada
* 1 Si esta todo ok
* 0 si hubo error
*
*/

int capturarMedallasGanadas(char* cadena)
{
    int retorno = 0;
    int tam;
    int i;
    int aux;
    char auxCadena[100];

    do
    {
        printf("Ingrese las medallas obtenidas por el competidor: ");
        fflush(stdin);
        gets(auxCadena);
        tam = strlen(auxCadena);

        for(i = 0; auxCadena[i] != '\0' && tam > 0 && tam < 3; i++)
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
int capturarId(int* id,int tam,char* mensaje)
{
    int aux;
    int retorno = -1;
    int respuesta;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&aux);

    while(respuesta == 0 || aux < 1)
    {
            printf("\nIngrese un id valido: ");
            fflush(stdin);
            respuesta = scanf("%d",&aux);
            retorno = 0;
    }
    *id = aux;

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
    printf("        ****       Listado de competidores      *****");
    printf("\n     ------------------------------------------------\n\n");
    printf("A)Modificar nombre\nB)Modificar pais de origen\nC)Modificar medallas ganadas\nX)Salir\n");
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
    printf("        ****       Menu para ordenar competidores        *****");
    printf("\n     ---------------------------------------------------------\n\n");
    printf("A)Ordenar por ID \nB)Ordenar por nombre\nC)Ordenar por pais de origen\nD)Ordenar por medallas obtenidas\nX)Salir\n");
    printf("Ingrese su accion a ejecutar: ");
    opcion = tolower(getchar());
    fflush(stdin);
    opcion = validarCaracter(opcion);
    return opcion;
}
