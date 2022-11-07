#include <stdio.h>
#include <stdlib.h>
#include "utn_get.h"
#include "parser.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
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
		}
		else{
			printf("Ha ocurrido un error al abrir el archivo...\n");
		}
	}
	fclose(pFile);
	return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	FILE* pFile;

	if(pArrayListJugador!=NULL)
	{
		if((pFile=fopen(path, "rb"))!=NULL)
		{
			parser_JugadorFromBinary(pFile, pArrayListJugador);
		}
		else{
			printf("Ha ocurrido un error al abrir el archivo...\n");
		}
		retorno=0;
	}
	fclose(pFile);
    return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
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

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int retorno;
	if(pArrayListJugador!=NULL)
	{
		editPlayer(pArrayListJugador);
		retorno=0;
	}
    return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int retorno=-1;

	if(pArrayListJugador!=NULL)
	{
		removePlayer(pArrayListJugador);
		retorno=0;
	}
    return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno=-1;
	if(pArrayListJugador!=NULL)
	{
		printListPlayers(pArrayListJugador);
		retorno=0;
	}
    return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	char method;
	int order;

	if(pArrayListJugador!=NULL)
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
				break;
		}
		retorno=0;
	}
    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	int cantidad;
	int id;
//	char nombreCompleto[100];
	int edad;
//	char posicion[30];
//	char nacionalidad[30];
	int idSeleccion;

    FILE* pFile;
    Jugador* unJugador;

    if(pArrayListJugador!=NULL)
    {
    	if((pFile=fopen(path, "w"))!=NULL)
		{
			cantidad=ll_len(pArrayListJugador);
			fprintf(pFile,"%s,%s,%s,%s,%s,%s\n","id","nombreCompleto","edad","posicion","nacionalidad","idSeleccion");
			for(int i=0; i<cantidad; i++)
			{
				unJugador = ll_get(pArrayListJugador, i);
				jug_getId(unJugador, &id);
//				jug_getNombreCompleto(unJugador, nombreCompleto);
				jug_getEdad(unJugador, &edad);
//				jug_getPosicion(unJugador, posicion);
//				jug_getNacionalidad(unJugador, nacionalidad);
				jug_getIdSeleccion(unJugador, &idSeleccion);
				fprintf(pFile,"%d,%s,%d,%s,%s,%d\n",id,unJugador->nombreCompleto,edad,unJugador->posicion,unJugador->nacionalidad,idSeleccion);
			}
		}else{
			printf("\nHa ocurrido un error al abrir el archivo...\n");
		}
    	fclose(pFile);
    }
    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno=-1;
	int cantidad;
	int auxId;
	Jugador* unJugador;
	FILE* pFile;

	if(pArrayListJugador!=NULL)
	{
		pFile=fopen(path, "wb");
		if(pFile!=NULL)
		{
			cantidad=ll_len(pArrayListJugador);
			for(int i=0; i<cantidad;i++)
			{
				unJugador = ll_get(pArrayListJugador, i);
				jug_getIdSeleccion(unJugador, &auxId);
				if(auxId!=0)
				{
					fwrite(unJugador,sizeof(Jugador),1,pFile);
				}
			}
		}
		else{
			printf("Ha ocurrido un error al abrir el archivo...\n");
		}
		retorno=0;
	}
	fclose(pFile);
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
/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
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
		}
		else{
			printf("Ha ocurrido un error al abrir el archivo...\n");
		}
	}
	fclose(pFile);
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
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

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int len;
	int id;
	char pais[30];
	char confederacion[30];
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
				fprintf(pFile,"%d,%s,%s,%d\n",id,pais,confederacion,convocados);
			}
		}else{
			printf("\nHa ocurrido un error al abrir el archivo...\n");
		}
	}
	fclose(pFile);
    return retorno;
}


