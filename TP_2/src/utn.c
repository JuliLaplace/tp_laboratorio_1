/*
 * utn.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Julieta
 */


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include"utn.h"





int esNumerico(char str[])
{
    int i=0;
    int retorno = 1;
    if (str != NULL && strlen (str) > 0){
        while (str[i] != '\0' ){
            if (str[i] < '0' || str[i] > '9' ){
                retorno = 0;
                break ;
            }
            i++;
        }
}
return retorno;
}


int getInt(int * pResultado)
{
    int ret=-1;
    char buffer[64];
    scanf( "%s" ,buffer);
    if (esNumerico(buffer)){
        *pResultado = atoi(buffer);
        ret=1;
    }
    return ret;
}




int utn_getNumero( int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
    int ret;
    int num;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
        while (reintentos>0){
            printf(mensaje);
            if (getInt(&num)==1){
                if (num<=maximo && num>=minimo)
                break ;
            }

            fflush(stdin);
            reintentos--;
            printf(mensajeError);
        }
        if (reintentos==0){
            ret=-1;
        }
        else{
            ret=0;
            *pResultado = num;
        }
}
return ret;
}


int esNumericoFlotante(char str[])
{
int    retorno = 1;
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           retorno = 0;
       i++;
   }
   return retorno;
}

float getFloat(float* pResultado)
{
    int ret=-1;
    char buffer[64];
    scanf( "%s" ,buffer);
    if (esNumericoFlotante(buffer)){
        *pResultado = atof(buffer);
        ret=1;
    }
    return ret;
}

float utn_getNumeroFlotante( float * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos)
{
    int ret;
    float num;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){

        while (reintentos>0)
            {
            printf(mensaje);
            if(getFloat(&num) == 1){

            if (num<=maximo && num>=minimo){
                break;
            }
            }
            fflush(stdin);
            reintentos--;
            printf(mensajeError);
            }
        if (reintentos==0)
        {
            ret=-1;
        }
        else
        {
            ret=0;
            *pResultado = num;
        }
    }
    return ret;
}



int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}




void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}


int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


