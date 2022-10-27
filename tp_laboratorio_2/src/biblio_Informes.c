#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "biblio_Informes.h"

void cabeceraJugadorEnConferencia(void)
{
	printf("====================================================\n");
	printf("|    NOMBRE              | POSICION  | N° CAMISETA |\n");
	printf("----------------------------------------------------\n");
}
void mostrarJugadorEnConferencia(eJugador jugador, eConfederacion* confederaciones, int lenConf)
{
	if(confederaciones!=NULL && lenConf > 0)
	{
		for(int i=0; i<lenConf; i++)
		{
			if(jugador.idConfederacion == (*(confederaciones+i)).id)
			{
				printf("| %22s | %9s |     %2d      |\n", jugador.nombre, jugador.posicion, jugador.numeroCamiseta);
			}
		}
	}
}
int ordenarPorConfederacionYNombre(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf)
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
					 if((*(jugadores+i)).idConfederacion > (*(jugadores+j)).idConfederacion)
					 {
						 auxJugador = (*(jugadores+i));
						 (*(jugadores+i)) = (*(jugadores+j));
						 (*(jugadores+j)) = auxJugador;
					 }
					 else if(((*(jugadores+i)).idConfederacion == (*(jugadores+j)).idConfederacion) && (strncmp((*(jugadores+i)).nombre, (*(jugadores+j)).nombre, 51) > 0))
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
int listadoPorConfederacion(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf)
{
	int retorno=-1;

	if(jugadores!=NULL && confederaciones !=NULL && len > 0 && lenConf > 0)
	{
		for(int i=0; i<lenConf; i++)
		{
			if((*(confederaciones+i)).isEmpty == 0)
			{
				printf("\n====================================================\n");
				printf("|                 %8s                         |\n", (*(confederaciones+i)).nombre);
				printf("----------------------------------------------------\n");
				cabeceraJugadorEnConferencia();
				for(int j=0; j<len; j++)
				{
					if((*(jugadores+j)).isEmpty == 0)
					{
						if((*(jugadores+j)).idConfederacion == (*(confederaciones+i)).id)
						{
							mostrarJugadorEnConferencia((*(jugadores+j)), confederaciones, lenConf);
						}
					}
				}
			}
		}
		retorno=0;
	}
	return retorno;
}
int promediarSalarios(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf)
{
	int retorno=-1;
	float salario=0;
	int salarioMayorPromedio=0;
	int cantJugadores=0;
	float promedioSalario;

	if(jugadores!=NULL && confederaciones !=NULL && len > 0 && lenConf > 0)
	{
		for(int i=0; i<len; i++)
		{
			if((*(jugadores+i)).isEmpty == 0)
			{
				salario+=(*(jugadores+i)).salario;
				cantJugadores++;
			}
		}
		promedioSalario = (float)(salario / cantJugadores);
		imprimirCabeceraJugadores();
		for(int j=0; j<len; j++)
		{
			if((*(jugadores+j)).isEmpty == 0)
			{
				if((*(jugadores+j)).salario > promedioSalario)
				{
					mostrarJugador((*(jugadores+j)), confederaciones, lenConf);
					salarioMayorPromedio++;
				}
			}
		}
		printf("==========================================================================================================\n");
		printf("\nEl total de todos los salarios es: %.2f", salario);
		printf("\nEl salario promedio de los jugadores es: %.2f\n", promedioSalario);
		printf("\nLa cantidad de jugadores que exceden el promedio es: %d\n", salarioMayorPromedio);
		retorno=0;
	}
	return retorno;
}
int contarAnios(eJugador* jugadores, int len, int idConfederacion)
{
	int cantAnios=-1;

	if(jugadores!=NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if((*(jugadores+i)).isEmpty == 0 && (*(jugadores+i)).idConfederacion == idConfederacion)
			{
				cantAnios+=(*(jugadores+i)).aniosContrato;
			}
		}
	}
	return cantAnios;
}
int confederacionConMasAnios(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf)
{
	int retorno=-1;
	int auxAnios=0;
	int maxAnios;
	int aniosConfederacion;
	char confederacion[30];
	if(jugadores!=NULL && confederaciones !=NULL && len > 0 && lenConf > 0)
	{
		for(int i=0; i<len; i++)
		{
			if((*(jugadores+i)).isEmpty == 0)
			{
				if(i== 0)
				{
					auxAnios = contarAnios(jugadores, len, jugadores->idConfederacion);
					maxAnios = (*(jugadores)).idConfederacion;
					aniosConfederacion = auxAnios;
				}
				else if((*(jugadores+i)).idConfederacion != (*(jugadores+i-1)).idConfederacion)
				{
					auxAnios = contarAnios(jugadores, len, (*(jugadores+i)).idConfederacion);
					if(auxAnios > aniosConfederacion)
					{
						maxAnios = (*(jugadores+i)).idConfederacion;
						aniosConfederacion = auxAnios;
					}
				}
			}
		}
		if(maxAnios!=0)
		{
			nombreDescripcion(confederaciones, maxAnios, lenConf, confederacion);
			printf("\n-> La confederacion con mas anios de contrato es: %s", confederacion);
			printf("\n-> La cantidad de anios en %s es: %d\n", confederacion, aniosConfederacion);
		}
		else
		{
			printf("\nNo hay jugadores cargados...\n");
		}
	}
	return retorno;
}
int porcentajePorConfederacion(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf)
{
	int retorno=-1;
	int cantidadJugadores=0;
	int contador=0;
	float porcentaje;

	if(jugadores!=NULL && confederaciones !=NULL && len > 0 && lenConf > 0)
	{
		printf("|==========================|\n");
		printf("| Confederacion | Promedio |\n");
		printf("----------------------------\n");
		for(int i=0; i<lenConf; i++)
		{
			if((*(confederaciones+i)).isEmpty == 0)
			{
				for(int j=0; j<len; j++)
				{
					if((*(jugadores+j)).isEmpty == 0)
					{
						cantidadJugadores++;
						if((*(jugadores+j)).idConfederacion == (*(confederaciones+i)).id)
						{
							contador++;
						}
					}
				}
				porcentaje = ((float) contador / cantidadJugadores)* 100;
				printf("|    %8s   | %6.2f%% |\n", (*(confederaciones+i)).nombre, porcentaje);
				cantidadJugadores=0;
				contador=0;
			}
		}
		retorno=0;
	}
	return retorno;
}
int contarRegion(eJugador* jugadores, int len, int region)
{
	int cantRegion=-1;

	if(jugadores!=NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if((*(jugadores+i)).isEmpty == 0 && (*(jugadores+i)).idConfederacion == region)
			{
				cantRegion++;
			}
		}
	}
	return cantRegion;
}
int regionConMasJugadores(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf)
{
	int retorno=-1;
	int auxRegion=0;
	int regionMax;
	int jugadorEnRegion;
	if(jugadores!=NULL && confederaciones !=NULL && len > 0 && lenConf > 0)
	{
		for(int i=0; i<len; i++)
		{
			if((*(jugadores+i)).isEmpty == 0)
			{
				if(i == 0)
				{
					auxRegion = contarRegion(jugadores, len, jugadores->idConfederacion);
					regionMax = (*(jugadores)).idConfederacion;
					jugadorEnRegion = auxRegion;
				}
				else if((*(jugadores+i)).idConfederacion != (*(jugadores+i-1)).idConfederacion)
				{
					auxRegion = contarRegion(jugadores, len, (*(jugadores+i)).idConfederacion);
					if(auxRegion > jugadorEnRegion)
					{
						regionMax = (*(jugadores+i)).idConfederacion;
						jugadorEnRegion = auxRegion;
					}
				}
			}
		}
		if(regionMax!=0)
		{
			regionDescripcion(confederaciones, regionMax, lenConf, confederaciones->region);
			imprimirCabeceraJugadores();
			for(int j=0; j<lenConf; j++)
			{
				if((*(jugadores+j)).idConfederacion == regionMax)
				{
					mostrarJugador((*(jugadores+j)), confederaciones, lenConf);
				}
			}
			printf("\n-> La region con mas jugadores es %s\n", confederaciones->region);
		}
		else{
			printf("\nNo hay jugadores registrados...\n");
		}
		retorno=0;
	}
	return retorno;
}
