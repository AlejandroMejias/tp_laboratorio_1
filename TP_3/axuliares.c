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
