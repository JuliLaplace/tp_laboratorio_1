#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    setbuf(stdout, NULL);
    LinkedList* listaEmpleados = ll_newLinkedList();

    if(listaEmpleados==NULL)
     {
         printf("Error. No se pudo crear el linkedlist.\n");
     }

    do{
    	switch(menu())
    	        {
    	            case 1:

    	                    printf("Datos de empleados cargados desde el archivo data.csv con exito.\n ");

    	                system("pause");
    	                break;
    	            case 2:

    	                    printf("Datos de empleados cargados desde el archivo data.bin con exito.\n ");

    	                system("pause");
    	                break;
    	            case 3:

    	                    printf("Empleado cargado con exito.\n");

    	                system("pause");
    	                break;
    	            case 4:
    	                switch(submenu()){
    	                	case 1:

    	                        printf("Nombre de empleado modificado con exito.\n");

    	                        system("pause");
    	                        break;

    	                	case 2:

    	                        printf("Horas trabajadas por empleado modificadas con exito.\n");

    	                        system("pause");
    	                        break;

    	                	case 3:

    	                        printf("Sueldo de empleado modificado con exito.\n");

    	                        system("pause");
    	                        break;

    	                	default:
    	                		printf("Opcion incorrecta.\n");
    	                		system("pause");
    	                		break;
    	                	}
    	                system("pause");
    	                break;

    	            case 5:

    	                    printf("Empleado eliminado con exito.\n");

    	                system("pause");
    	                break;

    	            case 6:


    	                    printf("Empleados listados con exito.\n");

    	                system("pause");
    	                break;

    	            case 7:
    	                switch(subMenuOrden()){
    	                    case 1:
    	                    	printf("Ordenar empleados por nombre.\n");

    	                        system("pause");
    	                        break;

    	                    case 2:

    	                        printf("Ordenar empleados por horas.\n");
    	                            system("pause");
    	                        break;

    	                    case 3:
    	                    	printf("Ordenar empleados por sueldo.\n");
    	                        system("pause");
    	                        break;


    	                    default:
    	                        printf("Opcion incorrecta.\n");
    	                        system("pause");
    	                        break;
    	                    }
    	                system("pause");
    	                break;

    	            case 8:

    	                    printf("Empleado cargados con exito.\n");

    	                system("pause");
    	                break;

    	            case 9:

    	                    printf("Empleado cargados con exito.\n");

    	                system("pause");
    	                break;

    	            case 10:
    	            	  printf("Esta seguro de que desea salir? Si no es asi presione 0: \n");
    	            	  scanf("%d", &option);
    	            	  break;

    	            default:
    	                printf("La opcion ingresada es incorrecta. Ingrese una opcion valida.\n");
    		            system("pause");
    	                break;
    	        }
    }while(option != 10);
    return 0;
}

