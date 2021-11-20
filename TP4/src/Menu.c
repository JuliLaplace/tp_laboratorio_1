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
        printf("2. Agregar mascotas a Linkedlist.\n");
        printf("3. Mostrar cantidad de mascotas cargadas.\n");
        printf("4. Mostrar mascotas.\n");
        printf("5. Ordenar edades de mascotas de manera descendente.\n");
        printf("6. Buscar si se encuentra 'Effy' en la lista.\n");
        printf("7. Copiamos la lista de mascotas a una nueva lista.\n");
        printf("8. Ver si se encuentran todas las mascotas en la lista copiada.\n");
        printf("9. Agregar (en indice 1 de lista mascotas original) una nueva mascota.\n");
        printf("10. Modifico los datos de una mascota de la lista mascotas.\n");
        printf("11. Eliminar mascota en indice 1 de lista mascotas.\n");
        printf("12. Eliminar mascota de lista copiada y mostrar que mascota se elimino.\n");
        printf("13. Eliminar elementos dentro de lista mascota copia.\n");
        printf("14. Buscar el indice donde se encuentra la mascota 'Elvis'.\n");
        printf("15. Hacer una subLista de mascotas del indice 0 al indice 2 (no incluido).\n");
        printf("16. Eliminar lista de mascotas.\n");
        printf("17. Salir. \n");
        printf("*****************************************************************************************\n");
        fflush(stdin);
        printf("Ingrese la opcion deseada: ");
        scanf("%d", &opcion);

        return opcion;

}
