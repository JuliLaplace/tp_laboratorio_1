/*
 * Menu.c
 *
 *  Created on: 14 oct. 2021
 *      Author: Julieta
 */


int menu(){


    int opcionOk;
    int opcion;

    system("cls");
    printf("*********************************************************************************************\n");
    printf("*                                   NOMINA EMPLEADOS                                        *\n");
    printf("*********************************************************************************************\n");


    printf("    1) ALTA PERSONA.\n");
    printf("    2) MODIFICAR PERSONA.\n");
    printf("    3) BAJA PERSONA.\n");
    printf("    4) INFORMAR:\n");
    printf("        a) Listar empleados ordenados alfabéticamente por Apellido y Sector\n");
    printf("        b) Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
    printf("    5) SALIR.\n");
    printf("*********************************************************************************************\n");

    opcionOk = utn_getNumero(&opcion, "Ingrese opcion a elegir: ", "Opcion invalida.\n", 1, 5, 3);

    if(opcionOk){
    	printf("Error");
    }
    return opcion;


}

int subMenuInformar(){
    int opcion;
    system("cls");
    printf("*********************************************************************************************\n");
    printf("*                                       INFORMAR                                            *\n");
    printf("*********************************************************************************************\n");
    printf("    1) Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
    printf("    2) Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n");
    printf("*********************************************************************************************\n\n");
    printf("Ingrese opcion a informar: ");
    scanf("%d", &opcion);
    return opcion;
}

int subMenuListarEmpleados(){
	int order;
						printf("*********************************************************************************************\n");
						printf("*                                       ORDEN                                            *\n");
                    	printf("*********************************************************************************************\n");;
                        printf("1. Ordenar de manera ascendente.\n");
                        printf("2. Ordenar de manera descendente.\n");
                        printf("*****************************************************************************************\n");
                        printf("Ingrese como desea ordenar los empleados: ");
                        scanf("%d", &order);
                    return order;

}


int subMenuModificar(){
    int opcion;
    system("cls");
    printf("*********************************************************************************************\n");
    printf("*                                       MODIFICAR                                            *\n");
    printf("*********************************************************************************************\n");
    printf("    1) NOMBRE PERSONA.\n");
    printf("    2) APELLIDO PERSONA.\n");
    printf("    3) SALARIO PERSONA.\n");
    printf("    4) SECTOR.\n");
    printf("*********************************************************************************************\n\n");
    printf("Ingrese opcion a informar: ");
    scanf("%d", &opcion);
    return opcion;
}
