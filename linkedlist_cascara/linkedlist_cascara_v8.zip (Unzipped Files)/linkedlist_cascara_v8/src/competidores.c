#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/LinkedList.h"
#include "../inc/competidores.h"
#include "../inc/controller.h"


/** \brief Guarda una estructura Competidor inicializada y devuelve un puntero a dicha estructura
 *
 * \param
 * \param
 * \return Competidor* puntero a la estructura inicializada
 *
 */

Competidor* nuevo_competidor()
{
    Competidor* nuevoCompetidor = (Competidor*) malloc(sizeof(Competidor));
    if(nuevoCompetidor != NULL)
    {
        nuevoCompetidor->id = 0;
        strcpy(nuevoCompetidor->nombre, " ");
        strcpy(nuevoCompetidor->paisOrigen, " ");
        nuevoCompetidor->medallasGanadas = 0;
    }
    return nuevoCompetidor;
}

/** \brief Recibe como string el id, el nombre, el pais y las medallas ganadas de un competidor para crearlo.
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* paisStr
 * \param char* medallasStr
 * \return Competidor* nuevo competidor
 *
 */

Competidor* competidor_nuevoParam(char* idStr, char* nombreStr, char* paisStr,char* medallasStr)
{
    Competidor* nuevoCompetidor = nuevo_competidor();
    if( nuevoCompetidor != NULL)
    {
        if(!(competidor_setId(nuevoCompetidor, atoi(idStr))
                && competidor_setNombre(nuevoCompetidor, nombreStr)
                && competidor_setPaisOrigen(nuevoCompetidor, paisStr)
                && competidor_setMedallasGanadas(nuevoCompetidor, atoi(medallasStr))))
        {
            nuevoCompetidor = NULL;
        }
    }

    return nuevoCompetidor;
}

/** \brief Muestra las estadisticas de un competidor
 *
 * \param Competidor*
 * \param
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int imprimirCompetidor(Competidor* this)
{
    int retorno = 0;

    if(this != NULL)
    {
        printf("%4d    %20s  %40s                   %2d\n", this->id, this->nombre, this->paisOrigen, this->medallasGanadas);
        retorno = 1;
    }
    return retorno;

}
/** \brief Asigna el id al competidor
 *
 * \param Competidor*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */
int competidor_setId(Competidor* this, int id)
{
    int retorno = 0;

    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}
/** \brief Obtiene el id del competidor
 *
 * \param Competidor*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int competidor_getId(Competidor* this, int* id)
{
    int retorno = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }

    return retorno;
}
/** \brief Obtiene el ID MAXIMO de la LinkedList
 *
 * \param Puntero a Linkedlist
 * \param Puntero donde se almacenara el maximo ID encontrado
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int idMaximo(LinkedList* this, int* id)
{
    int i;
    int retorno = 0;
    int maximo = 0;
    int tam = ll_len(this);
    int flag = 1;
    Competidor* auxCompetidor;


    if(this != NULL && id != NULL)
    {
        for(i = 0; i < tam; i++)
        {
            auxCompetidor = ll_get(this,i);
            if(flag == 1 || maximo < auxCompetidor->id)
            {
                maximo = auxCompetidor->id;
                *id = maximo;
                flag = 0;
            }
            retorno = 1;
        }
    }

    return retorno;
}

/** \brief Asigna el nombre al competidor
 *
 * \param Competidor*
 * \param char*
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int competidor_setNombre(Competidor* this, char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) < 50)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}
/** \brief Obtiene el nombre del competidor
 *
 * \param Competidor*
 * \param char*
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int competidor_getNombre(Competidor* this, char* nombre)
{
    int retorno = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}

/** \brief Asigna el pais de origen al competidor
 *
 * \param Competidor*
 * \param char*
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int competidor_setPaisOrigen(Competidor* this, char* paisOrigen)
{
    int retorno = 0;
    if(this != NULL && paisOrigen != NULL && strlen(paisOrigen) < 50)
    {
        strcpy(this->paisOrigen, paisOrigen);
        retorno = 1;
    }
    return retorno;
}
/** \brief Obtiene el pais de origen del competidor
 *
 * \param Competidor*
 * \param char*
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int competidor_getPaisOrigen(Competidor* this, char* paisOrigen)
{
    int retorno = 0;

    if( this != NULL && paisOrigen != NULL)
    {
        strcpy(paisOrigen, this->paisOrigen);
        retorno = 1;
    }
    return retorno;
}

/** \brief Asigna las medallas ganadas al competidor
 *
 * \param Competidor*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int competidor_setMedallasGanadas(Competidor* this, int medallas)
{
    int retorno = 0;

    if( this != NULL && medallas >= 0)
    {
        this->medallasGanadas = medallas;
        retorno = 1;
    }
    return retorno;
}
/** \brief Obtiene las medallas ganadas del competidor
 *
 * \param Competidor*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int competidor_getMedallasGanadas(Competidor* this, int* medallas)
{
    int retorno = 0;

    if(this != NULL && medallas != NULL)
    {
        *medallas = this->medallasGanadas;
        retorno = 1;
    }

    return retorno;
}

/** \brief Compara el id de dos competidores
 *
 * \param void*
 * \param void*
 * \return int
 *  1 si el primer id de competidor es mayor al segundo id de competidor,
 * -1 si el segundo id es mayor al primero,
 *  0 si son iguales.
 *
 */

