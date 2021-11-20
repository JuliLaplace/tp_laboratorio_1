/*
 * Mascotas.h
 *
 *  Created on: 20 nov. 2021
 *      Author: Julieta
 */
#include "../inc/LinkedList.h"
#ifndef SRC_MASCOTAS_H_
#define SRC_MASCOTAS_H_

typedef struct{
	int id;
	char nombre[20];
	char sexo;
	int edad;
	float peso;
}eMascota;


#endif /* SRC_MASCOTAS_H_ */

void mostrarMascota(eMascota* unaMascota);
void mostrarMascotas(LinkedList* list);
int ordenarEdadesMascotas(void* mascota1, void* mascota2);
