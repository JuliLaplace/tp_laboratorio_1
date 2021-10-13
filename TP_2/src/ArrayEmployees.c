/*
 * ArrayEmployees.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Julieta
 */


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include"utn.h"


int initEmployees(eEmployee* list, int len){
    int inicializar=-1;
    if(list!=NULL && len>0){
        for(int i = 0; i<len; i++){
            list[i].isEmpty = 1;
        }

        inicializar=0;
    }

    return inicializar;
}

int buscarLibre(eEmployee* list, int len){
    int lugarLibre=-1;

    if(list!=NULL && len>0){

       for (int i=0; i<len; i++){
            if(list[i].isEmpty){
                lugarLibre=i;
                break;
            }
        }
    }

    return lugarLibre;
}

int pedirEmployee(char nombre[], char apellido[], float* sueldo, int* sector){
    int cargaEmpleadosOk;
    int sectorOk;
    int sueldoOk;
    int nombreOk;
    int apellidoOk;




        if(nombre != NULL && apellido!=NULL && sueldo!= NULL && sector != NULL){
                system("cls");
                printf("*****************************************************************************************\n");
                printf("                   **********ALTA EMPLEADO*********\n");
                printf("*****************************************************************************************\n");



                fflush(stdin);
                nombreOk = getStringLetras("Ingrese su nombre: ", nombre);
                if(nombreOk == 1){
                    printf("Carga de nombre exitosa.\n");
                }else{
                    printf("Error en la carga.\n");
                }


                fflush(stdin);
                apellidoOk = getStringLetras("Ingrese su apellido: ", apellido);
                if(apellidoOk == 1){
                    printf("Carga de apellido exitosa.\n");
                }else{
                    printf("Error en la carga.\n");
                }


                //validar sueldo
                sueldoOk = utn_getNumeroFlotante(sueldo, "Ingrese sueldo de $0 a $500000: ", "Sueldo invalido. Reingrese valor: ", 0.0, 500000.0, 3);
                if(sueldoOk==0){
                    printf("Sueldo correctamente cargado.\n");
                } else {
                    printf("Error en la carga.\n");
                }

                //validar sector
                sectorOk = utn_getNumero(sector, "500)RRHH \n501)Ventas \n502)Administracion \n503)Sistemas \n504)Legales \nIngrese sector al que pertenece: ", "Sector invalido.\n", 500, 504, 3);
                if(sectorOk==0){
                    printf("Sector correctamente cargado.\n");
                } else {
                    printf("Error en la carga.\n");
                }

                //validar la carga total
                if(sectorOk == 0 && sueldoOk ==0 && nombreOk == 1 && apellidoOk==1 ){
                    cargaEmpleadosOk=0;
                }else {
                    cargaEmpleadosOk =-1;
                }


    }
    return cargaEmpleadosOk;
}

int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector){
    int todoOk=-1;
    int indiceLibre;
    indiceLibre = buscarLibre(list, len);

    if(indiceLibre!=-1 && list!= NULL && len>0){
        list[indiceLibre].id = id;
        list[indiceLibre].isEmpty = 0;
        strcpy(list[indiceLibre].name,name);
        strcpy(list[indiceLibre].lastName,lastName);
        list[indiceLibre].salary = salary;
        list[indiceLibre].sector = sector;
        todoOk=0;
    }else{
        printf("No hay lugar disponible.\n");
    }

    return todoOk;
}


int findEmployeeById(eEmployee* list, int len,int id){

 int indiceEmpleado=-1;

    if(list!=NULL && len>0){
        for (int i=0; i<len; i++){
            if(list[i].id == id && list[i].isEmpty ==0){
                indiceEmpleado=i;
                break;
            }
        }
    }

    return indiceEmpleado;
}


