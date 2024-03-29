#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "parser.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "Informes.h"

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	FILE* pFile;

	if(pArrayListJugador!=NULL)
	{
		if((pFile=fopen(path, "r"))!=NULL)
		{
			ll_clear(pArrayListJugador);
			parser_JugadorFromText(pFile, pArrayListJugador);
			puts("\n-> Se cargaron los jugadores desde el archivo correctamente!!");
			retorno=0;
		}
		else{
			printf("Ha ocurrido un error al abrir el archivo...\n");
		}
	}
	fclose(pFile);
	return retorno;
}
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	FILE* pFile;

	if(pArrayListJugador!=NULL)
	{
		if((pFile=fopen(path, "rb"))!=NULL)
		{
			parser_JugadorFromBinary(pFile, pArrayListJugador, pArrayListSeleccion);
			retorno=0;
		}
		else{
			printf("Ha ocurrido un error al abrir el archivo...\n");
		}
	}
	fclose(pFile);
    return retorno;
}
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno=-1;
	if(pArrayListJugador!=NULL)
	{
		addPlayer(pArrayListJugador);
		retorno=0;
	}
    return retorno;
}
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno;
	if(pArrayListJugador!=NULL)
	{
		editPlayer(pArrayListJugador, pArrayListSeleccion);
		retorno=0;
	}
    return retorno;
}
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;

	if(pArrayListJugador!=NULL)
	{
		removePlayer(pArrayListJugador, pArrayListSeleccion);
		retorno=0;
	}
    return retorno;
}
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	if(pArrayListJugador!=NULL)
	{
		printListPlayers(pArrayListJugador, pArrayListSeleccion);
		retorno=0;
	}
    return retorno;
}
int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	char method;
	int order;

	if(pArrayListJugador!=NULL)
	{
		if(!(ll_isEmpty(pArrayListJugador)))
		{
			utn_getChar(&method,"\n|~~~Ordenar y listar~~~|\nA) Jugadores por nacionalidad\nB) Selecciones por confederacion\nC) Jugadores por edad\nD) Jugadores por nombre\nF) SALIR.\n\n-> Ingrese opcion: ","\nIngrese una opcion valida...",'A','F',15);
			switch(method)
			{
				case 'A':
					utn_getNumberInt(&order, "\n-> Ingrese criterio de ordenamiento\n1. Criterio ascendente (1)\n2. Criterio descendente (2)\n3. Volver\n-> Ingrese criterio: ", "\nIngrese una opcion valida...",1,3,15);
					switch(order)
					{
						case 1:
							ll_sort(pArrayListJugador, compareByNacionality, order);
							break;
						case 2:
							order = 0;
							ll_sort(pArrayListJugador, compareByNacionality, order);
							break;
					}
					printListPlayers(pArrayListJugador, pArrayListSeleccion);
					break;
					case 'B':
						utn_getNumberInt(&order, "\n-> Ingrese criterio de ordenamiento\n1. Criterio ascendente (1)\n2. Criterio descendente (2)\n3. Volver\n-> Ingrese criterio: ", "\nIngrese una opcion valida...",1,3,15);
						switch(order)
						{
							case 1:
								ll_sort(pArrayListSeleccion, compareByConference, order);
								break;
							case 2:
								order = 0;
								ll_sort(pArrayListSeleccion, compareByConference, order);
								break;
						}
						printListSeleccion(pArrayListSeleccion);
						break;
					case 'C':
						utn_getNumberInt(&order, "\n-> Ingrese criterio de ordenamiento\n1. Criterio ascendente (1)\n2. Criterio descendente (2)\n3. Volver\n-> Ingrese criterio: ", "\nIngrese una opcion valida...",1,3,15);
						switch(order)
						{
							case 1:
								ll_sort(pArrayListJugador, compareByAge, order);
								break;
							case 2:
								order= 0;
								ll_sort(pArrayListJugador, compareByAge, order);
								break;
						}
						printListPlayers(pArrayListJugador, pArrayListSeleccion);
						break;
				case 'D':
					utn_getNumberInt(&order, "\n-> Ingrese criterio de ordenamiento\n1. Criterio ascendente (1)\n2. Criterio descendente (2)\n3. Volver\n-> Ingrese criterio: ", "\nIngrese una opcion valida...",1,3,15);
					switch(order)
					{
						case 1:
							ll_sort(pArrayListJugador, compareByName, order);
							break;
						case 2:
							order = 0;
							ll_sort(pArrayListJugador, compareByName, order);
							break;
					}
					printListPlayers(pArrayListJugador, pArrayListSeleccion);
					break;
			}
		}else{
    		puts("\nPrimero tenes que hacer la carga del archivo .csv!");
		}
		retorno=0;
	}
    return retorno;
}
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	int cantidad;
	int id;
	char nombreCompleto[120];
	int edad;
	char posicion[60];
	char nacionalidad[60];
	int idSeleccion;

    FILE* pFile;
    Jugador* unJugador;

    if(pArrayListJugador!=NULL)
    {
		if(!(ll_isEmpty(pArrayListJugador)))
		{
			if((pFile=fopen(path, "w"))!=NULL)
			{
				cantidad=ll_len(pArrayListJugador);
				fprintf(pFile,"%s,%s,%s,%s,%s,%s\n","id","nombreCompleto","edad","posicion","nacionalidad","idSeleccion");
				for(int i=0; i<cantidad; i++)
				{
					unJugador = ll_get(pArrayListJugador, i);
					jug_getId(unJugador, &id);
					jug_getNombreCompleto(unJugador, nombreCompleto);
					jug_getEdad(unJugador, &edad);
					jug_getPosicion(unJugador, posicion);
					jug_getNacionalidad(unJugador, nacionalidad);
					jug_getIdSeleccion(unJugador, &idSeleccion);
					fprintf(pFile,"%d,%s,%d,%s,%s,%d\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
				}
		    	fclose(pFile);
			}else{
				printf("\nHa ocurrido un error al abrir el archivo...\n");
			}
		}else{
    		puts("\nPrimero tenes que hacer la carga del archivo .csv!");
    	}
		retorno=0;
    }
    return retorno;
}
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	FILE* pFile;

	if(pArrayListJugador!=NULL)
	{
		if(!(ll_isEmpty(pArrayListJugador)))
		{
			pFile=fopen(path, "wb");
			if(pFile!=NULL)
			{
				parser_SaveJugadorToBinary(pFile, pArrayListJugador, pArrayListSeleccion);
				fclose(pFile);
			}
			else{
				printf("Ha ocurrido un error al abrir el archivo...\n");
			}
		}
		else{
    		puts("\nPrimero tenes que hacer la carga del archivo .csv!");
    	}
		retorno=0;
	}
    return retorno;
}
int controller_convocarJugadores(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador)
{
	int retorno=-1;
	if(pArrayListSeleccion!=NULL && pArrayListJugador!=NULL)
	{
		convocarJugadores(pArrayListSeleccion, pArrayListJugador);
		retorno=0;
	}
	return retorno;
}
int controller_listarConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;

	if(pArrayListJugador!=NULL)
	{
		printSummonedPlayers(pArrayListJugador, pArrayListSeleccion);
		retorno=0;
	}
	return retorno;
}
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	FILE* pFile;

	if(pArrayListSeleccion!=NULL)
	{
		if((pFile=fopen(path, "r"))!=NULL)
		{
			ll_clear(pArrayListSeleccion);
			parser_SeleccionFromText(pFile, pArrayListSeleccion);
			puts("-> Se cargaron las selecciones desde el archivo correctamente!!");
			retorno=0;
		}
		else{
			printf("Ha ocurrido un error al abrir el archivo...\n");
		}
	}
	fclose(pFile);
	return retorno;
}
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	if(pArrayListSeleccion!=NULL)
	{
		printListSeleccion(pArrayListSeleccion);
		retorno=0;
	}
    return retorno;
}
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int len;
	int id;
	char pais[62];
	char confederacion[62];
	int convocados;

	FILE* pFile;
	Seleccion* seleccionado;

	if(pArrayListSeleccion!=NULL)
	{
		if((pFile=fopen(path,"w"))!=NULL)
		{
			fprintf(pFile,"%s,%s,%s,%s\n","id","pais","confederacion","convocados");
			len=ll_len(pArrayListSeleccion);
			for(int i=0; i<len; i++)
			{
				seleccionado = ll_get(pArrayListSeleccion, i);
				selec_getId(seleccionado, &id);
				selec_getPais(seleccionado, pais);
				selec_getConfederacion(seleccionado, confederacion);
				selec_getConvocados(seleccionado, &convocados);
				fprintf(pFile,"%d,%s,%s,%d\n",id,seleccionado->pais,seleccionado->confederacion,convocados);
				// Uso el operador flecha porque por alguna razon, si llamo al getter, guarda un string (pais, confederacion) vacio. :(
			}
			puts("\nArchivos .csv guardados correctamente!");
		}
		else{
			printf("\nHa ocurrido un error al abrir el archivo...\n");
		}
		retorno=0;
	}
	fclose(pFile);
    return retorno;
}
int searchSeleccionById(LinkedList* pArrayListSeleccion, int idSeleccion)
{
	int cantidad;
	int index=-1;
	int idAux;
	Seleccion* unaSeleccion;
	if(pArrayListSeleccion!=NULL)
	{
		cantidad = ll_len(pArrayListSeleccion);
		for(int i=0; i<cantidad; i++)
		{
			unaSeleccion = ll_get(pArrayListSeleccion, i);
			selec_getId(unaSeleccion, &idAux);
			if(idAux == idSeleccion)
			{
				index = ll_indexOf(pArrayListSeleccion, unaSeleccion);
				break;
			}
		}
	}
	return index;
}

