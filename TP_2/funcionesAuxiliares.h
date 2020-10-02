#ifndef FUNCIONESAUXILIARES_H_INCLUDED
#define FUNCIONESAUXILIARES_H_INCLUDED
/** \brief Muestra y registra las opciones al usuario
 *
 * \return opcion seleccionada
 *
 */
int Menu();

/** \brief Funcion de ordenamiento ascendente
 *
 * \param Array de estructuras de tipo Employee
 * \param tamaño
 *
 */
void ordenarDescendente(Employee* list, int len);

/** \brief Funcion de ordenamiento descendente
 *
 * \param Array de estructuras de tipo Employee
 * \param tamaño
 *
 */
void ordenarAscendente(Employee* list, int len);

/** \brief Funcion para editar un empleado
 *
 * \param Array de estructuras de tipo Employee
 * \param tamaño
 * \param id  a editar
 *
 */
void editEmployee(Employee* list, int len, int busqueda);

/** \brief Funcion para validar cadenas de caracteres
 *
 * \param Nombre o Apellido ingresado por el usuario
 * \param tamaño maximo de la cadena
 * \return Devuelve dos valores posibles:
 *  0 = Todo ok
 * -1 = Detecto numeros o simbolos en el ingreso
 *
 */
int validarCadenas(char cadena[], int len);

/** \brief Funcion para calcular promedios, donde: Suma los salarios, devuelve el promedio y cuenta la cantidad de personas con salario mayor al promedio(30000)
 *
 * \param Array de estructuras de tipo Employee
 * \param tamaño
 * \return Devuelve dos valores posibles:
 *  0 = Todo ok
 * -1 = Si no detecta al menos un empleado cargado
 */

int calcularPromedios(Employee* list, int len);

#endif /* FUNCIONESAUXILIARES_H_INCLUDED */
