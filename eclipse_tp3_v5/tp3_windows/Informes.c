#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Informes.h"
#include "Seleccion.h"
#include "Controller.h"

void printHeadboard(void)
{
	printf("|=======|=============================|============|======================|==================|=================|\n");
	printf("|   ID  |       Nombre Completo       |    Edad    |       Posicion       |   Nacionalidad   |   IdSeleccion   |\n");
	printf("|-------|-----------------------------|------------|----------------------|------------------|-----------------|\n");
}
void printOnePlayer(Jugador* unJugador)
{
	int id;
	char nombreCompleto[120];
	int edad;
	char posicion[60];
	char nacionalidad[60];
	char sinConvocar[40]={"No convocado"};
	int idSeleccion;

	if(unJugador!=NULL)
	{
		jug_getId(unJugador, &id);
		jug_getNombreCompleto(unJugador, nombreCompleto);
		jug_getEdad(unJugador, &edad);
		jug_getPosicion(unJugador, posicion);
		jug_getNacionalidad(unJugador, nacionalidad);
		jug_getIdSeleccion(unJugador, &idSeleccion);
		printf("|  %3d  | %24s    |     %2d     | %20s | %15s  | %15s |\n",id,nombreCompleto,edad,posicion,nacionalidad,sinConvocar);
	}
}
int printListPlayers(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int cantidad;
	int auxId;
	Jugador* jugadores;

	if(pArrayListJugador!=NULL)
	{
		printHeadboard();
    	cantidad = ll_len(pArrayListJugador);
    	if(cantidad > 0)
    	{
			for(int i=0; i<cantidad; i++)
			{
				jugadores = ll_get(pArrayListJugador, i);
				jug_getIdSeleccion(jugadores, &auxId);
				if(auxId != 0)
				{
					printOneSummonedPlayer(jugadores, pArrayListSeleccion);
				}
				else{
					printOnePlayer(jugadores);
				}
			}
			printf("|==============================================================================================================|\n");
    	}else{
    		printf("\nNo hay jugadores cargados...\n");
    	}
    	retorno=0;
	}
	return retorno;
}
void printOneSummonedPlayer(Jugador* unJugador, LinkedList* pArrayListSeleccion)
{
	int id;
	char nombreCompleto[120];
	int edad;
	char posicion[60];
	char nacionalidad[42];
	int idSeleccion;
	char pais[60];
	int index;
	Seleccion* seleccionado;

	if(unJugador!=NULL && pArrayListSeleccion!=NULL)
	{
		jug_getId(unJugador, &id);
		jug_getNombreCompleto(unJugador, nombreCompleto);
		jug_getEdad(unJugador, &edad);
		jug_getPosicion(unJugador, posicion);
		jug_getNacionalidad(unJugador, nacionalidad);
		jug_getIdSeleccion(unJugador, &idSeleccion);
		index = searchSeleccionById(pArrayListSeleccion, idSeleccion);
		seleccionado = ll_get(pArrayListSeleccion, index);
		selec_getPais(seleccionado, pais);
		printf("|  %3d  | %24s    |     %2d     | %20s | %15s  | %15s |\n",id,nombreCompleto,edad,posicion,nacionalidad,pais);
	}
}
int printSummonedPlayers(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int auxId;
	int cantidad;
	Jugador* jugadores;

	if(pArrayListJugador!=NULL)
	{
    	cantidad = ll_len(pArrayListJugador);
    	if(cantidad > 0)
    	{
    		printHeadboard();
			for(int i=0; i<cantidad; i++)
			{
				jugadores = ll_get(pArrayListJugador, i);
				jug_getIdSeleccion(jugadores, &auxId);
				if(auxId != 0)
				{
					printOneSummonedPlayer(jugadores, pArrayListSeleccion);
				}
			}
			printf("|==============================================================================================================|\n");
    	}else{
    		printf("\nNo hay jugadores cargados...\n");
    	}
	}
	return retorno;
}

/*-----------------------------------------------------------------Informes de selecciones------------------------------------------------------------------*/
void printHeadboardSeleccion()
{
	puts("|======|================|===============|==============|");
	puts("|  ID  |      Pais      | Confederacion |  Convocados  |");
	puts("|------|----------------|---------------|--------------|");
}
void printOneSeleccion(Seleccion* unaSeleccion)
{
	int id;
	char pais[30];
	char confederacion[60];
	int convocados;
	selec_getId(unaSeleccion, &id);
	selec_getPais(unaSeleccion, pais);
	selec_getConfederacion(unaSeleccion, confederacion);
	selec_getConvocados(unaSeleccion, &convocados);
	printf("|  %2d  | %14s |   %8s    |      %2d      |\n",id,pais,confederacion,convocados);
}
int printListSeleccion(LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int cantidad;
	Seleccion* seleccion;

	if(pArrayListSeleccion!=NULL)
	{
		printHeadboardSeleccion();
		cantidad=ll_len(pArrayListSeleccion);
		if(cantidad > 0)
		{
			for(int i=0; i<cantidad; i++)
			{
				seleccion = ll_get(pArrayListSeleccion, i);
				printOneSeleccion(seleccion);
			}
			printf("|======================================================|\n");
		}else{
    		printf("\nNo hay selecciones cargadas...\n");
		}

		retorno=0;
	}
	return retorno;
}
