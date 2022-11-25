#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "Jugador.h"
#include "Controller.h"
#include "Seleccion.h"
#include "Informes.h"

Seleccion* selec_new()
{
	Seleccion* newSeleccion;

	newSeleccion=(Seleccion*)malloc(sizeof(Seleccion));
	return newSeleccion;
}
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* newSeleccion = NULL;
	newSeleccion = selec_new();

	if(newSeleccion!=NULL && idStr !=NULL && paisStr!=NULL && confederacionStr!=NULL && convocadosStr!=NULL)
	{
		selec_setId(newSeleccion, atoi(idStr));
		selec_setPais(newSeleccion, paisStr);
		selec_setConfederacion(newSeleccion, confederacionStr);
		selec_setConvocados(newSeleccion, atoi(convocadosStr));
	}
	return newSeleccion;
}
void selec_delete(Seleccion* seleccion)
{
	if(seleccion!=NULL)
	{
		free(seleccion);
	}
}
int selec_setId(Seleccion* this,int id)
{
	int retorno=-1;

	if(this!=NULL && id > 0)
	{
		this->id = id;
		retorno=0;
	}
	return retorno;
}
int selec_getId(Seleccion* this,int* id)
{
	int retorno=-1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		retorno=0;
	}
	return retorno;
}
int selec_setPais(Seleccion* this,char* pais)
{
	int retorno=-1;

	if(this!=NULL && strlen(pais) > 0)
	{
		strcpy(this->pais, pais);
		retorno=0;
	}
	return retorno;
}
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno=-1;

	if(this!=NULL && strlen(pais) > 0)
	{
		strcpy(pais, this->pais);
		retorno=0;
	}
	return retorno;
}
int selec_setConfederacion(Seleccion* this, char* confederacion)
{
	int retorno=-1;

	if(this!=NULL && strlen(confederacion) > 0)
	{
		strcpy(this->confederacion, confederacion);
		retorno=0;
	}
	return retorno;
}
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno=-1;

	if(this!=NULL && strlen(confederacion) > 0)
	{
		strcpy(confederacion, this->confederacion);
		retorno=0;
	}
	return retorno;
}
int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno=-1;

	if(this!=NULL && convocados>=0)
	{
		this->convocados = convocados;
		retorno=0;
	}
	return retorno;
}
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno=-1;

	if(this!=NULL && convocados!=NULL)
	{
		*convocados = this->convocados;
		retorno=0;
	}
	return retorno;
}
int compareStrings(char* pais, char* nacionalidad)
{
	int retorno=-1;
	for(int i=0; i<3; i++)
	{
		if(pais[i] == nacionalidad[i])
		{
			retorno=0;
		}
		else{
			retorno=-1;
			break;
		}
	}
	return retorno;
}
int convocarJugadores(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador)
{
	int retorno=-1;
	char option;
	char pais[100];
	char nacionalidad[82];
	int index;
	int continuar;
	int idJugador;
	int idSeleccion;
	int indexJugador;
	int convocados;
	Jugador* unJugador = NULL;
	Seleccion* unConvocado = NULL;

	if(pArrayListSeleccion!=NULL)
	{
		if(!(ll_isEmpty(pArrayListJugador)))
		{
			utn_getChar(&option,"\nA) Convocar\nB) Quitar de la seleccion\n->: ","\nIngrese una opcion valida...",'A','B',200);

			printListPlayers(pArrayListJugador, pArrayListSeleccion);
			switch(option)
			{
				case 'A':
					utn_getNumberInt(&idJugador, "\nIngrese ID del jugador para convocar: ","\nErorr, ingrese un ID valido...",1,10000000,200);
					indexJugador = searchPlayerById(pArrayListJugador, idJugador);
					break;
				case 'B':
					utn_getNumberInt(&idJugador, "\nIngrese ID del jugador para quitar: ","\nErorr, ingrese un ID valido...",1,10000000,200);
					indexJugador = searchPlayerById(pArrayListJugador, idJugador);
					break;
			}
			if(indexJugador==-1)
			{
				printf("\nNo se encontro al ID: %d\n", idJugador);
			}
			else
			{
				unJugador = ll_get(pArrayListJugador, indexJugador);
				jug_getIdSeleccion(unJugador, &idSeleccion);
				if(idSeleccion == 0 && option == 'A')
				{
					printHeadboard();
					printOnePlayer(unJugador);
					utn_getNumberInt(&continuar,"\nIngrese '1' para continuar: ","\nError, ingrese '1' para continuar...",1,1,200);
					printListSeleccion(pArrayListSeleccion);
					utn_getNumberInt(&idSeleccion,"\nIngrese un ID para seleccionar seleccionado: ", "\nError, ingrese un ID opcion valida...",1,32,200);
					index = searchSeleccionById(pArrayListSeleccion, idSeleccion);

					if(index==-1)
					{
						printf("\nNo se encontro al ID: %d\n", idSeleccion);
					}
					else
					{
						unConvocado = ll_get(pArrayListSeleccion, index);
						selec_getConvocados(unConvocado, &convocados);
						jug_getNacionalidad(unJugador, nacionalidad);
						selec_getPais(unConvocado, pais);
						if((compareStrings(pais, nacionalidad)) == 0)
						{
							jug_setIdSeleccion(unJugador, idSeleccion);
							convocados++;
							if(convocados <= 22)
							{
								selec_setConvocados(unConvocado, convocados);
								printHeadboard();
								printOneSummonedPlayer(unJugador, pArrayListSeleccion);
							}
							else
							{
								printf("\nNo podes llevar mas de 22 jugadores por Seleccion...\n");
							}
						}
						else
						{
							printf("\n-> No podes convocar un jugador que su nacionalidad no corresponde con su pais...\n");
						}
					}
				}
				else if(idSeleccion != 0 && option == 'A'){
					puts("\nEl jugador ya se encuentra convocado en una seleccion.");
				}
				if(idSeleccion != 0 && option == 'B')
				{
					printHeadboard();
					printOneSummonedPlayer(unJugador, pArrayListSeleccion);
					utn_getNumberInt(&continuar,"\nIngrese '1' para continuar: ","\nError, ingrese '1' para continuar...",1,1,200);
					index = searchSeleccionById(pArrayListSeleccion, idSeleccion);
					jug_setIdSeleccion(unJugador, 0);
					unConvocado = ll_get(pArrayListSeleccion, index);
					selec_getConvocados(unConvocado, &convocados);
					convocados--;
					selec_setConvocados(unConvocado, convocados);
					puts("\nJugador retirado de su seleccion. :(");
				}
			}
		}
		else{
    		puts("\nPrimero tenes que hacer la carga del archivo .csv!");
		}
		retorno=0;
	}
	return retorno;
}
