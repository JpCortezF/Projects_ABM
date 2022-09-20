#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "administrarEquipo.h"

int calcularCosto(float* pHospedaje, float* pComida, float* pTransporte, float* pMantenimiento)
{
	int retorno=-1;
	int opcion;
	int salir;

	if(pHospedaje!=NULL && pComida!=NULL && pTransporte!=NULL && pMantenimiento!=NULL)
	{
		do
		{
			printf("\n--------------------------\n");
			printf("1. Costo de Hospedaje -> %.2f\n", *pHospedaje);
			printf("2. Costo de Comida -> %.2f\n", *pComida);
			printf("3. Costo de Transporte -> %.2f\n", *pTransporte);
			printf("4. SALIR.\n");
			utn_getNumberInt(&opcion, "Ingrese gasto que desea ingresar: ", "\nError, elija una opcion valida...\n",1,4,5);
			switch(opcion)
			{
			case 1:
				utn_getNumberFloat(pHospedaje, "\nIngrese costo del hospedaje: ", "\nLo siento, ocurrio un problema con la carga :(\n", 2000, 9999999, 3);
				break;
			case 2:
				utn_getNumberFloat(pComida, "\nIngrese costo del comida: ", "\nLo siento, ocurrio un problema con la carga :(\n", 2000, 9999999, 3);
				break;
			case 3:
				utn_getNumberFloat(pTransporte, "\nIngrese costo del transporte: ", "\nLo siento, ocurrio un problema con la carga :(\n", 2000, 9999999, 3);
				break;
			case 4:
				if(pHospedaje!=0 || pComida!=0 || pTransporte!= 0)
				{
					utn_getNumberInt(&salir, "\n1.Seguir cargando\n2.Salir\nIngrese opcion: ","\nIngrese una opcion valida...\n",1,2,3);
				}
				break;
			}
			*pMantenimiento = *pHospedaje + *pComida + *pTransporte;
		}while(salir!=2);


		retorno=0;
	}
	return retorno;
}
int cargarEquipo(int* arquero, int* defensor, int* mediocampista, int* delantero,  int* confederacionAfc, int* confederacionCaf, int* confederacionConcacaf, int* confederacionConmebol, int* confederacionUefa, int* confederacionOfc, int* jugodoresTotal)
{
	int retorno=-1;
	int posicion;
	int dorsal;
	char confederacion[10];
	char auxPosicion[15];
	char posicionJugador[15];

	if(arquero!=NULL && defensor!=NULL && mediocampista!=NULL && delantero!=NULL)
	{
		do
		{
			strcpy(auxPosicion, " ");
			utn_getNumberInt(&posicion, "\nQue posicion tendriamos que agregar?\n(1) Arqueros\n(2) Defensores\n(3) Mediocampistas\n(4) Delanteros\n(5) SALIR.\nIngrese opcion: ", "\nIngrese una opcion valida...\n",1,5,5);
			switch(posicion)
			{
				case 1:
					if(*arquero < 2)
					{
						*arquero = *arquero + 1;
						strcpy(posicionJugador, "Arquero");
						strcpy(auxPosicion, posicionJugador);
						utn_getNumberInt(&dorsal, "\nQue dorsal deberia usar el Arquero?: ", "\nRecorda que solo podemos llevar 22 jugadores.\nLos numeros tienen que estar en ese rango...\n",1,22,3);
						elegirConfederacion(confederacion, confederacionAfc, confederacionCaf, confederacionConcacaf, confederacionConmebol, confederacionUefa, confederacionOfc);
					}
					else{
						printf("\nHay que tener presente que no podemos superar la cantidad maxima de 22 jugadores y\nno mas de dos por posicion, es decir, en total deberiamos tener 2 arqueros, 8 defensores,\n8 mediocampistas y 4 delanteros (teniendo en cuenta titulares y suplentes).\n");
					}
					break;
				case 2:
					if(*defensor < 8)
					{
						*defensor = *defensor + 1;
						strcpy(posicionJugador, "Defensor");
						strcpy(auxPosicion, posicionJugador);
						utn_getNumberInt(&dorsal, "\nQue dorsal deberia usar el Defensor?: ", "\nRecorda que solo podemos llevar 22 jugadores.\nLos numeros tienen que estar en ese rango...\n",1,22,3);
						elegirConfederacion(confederacion, confederacionAfc, confederacionCaf, confederacionConcacaf, confederacionConmebol, confederacionUefa, confederacionOfc);
					}
					else{
						printf("\nHay que tener presente que no podemos superar la cantidad maxima de 22 jugadores y\nno mas de dos por posicion, es decir, en total deberiamos tener 2 arqueros, 8 defensores,\n8 mediocampistas y 4 delanteros (teniendo en cuenta titulares y suplentes).\n");
					}
					break;
				case 3:
					if(*mediocampista < 8)
					{
						*mediocampista = *mediocampista + 1;
						strcpy(posicionJugador, "Mediocampista");
						strcpy(auxPosicion, posicionJugador);
						utn_getNumberInt(&dorsal, "\nQue dorsal deberia usar el Mediocampista?: ", "\nRecorda que solo podemos llevar 22 jugadores.\nLos numeros tienen que estar en ese rango...\n",1,22,3);
						elegirConfederacion(confederacion, confederacionAfc, confederacionCaf, confederacionConcacaf, confederacionConmebol, confederacionUefa, confederacionOfc);
					}
					else{
						printf("\nHay que tener presente que no podemos superar la cantidad maxima de 22 jugadores y\nno mas de dos por posicion, es decir, en total deberiamos tener 2 arqueros, 8 defensores,\n8 mediocampistas y 4 delanteros (teniendo en cuenta titulares y suplentes).\n");
					}
					break;
				case 4:
					if(*delantero < 4)
					{
						*delantero = *delantero + 1;
						strcpy(posicionJugador, "Delantero");
						strcpy(auxPosicion, posicionJugador);
						utn_getNumberInt(&dorsal, "\nQue dorsal deberia usar el Delentero?: ", "\nRecorda que solo podemos llevar 22 jugadores.\nLos numeros tienen que estar en ese rango...\n",1,22,3);
						elegirConfederacion(confederacion, confederacionAfc, confederacionCaf, confederacionConcacaf, confederacionConmebol, confederacionUefa, confederacionOfc);
					}
					else{
						printf("\nHay que tener presente que no podemos superar la cantidad maxima de 22 jugadores y\nno mas de dos por posicion, es decir, en total deberiamos tener 2 arqueros, 8 defensores,\n8 mediocampistas y 4 delanteros (teniendo en cuenta titulares y suplentes).\n");
					}
					break;
			}
			if(strcmp(posicionJugador, auxPosicion) == 0)
			{
				printf("\n¡¡Jugador agregado exitosamente!!\n\n");
				printf(" Arqueros -> %d\n", *arquero);
				printf(" Defensores -> %d\n", *defensor);
				printf(" Mediocampistas -> %d\n", *mediocampista);
				printf(" Delanteros -> %d\n", *delantero);
				printf("\nPosicion: %s -> Dorsal: %d -> CONFEDERACION: %s\n", posicionJugador, dorsal, confederacion);
				(*jugodoresTotal)++;
			}
		}while(posicion!=5);
		retorno=0;
	}
	return retorno;
}
int elegirConfederacion(char* confederacion, int* confederacionAfc, int* confederacionCaf, int* confederacionConcacaf, int* confederacionConmebol, int* confederacionUefa, int* confederacionOfc)
{
	int retorno=-1;
	int opcion;

	if(confederacion!=NULL && confederacionAfc!=NULL && confederacionCaf!=NULL && confederacionConcacaf!=NULL && confederacionConmebol!=NULL && confederacionUefa!=NULL && confederacionOfc!=NULL)
	{
		utn_getNumberInt(&opcion, "\n(1) AFC (Asia)\n(2) CAF (Africa)\n(3) CONCACAF (America del norte)\n(4) CONMEBOL (Sudamerica)\n(5) UEFA (Europa)\n(6) OFC (Oceania)\nIngrese confederacion a la que pertenece el jugador: ", "\nRecuerde que tiene que pertenecer a cualquiera de las 6 conferaciones de futbol\n",1,6,3);
		switch(opcion)
		{
			case 1:
				*confederacionAfc = *confederacionAfc + 1;
				strcpy(confederacion, "AFC");
				break;
			case 2:
				*confederacionCaf = *confederacionCaf + 1;
				strcpy(confederacion, "CAF");
				break;
			case 3:
				*confederacionConcacaf = *confederacionConcacaf + 1;
				strcpy(confederacion, "CONCACAF");
				break;
			case 4:
				*confederacionConmebol = *confederacionConmebol + 1;
				strcpy(confederacion, "CONMEBOL");
				break;
			case 5:
				*confederacionUefa = *confederacionUefa + 1;
				strcpy(confederacion, "UEFA");
				break;
			case 6:
				*confederacionOfc = *confederacionOfc + 1;
				strcpy(confederacion, "OFC");
				break;
		}
		retorno=0;
	}
	return retorno;
}
int promedioTotal(float* promedio, int sumaTotal, int confederaciones)
{
	int retorno=-1;
	if(promedio!=NULL)
	{
		*promedio = ((float) sumaTotal / confederaciones);
		retorno=0;
	}
	return retorno;
}
int porcentajeTotal(float* promedio, int sumaTotal, int len)
{
	int retorno=-1;
	if(promedio!=NULL && len > 0)
	{
		*promedio = ((float) sumaTotal / len) * 100;
		retorno=0;
	}
	return retorno;
}
