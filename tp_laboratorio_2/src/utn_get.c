#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_get.h"

#define LIMIT_LENGTH 51

int utn_getChar(char* pResult, char* message, char* errorMessage, char minimo, char maximo, int attemps)
{
	int retorno=-1;
	char buffer;
	do
	{
		if(pResult != NULL && message != NULL && errorMessage != NULL && minimo <= maximo && attemps >= 0)
		{
			printf("%s", message);
			fflush(stdin);
			scanf("%c", &buffer);
			buffer = toupper(buffer);
			if((buffer >= minimo && buffer <= maximo) && (isalpha(buffer)))
			{
				*pResult = buffer; //pResultado: Puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto.
				break;
			}
			else
			{
				printf("%s", errorMessage);
				attemps--;
			}
		}
	}while(attemps>= 0);

	return retorno;
}
int utn_getString(char* pResult, char* message, char* errorMessage, int attemps)
{
	int retorno=-1;
	char bufferString[LIMIT_LENGTH];

	do
	{
		if(pResult != NULL && message!= NULL && errorMessage != NULL && attemps >= 0)
		{
			printf("%s", message);
			fflush(stdin);
			gets(bufferString);

			if((strlen(bufferString)<=LIMIT_LENGTH) && (isalpha(*(bufferString))))
			{
				strcpy(pResult, bufferString);
				break;
			}
			else
			{
				printf("%s\n", errorMessage);
				attemps--;
			}
			retorno=0;
		}
	}while(attemps>=0);

	return retorno;
}
int myGets(char* cadena, int len)
{
	int retorno=-1;

	if(cadena != NULL && len >0 && fgets(cadena, len, stdin)==cadena){
		fflush(stdin);
		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]='\0';
		}
		retorno=0;
	}
	return retorno;
}
int utn_isNan(char* cadena)
{
	int retorno=-1;

	if(cadena !=NULL && strlen(cadena)>0){
		for(int i=0; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i]=='-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena [i] > '9')
			{
				retorno=0;
				break;
			}
		}

	}
	return retorno;
}
int getShortInt(short* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL){
		if(myGets(buffer, sizeof(buffer)) ==0 && utn_isNan(buffer))
		{
			*pResultado = atoi(buffer);
			retorno=0;
		}
	}
	return retorno;
}
int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL){
		if(myGets(buffer, sizeof(buffer)) ==0 && utn_isNan(buffer))
		{
			*pResultado = atoi(buffer);
			retorno=0;
		}
	}
	return retorno;
}
int getFloat(float* pResult)
{
	int retorno=-1;
	char buffer[64];

	if(pResult != NULL){
		if(myGets(buffer, sizeof(buffer)) ==0 && isFloat(buffer))
		{
			*pResult = atof(buffer);
			retorno=0;
		}
	}
	return retorno;
}
int isFloat(char* cadena)
{
	int retorno=1;
	int pointsCount=0;

	if(cadena !=NULL && strlen(cadena)>0){
		for(int i=0; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i]=='-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena [i] > '9')
			{
				if(cadena[i]=='.' && pointsCount == 0)
				{
					pointsCount++;
				}
				else
				{
					retorno=0;
					break;
				}
			}
		}
	}
	return retorno;
}
int utn_getShortInt(short* pResult, char* message, char* errorMessage, short min, short max, short attemps)
{
	int retorno=-1;
	short bufferInt;

	do
	{
		if(pResult != NULL && message != NULL && errorMessage != NULL && min <= max && attemps >= 0)
		{
			printf("%s", message);
			fflush(stdin);
			if((getShortInt(&bufferInt) == 0) || (isdigit(bufferInt)!=0))
			{

				if(bufferInt >= min && bufferInt <= max)
				{
					*pResult = bufferInt;
					retorno=0;
					break;
				}
				else
				{
					printf("%s", errorMessage);
					attemps--;
				}
			}
		}
	}while(attemps>= 0);
	return retorno;
}
int utn_getNumberInt(int* pResult, char* message, char* errorMessage, int min, int max, int attemps)
{
	int retorno=-1;
	int bufferInt;

	do
	{
		if(pResult != NULL && message != NULL && errorMessage != NULL && min <= max && attemps >= 0)
		{
			printf("%s", message);
			fflush(stdin);
			if((getInt(&bufferInt) == 0) || (scanf("%d", &bufferInt)))
			{

				if(bufferInt >= min && bufferInt <= max)
				{
					*pResult = bufferInt;
					retorno=0;
					break;
				}
				else
				{
					printf("%s", errorMessage);
					attemps--;
				}
			}
		}
	}while(attemps>= 0);
	return retorno;
}
int utn_getNumberFloat(float* pResult, char* message, char* errorMessage, float min, float max, int attemps)
{
	int retorno=-1;
	float bufferFloat;

	while(attemps>= 0)
	{
		if(pResult != NULL && message != NULL && errorMessage != NULL && min <= max && attemps >= 0)
		{
			printf("%s", message);
			fflush(stdin);
			if((getFloat(&bufferFloat) == 0) || (scanf("%f", &bufferFloat)))
			{
				if(bufferFloat >= min && bufferFloat <= max)
				{
					*pResult = bufferFloat;
					retorno=0;
					break;
				}
				else{
				printf("%s", errorMessage);
				attemps--;
				}
			}
		}
	}
	return retorno;
}
