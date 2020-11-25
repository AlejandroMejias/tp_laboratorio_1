#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../inc/LinkedList.h"
#include "../inc/competidores.h"
#include "../inc/parser.h"

/** \brief Parsea los datos los datos de los competidores desde el archivo data.csv (modo texto).
 *
 * \param Puntero File
 * \param pListadoCompetidores LinkedList*
 * \return int  1 si se ejecutó correctamente, 0 si error
 *
 */
int parsear_CompetidorDesdeTexto(FILE* pArchivo, LinkedList* pListadoCompetidores)
{
    int retorno = 0;
    char buffer[4][30];
    int respuesta;
    Competidor* auxCompetidor = NULL;

    if( pArchivo != NULL && pListadoCompetidores != NULL)
    {
        //fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while( !feof(pArchivo))
        {
            respuesta = fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if( respuesta == 4)
            {
                auxCompetidor = competidor_nuevoParam(buffer[0], buffer[1], buffer[2], buffer[3]);

                if(auxCompetidor != NULL)
                {
                    ll_add(pListadoCompetidores, auxCompetidor);
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
