/*
 ============================================================================
 Name        : TP_2.c
 Author      : Julieta Laplace
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#include "Menu.h"

#define TAM 5 //va 1000




int main(void) {
	setbuf(stdout,NULL);
	eEmployee nomina[TAM];
	    int id = 1000;
	    int flagCargaEmployee = 0;
	    char seguir = 's';

	    char nombre[51];
	    char apellido[51];
	    float sueldo;
	    int sector;

	    if(!initEmployees(nomina, TAM)){
	        printf("Ocurrio un error al inicializar la lista.\n");
	    }


	    do{
	        switch(menu()){

	            case 1:
	                if(pedirEmployee(nombre,apellido, &sueldo, &sector)==0){
	                    if(addEmployee(nomina, TAM, id, nombre, apellido, sueldo, sector)==0){
	                        printf("Carga exitosa.\n");
	                        id++;
	                        flagCargaEmployee = 1;
	                    }
	                }else{
	                    printf("Error. No se pudo realizar la carga.\n");
	                }

	                break;
	            case 2:
	                if(flagCargaEmployee){
	                	 if(modificarEmployee(nomina, TAM) ==0){
	                		 printf("Modificacion exitosa.\n");
	                	 } else {
	                	     printf("No se realizo la modificacion.\n");
	                	 }
	                }else{
	                    printf("Primero debe cargar algun empleado.\n\n");
	                }

	                break;
	            case 3:
	                 if(flagCargaEmployee){

	                    if(removeEmployee(nomina, TAM, id)==0){
	                        printf("Baja exitosa.\n");
	                    } else{
	                        printf("No se realizo la baja.\n");
	                    }

	                }else{
	                    printf("Primero debes dar de alta un empleado.\n");
	                }
	                break;


	            case 4:
	                if(flagCargaEmployee){
	                	int orden;
	                    switch(subMenuInformar()){
	                        case 1:
	                        	orden = subMenuListarEmpleados();
	                        	printEmployees(nomina,TAM);

	                        	if(sortEmployees(nomina, TAM, orden)==0){
	                        	        printEmployees(nomina, TAM);

	                        	}else{
	                        	        printf("No se pudo ordenar\n");
	                        	}
	                            break;
	                        case 2:
	                        	if(promEmployees(nomina, TAM)==0){
	                        		printf("\n\n Carga de promedio del salario exitosa.\n");
	                        	} else {
	                        	    printf("No se pudo realizar el promedio.\n");
	                        	}
	                            break;
	                        default:
	                            printf("Opcion invalida.\n\n");
	                            break;
	                    }
	                }else{
	                    printf("Primero debe cargar algun empleado.\n\n");
	                }
	                break;

	            case 5:
	                seguir='n';
	                break;

	            default:
	                printf("Opcion invalida.\n\n");
	                break;

	        }
	        system("pause");

	    }while(seguir=='s');

	return EXIT_SUCCESS;
}


