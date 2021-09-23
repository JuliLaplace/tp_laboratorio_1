/*
 * Biblioteca.c
 *
 *  Created on: 21 sep. 2021
 *      Author: Julieta
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Biblioteca.h"

char menu(int flagA, int flagB, int num1, int num2, int flagCalculo, int suma, int resta, int multiplicacion, int division, float resulDivision, int factorialPrimerNumOk, int resulPrimerFactorial, int factorialSegundoNumOk, int resulSegundoFactorial, int flagResult){

    char opcion;

    system("cls");
    printf("*********************************\n");
    printf("***********CALCULADORA***********\n");
    printf("*********************************\n\n");
    	//Primer valor a ingresar
		if(flagA){
				printf("*********************************\n");
				printf("1. Ingresar 1er operando: A=%d. \n", num1); //Esta ingresado, se muestra por pantalla
				printf("*********************************\n");
		}else{
				printf("*********************************\n");
				printf("1. Ingresar 1er operando: A=X. \n"); //No esta ingresado, se muestra X en pantalla
				printf("*********************************\n");
		}

		//Segundo valor a ingresar
		 if(flagB){
				printf("2. Ingrese 2do operando: B=%d. \n", num2); //Esta ingresado el numero, se muestra por pantalla
				printf("*********************************\n");
		 } else {
				printf("2. Ingrese 2do operando: B=X. \n");//No esta ingresado, se muestra X en pantalla
				printf("*********************************\n");
		 }

        //Realiza los calculos
        if(flagA && flagB){
        	printf("3. Calcular todas las operaciones:\n");
        	printf("a) Calcular la suma %d+%d.\n", num1, num2);
        	printf("b) Calcular la resta %d-%d.\n", num1,num2);
            printf("c) Calcular la multiplicacion %d*%d.\n", num1, num2);
            printf("d) Calcular la division %d/%d.\n", num1, num2);
            printf("e) Calcular  %d! y  %d!.\n", num1, num2);
            printf("*********************************\n");
        }else{
        	 printf("3. Calcular todas las operaciones:\n");
        	 printf("a) Calcular la suma (A+B).\n");
        	 printf("b) Calcular la resta (A-B).\n");
        	 printf("c) Calcular la multiplicacion (A*B).\n");
        	 printf("d) Calcular la division (A/B).\n");
        	 printf("e) Calcular factorial (A!) (B!).\n");
        	 printf("*********************************\n");
        }


        printf("4. Informar resultados:\n");

            if(flagResult){
                printf("a) El resultado de %d+%d es %d.\n", num1, num2, suma);
                printf("b) El resultado de %d-%d es %d.\n", num1, num2, resta);
                printf("c) El resultado de %d*%d es %d.\n", num1, num2, multiplicacion);

                //Condicional de division para mostrar o no su resultado.
                if(division){
                 printf("d. El resultado de %d/%d es: %.2f\n",num1, num2, resulDivision);
                 printf("*********************************\n");
                }else {
                   printf ("d. No se puede realizar la division por 0.\n");
                   printf("*********************************\n");
                   }

                //Condicional de Factorizar primer operando
                if(factorialPrimerNumOk){
                	printf("e) El factorial de %d es %d. ", num1, resulPrimerFactorial);
                } else {
                	printf ("d. No se puede realizar el factorial del primer numero ingresado. ");
                }

                //Condicional de factorizar segundo operando
                if(factorialSegundoNumOk){
                	printf("El factorial de %d es %d.\n", num2, resulSegundoFactorial);
                } else {
                	printf (" No se puede realizar el factorial del segundo numero ingresado.\n");
                }

            }else if(flagA && flagB){
                printf("a) Resultado de %d+%d.\n", num1, num2);
                printf("b) Resultado de %d-%d.\n", num1, num2);
                printf("c) Resultado de %d*%d.\n", num1, num2);
                printf("d) Resultado de %d/%d.\n", num1, num2);
                printf("e) Factorial de %d y el factorial de %d.\n", num1, num2);
                printf("*********************************\n");
            } else {
            	printf("a) Resultado de A+B.\n");
            	printf("b) Resultado de A-B.\n");
            	printf("c) Resultado de A*B.\n");
            	printf("d) Resultado de A/B.\n");
            	printf("e) Factorial de A y el factorial de B.\n");
            	printf("*********************************\n");
            }

            printf("5. Salir\n");
            printf("*********************************\n\n");
            printf("Ingrese opcion deseada: ");
            fflush(stdin);
            opcion = getchar();

        return opcion;
}


int suma(int num1, int num2){
	return num1+num2;
}
int resta(int num1, int num2){
	return num1-num2;
}
int multiplicacion(int num1, int num2){
	return num1*num2;
}
int division(int num1, int num2, float* pResulDivision){
		int sePuedeDividir = 0;
	    if (num2!= 0 && pResulDivision != NULL){
	        (*pResulDivision) = (float)num1/num2;
	        sePuedeDividir=1;
	    }
	    return sePuedeDividir;
}

int factorial(int num, int* factorialA)
{
	int sePuedeFactorizar=0;
	if(num>0 && factorialA != NULL){
		int factorial = 1;
		for ( int i = 1; i <= num; i++) {
			factorial*= i;
			(*factorialA) = factorial;
		 	}
		sePuedeFactorizar = 1;
	}

	return (sePuedeFactorizar);
}
