int suma(int a, int b)
{
    int resultado;
    resultado = a + b;
    return resultado;
}
/** \brief funcion suma: suma dos enteros.
 *
 * \param primer entero(a).
 * \param segundo entero(b).
 * \return el resultado de la cuenta es un entero.
 *
 */


int resta(int a, int b)
{
    int resultado;
    resultado = a - b;
    return resultado;
}
/** \brief funcion resta: resta dos enteros.
 *
 * \param primer entero(a).
 * \param segundo entero(b).
 * \return el resultado de la cuenta es un entero.
 *
 */


int division(int a, int b)
{
    int resultado;
    resultado = a / b;

    return resultado;
}
/** \brief funcion division: divide dos enteros.
 *
 * \param primer entero(a).
 * \param segundo entero(b).
 * \return el resultado de la cuenta es un entero.
 *
 */


int multiplicacion(int a, int b)
{
    int resultado;
    resultado = a * b;

    return resultado;
}
/** \brief funcion multiplicacion: multiplica dos enteros.
 *
 * \param primer entero(a).
 * \param segundo entero(b).
 * \return el resultado de la cuenta es un entero.
 *
 */

int factorial(int a)
{
    int respuesta;
    if(a == 1)
    {
        return 1;
    }
    respuesta = a * factorial(a - 1);
    return (respuesta);
}
/** \brief funcion factorial: factoria un enteros.
 *
 * \param entero(a).
 * \return el resultado de la cuenta es un entero.
 *
 */
