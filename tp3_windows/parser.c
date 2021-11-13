#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	  int carga = 0;
	    char buffer[4][120];
		Employee* auxEmpleado=NULL;

		if(pFile!=NULL && pArrayListEmployee!=NULL){

			fscanf(pFile,"[^\n]\n");

			while(!feof(pFile)){

				fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

				auxEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

				if(auxEmpleado != NULL)
				{
					if(!ll_add(pArrayListEmployee,auxEmpleado))
					{
						carga++;
					}
				}
			}
			fclose(pFile);
		}
		return carga;
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
