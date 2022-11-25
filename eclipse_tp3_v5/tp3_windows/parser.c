#include <stdio.h>
#include <stdlib.h>
#include "utn_get.h"
#include "Informes.h"
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
int parser_SaveJugadorToBinary(FILE* pFile, LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int cantidad;
	int idConfederacion;
	int auxId;
	Jugador* unJugador;

	utn_getNumberInt(&idConfederacion,"\n|~~~INGRESE LA CONFEDERACION QUE QUIERE CREAR Y GUARDAR EN EL ARCHIVO~~~|\n1. UEFA\n2. AFC\n3. CONMEBOL\n4. CONCACAF\n5. CAF\n->: ","\nError. ingrese una opcion valida...",1,5,200);
	cantidad=ll_len(pArrayListJugador);
	ll_sort(pArrayListSeleccion, compareByConference, 1);
	for(int i=0; i<cantidad;i++)
	{
		unJugador = ll_get(pArrayListJugador, i);
		jug_getIdSeleccion(unJugador, &auxId);
		if(auxId!=0)
		{
			switch(idConfederacion)
			{
				case 1:
					if(auxId == 1 || auxId == 5 || auxId == 11 || auxId == 14 || auxId == 16 || auxId == 17 || auxId == 19 || auxId == 20 || auxId == 25 || auxId == 26 || auxId == 29 || auxId == 30)
					{
						fwrite(unJugador,sizeof(Jugador),1,pFile);
					}
					break;
				case 2:
					if(auxId == 2 || auxId == 4 || auxId == 9 || auxId == 21 || auxId == 27 || auxId == 29)
					{
						fwrite(unJugador,sizeof(Jugador),1,pFile);
					}
					break;
				case 3:
					if(auxId == 3 || auxId == 6 || auxId == 13 || auxId == 32)
					{
						fwrite(unJugador,sizeof(Jugador),1,pFile);
					}
					break;
				case 4:
					if(auxId == 8 || auxId == 10 || auxId == 15 || auxId == 24)
					{
						fwrite(unJugador,sizeof(Jugador),1,pFile);
					}
					break;
				case 5:
					if(auxId == 7 || auxId == 18 || auxId == 23 || auxId == 28 || auxId == 31)
					{
						fwrite(unJugador,sizeof(Jugador),1,pFile);
					}
					break;
			}
		}
	}
	puts("\nCreando y guardando archivo binario 'data.bin'...");
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
			if(feof(pFile))
			{
				free(unJugador);
				break;
			}
			printOneSummonedPlayer(unJugador, pArrayListSeleccion);
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

