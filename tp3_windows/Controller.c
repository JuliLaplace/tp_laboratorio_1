#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#include "menu.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	   int todoOk = 0;

	    if(path!=NULL && pArrayListEmployee!=NULL){

	        FILE* file = fopen(path, "r"); //lee archivo texto

	        if(file==NULL){
	            printf("No se pudo abrir el archivo\n");
	            exit(1);
	        }else{
	          todoOk = parser_EmployeeFromText(file, pArrayListEmployee);

	        }
	        fclose(file);        //cierra archivo
	    }

	    return todoOk;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
	int todoOk = 0;

	    if(path!=NULL && pArrayListEmployee!=NULL){

	        FILE* file = fopen(path, "rb"); //lee archivo binario

	        if(file==NULL){
	            printf("No se pudo abrir el archivo ya que no existe. Primero debe crear un archivo guardandolo como .bin (opcion 9).\n");
	            system("pause");
	        }else{
	          todoOk = parser_EmployeeFromBinary(file, pArrayListEmployee);


	        }
	        fclose(file);        //cierra archivo
	    }

	    return todoOk;
}


int controller_addEmployee(LinkedList* pArrayListEmployee, int* pId)
{
	int todoOk=0;
	    Employee* auxEmpleado=NULL;

		int auxId;
		char auxNombre[128];
		char auxHoras[128];
		char auxSueldo[128];


		if(pArrayListEmployee != NULL){
			auxEmpleado = employee_new();

			auxId = (*pId);
	        fflush(stdin);

			while(!getStringLetras("Ingrese nombre de empleado: ", auxNombre)){

	             printf("Nombre invalido. \n");
			}

			while(!getStringNumeros("Ingrese horas trabajadas por empleado: ", auxHoras)){

	             printf("Valor de horas trabajadas invalido. \n");
			}
			while(!getStringNumerosFlotantes("Ingrese sueldo de empleado: ", auxSueldo)){

	            printf("Sueldo invalido. \n");
			}

			if(auxEmpleado != NULL && employee_setId(auxEmpleado,auxId) && employee_setNombre(auxEmpleado,auxNombre) && employee_setSueldo(auxEmpleado,atof(auxSueldo)) && employee_setHorasTrabajadas(auxEmpleado,atoi(auxHoras))){
				if(!ll_add(pArrayListEmployee,auxEmpleado)){


					todoOk = 1;
					(*pId)++;

				}else{

					printf("Error. No se pudo agregar el empleado");
					employee_delete(auxEmpleado);

				}
			}
		}

		return todoOk;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	 	Employee* aux=NULL;
	    int todoOk;
	    int id;
	    char respuesta;
	    char respuesta2;
	    char newNombre[128];
	    int newHorasTrabajadas;
	    int newSueldo;
	    	if(pArrayListEmployee!=NULL){
				controller_ListEmployee(pArrayListEmployee);
				printf("Ingrese ID del empleado que desea modificar: ");
				scanf("%d", &id);

				for(int i=0; i<ll_len(pArrayListEmployee); i++)
				{
					aux = (Employee*) ll_get(pArrayListEmployee,i);

					if (aux->id==id)
					{
						showEmployee(aux);
						printf("Desea modificar este empleado? s/n: ");
						fflush(stdin);
						scanf("%c", &respuesta);
					}

				}
				if(respuesta=='s' || respuesta == 'S')
				{

					switch(submenu())
					{

					case 1:
						fflush(stdin);
						while(!getStringLetras("Ingrese nuevo nombre de empleado: ", newNombre)){

										 printf("Nombre invalido. \n");
									}
						printf("Desea guardar cambios? s/n: ");
						fflush(stdin);
						scanf("%c", &respuesta2);
						if(respuesta2=='s' || respuesta2=='S')
						{
							strcpy(aux->nombre,newNombre);
							printf("Modificacion exitosa\n");
							todoOk=1;
						}
						else
						{
							printf("Modificacion cancelada por el usuario");
							todoOk=0;
						}

						break;
					case 2:
						if(utn_getNumero(&newHorasTrabajadas,"Ingrese nuevas Horas trabajadas por el empleado: ", "Horas invalidas. Debe ser un numero mayor a 0. ",0,5000,5)==0){
							printf("Desea guardar cambios? s/n: ");
							fflush(stdin);
							scanf("%c", &respuesta2);
							if(respuesta2=='s')
							{
								aux->horasTrabajadas=newHorasTrabajadas;
								printf("Modificacion exitosa\n");
								todoOk=1;
							}
							else
							{
								printf("Modificacion cancelada por el usuario");
								todoOk=0;
							}
						} else {
							printf("Error en la modificacion.\n");
							todoOk=0;
						}

						break;
					case 3:
						if(utn_getNumero(&newSueldo,"Ingrese nuevo sueldo del empleado: ", "Sueldo invalidos. Debe ser un numero mayor a 0. ",0.00,500000.00,5)==0){
								printf("Desea guardar cambios? s/n: ");
								fflush(stdin);
								scanf("%c", &respuesta2);
								if(respuesta2=='s')
								{
									aux->sueldo=newSueldo;
									printf("Modificacion exitosa\n");
									todoOk=1;
								}
								else
								{
									printf("Modificacion cancelada por el usuario");
									todoOk=0;
								}
						} else {
							printf("Error en la carga.\n");
							todoOk=0;
						}

						break;
					default:
						printf("Opcion invalida");
						break;

					}
					system("pause");

				}else if(respuesta=='n' || respuesta =='N'){
					printf("modificacion cancelada.\n");
					todoOk=0;
				}else{
					printf("Opcion invalida.\n");
					todoOk=0;
				}
}
	    return todoOk;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
		int todoOk;
		Employee* auxEmpleado=NULL;
	    int id;
	    char respuesta;
	    if(pArrayListEmployee!=NULL){


				controller_ListEmployee(pArrayListEmployee);
				printf("Ingrese ID del empleado que desea dar de baja: ");
				scanf("%d", &id);

				for(int i=0; i<ll_len(pArrayListEmployee); i++)
				{
					auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);
					if (auxEmpleado->id==id && id>0)
					{

						printf("Confirma baja? s/n: ");
						fflush(stdin);
						scanf("%c", &respuesta);
						if(respuesta== 's' || respuesta == 'S')
						{
							ll_remove(pArrayListEmployee,i);
							employee_delete(auxEmpleado);
							printf("Baja de empleado exitosa\n");
							todoOk=1;
						}
						else
						{

							todoOk=0;
						}

					}

				}

	    }
	    return todoOk;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	    Employee* auxEmpleado= NULL;

	    if(pArrayListEmployee!=NULL){

	        printf(" ID      Nombre    Horas Trabajadas      Sueldo\n");
	        printf("--------------------------------------------------------\n");

	        for(int i =0; i<ll_len(pArrayListEmployee); i++){

	            auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);
	            showEmployee(auxEmpleado);

	        }
	        printf("\n\n");
	        todoOk=1;
	    }
	    return todoOk;
}
int showEmployee(Employee* empleado){
    int todoOk=0;
    int id;
    char nombre[120];
    int horasTrab;
    float sueldo;

    if(empleado!=NULL && employee_getId(empleado, &id) && employee_getNombre(empleado, nombre) && employee_getHorasTrabajadas(empleado, &horasTrab) && employee_getSueldo(empleado, &sueldo)){

            printf("%d      ", id);
            printf("%10s       ", nombre);
            printf("%d    ", horasTrab);
            printf("%.2f\n", sueldo);
            printf("\n");
        todoOk=1;
    }


return todoOk;
}




