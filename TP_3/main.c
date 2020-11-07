#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "auxiliares.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        option = menu();
        switch(option)
        {
            case 'a':
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 'b':
                controller_loadFromBinary("data.bin",listaEmpleados);
                break;
            case 'c':
                controller_addEmployee(listaEmpleados);
                break;
            case 'd':
                controller_editEmployee(listaEmpleados);
                break;
            case 'e':
                controller_removeEmployee(listaEmpleados);
                break;
            case 'f':
                system("cls");
                controller_ListEmployee(listaEmpleados);
                break;
            case 'g':
                controller_sortEmployee(listaEmpleados);
                break;
            case 'h':
                controller_saveAsText("data.csv",listaEmpleados);
                break;
            case 'i':
                controller_saveAsBinary("data.bin",listaEmpleados);
                break;
        }
        system("cls");
        fflush(stdin);
    }while(option != 'x');
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
