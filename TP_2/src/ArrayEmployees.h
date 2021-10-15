/*
 * ArrayEmployees.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Julieta
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

#endif /* ARRAYEMPLOYEES_H_ */


/** \brief Funcion que inicializa el array, indicando a las posiciones del array en el campo isEmpty como vacio (valor 1)
*
* \param list eEmployee* puntero a estructura "nomina" cargada con los usuarios.
* \param len int tamaño de la estructura "nomina".
* \return int retorna 0 si se pudo inicializar correctamente la estructura eEmployee nomina,
* o -1 si hubo un error en su inicializacion.
*
*/
int initEmployees(eEmployee* list, int len);

/** \brief funcion que busca indice libre dentro de array eEmployees nomina.
 *
 * \param list eEmployee* puntero a estructura "nomina" cargada con los usuarios.
 * \param len int tamaño de la estructura "nomina".
 * \return int retora -1 si no encontro posicion libre dentro de la estructura eEmployee nomina,
 * o la posicion del indice que se encuentra libre de datos.
 *
 */
int buscarLibre(eEmployee* list, int len);


/** \brief funcion que pide datos a usuario y los valida antes de ser cargados a la estructura eEmployee Nomina
 *
 * \param nombre[] char array que guarda el nombre del usuario ingresado
 * \param apellido[] char array que guarda el apellido del usuario ingresado
 * \param sueldo float* puntero a la variable sueldo, donde se va a guardar el valor correcto del sueldo ingresado
 * \param sector int* puntero a la variable sector, donde se va a guardar el valor correcto del sector ingresado
 * \return int retorna 0 si se pudo cargar correctamente los datos o -1 si hubo un error en la carga
 *
 */
int pedirEmployee(char nombre[], char apellido[], float* sueldo, int* sector);

/** \brief Agrega datos de un empleado(antes pedidos y validados) a una la lista eEmployee nomina.
*
* \param list eEmployee* puntero a estructura "nomina" para ser cargada con datos ingresados por el usuario.
* \param len int tamaño de la estructura "nomina".
* \param id int ID cargado por el usuario.
* \param name[] char array donde se encuentra el nombre a cargado por el usuario.
* \param lastName[] char array donde se encuentra el apellido cargado por el usuario.
* \param salary float valor del sueldo cargado por el usuario
* \param sector int valor el sector cargado por el usuario
* \return int retorna 0 si pudo agregar exitosamente el usuario a eEmployees nomina, o -1 si no pudo ser agregado.
*
*/
int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief Funcion que busca un empleado por su ID retornando la posicion (indice) donde se encuentra en el array.
*
* \param list eEmployee* puntero a estructura "nomina" cargada con los usuarios.
* \param len int tamaño de la estructura "nomina".
* \param id int ID del usuario a buscar.
* \return int retorna el indice donde se encontro el id del empleado, o -1 si no pudo ser eliminado
*
*/
int findEmployeeById(eEmployee* list, int len,int id);

/** \brief Elimina un usuario seleccionado por su ID por el usuario (colocando su campo isEmpty en 1)
*
* \param list eEmployee* puntero a estructura "nomina" cargada con los usuarios
* \param len int tamaño de la estructura "nomina".
* \param id int ID del usuario a buscar.
* \return int retorna 0 si pudo eliminar exitosamente el usuario, o -1 si no pudo ser eliminado
*
*/
int removeEmployee(eEmployee* list, int len, int id);


/** \brief Funcion que permite modificar al usuario un dato (seleccionado) de un empleado
 *
 * \param lista eEmployee* puntero a estructura "nomina" cargada con los usuarios
 * \param len int tamaño de la estructura "nomina"
 * \return int retorna 0 si pudo modificar exitosamente el usuario, o -1 si no pudo ser modificado
 *
 */
int modificarEmployee (eEmployee* lista, int len);


/** \brief Funcion que ordena los elementos del array eEmployeess nomina segun su orden(ascendente - descendente)
*
* \param list eEmployee* puntero a estructura "nomina" cargada con los usuarios.
* \param len int tamaño de la estructura "nomina".
* \param order int orden 1 es ascendente, orden 0 es descendente.
* \return int Retorna -1) si ocurre un error en el ordenamiento, o retorna 0 si pudo ordenarlos.
*
*/
int sortEmployees(eEmployee* list, int len, int order);

/** \brief funcion que calcula el promedio de los salarios de los usuarios ingresados
 *
 * \param list eEmployee* puntero a estructura "nomina" cargada con los usuarios
 * \param len int tamaño de la estrutura "nomina"
 * \return int retorna 0 si pudo realizar el promedio y -1 si no se pudo realizar.
 *
 */
int promEmployees(eEmployee* list, int len);

/** \brief funcion que imprime la totalidad de datos en la lista eEmployee nomina
*
* \param list eEmployee* puntero a estructura "nomina" cargada con los usuarios
* \param length int tamaño de la estructura "nomina"
* \return int devuelve 0 si imprimio algun empleado o -1 si no existe empleado y no se imprimio.
*
*/
int printEmployees(eEmployee* list, int length);


/** \brief muestra un solo empleado (seleccionado) por el usuario
 *
 * \param list eEmployee lista de empleados en nomina
 * \return void
 *
 */
void showEmployee(eEmployee list);
