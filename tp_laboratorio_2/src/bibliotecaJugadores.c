#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "bibliotecaJugadores.h"
#include "biblio_Informes.h"

void hardcodeoJugadores(eJugador* jugadores)
{
	int id[7]={1,2,3,4,5,6,7};
	char nombre[7][50]={"Julian Alvarez", "Lionel Messi", "Enzo Fernandez", "Franco Armani", "Nicolas Otamendi", "Nicolas De La Cruz", "Erling Haaland"};
	char posicion[7][50]={"Delantero", "Delantero", "Medio", "Arquero", "Defensor", "Medio", "Delantero"};
	int numeroCamiseta[7]={19,30,13,12,17,10,9};
	int idConfederacion[7]={101,101,101,100,101,100,101};
	float salario[7]={200000,600000,85000,70000,110000,120000,400000};
	int aniosContrato[7]={5,2,4,4,1,3,4};
	int isEmpty[7]={0,0,0,0,0,0,0};

	if(jugadores!=NULL)
	{
		for(int i=0; i<7; i++)
		{
			(*(jugadores+i)).id = (*(id+i));
			strcpy((*(jugadores+i)).nombre, (*(nombre+i)));
			strcpy((*(jugadores+i)).posicion, (*(posicion+i)));
			(*(jugadores+i)).numeroCamiseta = (*(numeroCamiseta+i));
			(*(jugadores+i)).idConfederacion = (*(idConfederacion+i));
			(*(jugadores+i)).salario = (*(salario+i));
			(*(jugadores+i)).aniosContrato = (*(aniosContrato+i));
			(*(jugadores+i)).isEmpty = (*(isEmpty+i));
		}
	}
}
int inicializarJugadores(eJugador* jugadores, int len)
{
	int retorno=-1;

	if(jugadores!=NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			(*(jugadores+i)).isEmpty = 1;
		}
		retorno=0;
	}
	return retorno;
}
int buscarJugadorLibre(eJugador* jugadores, int len)
{
	int indice=-1;

	if(jugadores!=NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if((*(jugadores+i)).isEmpty == 1)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
int buscarJugadorOcupado(eJugador* jugadores, int len)
{
	int indice=0;

	if(jugadores!=NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if((*(jugadores+i)).isEmpty == 0)
			{
				indice = -1;
				break;
			}
		}
	}
	return indice;
}
int altaJugador(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf, int* idJugador, int idConfederacion)
{
	int retorno=-1;
	int indice;
	char auxNombre[50];
	char auxPosicion[50];
	eJugador nuevoJugador;

	if(jugadores!=NULL && confederaciones !=NULL && idJugador!=NULL && len > 0 && lenConf > 0)
	{
		listarConfederaciones(confederaciones, lenConf);
		utn_getNumberInt(&nuevoJugador.idConfederacion, "\nIngrese un ID confederacion de los mostrados arriba: ", "\nError, ingrese una opcion valida...",100,idConfederacion,15);
		indice = buscarConfederacionPorId(confederaciones, lenConf, nuevoJugador.idConfederacion);
		if(indice==-1)
		{
			printf("\nNo hay una confederacion con el ID: %d\n", nuevoJugador.idConfederacion);
		}
		else
		{
			indice = buscarJugadorLibre(jugadores, len);
			if(indice!=-1)
			{
				utn_getString(auxNombre, "\nIngrese nombre: ","\nIngrese un nombre mas corto...",15);
				strcpy(nuevoJugador.nombre, auxNombre);
				utn_getString(auxPosicion, "\nIngrese posicion: ","\nIngrese una posicion mas corta...",15);
				strcpy(nuevoJugador.posicion, auxPosicion);
				utn_getShortInt(&nuevoJugador.numeroCamiseta, "\nIngrese dorsal: ", "\nIngrese un numero de camiseta mas chico (1-99)...",1,99,15);
				utn_getNumberFloat(&nuevoJugador.salario, "\nIngrese salario: ", "\nIngrese un salario valido...",20000, 9999999999, 15);
				utn_getShortInt(&nuevoJugador.aniosContrato, "\nIngrese años de contrato: ", "\nIngrese años de contrato validos...",1,15,15);
				(*idJugador)++;
				nuevoJugador.isEmpty = 0;
				nuevoJugador.id = *idJugador;

				(*(jugadores+indice)) = nuevoJugador;
			}
			else{
				printf("\nNo hay espacio para dar de alta mas jugadores...\n");
			}
		}
		retorno=0;
	}
	return retorno;
}
int buscarJugadorPorId(eJugador* jugadores, int len, int id)
{
	int indice=-1;

	if(jugadores!=NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(((*(jugadores+i)).isEmpty == 0) && ((*(jugadores+i)).id == id))
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
int bajarJugador(eJugador* jugadores,  eConfederacion* confederaciones, int len, int lenConf)
{
	int retorno=-1;
	int id;
	int indice;
	int confirmarBaja;
	if(jugadores!=NULL && confederaciones!=NULL && len > 0 && lenConf > 0)
	{
		if(buscarJugadorOcupado(jugadores, len) != 0)
		{
			ordenarPorId(jugadores, confederaciones, len, lenConf);
			utn_getNumberInt(&id,"\nIngrese ID del jugador: ","\nExcede los parametros posibles...\n",1,30000,10);
			indice = buscarJugadorPorId(jugadores, len, id);
			if(indice==-1)
			{
				printf("\nNo hay un jugador con el ID: %d\n", id);
			}
			else{
				imprimirCabeceraJugadores();
				mostrarJugador((*(jugadores+indice)), confederaciones, lenConf);
				printf("==========================================================================================================\n");
				utn_getNumberInt(&confirmarBaja, "\n1. Confirmar baja\n2. Cancelar baja\n Ingrese opcion: ","\nERROR, ingrese una opcion valida...\n",1,2,10);
				switch(confirmarBaja)
				{
					case 1:
						(*(jugadores+indice)).isEmpty = 1;
						printf("\n!Baja exitosa!\n");
						break;
					case 2:
						printf("\nBaja cancelada...\n");
						break;
				}
				listarJugadores(jugadores, confederaciones, len, lenConf);
			}
		}
		else{
			printf("\nNo hay jugadores cargados...\n");
		}
		retorno=0;
	}
	return retorno;
}
int modificarJugador(eJugador* jugadores,  eConfederacion* confederaciones, int len, int lenConf)
{
	int retorno=-1;
	int id;
	int indice;
	int modificarCampo;
	eJugador jugadorModificado;

	if(jugadores!=NULL && len > 0)
	{
		if(buscarJugadorOcupado(jugadores, len) != 0)
		{
			ordenarPorId(jugadores, confederaciones, len, lenConf);
			utn_getNumberInt(&id,"\nIngrese ID del jugador a modificar: ","\nExcede los parametros posibles...\n",1,30000,10);
			indice = buscarJugadorPorId(jugadores, len, id);
			if(indice==-1)
			{
				printf("\nNo hay un jugador con el ID: %d\n", id);
			}
			else{
				imprimirCabeceraJugadores();
				mostrarJugador((*(jugadores+indice)), confederaciones, lenConf);
				printf("==========================================================================================================\n");
				utn_getNumberInt(&modificarCampo, "\n1. Modificar nombre\n2. Modificar posicion\n3. Modificar numero de la camiseta\n4. Modificar confederacion\n5. Modificar salario\n6. Modificar años de contrato\n7. SALIR\n Ingrese opcion: ","\nERROR, ingrese una opcion valida...\n",1,7,15);
				switch(modificarCampo)
				{
					case 1:
						utn_getString(jugadorModificado.nombre, "\nNuevo nombre: ", "\nIngrese un nombre mas corto...",15);
						strcpy((*(jugadores+indice)).nombre, jugadorModificado.nombre);
						break;
					case 2:
						utn_getString(jugadorModificado.posicion, "\nNueva posicion: ", "\nIngrese una posicion mas corta...",15);
						strcpy((*(jugadores+indice)).posicion, jugadorModificado.posicion);
						break;
					case 3:
						utn_getShortInt(&jugadorModificado.numeroCamiseta, "\nNuevo dorsal: ", "\nIngrese un dorsal mas pequeño...",1,99,15);
						(*(jugadores+indice)).numeroCamiseta = jugadorModificado.numeroCamiseta;
						break;
					case 4:
						listarConfederaciones(confederaciones, lenConf);
						utn_getNumberInt(&jugadorModificado.idConfederacion, "\nIngrese un ID confederacion de los mostrados arriba: ", "\nError, ingrese una opcion valida...",100,105,15);
						(*(jugadores+indice)).idConfederacion = jugadorModificado.idConfederacion;
						break;
					case 5:
						utn_getNumberFloat(&jugadorModificado.salario,"\nNuevo salario: ", "\nERROR, ingrese nuevamente el salario...", 20000, 9999999999, 15);
						(*(jugadores+indice)).salario = jugadorModificado.salario;
						break;
					case 6:
						utn_getShortInt(&jugadorModificado.aniosContrato, "\nModificar años de contrato: ", "\nERROR, ingrese nuevamente los años de contrato..",1,15,15);
						(*(jugadores+indice)).aniosContrato = jugadorModificado.aniosContrato;
						break;
				}
				listarJugadores(jugadores, confederaciones, len, lenConf);
			}
		}
		else{
			printf("\nNo hay jugadores cargados...\n");
		}
		retorno=0;
	}
	return retorno;
}
void imprimirCabeceraJugadores(void)
{
	printf("==========================================================================================================\n");
	printf("| ID  |    NOMBRE              | POSICION  | N° CAMISETA | SUELDO     | CONFEDERACION | AÑOS DE CONTRATO |\n");
	printf("----------------------------------------------------------------------------------------------------------\n");
}
void mostrarJugador(eJugador jugador, eConfederacion* confederaciones, int lenConf)
{
	if(confederaciones!=NULL && lenConf > 0)
	{
		for(int i=0; i<lenConf; i++)
		{
			if(jugador.idConfederacion == (*(confederaciones+i)).id)
			{
				printf("|  %2d | %22s | %9s |     %2d      |  %9.2f | %8s      |        %2d        |\n", jugador.id, jugador.nombre, jugador.posicion, jugador.numeroCamiseta, jugador.salario, (*(confederaciones+i)).nombre, jugador.aniosContrato);
			}
		}
	}
}
int listarJugadores(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf)
{
	int retorno=-1;

	if(jugadores!=NULL && confederaciones !=NULL && len > 0 && lenConf > 0)
	{
		imprimirCabeceraJugadores();
		for(int i=0; i<len; i++)
		{
			if((*(jugadores+i)).isEmpty == 0)
			{
				for(int j=0; j<lenConf; j++)
				{
					if((*(jugadores+i)).idConfederacion == (*(confederaciones+j)).id)
					{
						mostrarJugador((*(jugadores+i)), confederaciones, lenConf);
					}
				}
			}
		}
		printf("==========================================================================================================\n");
		retorno=0;
	}
	return retorno;
}
int ordenarPorId(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf)
{
	int retorno=-1;
	eJugador auxJugador;

	if(jugadores!=NULL && confederaciones !=NULL && len > 0 && lenConf > 0)
	{
		for(int i=0; i<len-1; i++)
		{
			 if((*(jugadores+i)).isEmpty == 0)
			 {
				 for(int j=i+1; j<len; j++)
				 {
					 if((*(jugadores+i)).id > (*(jugadores+j)).id)
					 {
						 auxJugador = (*(jugadores+i));
						 (*(jugadores+i)) = (*(jugadores+j));
						 (*(jugadores+j)) = auxJugador;
					 }
				 }
			 }
		}
		listarJugadores(jugadores, confederaciones, len, lenConf);
		retorno=0;
	}
	return retorno;
}