int removeEmployee(eEmployee* list, int len, int id){
     int removeOk=-1;

    int idEmpleado;
    int indiceEmpleado;
    char confirmacion;

    system("cls");
    printf("*****************************************************************************************\n");
    printf("\t\t\t\tBaja de empleado        \n");
    printf("*****************************************************************************************\n");
    printEmployees(list, len);
    printf("\n");


    printf("Ingrese el ID del empleado que desea dar de baja:");
    scanf("%d", &idEmpleado);

    indiceEmpleado = findEmployeeById(list, len, idEmpleado);

    if(indiceEmpleado != -1 && list!= NULL && len>0){

        printf("El ID pertenece al siguiente empleado: \n");
        showEmployee(list[indiceEmpleado]);
        printf("\nDesea dar de baja? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmacion);

            if(confirmacion == 's'){

                list[indiceEmpleado].isEmpty = 1;
                removeOk=0;
            }else{
                printf("Baja cancelada.");
            }



    }else{

        printf("No existe el ID: %d ingresado.\n", idEmpleado);
    }
     return removeOk;
}



int sortEmployees(eEmployee* list, int len, int order){
    int sortOk;
    eEmployee auxEmpleado;
    if(list!= NULL && len>0){
        if(order==1){

            for(int i =0; i<len-1; i++){
                for (int j=i+1; j<len; j++){

                    if(list[i].sector > list[j].sector || (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName)>0)){

                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j]= auxEmpleado;
                    }
                }
            }
        }else if(order == 2){

            for(int i =0; i<len-1; i++){
                for (int j=i+1; j<len; j++){

                    if(list[i].sector < list[j].sector || (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName)<0)){

                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j]= auxEmpleado;
                    }
                }
            }



        }
        sortOk=0;

    }else{
        sortOk=-1;
    }



    return sortOk;
}

int promEmployees(eEmployee* list, int len){

    int promOk=-1;
    int contador = 0;
    float sumaPromedio = 0;
    float total;
    int ciclo = 0;


    if(list!=NULL && len>0){

        for(int i=0;i<len;i++){

            if(list[i].isEmpty==0){
                ciclo++;
                sumaPromedio += list[i].salary;
                }

        }
        total = (float)sumaPromedio/ciclo;

        for(int j=0;j<len;j++){
            if(list[j].isEmpty==0 && list[j].salary > total ){
                contador += 1;
            }
        }

        if(ciclo!=0){
            printf("La suma total de los salarios es de: $ %.2f.\n",sumaPromedio);
            printf("El promedio total de los salarios es de: $ %.2f.\n",total);
            printf("Los empleados que superan el promedio son %d.\n",contador);
        } else {
            printf("No hay promedios que mostrar.\n");
        }





        promOk=0;
    }
    return promOk;
}



void showEmployee(eEmployee list){
    printf("%d\t  %10s   \t%10s \t  %9.2f \t        %d\n", list.id, list.name, list.lastName, list.salary, list.sector);

}

int printEmployees(eEmployee* list, int length){
    int flag=1;   //bandera para saber si se cargo un empleado(0) o no (1)
    int printOk;

    printf("*****************************************************************************************\n");
    printf("\t\t\t\t***Empleados***\n");
    printf("*****************************************************************************************\n");
    printf("ID\t      Nombre \t    Apellido \t  Sueldo \t     Sector \n");
    printf("-----------------------------------------------------------------------------------------\n");
    //RECORRER NOMINA CON FOR PARA MOSTRARLO
    for(int i=0; i<length; i++)
    {

        if(!(list[i].isEmpty))  ////verifico si esta cargado(0) o no (1) un empleado con variable isEmpty
        {
            showEmployee(list[i]);

            flag=0;//cambia bandera por que entro en el if para mostrar un empleado
            printOk=0;
        }
    }
    if (flag){
        printf("                          No hay empleados que mostrar\n");
        printOk=-1;
    }
    printf("-----------------------------------------------------------------------------------------\n");
    printf("\n");

    return printOk;
}
