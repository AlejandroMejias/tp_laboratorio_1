/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/auxiliares.h"
#include "../inc/controller.h"




int main(void)
{

//        startTesting(1);  //ll_newLinkedList
//        startTesting(2);   //ll_len
//        startTesting(3);  // getNode - test_getNode
//        startTesting(4);  // addNode - test_addNode
//        startTesting(5);  // ll_add
//        startTesting(6);  // ll_get
//        startTesting(7);  // ll_set
//        startTesting(8);  // ll_remove
//        startTesting(9);  // ll_clear
//        startTesting(10); // ll_deleteLinkedList
//        startTesting(11); // ll_indexOf
//        startTesting(12); // ll_isEmpty
//        startTesting(13); // ll_push
//        startTesting(14); // ll_pop
//        startTesting(15); // ll_contains
//        startTesting(16); // ll_containsAll
//        startTesting(17); // ll_subList
//        startTesting(18); // ll_clone
//        startTesting(19); // ll_sort


    char option;
    LinkedList* ListaCompetidores = ll_newLinkedList();

    do
    {
        option = menu();

        switch(option)
        {
            case 'a':
                controlador_cargarDesdeTexto("competidores.csv",ListaCompetidores);
                break;
            case 'b':
                controlador_addCompetidor(ListaCompetidores);
                break;
            case 'c':
                controlador_editCompetidor(ListaCompetidores);
                break;
            case 'd':
                controlador_eliminarCompetidor(ListaCompetidores);
                break;
            case 'e':
                controlador_listarCompetidores(ListaCompetidores);
                break;
            case 'f':
                controlador_sortCompetidores(ListaCompetidores);
                break;
            case 'h':
                controlador_generarSublista(ListaCompetidores);
                break;
            case 'i':
                controlador_listadoGanadores("ganadores.csv",ListaCompetidores);
                break;
            case 'j':
                controlador_moverCompetidor(ListaCompetidores);
                break;
            case 'k':
                controlador_copiaSeguridad("copia.csv",ListaCompetidores);
                break;
            case 'l':
                controlador_guardarDesdeTexto("competidores.csv",ListaCompetidores);
                break;
            case 'x':
                system("cls");
                printf("\n\nCerrando el sistema...\n\n\n");
                system("pause");
                break;
            default:
                system("cls");
                printf("La opcion ingresada no es valida...\n\n\n");
                system("pause");

        }
        system("cls");
        fflush(stdin);
    }
    while(option != 'x');


    ll_deleteLinkedList(ListaCompetidores);
    return 0;
}

































