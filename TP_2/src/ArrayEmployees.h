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


/** \brief
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int initEmployees(eEmployee* list, int len);

/** \brief
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int buscarLibre(eEmployee* list, int len);


/** \brief
 *
 * \param nombre[] char
 * \param apellido[] char
 * \param sueldo float*
 * \param sector int*
 * \return int
 *
 */
int pedirEmployee(char nombre[], char apellido[], float* sueldo, int* sector);

/** \brief
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int
 *
 */
int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int
 *
 */
int findEmployeeById(eEmployee* list, int len,int id);

/** \brief
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int
 *
 */
int removeEmployee(eEmployee* list, int len, int id);


/** \brief
 *
 * \param list Employee*
 * \param len int
 * \param order int
 * \return int
 *
 */
int sortEmployees(eEmployee* list, int len, int order);

/** \brief
 *
 * \param list eEmployee*
 * \param len int
 * \return int
 *
 */
int promEmployees(eEmployee* list, int len);

/** \brief
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee* list, int length);


/** \brief
 *
 * \param list[] Employee
 * \return void
 *
 */
void showEmployee(eEmployee list);
