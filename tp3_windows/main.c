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
    int id = 1001;
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
    	            	 if(controller_addEmployee(listaEmpleados, &id)){
    	            	                    printf("Empleado cargado con exito.\n");
    	            	                }
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
    	            	 if(flag && controller_removeEmployee(listaEmpleados)){
    	            	                    printf("Empleado eliminado con exito.\n");
    	            	                }
    	            	                system("pause");
    	            	                break;

    	            case 6:


    	            		if(flag && controller_ListEmployee(listaEmpleados)){
    	            			printf("Empleados listados con exito.\n");
    	            		}else{
    	            			printf("Primero debes cargar empleados en la lista.\n");
    	            		}

    	                system("pause");
    	                break;

    	            case 7:

    	            	//controller_sortEmployee(LinkedList* pArrayListEmployee);
    	            	//controller_ListEmployee(LinkedList* pArrayListEmployee);

    	                if(flag){
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
    	                }else{
    	                	printf("Primero debes cargar empleados en la lista.\n");
    	                }

    	                system("pause");
    	                break;

    	            case 8:



    	            		if(flag && controller_saveAsText("data.csv", listaEmpleados)){
    	            			 printf("Empleado cargados con exito.\n");
    	            		}else{
    	            			printf("Primero debes cargar empleados en la lista.\n");
    	            		}


    	                system("pause");
    	                break;

    	            case 9:


    	            		if(flag && controller_saveAsBinary("data.bin", listaEmpleados)){
    	            			 printf("Empleado cargados con exito.\n");
    	            		}else{
    	            			printf("Primero debes cargar empleados en la lista.\n");
    	            		}


    	                system("pause");
    	                break;

    	            case 10:
    	            	 option = 10;
    	            	  break;

    	            default:
    	                printf("La opcion ingresada es incorrecta. Ingrese una opcion valida.\n");
    		            system("pause");
    	                break;
    	        }
    }while(option != 10);
    return 0;
}