int competidor_sortId(void* e1, void* e2)
{
    int retorno;

    Competidor* competidorUno;
    Competidor* competidorDos;

    if(e1 != NULL && e2 != NULL)
    {
        competidorUno=(Competidor*) e1;
        competidorDos=(Competidor*) e2;

        if(competidorUno->id > competidorDos->id)
        {
            retorno = 1;
        }
        else if(competidorUno->id < competidorDos->id)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}
/** \brief Compara el nombre de dos competidores
 *
 * \param void*
 * \param void*
 * \return int
 *  1 si el primer nombre del competidor es mayor al segundo id del competidor,
 * -1 si el segundo nombre es mayor al primero,
 *  0 si son iguales.
 */

int competidor_sortNombre(void* e1, void* e2)
{
    int retorno;

    Competidor* competidorUno;
    Competidor* competidorDos;

    if(e1 != NULL && e2 != NULL)
    {
        competidorUno =(Competidor*) e1;
        competidorDos =(Competidor*) e2;

        if((strcmp(competidorUno->nombre, competidorDos->nombre)) > 0)
        {
            retorno = 1;
        }
        else if((strcmp(competidorUno->nombre, competidorDos->nombre)) < 0)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}
/** \brief Compara el pais de origen de dos competidores
 *
 * \param void*
 * \param void*
 * \return int
 *  1 si el primer pais de origen del competidor es mayor al segundo id del competidor,
 * -1 si el segundo nombre es mayor al primero,
 *  0 si son iguales.
 */

int competidor_sortPaisOrigen(void* e1, void* e2)
{
    int retorno;

    Competidor* competidorUno;
    Competidor* competidorDos;

    if(e1 != NULL && e2 != NULL)
    {
        competidorUno =(Competidor*) e1;
        competidorDos =(Competidor*) e2;

        if((strcmp(competidorUno->paisOrigen, competidorDos->paisOrigen)) > 0)
        {
            retorno = 1;
        }
        else if((strcmp(competidorUno->paisOrigen, competidorDos->paisOrigen)) < 0)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Compara las medallas obtenidas de dos competidores
 *
 * \param void*
 * \param void*
 * \return int
 * 1 si el sueldo del primer competidor es mayor al del segundo competidor,
 * -1 si el sueldo del segundo competidor es mayor al del primer competidor,
 * 0 si son iguales.
 *
 */

int competidor_sortMedallasGanadas(void* e1, void* e2)
{
    int retorno;

    Competidor* competidorUno;
    Competidor* competidorDos;

    if(e1 != NULL && e2 != NULL)
    {
        competidorUno =(Competidor*) e1;
        competidorDos =(Competidor*) e2;

        if(competidorUno->medallasGanadas > competidorDos->medallasGanadas)
        {
            retorno = 1;
        }
        else if(competidorUno->medallasGanadas < competidorDos->medallasGanadas)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}
