/*
 * Biblioteca.h
 *
 *  Created on: 21 sep. 2021
 *      Author: Julieta
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_



#endif /* BIBLIOTECA_H_ */
/** \brief Funcion menu retorna un caracter numerico como "opcion" elegida por el usuario para utilizar la
** calculadora.
 *
 * \param flagA int bandera para informar si se ingreso primer operando (vale 1) o no (vale 0).
 * \param flagB int bandera para informar si se ingreso el segundo operando (vale 1) o no (vale 0)..
 * \param num1 int primer operando ingresado por usuario.
 * \param num2 int segundo operando ingresado por usuario.
 * \param flagCalculo int bandera para informar si se realizaron los calculos (vale 1) o no(vale 0).
 * \param suma int resultado de la funcion suma.
 * \param resta int resultado de la funcion resta.
 * \param multiplicacion int resultado de la funcion multiplicacion.
 * \param division int valor si se pudo realizar la operacion dividir (vale 1) o no pudo realizarse (vale 0).
 * \param resulDivision float resultado de la funcion division si se pudo realizar.
 * \param factorialPrimerNumOk int valor de control para ver si se pudo realizar el factorial (1) o no se pudo realizar (0) de numA.
 * \param resulPrimerFactorial int resultado de la funcion factorial de primer operando.
 * \param factorialSegundoNumOk int valor de control para ver si se pudo realizar el factorial (1) o no se pudo realizar (0) de numB
 * \param resulSegundoFactorial int resultado de la funcion factorial del segundo operando.
 * \param flagResul int bandera para informar si se imprimieron los resultados (vale 1) o no (vale 0).
 * \return char funcion menu devuelve un caracter numerico como opcion elegida por el usuario.
 *
 */
char menu(int flagA, int flagB, int num1, int num2, int flagCalculo, int suma, int resta, int multiplicacion, int division, float resulDivision, int factorialPrimerNumOk, int resulPrimerFactorial, int factorialSegundoNumOk, int resulSegundoFactorial, int flagResult);

/** \brief Funcion para realizar la suma de dos operandos ingresados por el usuario.
 *
 * \param num1 int primer operando ingresado por el usuario.
 * \param num2 int segundo operando ingresado por el usuario.
 * \return int retorna el resultado de la suma de los dos operandos ingresados.
 *
 */
int suma(int num1, int num2);

/** \brief Funcion para realizar la resta de dos operandos ingresados por el usuario.
 *
 * \param num1 int primer operando ingresado por el usuario.
 * \param num2 int segundo operando ingresado por el usuario.
 * \return int retorna el resultado de la resta de los dos operandos ingresados.
 *
 */
int resta(int num1, int num2);

/** \brief Funcion para realizar el producto de dos operandos ingresados por el usuario.
 *
 * \param num1 int primer numero operandos por el usuario.
 * \param num2 int segundo operandos ingresado por el usuario.
 * \return int retorna el resultado de la multiplicacion de los dos operandos ingresados.
 *
 */
int multiplicacion(int num1, int num2);

/** \brief Funcion para realizar la division de dos operandos ingresados por el usuario.
 *
 * \param num1 int primer operando ingresado por el usuario (dividendo).
 * \param num2 int segundo operando ingresado por el usuario (divisor).
 * \param pResulDivision float* puntero para almacenar el valor de la division entre num1 y num2.
 * \return int retorna 1 si se puede realizar la division (cuando dividendo sea distinto de 0 y cuando puntero *pResulDivision no sea NULL) o retorna 0 si no se pudo realizar la division.
 *
 */
int division(int num1, int num2, float* pResulDivision);



/** \brief Funcion para calcular el factorial de numero (ingresado por el usuario) siendo mayor a cero.
 *
 * \param num int operando ingresado por el usuario.
 * \param factorialA int* puntero que almacena el valor de la factorizacion del parametro num.
 * \return int retorna 1 si se puede factorizar num (num sea mayor a cero y cuando el puntero *factorialA no sea NULL) o retorna 0 si no se pudo realizar.
 *
 */
int factorial(int num, int* factorialA);
