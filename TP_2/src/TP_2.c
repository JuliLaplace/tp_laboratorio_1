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

#define TAM 5 //va 1000

int menu();
int subMenuInformar();
int subMenuModificar();

int main(void) {
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
	                    switch(subMenuModificar()){
	                        case 1:
	                            printf("Nombre.");
	                            break;
	                        case 2:
	                            printf("Apellido.");
	                            break;
	                        case 3:
	                            printf("Salario.");
	                            break;
	                        case 4:
	                            printf("Sector.");
	                            break;
	                        default:
	                            printf("Opcion invalida.\n");
	                            break;
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
	                    switch(subMenuInformar()){
	                        case 1:
	                            break;
	                        case 2:
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

int menu(){


    int opcion;
    system("cls");
    printf("*********************************************************************************************\n");
    printf("*                                   NOMINA EMPLEADOS                                        *\n");
    printf("*********************************************************************************************\n");


    printf("    1) ALTA PERSONA.\n");
    printf("    2) MODIFICAR PERSONA.\n");
    printf("    3) BAJA PERSONA.\n");
    printf("    4) INFORMAR:\n");
    printf("        a) Listar empleados ordenados alfabéticamente por Apellido y Sector\n");
    printf("        b) Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
    printf("    5) SALIR.\n");
    printf("*********************************************************************************************\n");
    printf("Ingrese opcion deseada: ");
    scanf("%d", &opcion);
    printf("*********************************************************************************************\n");
    return opcion;


}

int subMenuInformar(){
    int opcion;
    system("cls");
    printf("*********************************************************************************************\n");
    printf("*                                       INFORMAR                                            *\n");
    printf("*********************************************************************************************\n");
    printf("    1) Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
    printf("    2) Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n");
    printf("*********************************************************************************************\n\n");
    printf("Ingrese opcion a informar: ");
    scanf("%d", &opcion);
    return opcion;
}


int subMenuModificar(){
    int opcion;
    system("cls");
    printf("*********************************************************************************************\n");
    printf("*                                       MODIFICAR                                            *\n");
    printf("*********************************************************************************************\n");
    printf("    1) NOMBRE PERSONA.\n");
    printf("    2) APELLIDO PERSONA.\n");
    printf("    3) SALARIO PERSONA.\n");
    printf("    4) SECTOR.\n");
    printf("*********************************************************************************************\n\n");
    printf("Ingrese opcion a informar: ");
    scanf("%d", &opcion);
    return opcion;
}
