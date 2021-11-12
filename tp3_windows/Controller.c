#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	   int todoOk = 0;

	    if(path!=NULL && pArrayListEmployee!=NULL){

	        FILE* file = fopen(path, "r"); //lee archivo texto

	        if(file==NULL){
	            printf("No se pudo abrir el archivo\n");
	            exit(1);
	        }else{
	          todoOk = parser_EmployeeFromText(file, pArrayListEmployee);
	          fclose(file);        //cierra archivo
	        }
	    }

	    return todoOk;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;

	    if(path!=NULL && pArrayListEmployee!=NULL){

	        FILE* file = fopen(path, "rb"); //lee archivo binario

	        if(file==NULL){
	            printf("No se pudo abrir el archivo\n");
	            exit(1);
	        }else{
	          todoOk = parser_EmployeeFromBinary(file, pArrayListEmployee);

	          fclose(file);        //cierra archivo
	        }
	    }

	    return todoOk;
}


int controller_addEmployee(LinkedList* pArrayListEmployee, int* pId)
{
	int todoOk=0;
	    Employee* auxEmpleado=NULL;

		int auxId;
		int lenLista;
		char auxNombre[128];
		char auxHoras[128];
		char auxSueldo[128];


		if(pArrayListEmployee != NULL){
			auxEmpleado = employee_new();

			lenLista = ll_len(pArrayListEmployee);
			auxId = lenLista++;
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

					printf("Empleado cargado");
					todoOk = 1;
					*pId= auxId++;

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
    return 1;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	    Employee* auxEmpleado= NULL;

	    if(pArrayListEmployee!=NULL){

	        printf(" Legajo      Nombre    Horas Trabajadas      Sueldo\n");
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


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	    Employee* aux;

	    FILE* f= fopen(path, "w");
	    if(f==NULL)
	    {
	    	printf("Error en abrir el archivo.\n");
	    }
	    fprintf(f,"Id,nombre,horasTrabajadas,sueldo\n");
	    for(int i=0; i<ll_len(pArrayListEmployee); i++)
	    {
	        aux=ll_get(pArrayListEmployee,i);
	        if(aux!=NULL)
	        {
	            fprintf(f,"%d,%s,%d,%d\n",
	                    aux->id,
	                    aux->nombre,
	                    aux->horasTrabajadas,
	                    aux->sueldo);
	            todoOk=1;
	        }
	    }
	    fclose(f);



	    return todoOk;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	    int cant;


	    FILE* f= fopen(path, "wb");
	    if(f==NULL)
	    {
	        printf("Error en abrir el archivo.\n");
	    }

	    for(int i=0; i<ll_len(pArrayListEmployee); i++)
	    {
	        cant=fwrite(ll_get(pArrayListEmployee,i), sizeof(Employee),1,f);
	        if(cant<1)
	        {
	            todoOk=1;
	        }

	    }
	    fclose(f);



	    return todoOk;

}

