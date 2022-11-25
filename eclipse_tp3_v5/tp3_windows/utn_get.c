#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_get.h"

#define LIMIT_LENGTH 51

int myGets(char* cadena, int len)
{
	int retorno=-1;
	char bufferString[LIMIT_LENGTH];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]=='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString) <= len))
			{
				strncpy(cadena, bufferString, len);
				retorno=0;
			}
		}
	}
	return retorno;
}
int utn_isNan(char* cadena, int len)
{
	int retorno=-1;

	if(cadena !=NULL && strlen(cadena)>0){
		for(int i=0; i < len && cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i]== '-' || cadena[i] == '+'))
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
int isFloat(char* cadena, int len)
{
	int retorno=1;
	int pointsCount=0;

	if(cadena !=NULL && strlen(cadena)>0){
		for(int i=0; i < len && cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i]=='-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena [i] > '9')
			{
				if(cadena[i]=='.' && cadena[i]==',' && pointsCount == 0)
				{
					pointsCount++;
					continue;
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
int isAChar(char* string, int len)
{
	int retorno=0;

	if(string != NULL && len > 0)
	{
		for(int i=0; i < len && string[i] != '\0'; i++)
		{
			if((string[i]<'a' || string[i] > 'z') && (string[i]<'A' || string[i] > 'Z'))
			{
				if(i != 0 && string[i] == ' ')
				{
					retorno=0;
					break;
				}
				else
				{
					retorno = -1;
					break;
				}
			}
		}
	}
	return retorno;
}
int getChar(char* pResult)
{
	int retorno=-1;
	char bufferString[LIMIT_LENGTH];

	if(pResult!=NULL && myGets(bufferString, sizeof(bufferString)) == 0
	&& isAChar(bufferString, sizeof(bufferString))==0)
	{
		strcpy(pResult, bufferString);
		retorno=0;
	}
	return retorno;
}
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
			printf("%s", errorMessage);
			attemps--;
		}
	}while(attemps>= 0);

	return retorno;
}
int utn_getString(char* pResult, char* message, char* errorMessage, int len, int attemps)
{
	int retorno=-1;
	char bufferString[LIMIT_LENGTH];

	do
	{
		if(pResult != NULL && message!= NULL && errorMessage != NULL && attemps >= 0)
		{
			printf("%s", message);
			if(getChar(bufferString) == 0)
			{
				strncpy(pResult, bufferString, len);
				retorno=0;
				break;
			}
			printf("%s\n", errorMessage);
			attemps--;
		}
	}while(attemps>=0);

	return retorno;
}
int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL){
		if(myGets(buffer, sizeof(buffer)) ==0 && utn_isNan(buffer,sizeof(buffer)))
		{
			*pResultado = atoi(buffer);
			retorno=0;
		}
	}
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
			if((getInt(&bufferInt) == 0) && (bufferInt >= min && bufferInt <= max))
			{
				*pResult = bufferInt;
				retorno=0;
				break;
			}
			printf("%s", errorMessage);
			attemps--;
		}
	}while(attemps>= 0);
	return retorno;
}
int getFloat(float* pResult)
{
	int retorno=-1;
	char buffer[64];

	if(pResult != NULL){
		if(myGets(buffer, sizeof(buffer)) ==0 && isFloat(buffer, sizeof(buffer)))
		{
			*pResult = atof(buffer);
			retorno=0;
		}
	}
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
			if((getFloat(&bufferFloat) == 0) && (bufferFloat >= min && bufferFloat <= max))
			{
				*pResult = bufferFloat;
				retorno=0;
				break;
			}
			printf("%s", errorMessage);
			attemps--;
		}
	}
	return retorno;
}
