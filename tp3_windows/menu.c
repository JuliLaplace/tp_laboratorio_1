/*
 * menu.c
 *
 *  Created on: 9 nov. 2021
 *      Author: Julieta
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu(){

        int opcion;
        system("cls");

        printf("*****************************************************************************************\n");
        printf("\t\t\t   ********MENU DE OPCIONES********\n");
        printf("*****************************************************************************************\n");
        printf("1. CARGAR DATOS EMPLEADOS (MODO TEXTO).\n");
        printf("2. CARGAR DATOS EMPLEADOS (MODO BINARIO).\n");
        printf("3. ALTAS EMPLEADOS.\n");
        printf("4. MODIFICAR EMPLEADO.\n");
        printf("5. BAJAS EMPLEADOS.\n");
        printf("6. LISTAR EMPLEADOS.\n");
        printf("7. ORDENAR EMPLEADOS.\n");
        printf("8. GUARDAR DATOS EN ARCHIVO DATA.CSV(modo texto).\n");
        printf("9. GUARDAR DATOS EN ARCHIVO DATA.BIN(modo binario).\n");
        printf("10. Salir. \n");
        printf("*****************************************************************************************\n");
        fflush(stdin);
        printf("Ingrese la opcion deseada: ");
        scanf("%d", &opcion);

        return opcion;

}

int submenu(){
    int opcion;
        system("cls");

        printf("*****************************************************************************************\n");
        printf("\t\t\t   ********MODIFICAR EMPLEADO********\n");
        printf("*****************************************************************************************\n");
        printf("1. Modificar nombre. \n");
        printf("2. Modificar horas trabajadas. \n");
        printf("3. Modificar sueldo. \n");
        printf("*****************************************************************************************\n");
        fflush(stdin);
        printf("Ingrese la opcion deseada: ");
        scanf("%d", &opcion);

        return opcion;

}

int subMenuOrden(){
    int opcion;
        system("cls");

        printf("*****************************************************************************************\n");
        printf("\t\t\t   ********ORDENAR EMPLEADO********\n");
        printf("*****************************************************************************************\n");
        printf("1. Ordenar nombres de empleados.\n");
        printf("2. Ordenar empleados por horas trabajadas. \n");
        printf("3. Ordenar empleados por sueldo. \n");
        printf("*****************************************************************************************\n");
        fflush(stdin);
        printf("Ingrese la opcion deseada: ");
        scanf("%d", &opcion);

        return opcion;

}
