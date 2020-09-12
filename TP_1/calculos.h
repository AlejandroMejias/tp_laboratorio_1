#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED

/** \brief Pide el ingreso y almacena el primer operando
 *
 * \return Devuelve el primer operando ingresado por el usuario
 */
float numeroUno();

/** \brief Pide el ingreso y almacena el segundo operando
 *
 * \return Devuelve el segundo operando
 */
float numeroDos();

/** \brief Destinada al calculo de la suma
 *
 * \param Primer operando ingresado por el usuario
 * \param Segundo operando ingresado por el usuario
 * \return Resultado de la suma entre ambos operandos
 */
float utn_CalcularSuma(float numeroUno,float numeroDos);

/** \brief Destinada al calculo de la resta
 *
 * \param Primer operando ingresado por el usuario
 * \param Segundo operando ingresado por el usuario
 * \return Resultado de la resta entre ambos operandos
 *
 */
float utn_CalcularResta(float numeroUno, float numeroDos);

/** \brief Destinada al calculo de la division, si no se cumplen las condiciones significa que el numerador es cero
 *
 * \param Primer operando ingresado por el usuario
 * \param Segundo operando ingresado por el usuario
 * \return Devuelve 3 valores posibles:
 * -1 = Cuando el segundo operando tiene valor cero
 *  0 = En caso de que el primer operando sea cero
 *  Resultado de la division entre ambos operandos en caso de ser exitosa
 *
 */
float utn_CalcularDivision(float numeroUno, float numeroDos);

/** \brief Destinada al calculo de la multiplicacion
 *
 * \param Primer operando ingresado por el usuario
 * \param Segundo operando ingresado por el usuario
 * \return Resultado de la multiplicacion
 *
 */
float utn_CalcularMultiplicacion(float numeroUno, float numeroDos);

/** \brief Destinada al calculo del factorial del primer operando
 *
 * \param Primer operando ingresado por el usuario
 * \return Devuelve 2 valores posibles:
 *  -1 = Para indicar que no es posible calcular factorial en numeros negativos
 Calculo del factorial del primer operando
 *
 */
long long int utn_CalcularFactorialUno(int numeroUno);

/** \brief Destinada al calculo del factorial del segundo operando
 *
 * \param Segundo operando ingresado por el usuario
 * \return Devuelve 2 valores posibles:
 *  -1 = Para indicar que no es posible calcular factorial en numeros negativos
 *  Calculo del factorial del segundo operando
 *
 */
long long int utn_CalcularFactorialDos(int numeroDos);

#endif /* CALCULOS_H_INCLUDED */
