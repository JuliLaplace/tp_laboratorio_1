/*
 * Menu.h
 *
 *  Created on: 14 oct. 2021
 *      Author: Julieta
 */
#include <stdio.h>
#include <stdlib.h>


#ifndef MENU_H_
#define MENU_H_



#endif /* MENU_H_ */


/** \brief Funcion que muestra menu principal de opciones y retorna opcion elegida por usuario
 *
 * \return int retorna el numero de opcion elegida por usuario
 *
 */
int menu();

/** \brief Funcion que muestra submenu de opciones para listar empleados por orden alfabetico o por promedio creciente/decreciente.
 * retorna opcion elegida por usuario.
 *
 * \return int retorna el numero de opcion elegida por usuario.
 *
 */
int subMenuInformar();

/** \brief Funcion que brinda un menu para la eleccion de dato a modificar en empleado elegido previamente por id.
 *
 * \return int int retorna el numero de opcion elegida por usuario.
 *
 */
int subMenuModificar();

/** \brief Funcion que da dos opciones para listar empleados por apellido y sector (ascendente 1 - descendente 2)
 *
 * \return int int retorna el numero de opcion elegida por usuario.
 *
 */
int subMenuListarEmpleados();
