#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;


/** \brief Se encarga de inicializar el valor isEmpty en todos los campos del array
 *
 * \param Array de estructuras de tipo Employee
 * \param tamaño
 * \return 0
 *
 */
int initEmployees(Employee* list,int len);

/** \brief Se encarga de agregar empleados
 *
 * \param Array de estructuras de tipo Employee
 * \param tamaño
 * \param nombre
 * \param apellido
 * \param id
 * \param salario
 * \param sector
 * \return Devuelve dos valores posibles:
 *  0 = Todo ok
 * -1 = No pudo agregar el empleado
 *
 */
int addEmployee(Employee* list, int len,char name[],char lastName[],int id,float salary, int sector);

/** \brief Se encarga de buscar a un empleado por su id
 *
 * \param Array de estructuras de tipo Employee
 * \param tamaño
 * \param id
 * \return Devuelve dos valores posibles:
 *  0 = Todo ok
 * -1 = No pudo encontrar o no existe el id
 */
int findEmployeeById(Employee* list,int len,int id);

/** \brief Se encarga de dar de baja a un empleado
 *
 * \param Array de estructuras de tipo Employee
 * \param tamaño
 * \param id
 * \return Devuelve dos valores posibles:
 *  0 = Todo ok
 * -1 = No pudo dar de baja o no existe el id
 *
 */
int removeEmployee(Employee* list, int len, int busqueda);

/** \brief Se encarga de ordenar el array de empleados
 *
 * \param Array de estructuras de tipo Employee
 * \param tamaño
 * \param criterio de ordenamiento
 * \return 0
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief Se encarga de imprimir la lista de empleados
 *
 * \param Array de estructuras de tipo Employee
 * \param tamaño
 * \return Devuelve dos valores posibles:
 *  0 = Todo ok
 * -1 = No imprimir la lista o la misma se encuentra vacia
 *
 */

int printEmployees(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_INCLUDED */
