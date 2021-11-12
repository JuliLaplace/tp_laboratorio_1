#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	    char buffer[4][120];
	    int cant;
		Employee* auxEmpleado=NULL;

		if(pFile!=NULL && pArrayListEmployee!=NULL){

			fscanf(pFile,"[^\n]\n"); //lectura fantasma primera linea

			 while(!feof(pFile))
			    {
			        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			        if(cant==4)
			        {
			            auxEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

			            if(auxEmpleado!=NULL)
			            {
			                ll_add(pArrayListEmployee,auxEmpleado);
			            }

			        }

			    }
		}
		fclose(pFile);
		return 1;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmpleado;
	    int cant;
	    while(!feof(pFile))
	    {
	        auxEmpleado=employee_new();

	        if(auxEmpleado!=NULL)
	        {
	            cant=fread(auxEmpleado, sizeof(Employee), 1,pFile);
	            if(cant<1)
	            {
	                break;
	            }
	            ll_add(pArrayListEmployee,auxEmpleado);
	        }


	    }
	    fclose(pFile);
	    return 1;

}
