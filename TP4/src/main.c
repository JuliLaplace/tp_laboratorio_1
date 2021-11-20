/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Mascotas.h"
#include "Menu.h"




int main(void)
{
	setbuf(stdout, NULL);
	char seguir = 's';
	int flag=0;
	int flagListaCopia=0;
	int flagCargaMascotas=0;
	int tamMascotas;
	int indiceMascota;


	LinkedList* mascotas = NULL;
	LinkedList* mascotasSubList = NULL;
	LinkedList* listaMascotasCopia=NULL;
	eMascota* mascota1 = NULL;//(eMascota*) malloc(sizeof(eMascota));
	eMascota* mascota2 = NULL;//(eMascota*) malloc(sizeof(eMascota));
	eMascota* mascota3 = NULL;//(eMascota*) malloc(sizeof(eMascota));
	eMascota* mascotaEliminada=NULL;


	do{
		switch(menu()){
			case 1:
				mascotas = ll_newLinkedList(); // creo una linkedlist para guardar mascotas
												//y verifico si pudo o no crearla
				if(mascotas==NULL){
					printf("No se pudo crear la LinkedList pedida.\n");
					exit(1);
				}else{
					printf("Linkedlist creada con exito.\n");
					flag =1;
				}
				break;
			case 2:
				if(flag){
						mascota1 = malloc(sizeof(eMascota));
						mascota2=malloc(sizeof(eMascota));;
						mascota3=malloc(sizeof(eMascota));
						if(mascota1!=NULL && mascota2!=NULL && mascota3!=NULL){
							 mascota1->id = 1000;
							 strcpy(mascota1->nombre, "Morty");
							 mascota1->sexo='m';
							 mascota1->edad = 2;
							 mascota1->peso=6.550;

							  mascota2->id = 1001;
							  strcpy(mascota2->nombre, "Effy");
							  mascota2->sexo='f';
							  mascota2->edad = 7;
							  mascota2->peso=4.100;

							  mascota3->id = 1002;
							  strcpy(mascota3->nombre, "Elvis");
							  mascota3->sexo='m';
							  mascota3->edad = 9;
							  mascota3->peso=7.8000;


							  if(!ll_add(mascotas, mascota1) && !ll_add(mascotas, mascota2) && !ll_add(mascotas, mascota3)){
								 printf("Mascotas agregadas a la LinkedList mascotas.\n");
							}else{
								printf("Error en carga de mascotas en LinkedList mascotas.\n");
							}
							  printf("Datos de mascotas cargados con exito.\n");
							  flagCargaMascotas=1;
						}

				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}
				break;
			case 3:
				if(flag){
					tamMascotas= ll_len(mascotas);
					printf("La cantidad de mascotas que hay en la lista es: %d.\n", tamMascotas);
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}
				break;
			case 4:
				if(flag){
					mostrarMascotas(mascotas);	//en funcion mostrarMascotas se utiliza funcion ll_get
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}
				break;
			case 5:
				if(flag && flagCargaMascotas){
					if(ll_sort(mascotas,ordenarEdadesMascotas,1)!=-1){
						mostrarMascotas(mascotas);
						printf("\nMascotas ordenadas por edad correctamente.\n");
					}
				}else if(flag && !flagCargaMascotas){
					printf("Debes cargar datos de mascotas en la LinkedList primero (opcion 2).\n");
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}
				break;
			case 6:
				if(flag && flagCargaMascotas){
					if(ll_contains(mascotas, mascota2)){
						printf("La mascota Effy (mascota 2) se encuentra en la lista.\n");
					}else{
						printf("La mascota Effy (mascota 2) no se encuentra en la lista.\n");
					}
				}else if(flag && !flagCargaMascotas){
					printf("Debes cargar datos de mascotas en la LinkedList primero (opcion 2).\n");
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}
				break;
			case 7:
				if(flag && flagCargaMascotas){
					listaMascotasCopia = ll_clone(mascotas);
						if(listaMascotasCopia!=NULL){
							 printf("*****************************************************************************************\n");
							 printf("*							COPIA DE LISTA DE MASCOTAS									 *\n");
							 printf("*****************************************************************************************\n");
							mostrarMascotas(listaMascotasCopia);
							printf("Lista de mascotas copiada a nueva LinkedList.\n");
							flagListaCopia=1;

						}else{
							printf("No se pudo copiar la lista de mascotas a la nueva LinkedList.\n");
						}
				}else if(flag && !flagCargaMascotas){
					printf("Debes cargar datos de mascotas en la LinkedList primero (opcion 2).\n");
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}

				break;
			case 8:
				if(flag && flagListaCopia){
					if(ll_containsAll(listaMascotasCopia, mascotas)){
						printf("Todas las mascotas pertenecientes a la lista original de mascotas se encuentran en la lista de mascotas copiada.\n\n");
					}else{
						printf("No se encuentran todas las mascotas copiadas en la lista.");
					}
				}else if(flag && !(flagListaCopia)){
					printf("Debes copiar la lista (opcion 7) para acceder a este campo.\n");
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}
				break;
			case 9:
				if(flag && flagListaCopia){
					eMascota* mascota4 = (eMascota*) malloc(sizeof(eMascota));
					if(mascota4!=NULL){
						mascota4->id = 1004;
						strcpy(mascota4->nombre, "Zina");
						mascota4->sexo='f';
						mascota4->edad = 2;
						mascota4->peso=3.400;
					}
					if(!ll_push(mascotas,1,mascota4)){
						printf("Nueva mascota cargada en lista (indice 1) correctamente.\n");
						mostrarMascotas(mascotas);
					}
				}else if(flag && !flagListaCopia){
					printf("Debes copiar la lista (opcion 7) para acceder a este campo.\n");
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}
				break;
			case 10:
				if(flag && flagCargaMascotas){
					eMascota* aux = (eMascota*) malloc(sizeof(eMascota));
					if(aux!=NULL){
						aux->id = 1002;
						strcpy(aux->nombre, "Summer");
						aux->sexo='f';
						aux->edad = 10;
						aux->peso=5.500;
						if(!ll_set(mascotas,1,aux)){

							printf("Mascota de indice 1 modificada correctamente.\n");
							mostrarMascotas(mascotas);
						}else{
							printf("No existen mascotas en el indiceindicado para modificar.\n");
						}
					}

				}else if(flag && !flagCargaMascotas){
					printf("Debes cargar datos de mascotas en la LinkedList primero (opcion 2).\n");
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}
				break;
			case 11:
				if(flag){
					if(!ll_remove(mascotas,1)){
						printf("Mascota en indice 3 eliminada correctamente.\n");
						mostrarMascotas(mascotas);
					}else{
						printf("No se encuentran mascotas en el indice indicado (indice 3).\n");
					}
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}
				break;
			case 12:
				if(flag && flagListaCopia){
					mascotaEliminada = ll_pop(listaMascotasCopia,0);
					if(mascotaEliminada !=NULL){
						printf("Se elimino esta mascota:\n");
						mostrarMascota(mascotaEliminada);
						printf("\n\n");
						mostrarMascotas(listaMascotasCopia);
					}else{
						printf("No hay mascotas que eliminar.\n");
					}

				}else if(flag && !flagListaCopia){
					printf("Debes copiar la lista (opcion 7) para acceder a este campo.\n");
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}
				break;
			case 13:
				if(flag && flagListaCopia){
					if(!ll_clear(listaMascotasCopia)){
						 printf("*****************************************************************************************\n");
						 printf("*                         COPIA DE LISTA DE MASCOTAS                                    *\n");
						 printf("*****************************************************************************************\n");
								printf("Lista de mascotas (copia) eliminada correctamente.\n");
								mostrarMascotas(listaMascotasCopia);
					}
				}else if(flag && !flagListaCopia){
					printf("Debes copiar la lista (opcion 7) para acceder a este campo.\n");
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}

				break;
			case 14:
				if(flag && flagCargaMascotas){
					indiceMascota = ll_indexOf(mascotas,mascota3);
					if(indiceMascota!= -1){
						printf("La mascota 'Elvis' se encuentra en el indice %d.\n", indiceMascota);
					}else{
						printf("No existe la mascota 'Elvis' en la lista.\n");
					}
				}else if(flag && !flagCargaMascotas){
					printf("Debes cargar datos de mascotas en la LinkedList primero (opcion 2).\n");
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}
				break;
			case 15:
				if(flag && flagCargaMascotas){
					mascotasSubList = ll_subList(mascotas, 0, 2);
					if(mascotasSubList!=NULL){
						printf("SubLista de mascotas desde el indice 0 al indice 2 (no incluido) creada correctamente.\n");
						mostrarMascotas(mascotasSubList);
						ll_deleteLinkedList(mascotasSubList);

					}else{
						printf("No hay mascotas que mostrar.\n");
					}
				}else if(flag && !flagCargaMascotas){
					printf("Debes cargar datos de mascotas en la LinkedList primero (opcion 2).\n");
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}
				break;
			case 16:
				if(flag){
					if(!(ll_deleteLinkedList(mascotas))){
						 printf("Lista de mascotas (original) eliminada correctamente.\n\n");
						 flag=0;
					}else{
						printf("El puntero en nulo (NULL)");
					}
				}else{
					printf("Primero debes crear una Linkedlist (opcion 1).\n");
				}

				break;
			case 17:
				seguir = 'n';
				break;
			 default:
				 printf("La opcion ingresada es incorrecta. Ingrese una opcion valida.\n");
				 break;
		}
		system("pause");

	}while(seguir=='s');



	//startTesting(1);  // ll_newLinkedList
	//startTesting(2);  // ll_len
	//startTesting(3);  // getNode - test_getNode
	//startTesting(4);  // addNode - test_addNode
	//startTesting(5);  // ll_add
	//startTesting(6);  // ll_get
	//startTesting(7);  // ll_set
	//startTesting(8);  // ll_remove
	//startTesting(9);  // ll_clear
	//startTesting(10); // ll_deleteLinkedList
	//startTesting(11); // ll_indexOf
	//startTesting(12); // ll_isEmpty
	//startTesting(13); // ll_push
	//startTesting(14); // ll_pop
	//startTesting(15); // ll_contains
	//startTesting(16); // ll_containsAll
	//startTesting(17); // ll_subList
	//startTesting(18); // ll_clone
	//startTesting(19); // ll_sort


    return 0;
}
