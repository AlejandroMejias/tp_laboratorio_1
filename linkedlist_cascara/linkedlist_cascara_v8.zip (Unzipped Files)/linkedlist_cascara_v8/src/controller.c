#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/LinkedList.h"
#include "../inc/auxiliares.h"
#include "../inc/controller.h"
#include "../inc/competidores.h"
#include "../inc/parser.h"

/** \brief Carga los datos de los competidores desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pListadoCompetidores LinkedList*
 * \return int 1 si se ejecutó correctamente, 0 si error
 *
 */
int controlador_cargarDesdeTexto(char* path, LinkedList* pListadoCompetidores)
{
    int retorno = 0;
    FILE* pArchivo;

    system("cls");

    if(path != NULL && pListadoCompetidores != NULL)
    {
        pArchivo = fopen(path, "r");

        if(pArchivo != NULL)
        {
            if(parsear_CompetidorDesdeTexto(pArchivo,pListadoCompetidores))
            {
                retorno = 1;
            }
            fclose(pArchivo);
        }
    }

    if(retorno == 1)
    {
        printf("\n\nDatos guardados en data.csv exitosamente...\n\n\n");
    }
    else
    {
        printf("\n\nNo se pudo guardar los datos en data.csv...\n\n\n");
    }

    system("pause");

    return retorno;
}

/** \brief Alta de competidores
 *
 * \param pListadoCompetidores LinkedList*
 * \return int 1 si se ejecutó correctamente, 0 si error en la carga del competidor, -1 si aun no se cargó ningún archivo
 *
 */
