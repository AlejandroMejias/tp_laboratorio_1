#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"

/** \brief Guarda una estructura Employee inicializada y devuelve un puntero a dicha estructura
 *
 * \param
 * \param
 * \return Employee* puntero a la estructura inicialiada
 *
 */

Employee* employee_new()
{
    Employee* new_Employee = (Employee*) malloc(sizeof(Employee));
    if(new_Employee != NULL)
    {
        new_Employee->id = 0;
        strcpy(new_Employee->nombre, " ");
        new_Employee->horasTrabajadas = 0;
        new_Employee->sueldo = 0;
    }
    return new_Employee;
}

/** \brief Recibe como string el id, el nombre, las horas trabajadas y el sueldo de un empleado para crearlo.
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldoStr
 * \return Employee* nuevo empleado
 *
 */

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* new_Employee = employee_new();
    if( new_Employee != NULL)
    {
        if(!(employee_setId(new_Employee, atoi(idStr))
                && employee_setNombre(new_Employee, nombreStr)
                && employee_setHorasTrabajadas(new_Employee, atoi(horasTrabajadasStr))
                && employee_setSueldo(new_Employee, atoi(sueldoStr))))
        {
            new_Employee = NULL;
        }
    }

    return new_Employee;
}

/** \brief Muestra los datos de un empleado
 *
 * \param Employee*
 * \param
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int printEmployee(Employee* this)
{
    int retorno = 0;

    if(this != NULL)
    {
        printf("%4d  %20s          %4d           %7d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        retorno = 1;
    }
    return retorno;

}

/** \brief Asigna el id al empleado
 *
 * \param Employee*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_setId(Employee* this, int id)
{
    int retorno = 0;

    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}
/** \brief Obtiene el id del empleado
 *
 * \param Employee*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_getId(Employee* this, int* id)
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
    Employee* auxEmpleado;
    int maximo = 0;
    int tam = ll_len(this);
    int flag = 1;


    if(this != NULL && id != NULL)
    {
        for(i = 0; i < tam; i++)
        {
            auxEmpleado = ll_get(this,i);
            if(flag == 1 || maximo < auxEmpleado->id)
            {
                maximo = auxEmpleado->id;
                *id = maximo;
                flag = 0;
            }
            retorno = 1;
        }
    }

    return retorno;
}

/** \brief Asigna el nombre al empleado
 *
 * \param Employee*
 * \param char*
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) < 128)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}
/** \brief Obtiene el nombre del empleado
 *
 * \param Employee*
 * \param char*
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
    return retorno;
}

/** \brief Asigna las horas trabajadas al empleado
 *
 * \param Employee*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = 0;

    if( this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}
/** \brief Obtiene las horas trabajadas del empleado
 *
 * \param Employee*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

/** \brief Asigna el sueldo al empleado
 *
 * \param Employee*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = 0;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = 1;
    }
    return retorno;
}

/** \brief Obtiene el sueldo del empleado
 *
 * \param Employee*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = 0;

    if( this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }

    return retorno;
}

/** \brief Compara el id de dos empleados
 *
 * \param void*
 * \param void*
 * \return int
 *  1 si el primer id de empleado es mayor al segundo id de empleado,
 * -1 si el segundo id es mayor al primero,
 *  0 si son iguales.
 *
 */

int employee_sortId(void* e1, void* e2)
{
    int retorno;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(e1 != NULL && e2 != NULL)
    {
        empleadoUno=(Employee*) e1;
        empleadoDos=(Employee*) e2;

        if(empleadoUno->id > empleadoDos->id)
        {
            retorno = 1;
        }
        else if(empleadoUno->id < empleadoDos->id)
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

/** \brief Compara el nombre de dos empleados
 *
 * \param void*
 * \param void*
 * \return int
 *  1 si el primer nombre de empleado es mayor al segundo id de empleado,
 * -1 si el segundo nombre es mayor al primero,
 *  0 si son iguales.
 */

int employee_sortNombre(void* e1, void* e2)
{
    int retorno;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(e1 != NULL && e2 != NULL)
    {
        empleadoUno=(Employee*) e1;
        empleadoDos=(Employee*) e2;

        if((strcmp(empleadoUno->nombre, empleadoDos->nombre)) > 0)
        {
            retorno = 1;
        }
        else if((strcmp(empleadoUno->nombre, empleadoDos->nombre)) < 0)
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

/** \brief Compara las horas trabajadas de dos empleados
 *
 * \param void*
 * \param void*
 * \return int
 *  1 si la cantidad de horas trabajadas del primer empleado es mayor a la del segundo empleado,
 * -1 si la cantidad de horas trabajadas del segundo empleado es mayor a la del primer empleado,
 *  0 si son iguales.
 *
 */

int employee_sortHorasTrabajadas(void* e1, void* e2)
{
    int retorno;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(e1 != NULL && e2 != NULL)
    {
        empleadoUno = (Employee*)e1;
        empleadoDos = (Employee*)e2;

        if(empleadoUno->horasTrabajadas > empleadoDos->horasTrabajadas)
        {
            retorno = 1;
        }
        else if(empleadoUno->horasTrabajadas < empleadoDos->horasTrabajadas)
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
/** \brief Compara el sueldo de dos empleados
 *
 * \param void*
 * \param void*
 * \return int
 * 1 si el sueldo del primer empleado es mayor al del segundo empleado,
 * -1 si el sueldo del segundo empleado es mayor al del primer empleado,
 * 0 si son iguales.
 *
 */

int employee_sortSueldo(void* e1, void* e2)
{
    int retorno;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(e1 != NULL && e2 != NULL)
    {
        empleadoUno=(Employee*) e1;
        empleadoDos=(Employee*) e2;

        if(empleadoUno->sueldo > empleadoDos->sueldo)
        {
            retorno = 1;
        }
        else if(empleadoUno->sueldo < empleadoDos->sueldo)
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
