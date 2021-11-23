#include "Employee.h"
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* archivo a abrir
 * \param pArrayListEmployee LinkedList* lista de linkedlist
 * \return int retorna 1 si logro cargar los datos correctamente o 0 si no pudo realizar la carga
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* archivo a abrir
 * \param pArrayListEmployee LinkedList* lista de linkedlist
 * \return int retorna 1 si logro cargar los datos correctamente o 0 si no pudo realizar la carga
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param path char* archivo a cargar
 * \param pArrayListEmployee LinkedList* lista de linkedlist
 * \param pId puntero a id a cargar, aumentar y escribir
 * \return int retorna 1 si logro cargar el empleado correctamente o 0 si no pudo realizar la carga
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param path char* archivo a modificar
 * \param pArrayListEmployee LinkedList* lista de linkedlist
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Baja de empleado
 *
 * \param path char* archivo a modificar
 * \param pArrayListEmployee LinkedList* lista de linkedlist
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param path char* archivo a buscar data para listar
 * \param pArrayListEmployee LinkedList* lista de linkedlist
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Funcion que muestra por pantalla un empleado
 *
 * \param empleado Employee* puntero a array empleados.
 * \return int retorna 1 si logro mostrar el empleado correctamente o 0 si no pudo realizarlo
 *
 */
int showEmployee(Employee* empleado);


/** \brief Ordenar empleados
 *
 * \param path char* archivo con data a ordenar
 * \param pArrayListEmployee LinkedList* lista de linkedlist
 * \return int retorna 1 si logro ordenarlos empleados correctamente o 0 si no pudo realizarlo
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* archivo donde se guardaran los datos
 * \param pArrayListEmployee LinkedList* lista de linkedlist
 * \return int retorna 1 si logro guardar el archivo como texto, o 0 si no logro realizarlo
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* archivo donde se guardaran los datos
 * \param pArrayListEmployee LinkedList* lista de linkedlist
 * \return int retorna 1 si logro guardar el archivo como binario, o 0 si no logro realizarlo
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);




