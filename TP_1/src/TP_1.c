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
#include "Biblioteca.h"





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
    int sePuedeFactorizarPNum;
    int resulFactorialPrimerNum;
    int sePuedeFactorizarSNum;
    int resulFactorialSegundoNum;




    do{

        switch(menu(flagPrimerNum, flagSegundoNum, primerNumero, segundoNumero, flagCalculos, resultadoSuma, resultadoResta, resultadoMultiplicacion, sePuedeDividir, resultadoDivision, sePuedeFactorizarPNum, resulFactorialPrimerNum, sePuedeFactorizarSNum, resulFactorialSegundoNum, flagResultado)){

            case '1':
            	flagPrimerNum=0; //Reinicio banderas.
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
                sePuedeFactorizarPNum = factorial(primerNumero, &resulFactorialPrimerNum);
                sePuedeFactorizarSNum = factorial(segundoNumero, &resulFactorialSegundoNum);


                printf("Calculos realizados.\nPresione enter para continuar.\n"); //Imprime en pantalla para avisar al usuario
                flagCalculos=1; 			//Actualizo bandera

            }else if(flagPrimerNum && !flagSegundoNum){
                printf("Debe ingresar un segundo operando para realizar la operacion.\nPresione enter para continuar.\n");

            }else{
                printf("Debe ingresar el primer operando, luego segundo operando para realizar los calculos. \nPresione enter para continuar.\n");
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

                printf("Primero debe ingresar operandos.\nPresione enter para continuar.\n");

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


