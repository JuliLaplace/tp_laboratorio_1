/*
 * Mascotas.c
 *
 *  Created on: 20 nov. 2021
 *      Author: Julieta
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mascotas.h"
#include "../testing/inc/main_test.h"



void mostrarMascota(eMascota* unaMascota)
{
    if(unaMascota!= NULL)
    {
        printf("%d         %10s  %c %d %.3f\n", unaMascota->id, unaMascota->nombre, unaMascota->sexo, unaMascota->edad, unaMascota->peso);
    }
}

void mostrarMascotas(LinkedList* list)
{
    int tam;

    eMascota* aux = NULL;
    printf("*****************************************************************************************\n");
    printf("*									MASCOTAS         									*\n");
    printf("*****************************************************************************************\n");
    printf("*****************************************************************************************\n");
	printf("ID         Nombre  	Sexo		Edad		Peso\n");
	printf("*****************************************************************************************\n");
    if(list != NULL && !(ll_isEmpty(list))) 	//uso ll_isEmpty para fijarme si la lista esta vacia e informar
    {
        tam = ll_len(list);	//uso la cantidad de elementos que tiene la lista para recorrer con el for

        for(int i=0; i<tam; i++)
        {
        	aux = (eMascota*) ll_get(list,i); 	// uso ll_get para obtener la mascota de
												//la lista que esta en la posicion i y se lo paso
												//a mostrarMascota
            mostrarMascota(aux);
        }

    }else{
    	printf("No hay mascotas para mostrar");
    }

}



int ordenarEdadesMascotas(void* mascota1, void* mascota2)
{

    int retorno=-1;


    if(mascota1 != NULL && mascota2 != NULL)
    {

        if(((eMascota*)mascota1)->edad <(((eMascota*)mascota2)->edad)){
        	retorno = 1;
        }else{
        	retorno =0;
        }

    }

    return retorno;
}
