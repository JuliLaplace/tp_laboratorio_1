/*
 * utn.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Julieta
 */

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */


/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);




int getInt(int* pResultado);

/** \brief
 *
 * \param pResultado int* Puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto.
 * \param mensaje char* Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola.
 * \param mensajeError char* Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
 * \param minimo int Valor mínimo admitido.
 * \param maximo intValor máximo admitido (inclusive)
 * \param reintentos int cantidad de veces que el usuario puede reintentar ingresar un dato
 * \return int devuelde 0 si el valor ingresado es valido
 *
 */
int utn_getNumero( int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);



/** \brief
 *
 * \param pResultado float* Puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto.
 * \param mensaje char* Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola.
 * \param mensajeError char* Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
 * \param minimo float Valor mínimo admitido.
 * \param maximo float Valor maximo admitido.
 * \param reintentos int cantidad de veces que el usuario puede reintentar ingresar un dato
 * \return int devuelde 0 si el valor ingresado es valido
 *
*/
float utn_getNumeroFlotante( float * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);

float getFloat(float* pResultado);

/**
 * \brief Verifica si el valor recibido es numérico(float)
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico(float) y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[]);



/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);
