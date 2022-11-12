#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	char id[10];
	char name[120];
	char edad[10];
	char posicion[60];
	char nacionalidad[60];
	char idSeleccion[10];
	Jugador* unJugador;

	if(pArrayListJugador!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,edad,posicion,nacionalidad,idSeleccion);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,edad,posicion,nacionalidad,idSeleccion);
			unJugador = jug_newParametros(id,name,edad,posicion,nacionalidad,idSeleccion);
			ll_add(pArrayListJugador, unJugador);
		}
		retorno=0;
	}
	return retorno;
}
int parser_JugadorFromBinary(FILE* pFile, LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	Jugador* unJugador;

	if(pArrayListJugador!=NULL)
	{
		printHeadboard();
		while(!feof(pFile))
		{
			unJugador=jug_new();
			fread(unJugador, sizeof(Jugador),1,pFile);
			printOneSummonedPlayer(unJugador, pArrayListSeleccion);
			if(feof(pFile))
			{
				free(unJugador);
				break;
			}
		}
		retorno=0;
	}
    return retorno;
}
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	char id[10];
	char pais[30];
	char confederacion[30];
	char convocados[10];

	Seleccion* unaSeleccion;

	if(pArrayListSeleccion!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);
			unaSeleccion = selec_newParametros(id, pais, confederacion, convocados);
			ll_add(pArrayListSeleccion, unaSeleccion);
		}
		retorno=0;
	}
    return retorno;
}