int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
		int todoOk;
		int cant;
	    Employee* auxEmpleado=NULL;

	    	if(path!=NULL && pArrayListEmployee!=NULL){
	    		FILE* file= fopen(path, "w");
				if(file==NULL)
				{
					printf("Error en abrir el archivo.\n");
					todoOk=0;
				}
				fprintf(file,"ID,Nombre,HorasTrabajadas,Sueldo.\n");
				for(int i=0; i<ll_len(pArrayListEmployee); i++)
				{
					auxEmpleado=ll_get(pArrayListEmployee,i);
					if(auxEmpleado!=NULL)
					{
						cant=fprintf(file,"%d,%s,%d,%d\n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);

						if(cant<1){
							todoOk=0;
						}else{
							todoOk=1;
						}
					}
				}
				fclose(file);
	    	}




	    return todoOk;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk;
	int cant;

	if(path!=NULL && pArrayListEmployee!=NULL){
		 FILE* file= fopen(path, "wb");
			    if(file!=NULL)
			    {
			    	for(int i=0; i<ll_len(pArrayListEmployee); i++)
			    		    {
			    		        cant=fwrite(ll_get(pArrayListEmployee,i), sizeof(Employee),1,file);
			    		        if(cant<1)
			    		        {
			    		            todoOk=0;
			    		        }else{
			    		        	todoOk=1;
			    		        }

			    		    }

			    		    fclose(file);
			    }
	}






	    return todoOk;

}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	if(pArrayListEmployee!=NULL){


				ll_sort(pArrayListEmployee,employeeCmpNombre,1);
				controller_ListEmployee(pArrayListEmployee);
				todoOk=1;

	}



	    return todoOk;
}

