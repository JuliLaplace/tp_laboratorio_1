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
    char seguir = 's';
    setbuf(stdout, NULL);
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flag=0;

    if(listaEmpleados==NULL)
     {
         printf("Error. No se pudo crear el linkedlist.\n");
     }

    do{
    	switch(menu())
    	        {
    	            case 1:
    	            	if(controller_loadFromText("data.csv",listaEmpleados)){
    	            	                    printf("Datos de empleados cargados desde el archivo data.csv con exito.\n ");
    	            	                    flag=1;
    	            	                }else{
    	            	                    printf("Error en carga de datos desde archivo data.csv\n ");
    	            	                }
    	            	                system("pause");
    	            	                break;
    	            case 2:

    	            	if(controller_loadFromBinary("data.bin",listaEmpleados)){
    	            	                    printf("Datos de empleados cargados desde el archivo data.bin con exito.\n ");
    	            	                    flag=1;
    	            	                }else{
    	            	                    printf("Error en carga de datos desde archivo data.bin\n ");
    	            	                }
    	            	                system("pause");
    	            	                break;
    	            case 3:
    	            	 if(flag && controller_addEmployee(listaEmpleados)){
    	            	                    printf("Empleado cargado con exito.\n");
    	            	                }else{
    	            	                	printf("Primero debes cargar datos de empleados en la lista.\n");
    	            	                }
    	            	                system("pause");
    	            	                break;
    	            case 4:
    	            	if(flag){
    	            		controller_editEmployee(listaEmpleados);
    	            	}else{
    	            		printf("Primero debes cargar datos de empleados en la lista.\n");
    	            	}

    	                system("pause");
    	                break;

    	            case 5:
    	            	 if(flag){
    	            		 if(controller_removeEmployee(listaEmpleados)){

    	            			 printf("Empleado eliminado con exito.\n");
    	            	     }else{
    	            	          printf("Baja cancelada\n");
    	            	     }
    	            	 }else{
    	            		 printf("Primero debes cargar datos de empleados en la lista.\n");
    	            	 	 }
    	            	  system("pause");
    	            	  break;

    	            case 6:


    	            		if(flag && controller_ListEmployee(listaEmpleados)){
    	            			printf("Empleados listados con exito.\n");
    	            		}else{
    	            			printf("Primero debes cargar datos de empleados en la lista.\n");
    	            		}

    	                system("pause");
    	                break;

    	            case 7:
    	                if(flag){
    	                	if(controller_sortEmployee(listaEmpleados)){

    	                		printf("Empleados ordenados.\n");
    	                	}

    	                }else{
    	                	printf("Primero debes cargar datos de empleados en la lista.\n");
    	                }

    	                system("pause");
    	                break;

    	            case 8:

    	            		if(flag && controller_saveAsText("data.csv", listaEmpleados)){
    	            			 printf("Datos cargados con exito.\n");
    	            		}else{
    	            			printf("Primero debes cargar datos de empleados en la lista (opcion 1), luego cargarlos como data.cvs (opcion8).\n");
    	            		}


    	                system("pause");
    	                break;

    	            case 9:


    	            		if(flag && controller_saveAsBinary("data.bin", listaEmpleados)){
    	            			 printf("Datos cargados con exito.\n");

    	            		}else{
    	            			printf("Primero debes cargar datos de empleados en la lista (opcion 2), luego cargarlos como data.bin (opcion 9).\n");
    	            		}


    	                system("pause");
    	                break;

    	            case 10:
    	            	 seguir = 'n';
    	            	  break;

    	            default:
    	                printf("La opcion ingresada es incorrecta. Ingrese una opcion valida.\n");
    		            system("pause");
    	                break;
    	        }
    }while(seguir != 'n');
    return 0;
}

