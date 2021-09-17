/*
 ============================================================================
 Name        : TP_1.c
 Author      : Julieta Laplace
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char menu(int flagA, int flagB, int num1, int num2, int flagCalculo, int suma, int resta, int multiplicacion, int division, float resulDivision, int flagResult);
int suma(int num1, int num2);
int resta(int num1, int num2);
int multiplicacion(int num1, int num2);
int division(int num1, int num2, float* pResulDivision);


int main()
{
	setbuf(stdout,NULL);
    int primerNumero;
    int segundoNumero;
    char respuesta='n';

    //Banderas
    int flagPrimerNum=0;
    int flagSegundoNum=0;
    int flagCalculos=0;
    int flagResultado=0;

    //Resultado Funciones
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    int sePuedeDividir;
    float resultadoDivision;




    do{

        switch(menu(flagPrimerNum, flagSegundoNum, primerNumero, segundoNumero, flagCalculos, resultadoSuma, resultadoResta, resultadoMultiplicacion, sePuedeDividir, resultadoDivision, flagResultado)){

            case '1':
            	flagPrimerNum=0; //Reinicio banderas para limpiar los numeros ingresados en el menu.
            	flagSegundoNum=0;
            	flagCalculos=0;

                printf("1. Ingresar 1er operando (A=X): ");
                scanf("%d", &primerNumero);
                flagPrimerNum=1; 			//Actualizo bandera de ingreso de primerNumero
                flagResultado=0;
                break;

            case '2':

                if(flagPrimerNum){
                    printf("2. Ingresar 2do operando (B=Y): ");
                    scanf("%d", &segundoNumero);
                    flagSegundoNum=1; 			//Actualizo bandera de ingreso de segundoNumero

                } else {
                    printf("Ingrese primer operando, luego segundo operando.\nPresione enter para continuar.\n");
                    fflush(stdin);
                    getchar();
                }
                flagResultado=0;
                break;

        case '3':

            if(flagPrimerNum && flagSegundoNum){
                resultadoSuma = suma(primerNumero, segundoNumero);  //Calculos
                resultadoResta = resta(primerNumero, segundoNumero);
                resultadoMultiplicacion = multiplicacion(primerNumero, segundoNumero);
                sePuedeDividir = division(primerNumero, segundoNumero, &resultadoDivision);


                printf("Calculos realizados.\nPresione enter para continuar.\n"); //Imprime en pantalla para avisar al usuario
                flagCalculos=1; 			//Actualizo bandera

            }else if(flagPrimerNum && !flagSegundoNum){
                printf("Ingrese segundo valor para realizar la operacion.\nPresione enter para continuar.\n");

            }else{
                printf("Ingrese primer valor, luego segundo valor para realizar los calculos. \nPresione enter para continuar.\n");
            }
            flagResultado=0;
            fflush(stdin);
            getchar();
            break;

        case '4':

            if(flagCalculos){
                printf("Resulados impresos.\nPresione enter para continuar.\n");
                flagResultado=1;


            } else if (!(flagCalculos) && flagSegundoNum){

                printf("Debe calcular los resultados primero.\nPresione enter para continuar.\n");

            } else{

                printf("Primero ingrese valores.\nPresione enter para continuar.\n");

            }
            fflush(stdin);
            getchar();
            break;

        case '5':

            respuesta = 's';  //Usuario sale del do-while
            break;

        default:

            //Para valores erroneos, informo que ingrese otro valor valido.
            printf("El valor ingresado es invalido.\nPresione enter para continuar. \n");
            fflush(stdin);
            getchar();
            break;
           }
    } while( respuesta == 'n');

    return 0;
}

char menu (int flagA, int flagB, int num1, int num2, int flagCalculo, int suma, int resta, int multiplicacion, int division, float resulDivision, int flagResult){

    char opcion;

    system("cls");

    printf("********CALCULADORA********\n\n");
    	//Primer valor a ingresar
		if(flagA){
				printf("1. Ingresar 1er operando: A=%d. \n", num1); //Esta ingresado, se muestra por pantalla
		}else{
				printf("1. Ingresar 1er operando: A=X. \n"); //No esta ingresado, se muestra X en pantalla
		}

		//Segundo valor a ingresar
		 if(flagB){
				printf("2. Ingrese 2do operando: B=%d. \n", num2); //Esta ingresado el numero, se muestra por pantalla

		 } else {
				printf("2. Ingrese 2do operando: B=X. \n");//No esta ingresado, se muestra X en pantalla
		 }

        //Realiza los calculos
        if(flagA && flagB){
        	printf("3. Calcular todas las operaciones:\n");
        	printf("a) Calcular la suma %d+%d.\n", num1, num2);
        	printf("b) Calcular la resta %d-%d.\n", num1,num2);
            printf("c) Calcular la multiplicacion %d*%d.\n", num1, num2);
            printf("d) Calcular la division %d/%d.\n", num1, num2);
            //printf("e) Calcular  %d! y  %d!.\n", num1, num2);
        } else {
        	 printf("3. Calcular todas las operaciones:\n");
        	 printf("a) Calcular la suma (A+B).\n");
        	 printf("b) Calcular la resta (A-B).\n");
        	 printf("c) Calcular la multiplicacion (A*B).\n");
        	 printf("d) Calcular la division (A/B).\n");
        	 printf("e) Calcular factorial (A!) (B!).\n");
        }


        printf("4. Informar resultados:\n");

            if(flagResult){
                printf("a) El resultado de %d+%d es %d.\n", num1, num2, suma);
                printf("b) El resultado de %d-%d es %d.\n", num1, num2, resta);
                printf("c) El resultado de %d*%d es %d.\n", num1, num2, multiplicacion);

                //Condicional de division para mostrar o no su resultado.
                if(division){
                 printf("d. El resultado de %d/%d es: %.2f\n",num1, num2, resulDivision);
                } else {
                   printf ("d. No se puede realizar la division por 0.\n");
                   }



            } else if(flagA && flagB){
                printf("a) Resultado de %d+%d.\n", num1, num2);
                printf("b) Resultado de %d-%d.\n", num1, num2);
                printf("c) Resultado de %d*%d.\n", num1, num2);
                printf("d) Resultado de %d/%d.\n", num1, num2);
                //printf("e) Factorial de %d y el factorial de %d.\n", num1, num2);
            } else {
            	printf("a) Resultado de A+B.\n");
            	printf("b) Resultado de A-B.\n");
            	printf("c) Resultado de A*B.\n");
            	printf("d) Resultado de A/B.\n");
            	printf("e) Factorial de A y el factorial de B.\n");
            }

            printf("5. Salir\n");
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
