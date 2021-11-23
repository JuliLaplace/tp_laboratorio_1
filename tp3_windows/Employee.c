#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "utn.h"

Employee* employee_new(){
	Employee* nuevoEmpleado;
	    nuevoEmpleado = (Employee*) malloc(sizeof(Employee));
	    if(nuevoEmpleado!=NULL){
	        nuevoEmpleado->id = 0;
	        strcpy(nuevoEmpleado->nombre, "NN");
	        nuevoEmpleado->horasTrabajadas=' ';
	        nuevoEmpleado->sueldo = 0;
	    }

	    return nuevoEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
	Employee* nuevoEmpleado = employee_new(); //aca pido malloc de Employee*

	if(nuevoEmpleado!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL){
	        if(!(employee_setId(nuevoEmpleado, atoi(idStr)) && employee_setNombre(nuevoEmpleado, nombreStr) && employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr)) && employee_setSueldo(nuevoEmpleado, atoi(sueldoStr)))){
	            employee_delete(nuevoEmpleado);
	            nuevoEmpleado=NULL;
	        }
	    }

	    return nuevoEmpleado;
}
void employee_delete(Employee* this){
	free(this);
}

int employee_setId(Employee* this,int id){
	int todoOk=0;
	    if(this!=NULL && id>0){
	        this->id=id;
	        todoOk=1;
	    }


	return todoOk;
}
int employee_getId(Employee* this,int* id){
	 int todoOk=0;
	    if(this!=NULL && id!=NULL){
	        *id= this->id;
	        todoOk=1;
	    }


	    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre){
	int todoOk=0;
	    if(this!=NULL && nombre!=NULL){
	       if(strlen(nombre)<128 && strlen(nombre)>2){
	            strcpy(this->nombre, nombre);
	            strlwr(this->nombre);
	            this->nombre[0]=toupper(this->nombre[0]);

	            todoOk=1;
	       }

	    }

	return todoOk;
}
int employee_getNombre(Employee* this,char* nombre){

    int todoOk=0;
    if(this!=NULL && nombre!=NULL){
        strcpy(nombre, this->nombre);
        todoOk=1;
    }


    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int todoOk=0;
		    if(this!=NULL && horasTrabajadas>=1){
		        this->horasTrabajadas = horasTrabajadas;
		        todoOk=1;
		    }
		    else{
		        printf("Cantidad de horas trabajadas invalido. \n");
		    }

		return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int todoOk=0;
		    if(this!=NULL && horasTrabajadas!=NULL){
		        *horasTrabajadas = this->horasTrabajadas;
		        todoOk=1;
		    }


		    return todoOk;
}

int employee_setSueldo(Employee* this,float sueldo){
	int todoOk=0;
	    if(this!=NULL && sueldo>0){
	        this->sueldo = sueldo;
	        todoOk=1;
	    }
	    else{
	        printf("Sueldo Invalido \n");
	    }

	return todoOk;
}
int employee_getSueldo(Employee* this,float* sueldo){
	int todoOk=0;
	    if(this!=NULL && sueldo!=NULL){
	        *sueldo = this->sueldo;
	        todoOk=1;
	    }


	    return todoOk;
}



int employeeCmpNombre(void* a, void* b){

	int todoOk = 0;
	char auxNombre1[20];
	char auxNombre2[20];
	if(a!=NULL && b!=NULL){
		employee_getNombre(a, auxNombre1);
		employee_getNombre(b, auxNombre2);

		if(strcmp(auxNombre1,auxNombre2)>0){
			todoOk=1;
		}
	}


	    return todoOk;

}

int employee_nextId(LinkedList* pArrayList, int* id)
{
    int todoOk = 0;
    int mayor=0;
    Employee* aux = NULL;

    if(pArrayList != NULL)
    {
        for(int i = 0; i<ll_len(pArrayList); i++)
        {
            aux = (Employee*) ll_get(pArrayList, i);
            if(i==0 || aux->id > mayor)	//i se usa como bandera
            {
                mayor = aux->id;
            }
        }
        *id = mayor+1;
        todoOk = 1;
    }
    return todoOk;
}
