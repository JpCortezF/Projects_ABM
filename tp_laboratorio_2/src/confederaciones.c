#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "confederaciones.h"
#include "biblio_Informes.h"
#include "bibliotecaJugadores.h"

void hardcodeoConfederacion(eConfederacion* confederaciones)
{
	int id[6]={100,101,102,103,104,105};
	char nombre[6][50]={"CONMEBOL","UEFA","AFC","CAF","CONCACAF","OFC"};
	char region[6][50]={"SUDAMERICA", "EUROPA", "ASIA", "AFRICA", "NORTE Y CENTRO AMERICA","OCEANIA"};
	int anioCreacion[6]={1916, 1954, 1954, 1957, 1961, 1966};
	int isEmpty[6]={0,0,0,0,0,0};
	if(confederaciones!=NULL)
	{
		for(int i=0; i<6; i++)
		{
			(*(confederaciones+i)).id = (*(id+i));
			strcpy((*(confederaciones+i)).nombre, (*(nombre+i)));
			strcpy((*(confederaciones+i)).region, (*(region+i)));
			(*(confederaciones+i)).anioCreacion = (*(anioCreacion+i));
			(*(confederaciones+i)).isEmpty = (*(isEmpty+i));
		}
	}
}
void imprimirCabecera(void)
{
	printf("===========================================================\n");
	printf("| ID   | NOMBRE   |      REGION            | AÑO CREACION |\n");
	printf("-----------------------------------------------------------\n");
}
void mostrarConfederacion(eConfederacion confederacion)
{
	printf("| %3d  | %8s | %22s |    %4d      |\n", confederacion.id, confederacion.nombre, confederacion.region, confederacion.anioCreacion);

}
int listarConfederaciones(eConfederacion* confederaciones, int lenConf)
{
	int retorno=-1;

	if(confederaciones!=NULL && lenConf > 0)
	{
		imprimirCabecera();
		for(int i=0; i<lenConf; i++)
		{
			if((*(confederaciones+i)).isEmpty == 0)
			{
				mostrarConfederacion((*(confederaciones+i)));
			}
		}
		printf("===========================================================\n");
		retorno=0;
	}
	return retorno;
}
int regionDescripcion(eConfederacion* confederaciones, int regionMax, int lenConf, char* region)
{
	int retorno=-1;

	if(confederaciones!=NULL && region!=NULL && lenConf > 0)
	{
		for(int i=0; i<lenConf; i++)
		{
			if((*(confederaciones+i)).id == regionMax)
			{
				strcpy(region, (*(confederaciones+i)).region);
				break;
			}
		}
		retorno=0;
	}
	return retorno;
}
int nombreDescripcion(eConfederacion* confederaciones, int regionMax, int lenConf, char* nombre)
{
	int retorno=-1;

	if(confederaciones!=NULL && nombre!=NULL && lenConf > 0)
	{
		for(int i=0; i<lenConf; i++)
		{
			if((*(confederaciones+i)).id == regionMax)
			{
				strcpy(nombre, (*(confederaciones+i)).nombre);
				break;
			}
		}
		retorno=0;
	}
	return retorno;
}
int inicializarConfederacion(eConfederacion* confederaciones, int lenConf)
{
	int retorno=-1;

	if(confederaciones!=NULL && lenConf > 0)
	{
		for(int i=0; i<lenConf; i++)
		{
			(*(confederaciones+i)).isEmpty = 1;
		}
		retorno=0;
	}
	return retorno;
}
int buscarConfederacionLibre(eConfederacion* confederaciones, int lenConf)
{
	int indice=-1;

	if(confederaciones!=NULL && lenConf > 0)
	{
		for(int i=0; i<lenConf; i++)
		{
			if((*(confederaciones+i)).isEmpty == 1)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
int buscarConfederacionPorId(eConfederacion* confederaciones, int lenConf, int id)
{
	int indice=-1;

	if(confederaciones!=NULL && lenConf > 0)
	{
		for(int i=0; i<lenConf; i++)
		{
			if(((*(confederaciones+i)).isEmpty == 0) && ((*(confederaciones+i)).id == id))
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
int altaConfederacion(eConfederacion* confederaciones, int lenConf, int* idConfederacion)
{
	int retorno=-1;
	int indice;
	char auxNombre[50];
	char auxRegion[50];
	eConfederacion nuevaConfederacion;

	if(confederaciones !=NULL && idConfederacion!=NULL && lenConf > 0)
	{
		indice = buscarConfederacionLibre(confederaciones, lenConf);
		if(indice!=-1)
		{
			utn_getString(auxNombre, "\nIngrese nombre: ","\nIngrese un nombre mas corto...",15);
			strcpy(nuevaConfederacion.nombre, auxNombre);
			utn_getString(auxRegion, "\nIngrese region: ","\nIngrese un region mas corto...",15);
			strcpy(nuevaConfederacion.region, auxRegion);
			utn_getNumberInt(&nuevaConfederacion.anioCreacion, "\nIngrese anio de creacion: ", "\nError, ingrese un anio de creacion valido...",1800,2022,15);
			(*idConfederacion)++;
			nuevaConfederacion.isEmpty = 0;
			nuevaConfederacion.id = *idConfederacion;
			(*(confederaciones+indice)) = nuevaConfederacion;
		}
	}
	return retorno;
}
int bajaConfederacion(eConfederacion* confederaciones, int lenConf)
{
	int retorno=-1;
	int indice;
	int id;
	int confirmarBaja;
	if(confederaciones !=NULL && lenConf > 0)
	{
		listarConfederaciones(confederaciones, lenConf);
		utn_getNumberInt(&id,"\nIngrese ID del jugador: ","\nExcede los parametros posibles...\n",1,30000,10);
		indice = buscarConfederacionPorId(confederaciones, lenConf, id);
		if(indice==-1)
		{
			printf("\nNo hay una conferencia con el ID: %d\n", id);
		}
		else{
			imprimirCabecera();
			mostrarConfederacion((*(confederaciones+indice)));
			printf("===========================================================\n");
			utn_getNumberInt(&confirmarBaja, "\n1. Confirmar baja\n2. Cancelar baja\n Ingrese opcion: ","\nERROR, ingrese una opcion valida...\n",1,2,10);
			switch(confirmarBaja)
			{
				case 1:
					(*(confederaciones+indice)).isEmpty = 1;
					printf("\n!Baja exitosa!\n");
					break;
				case 2:
					printf("\nBaja cancelada...\n");
					break;
			}
			listarConfederaciones(confederaciones, lenConf);
		}

		retorno=0;
	}
	return retorno;
}
int modifcarConfederacion(eConfederacion* confederaciones, int lenConf)
{
	int retorno=-1;
	int id;
	int indice;
	int modificacion;
	eConfederacion confederacionModificada;
	if(confederaciones !=NULL && lenConf > 0)
	{
		listarConfederaciones(confederaciones, lenConf);
		utn_getNumberInt(&id,"\nIngrese ID de la conferencia: ","\nExcede los parametros posibles...\n",1,30000,10);
		indice = buscarConfederacionPorId(confederaciones, lenConf, id);
		if(indice==-1)
		{
			printf("\nNo hay una conferencia con el ID: %d\n", id);
		}
		else{
			imprimirCabecera();
			mostrarConfederacion((*(confederaciones+indice)));
			printf("===========================================================\n");
			utn_getNumberInt(&modificacion, "\n1. Modificar nombre\n2. Modificar region\n3. Modificar anio de creacion\n4. SALIR\n Ingrese una opcion: ","\nERROR, ingrese una opcion valida...\n",1,4,15);
			switch(modificacion)
			{
				case 1:
					utn_getString(confederacionModificada.nombre, "\nNuevo nombre: ", "\nIngrese un nombre mas corto...",15);
					strcpy((*(confederaciones+indice)).nombre, confederacionModificada.nombre);
					break;
				case 2:
					utn_getString(confederacionModificada.region, "\nNueva region: ", "\nIngrese un nombre mas corto...",15);
					strcpy((*(confederaciones+indice)).region, confederacionModificada.region);
					break;
				case 3:
					utn_getNumberInt(&confederacionModificada.anioCreacion, "\nIngrese nuevo anio de creacion: ", "\nError, ingrese una opcion valida...",1800,2022,15);
					(*(confederaciones+indice)).anioCreacion = confederacionModificada.anioCreacion;
					break;
					printf("\n!Modificacion exitosa!\n");
			}
		}
		listarConfederaciones(confederaciones, lenConf);
		retorno=0;
	}
	return retorno;
}
