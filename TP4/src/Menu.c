/*
 * Menu.c
 *
 *  Created on: 20 nov. 2021
 *      Author: Julieta
 */


#include <stdio.h>
#include <stdlib.h>
int menu(){

        int opcion;
        system("cls");

        printf("*****************************************************************************************\n");
        printf("\t\t\t   ********MENU DE OPCIONES********\n");
        printf("*****************************************************************************************\n");
        printf("1. Crear una nueva LinkedList de mascotas.\n");
        printf("2. Pedir memoria dinamica para mascotas y agregar sus datos.\n");
        printf("3. Agregar mascotas a Linkedlist.\n");
        printf("4. Mostrar cantidad de mascotas cargadas.\n");
        printf("5. Mostrar mascotas.\n");
        printf("6. Ordenar edades de mascotas de manera descendente.\n");
        printf("7. Buscar si se encuentra 'Effy' (mascota 2) en la lista.\n");
        printf("8. Copiamos la lista de mascotas a una nueva lista.\n");
        printf("9. Ver si se encuentran todas las mascotas en la lista copiada.\n");
        printf("10. Agregar (en indice 1 de lista) una nueva mascota.\n");
        printf("11. Modifico los datos de una mascota de la lista mascotas.\n");
        printf("12. Eliminar mascota que esta en indice 3 de lista mascotas.\n");
        printf("13. Eliminar elementos dentro de lista mascota copia.\n");
        printf("14. .\n");
        printf("15. Eliminar lista de mascotas y lista (copia) de mascotas.\n");
        printf("16. Salir. \n");
        printf("*****************************************************************************************\n");
        fflush(stdin);
        printf("Ingrese la opcion deseada: ");
        scanf("%d", &opcion);

        return opcion;

}
