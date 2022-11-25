#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "utn_get.h"
#include "Informes.h"
#include "Seleccion.h"
#include "Controller.h"

Jugador* jug_new()
{
	Jugador* newJugador;

	newJugador = (Jugador*)malloc(sizeof(Jugador));
	return newJugador;
}
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr)
{
	Jugador* newJugador = NULL;

	newJugador = jug_new();

	if(newJugador!=NULL && idStr !=NULL && nombreCompletoStr !=NULL && edadStr !=NULL && posicionStr !=NULL && nacionalidadStr !=NULL && idSeleccionStr !=NULL)
	{
		jug_setId(newJugador, atoi(idStr));
		jug_setNombreCompleto(newJugador, nombreCompletoStr);
		jug_setEdad(newJugador, atoi(edadStr));
		jug_setPosicion(newJugador, posicionStr);
		jug_setNacionalidad(newJugador, nacionalidadStr);
		jug_setIdSeleccion(newJugador, atoi(idSeleccionStr));
	}
	return newJugador;
}
void jug_delete(Jugador* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}
int jug_setId(Jugador* this,int id)
{
	int retorno=-1;
	if(this!=NULL && id>= 0)
	{
		this->id = id;
		retorno=0;
	}
	return retorno;
}
int jug_getId(Jugador* this,int* id)
{
	int retorno=-1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		retorno=0;
	}
	return retorno;
}
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno=-1;

	if(this!=NULL && strlen(nombreCompleto) > 0)
	{
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno=0;
	}
	return retorno;
}
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno=-1;

	if(this!=NULL && strlen(nombreCompleto) > 0)
	{
		strcpy(nombreCompleto, this->nombreCompleto);
		retorno=0;
	}
	return retorno;
}
int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno=-1;

	if(this!=NULL && strlen(posicion) > 0)
	{
		strcpy(this->posicion, posicion);
		retorno=0;
	}
	return retorno;
}
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno=-1;

	if(this!=NULL && strlen(posicion) > 0)
	{
		strcpy(posicion, this->posicion);
		retorno=0;
	}
	return retorno;
}
int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno=-1;

	if(this!=NULL && strlen(nacionalidad) > 0)
	{
		strcpy(this->nacionalidad, nacionalidad);
		retorno=0;
	}
	return retorno;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno=-1;

	if(this!=NULL && strlen(nacionalidad) > 0)
	{
		strcpy(nacionalidad, this->nacionalidad);
		retorno=0;
	}
	return retorno;
}
int jug_setEdad(Jugador* this,int edad)
{
	int retorno=-1;
	if(this!=NULL && edad>= 0)
	{
		this->edad = edad;
		retorno=0;
	}
	return retorno;
}
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno=-1;

	if(this!=NULL && edad!=NULL)
	{
		*edad = this->edad;
		retorno=0;
	}
	return retorno;
}
int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno=-1;
	if(this!=NULL && idSeleccion>= 0)
	{
		this->idSeleccion = idSeleccion;
		retorno=0;
	}
	return retorno;
}
int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno=-1;

	if(this!=NULL && idSeleccion!=NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno=0;
	}
	return retorno;
}
int player_idGenerator(int* id)
{
	int retorno=-1;
	int auxId;
	FILE* pFile;

	if(id!=NULL)
	{
		if((pFile=fopen("id.bin","rb"))!=NULL)
		{
			fread(&auxId,sizeof(int),1,pFile);
			fclose(pFile);
			if((pFile=fopen("id.bin","wb"))!=NULL)
			{
				if(auxId >= 370)
				{
					auxId+=1;
					*id = auxId;
				}
				else if(auxId < 371)
				{
					auxId=371;
				}
				fwrite(&auxId,sizeof(int),1,pFile);
			}else{
				puts("\nError al escribir el archivo...");
			}
			retorno=0;
		}else{
			puts("\nError al abrir el generador de ID...");
		}
	}
	fclose(pFile);
	return retorno;
}
int addPlayer(LinkedList* pArrayListJugador)
{
	int retorno=-1;
	char auxNombre[120];
	char auxPosicion[60];
	char auxNacionalidad[60];
	int nombreValidado=-1;
	int idSeleccion;
	int edad;
	int id=0;

	Jugador* newJugador = jug_new();
	if(pArrayListJugador!=NULL)
	{
		if(!(ll_isEmpty(pArrayListJugador)))
		{
			player_idGenerator(&id);
			nombreValidado = utn_getString(auxNombre, "\nIngrese nombre completo: ", "\nReingrese nombre completo (Nombre y Apellido)...",30,150);
			utn_getNumberInt(&edad, "\nIngrese edad: ", "\nIngrese una edad dentro de los parametros...(16-50)", 16, 50, 150);
			utn_getString(auxPosicion, "\nIngrese posicion: ", "\nHa ocurrido un problema en la carga de la posicion...",30, 150);
			utn_getString(auxNacionalidad, "\nIngrese nacionalidad: ", "\nHa ocurrido un problema en la carga de la nacionalidad...",30, 150);
			idSeleccion = 0;
			if(nombreValidado != -1)
			{
				jug_setId(newJugador, id);
				jug_setNombreCompleto(newJugador, auxNombre);
				jug_setEdad(newJugador, edad);
				jug_setPosicion(newJugador, auxPosicion);
				jug_setNacionalidad(newJugador, auxNacionalidad);
				jug_setIdSeleccion(newJugador, idSeleccion);
				ll_add(pArrayListJugador, newJugador);
				printHeadboard();
				printOnePlayer(newJugador);
				puts("\n-> Jugador cargado con exito...");
			}
			retorno=0;
		}else{
    		puts("\nPrimero tenes que hacer la carga del archivo .csv!");
		}
	}
	return retorno;
}
int searchPlayerById(LinkedList* pArrayListJugador, int id)
{
	int cantidad;
	int index=-1;
	int idAux;
	Jugador* auxJugador;
	if(pArrayListJugador!=NULL)
	{
		cantidad = ll_len(pArrayListJugador);
		for(int i=0; i<cantidad; i++)
		{
			auxJugador = ll_get(pArrayListJugador, i);
			jug_getId(auxJugador, &idAux);
			if(idAux == id)
			{
				index = ll_indexOf(pArrayListJugador, auxJugador);
				break;
			}
		}
	}
	return index;
}
int removePlayer(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int confirma;
	int idJugador;
	int convocados;
	int index;
	int id;

	Jugador* unJugador;
	Seleccion* seleccionado;
	if(pArrayListJugador!=NULL)
	{
		if(!(ll_isEmpty(pArrayListJugador)))
		{
			printListPlayers(pArrayListJugador, pArrayListSeleccion);
			utn_getNumberInt(&id,"\nIngrese ID del jugador a dar de baja: ","\nOcurrio un error en la busqueda del ID...",1,100000000,200);
			index = searchPlayerById(pArrayListJugador, id);

			if(index==-1)
			{
				printf("\nNo se encontro al ID: %d\n", id);
			}
			else
			{
				unJugador = ll_get(pArrayListJugador, index);
				jug_getIdSeleccion(unJugador, &idJugador);
				printHeadboard();
				if(idJugador!=0)
				{
					printOneSummonedPlayer(unJugador, pArrayListSeleccion);
				}
				else{
					printOnePlayer(unJugador);
				}
				printf("|==============================================================================================================|\n");
				utn_getNumberInt(&confirma,"\nConfirmar la baja?\n1. Confirmar\n2. Cancelar\n ->: ","\nIngrese una opcion valida...",1,2,200);
				switch(confirma)
				{
					case 1:
						ll_remove(pArrayListJugador, index);
						printf("	Baja confirmada!\n");
						jug_getIdSeleccion(unJugador, &idJugador);
						if(id!=0)
						{
							index = searchSeleccionById(pArrayListSeleccion, id);
							seleccionado = ll_get(pArrayListSeleccion, index);
							selec_getConvocados(seleccionado, &convocados);
							convocados--;
							selec_setConvocados(seleccionado, convocados);
						}
						break;
					case 2:
						printf("   Baja cancelada!\n");
						break;
				}
			}
		}else{
    		puts("\nPrimero tenes que hacer la carga del archivo .csv!");
		}
	}
	return retorno;
}
int editPlayer(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	char auxNombre[120];
	char auxPosicion[60];
	char auxNacionalidad[60];
	int idJugador;
	int auxEdad;
	int index;
	int edit;
	int id;
	Jugador* unJugador;

	if(pArrayListJugador!=NULL)
	{
		if(!(ll_isEmpty(pArrayListJugador)))
		{
			printListPlayers(pArrayListJugador, pArrayListSeleccion);
			utn_getNumberInt(&id,"\nIngrese ID del jugador a modificar: ","\nOcurrio un error en la busqueda del ID...",1,1000000000,200);
			index = searchPlayerById(pArrayListJugador, id);

			if(index==-1)
			{
					printf("\nNo se encontro al ID: %d\n", id);
				}
				else{
					unJugador = ll_get(pArrayListJugador, index);
					jug_getIdSeleccion(unJugador, &idJugador);
					printHeadboard();
					if(idJugador!=0)
					{
						printOneSummonedPlayer(unJugador, pArrayListSeleccion);
					}
					else{
						printOnePlayer(unJugador);
					}
					printf("|==============================================================================================================|\n");
					utn_getNumberInt(&edit,"\n\n1. Modificar nombre completo\n2. Modificar edad\n3. Modificar posicion\n4. Modificar nacionalidad\n ->: ","\nIngrese una opcion valida...",1,4,200);
					switch(edit)
					{
						case 1:
							utn_getString(auxNombre, "\nIngrese nombre completo: ", "\nHa ocurrido un problema en la carga del nombre...",30, 150);
							jug_setNombreCompleto(unJugador, auxNombre);
							break;
						case 2:
							utn_getNumberInt(&auxEdad, "\nIngrese edad: ", "\nIngrese una edad dentro de los parametros...(16-50)", 16, 50, 150);
							jug_setEdad(unJugador, auxEdad);
							break;
						case 3:
							utn_getString(auxPosicion, "\nIngrese posicion: ", "\nHa ocurrido un problema en la carga de la posicion...",30, 150);
							jug_setPosicion(unJugador, auxPosicion);
							break;
						case 4:
							utn_getString(auxNacionalidad, "\nIngrese nacionalidad: ", "\nHa ocurrido un problema en la carga de la nacionalidad...",30, 150);
							jug_setNacionalidad(unJugador, auxNacionalidad);
							break;
					}
					printHeadboard();
					if(idJugador!=0)
					{
						printOneSummonedPlayer(unJugador, pArrayListSeleccion);
					}
					else{
						printOnePlayer(unJugador);
					}
					printf("|==============================================================================================================|\n");
				}
		}else{
    		puts("\nPrimero tenes que hacer la carga del archivo .csv!");
		}
		retorno=0;
	}
	return retorno;
}
int compareByNacionality(void* jugadorUno,void* jugadorDos)
{
	int retorno=0; //si son iguales
	char nacionalidad[100];
	char nacionalidad2[100];

	jug_getNacionalidad(jugadorUno, nacionalidad);
	jug_getNacionalidad(jugadorDos, nacionalidad2);

	retorno = strcmp(nacionalidad, nacionalidad2);
	return retorno;
}
int compareByConference(void* seleccionUno,void* seleccionDos)
{
	int retorno=0;
	char confederacion[100];
	char confederacion2[100];

	selec_getConfederacion(seleccionUno, confederacion);
	selec_getConfederacion(seleccionDos, confederacion2);
	retorno = strcmp(confederacion, confederacion2);

	return retorno;
}
int compareByAge(void* jugadorUno,void* jugadorDos)
{
	int retorno=0;
	int edad;
	int edad2;
	jug_getEdad(jugadorUno, &edad);
	jug_getEdad(jugadorDos, &edad2);
	if(edad > edad2)
	{
		retorno=1;
	}
	if(edad < edad2)
	{
		retorno=-1;
	}
	return retorno;
}
int compareByName(void* jugadorUno,void* jugadorDos)
{
	int retorno=-1;
	char nombreCompleto[100];
	char nombreCompleto2[100];

	if(jugadorUno!=NULL && jugadorDos!=NULL)
	{
		jug_getNombreCompleto(jugadorUno, nombreCompleto);
		jug_getNombreCompleto(jugadorDos, nombreCompleto2);
		retorno = stricmp(nombreCompleto, nombreCompleto2);
	}
	return retorno;
}