int controlador_addCompetidor(LinkedList* pListadoCompetidores)
{
    int retorno = -1;
    int auxId = 0;
    char auxMedallasGanadas[200];
    char auxPaisOrigen[200];
    char auxNombre[200];
    char idStr[20];
    Competidor* nuevoCompetidor = NULL;

    system("cls");

    if(pListadoCompetidores != NULL && !(ll_isEmpty(pListadoCompetidores)))
    {
        nuevoCompetidor = nuevo_competidor();

        printf("*****  Nuevo competidor  *****\n");
        printf("-----------------------------\n\n");

        idMaximo(pListadoCompetidores,&auxId);
        auxId++;

        /*Capturo y valido el nombre*/
        capturarNombre(auxNombre);
        system("cls");

        /*Capturo y valido el pais de origen*/
        capturarPaisOrigen(auxPaisOrigen);
        system("cls");

        /*Capturo y valido las medallas obtenidas*/
        capturarMedallasGanadas(auxMedallasGanadas);
        system("cls");

        // Convierto el entero auxId, a una cadena idStr, de base 10( decimal )
        itoa(auxId, idStr, 10);
        nuevoCompetidor = competidor_nuevoParam(idStr,auxNombre,auxPaisOrigen,auxMedallasGanadas);

        if(nuevoCompetidor != NULL)
        {
            ll_add(pListadoCompetidores,nuevoCompetidor);
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }

    if(retorno == 1)
    {
        printf("\n\nCompetidor agregado exitosamente...\n\n");
        system("pause");
    }
    else if(retorno == 0)
    {
        printf("\n\nNo se pudo agregar el competidor... \n\n");
        system("pause");
    }
    else
    {
        printf("\n\nCargue un archivo antes de agregar nuevos competidores... \n\n");
        system("pause");
    }
    return retorno;
}

/** \brief Modifica datos de un competidor
 *
 * \param pListadoCompetidores LinkedList*
 * \return int 1 si se ejecutó correctamente, 0 si error, -1 si se canceló la modificación
 *
 */
int controlador_editCompetidor(LinkedList* pListadoCompetidores)
{
    int retorno = 0;
    int respuesta;
    int tam = ll_len(pListadoCompetidores);
    int auxId;
    int i;
    char opcion;
    char auxNombre[100];
    char auxPaisOrigen[100];
    char auxMedallasStr[100];
    int auxMedallas;
    Competidor* auxCompetidor = NULL;


    if(pListadoCompetidores != NULL && !(ll_isEmpty(pListadoCompetidores)))
    {
        system("cls");
        controlador_listarCompetidores(pListadoCompetidores);
        printf("\n\n\nIngrese id de competidor a modificar: ");
        respuesta = scanf("%d", &auxId);
        fflush(stdin);

        while(respuesta == 0 || auxId < 0)
        {
            printf("\n\nNo se registraron competidores con ese numero de id, reingrese un id valido\n\n\n");
            system("pause");
            system("cls");
            controlador_listarCompetidores(pListadoCompetidores);
            printf("\n\n\nIngrese id de competidor a modificar: ");
            respuesta = scanf("%d", &auxId);
            fflush(stdin);
        }

        for(i = 0; i < tam; i++)
        {
            auxCompetidor = ll_get(pListadoCompetidores, i);
            if(auxId == auxCompetidor->id)
            {
                retorno = 1;
                break;
            }
        }

        if(retorno == 1)
        {
            opcion = menuModificacion();

            switch(opcion)
            {
            case 'a':
                system("cls");
                if(capturarNombre(auxNombre))
                {
                    competidor_setNombre(auxCompetidor, auxNombre);
                    retorno = 1;
                }
                break;
            case 'b':
                system("cls");
                if(capturarPaisOrigen(auxPaisOrigen))
                {
                    competidor_setPaisOrigen(auxCompetidor,auxPaisOrigen);
                    retorno = 1;
                }
                break;
            case 'c':
                system("cls");
                if(capturarMedallasGanadas(auxMedallasStr))
                {
                    auxMedallas = atoi(auxMedallasStr);
                    competidor_setMedallasGanadas(auxCompetidor, auxMedallas);
                    retorno = 1;
                }
                break;

            case 'x':
                retorno = -1;
                break;

            default:
                printf("\nOpcion invalida...\n\n");
                retorno = 0;
            }
        }
    }

    if(retorno == 1)
    {
        printf("\n\nCompetidor modificado exitosamente...\n\n");
        system("pause");
    }
    else if(retorno == 0)
    {
        system("cls");
        printf("\n\nNo se pudo modificar al competidor. Ingrese una opcion valida o cargue un archivo si aun no lo hizo...\n\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n\nLa modificacion fue cancelada...\n\n");
        system("pause");
    }
    return retorno;
}

/** \brief Baja de competidor
 *
 * \param pListadoCompetidores LinkedList*
 * \return int  1 si se ejecutó correctamente, 0 si error, -1 si se canceló la eliminacion
 *
 */
int controlador_eliminarCompetidor(LinkedList* pListadoCompetidores)
{
    int retorno = 0;
    int respuesta;
    int tam = ll_len(pListadoCompetidores);
    int auxId;
    int i;
    char opcion;

    Competidor* auxCompetidor = NULL;

    if(pListadoCompetidores != NULL && !(ll_isEmpty(pListadoCompetidores)))
    {
        system("cls");
        controlador_listarCompetidores(pListadoCompetidores);
        printf("\n\nIngrese id del competidor a eliminar: ");
        respuesta = scanf("%d", &auxId);
        while(respuesta == 0 || auxId < 0 || auxId > tam)
        {
            printf("\n\nNo se registraron competidores con ese numero de id, reingrese un id valido\n\n\n");
            system("pause");
            system("cls");
            controlador_listarCompetidores(pListadoCompetidores);
            printf("\n\n\nIngrese id de competidor a eliminar: ");
            respuesta = scanf("%d", &auxId);
            fflush(stdin);
        }

        for(i = 0; i < tam; i++)
        {
            auxCompetidor = ll_get(pListadoCompetidores, i);
            if(auxId == auxCompetidor->id)
            {
                retorno = 1;
                break;
            }
        }

        if(retorno == 1)
        {
            system("cls");
            printf("\nSe eliminara al siguiente competidor:\n\n");
            imprimirCompetidor(auxCompetidor);
            printf("\n\n");
            printf("\n\nDesea continuar? Ingrese S(SI) / N(NO): ");
            fflush(stdin);
            opcion = tolower(getchar());
            while(opcion != 's' && opcion != 'n')
            {
                system("cls");
                printf("\nERROR!Ingrese S(SI) para eliminar al competidor, N(NO) para cancelar: ");
                fflush(stdin);
                opcion = tolower(getchar());
            }
            if(opcion == 's')
            {
                ll_remove(pListadoCompetidores, i);
                retorno = 1;
                printf("\nEl competidor se elimino correctamente...\n\n");
                system("pause");
            }
            if(opcion == 'n')
            {
                retorno = -1;
                printf("\n\nSe ha cancelado la eliminacion...\n\n");
                system("pause");
            }
        }
        else
        {
            system("cls");
            printf("\n\nNo hay competidores con ese numero de id, por favor vuelva a intentarlo...\n\n");
            system("pause");
        }

    }

    if(ll_isEmpty(pListadoCompetidores))
    {
        printf("\n\nNo hay competidores cargados todavia...\n\n\n");
        system("pause");
    }
    return retorno;
}

/** \brief Listar competidores
 *
 * \param pListadoCompetidores LinkedList*
 * \return int  1 si se ejecutó correctamente, 0 si error
 *
 */
int controlador_listarCompetidores(LinkedList* pListadoCompetidores)
{
    int retorno = 0;
    int i;
    int tam = ll_len(pListadoCompetidores);
    Competidor* auxCompetidor = NULL;


    if(pListadoCompetidores != NULL && tam > 0)
    {
        system("cls");
        printf("  ID                  NOMBRE                               PAIS ORIGEN           MEDALLAS OBTENIDAS\n");
        printf("------------------------------------------------------------------------------------------------------\n\n");
        for(i = 0; i < tam; i++)
        {
            auxCompetidor = (Competidor*)ll_get(pListadoCompetidores,i);
            if(auxCompetidor != NULL)
            {
                imprimirCompetidor(auxCompetidor);

            }
        }
        retorno = 1;
    }
    else
    {
        system("cls");
        printf("\nNo se encontraron competidores en la lista,debes cargarlos primero...\n");
    }
    printf("\n\n");
    system("pause");
    return retorno;
}

/** \brief Ordenar competidores segun criterio
 *
 * \param pListadoCompetidores LinkedList*
 * \return int  1 si se ejecutó correctamente, 0 si error, -1 si desea salir del menu directamente
 *
 */
int controlador_sortCompetidores(LinkedList* pListadoCompetidores)
{
    int retorno = 0;
    char opcion;
    char orden;

    system("cls");

    if(pListadoCompetidores != NULL && !(ll_isEmpty(pListadoCompetidores)))
    {
        system("cls");
        opcion = menuOrdenamiento();

        switch(opcion)
        {
        // m == Ascendente , n == Descendente

        case 'a':
            system("cls");
            printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente\n");
            printf("\nIngrese opcion: ");
            fflush(stdin);
            orden = tolower(getchar());
            while(orden != 'm' && orden != 'n')
            {
                printf("\ERROR!.Ingresa una opcion correcta...");
                system("cls");
                printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente\n");
                printf("\nIngrese opcion: ");
                fflush(stdin);
                orden = tolower(getchar());
            }
            if(orden == 'm')
            {
                ll_sort(pListadoCompetidores, competidor_sortId, 1);
            }
            else
            {
                ll_sort(pListadoCompetidores, competidor_sortId, 0);
            }
            retorno = 1;
            break;

        case 'b':
            system("cls");
            printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente\n");
            printf("\nIngrese opcion: ");
            fflush(stdin);
            orden = tolower(getchar());
            while(orden != 'm' && orden != 'n')
            {
                printf("\ERROR!.Ingresa una opcion correcta...");
                system("cls");
                printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente\n");
                printf("\nIngrese opcion: ");
                fflush(stdin);
                orden = tolower(getchar());
            }
            if(orden == 'm')
            {
                ll_sort(pListadoCompetidores, competidor_sortNombre, 1);
            }
            else
            {
                ll_sort(pListadoCompetidores, competidor_sortNombre, 0);
            }
            retorno = 1;
            break;

        case 'c':
            system("cls");
            printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente\n");
            printf("\nIngrese opcion: ");
            fflush(stdin);
            orden = tolower(getchar());
            while(orden != 'm' && orden != 'n')
            {
                printf("\ERROR!.Ingresa una opcion correcta...");
                system("cls");
                printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente\n");
                printf("\nIngrese opcion: ");
                fflush(stdin);
                orden = tolower(getchar());
            }
            if(orden == 'm')
            {
                ll_sort(pListadoCompetidores, competidor_sortPaisOrigen, 1);
            }
            else
            {
                ll_sort(pListadoCompetidores, competidor_sortPaisOrigen, 0);
            }
            retorno = 1;
            break;

        case 'd':
            system("cls");
            printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente\n");
            printf("\nIngrese opcion: ");
            fflush(stdin);
            orden = tolower(getchar());
            while(orden != 'm' && orden != 'n')
            {
                printf("\ERROR!.Ingresa una opcion correcta...");
                system("cls");
                printf("\nDeseas ordenar de forma: \nM)Ascendente\nN)Descendente\n");
                printf("\nIngrese opcion: ");
                fflush(stdin);
                orden = tolower(getchar());
            }
            if(orden == 'm')
            {
                ll_sort(pListadoCompetidores, competidor_sortMedallasGanadas, 1);
            }
            else
            {
                ll_sort(pListadoCompetidores, competidor_sortMedallasGanadas, 0);
            }
            retorno = 1;
            break;

        case 'x':
            retorno = -1;
            break;

        default:
            printf("\nOpcion invalida...\n\n");
        }
    }

    if(ll_isEmpty(pListadoCompetidores))
    {
        printf("No se puede ordenar sin haber cargado competidores previamente...\n\n");
    }

    if(retorno == 1)
    {
        printf("\n\nCompetidores ordenados satisfactoriamente...\n\n");
    }
    system("pause");

    return retorno;
}

int controlador_generarSublista(LinkedList* pListadoCompetidores)
{
    int retorno = -1;
    int tam = ll_len(pListadoCompetidores);
    LinkedList* sublist;
    int from;
    int to;
    int i;
    int flag = 0;
    Competidor* auxCompetidor = NULL;

    if(pListadoCompetidores != NULL && !ll_isEmpty(pListadoCompetidores))
    {
        controlador_listarCompetidores(pListadoCompetidores);
        capturarId(&from,tam,"\n\nIngrese el id DESDE donde desea crear la sublista: ");
        capturarId(&to,tam,"\n\nIngrese el id HASTA donde desea crear la sublista: ");

        // Consigo los indices de los ID almacenados en FROM y TO para pasarlos al sublist
        for(i = 0; i < tam; i++)
        {
            auxCompetidor = ll_get(pListadoCompetidores,i);

            if(auxCompetidor != NULL)
            {
                if(auxCompetidor->id == from && flag == 0)
                {
                    from = ll_indexOf(pListadoCompetidores,auxCompetidor);
                    flag = 1;
                }
                else if(auxCompetidor->id == to)
                {
                    to = ll_indexOf(pListadoCompetidores,auxCompetidor);
                    retorno = 0;
                    break;
                }
            }
        }
        sublist = ll_subList(pListadoCompetidores,from,to+1);

    }

    if(retorno == -1)
    {
        system("cls");
        printf("\n\nNo se pudo crear la sublista,introduzca un id valido o cargue un archivo si aun no lo hizo...\n\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n\nLista creada satisfactoriamente...\n\n");
        system("pause");
        system("cls");
        controlador_listarCompetidores(sublist);
        ll_deleteLinkedList(sublist);
    }

    return retorno;
}

int controlador_moverCompetidor(LinkedList* pListadoCompetidores)
{
    int retorno = -1;
    int tam = ll_len(pListadoCompetidores);
    int id;
    int i;
    int indice;
    Competidor* auxCompetidor = NULL;
    Competidor* CompetidorAMover = NULL;

    if(pListadoCompetidores != NULL && !ll_isEmpty(pListadoCompetidores))
    {
        controlador_listarCompetidores(pListadoCompetidores);
        capturarId(&id,tam,"\n\nIngrese el id del competidor que necesita reubicar: ");

        for(i = 0; i < tam; i++)
        {
            auxCompetidor = ll_get(pListadoCompetidores,i);

            if(auxCompetidor != NULL && auxCompetidor->id == id)
            {
                indice = ll_indexOf(pListadoCompetidores,auxCompetidor);
                auxCompetidor = (Competidor*)ll_pop(pListadoCompetidores,indice);
                break;
            }
        }

        capturarId(&id,tam,"\n\nIngrese la nueva posicion donde necesita ubicarlo: ");

        for(i = 0; i < tam; i++)
        {
            CompetidorAMover = ll_get(pListadoCompetidores,i);

            if(CompetidorAMover != NULL && CompetidorAMover->id == id)
            {
                indice = ll_indexOf(pListadoCompetidores,CompetidorAMover);
                ll_push(pListadoCompetidores,indice,auxCompetidor);
                retorno = 0;
                break;
            }
        }
    }

    if(retorno == -1)
    {
        system("cls");
        printf("\n\nNo se pudo mover la competidor,cargue un archivo si aun no lo hizo...\n\n");
        system("pause");
    }
    return retorno;
}

int controlador_listadoGanadores(char* path, LinkedList* pListadoCompetidores)
{
    int retorno = 0;
    int i;
    int tam = ll_len(pListadoCompetidores);
    int auxId;
    char auxNombre[100];
    char auxPaisOrigen[100];
    int auxMedallasGanadas;
    FILE* pArchivo;
    Competidor* auxCompetidor = NULL;

    system("cls");

    if(pListadoCompetidores != NULL && path != NULL && tam > 0)
    {
        pArchivo = fopen(path, "w");
        if(pArchivo != NULL)
        {
            for(i = 0; i < tam; i++)
            {
                auxCompetidor = (Competidor*)ll_get(pListadoCompetidores,i);
                if(auxCompetidor != NULL && auxCompetidor->medallasGanadas > 0)
                {
                    competidor_getId(auxCompetidor,&auxId);
                    competidor_getNombre(auxCompetidor,auxNombre);
                    competidor_getPaisOrigen(auxCompetidor,auxPaisOrigen);
                    competidor_getMedallasGanadas(auxCompetidor,&auxMedallasGanadas);

                    fprintf(pArchivo,"%d,%s,%s,%d\n",auxId,auxNombre,auxPaisOrigen,auxMedallasGanadas);
                }
            }
            fclose(pArchivo);
            retorno = 1;
        }
    }

    if(retorno == 1)
    {
        printf("Se genero un nuevo archivo ganadores.csv con todos los ganadores...\n\n");
    }
    else
    {
        printf("Para generar un listado de ganadores, debe cargarlos previamente...\n\n");
    }

    system("pause");

    return retorno;
}

int controlador_copiaSeguridad(char* path, LinkedList* pListadoCompetidores)
{
    int retorno = 0;
    int i;
    int tam = ll_len(pListadoCompetidores);
    int auxId;
    char auxNombre[100];
    char auxPaisOrigen[100];
    int auxMedallasGanadas;

    FILE* pArchivo;
    Competidor* auxCompetidor = NULL;
    LinkedList* CopiaSeguridad = ll_newLinkedList();;

    system("cls");

    if(pListadoCompetidores != NULL && path != NULL && CopiaSeguridad != NULL)
    {
        CopiaSeguridad = ll_clone(pListadoCompetidores);

        pArchivo = fopen(path, "w");

        if(pArchivo != NULL && ll_containsAll(pListadoCompetidores,CopiaSeguridad) && !ll_isEmpty(pListadoCompetidores))
        {
            for(i = 0; i < tam; i++)
            {
                auxCompetidor = (Competidor*)ll_get(pListadoCompetidores,i);
                if(auxCompetidor != NULL)
                {
                    competidor_getId(auxCompetidor,&auxId);
                    competidor_getNombre(auxCompetidor,auxNombre);
                    competidor_getPaisOrigen(auxCompetidor,auxPaisOrigen);
                    competidor_getMedallasGanadas(auxCompetidor,&auxMedallasGanadas);

                    fprintf(pArchivo,"%d,%s,%s,%d\n",auxId,auxNombre,auxPaisOrigen,auxMedallasGanadas);
                }
            }
            fclose(pArchivo);
            retorno = 1;
        }
    }

    if(retorno == 1)
    {
        printf("Se genero un nuevo de seguridad copia.csv con todos los datos...\n\n");
        ll_deleteLinkedList(CopiaSeguridad);
    }
    else
    {
        printf("Para generar una copia de seguridad, debe cargarlos previamente...\n\n");
    }

    system("pause");

    return retorno;
}
/** \brief Guarda los datos de los competidores en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pListadoCompetidores LinkedList*
 * \return int  1 si se ejecutó correctamente, 0 si error
 *
 */
int controlador_guardarDesdeTexto(char* path, LinkedList* pListadoCompetidores)
{
    int retorno = 0;
    int i;
    int tam = ll_len(pListadoCompetidores);
    int auxId;
    char auxNombre[100];
    char auxPaisOrigen[100];
    int auxMedallasGanadas;
    FILE* pArchivo;
    Competidor* auxCompetidor = NULL;

    system("cls");

    if(pListadoCompetidores != NULL && path != NULL && tam > 0)
    {
        pArchivo = fopen(path, "w");
        if(pArchivo != NULL)
        {
            for(i = 0; i < tam; i++)
            {
                auxCompetidor = (Competidor*)ll_get(pListadoCompetidores,i);
                if(auxCompetidor != NULL)
                {
                    competidor_getId(auxCompetidor,&auxId);
                    competidor_getNombre(auxCompetidor,auxNombre);
                    competidor_getPaisOrigen(auxCompetidor,auxPaisOrigen);
                    competidor_getMedallasGanadas(auxCompetidor,&auxMedallasGanadas);

                    fprintf(pArchivo,"%d,%s,%s,%d\n",auxId,auxNombre,auxPaisOrigen,auxMedallasGanadas);
                }
            }
            fclose(pArchivo);
            retorno = 1;
        }
    }

    if(retorno == 1)
    {
        printf("Datos guardados en data.csv exitosamente...\n\n");
    }
    else
    {
        printf("No se pudo guardar los datos en data.csv, debe cargarlos previamente...\n\n");
    }

    system("pause");

    return retorno;
}

