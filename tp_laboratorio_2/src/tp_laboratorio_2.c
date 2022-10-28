/*
 ============================================================================
 Name        : tp_laboratorio_2.c
 Author      : Juan Pablo Cortez
 Description : Trabajo practico n°2 laboratorio
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "utn_get.h"
#include "bibliotecaJugadores.h"
#include "biblio_Informes.h"
#include "confederaciones.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int informes;
	int altas;
	int bajas;
	int modificacion;
	int idConfederacion=105;
	int idJugador=0; // EN CASO DE DESCOMENTAR EL HARDCODEO DE JUGADORES INICIALIZAR idJugador en 7.
	eJugador jugadores[LEN];
	eConfederacion confederaciones[CONF];

	inicializarJugadores(jugadores, LEN);
	inicializarConfederacion(confederaciones, CONF);
//	hardcodeoJugadores(jugadores); // EN CASO DE DESCOMENTAR EL HARDCODEO DE JUGADORES INICIALIZAR idJugador en 7.
	hardcodeoConfederacion(confederaciones);
	do
	{
		printf("\n        Menu de opciones          \n");
		printf("- - - - - - - - - - - - - - - - - - \n");
		printf("1. Menu de Altas\n");
		printf("2. Menu de Bajas\n");
		printf("3. Menu de Modificaciones\n");
		printf("4. Informes\n");
		printf("5. SALIR\n");
		utn_getNumberInt(&opcion, "Ingrese una opcion: ", "\nIngrese una opcion valida...\n",1,5,10);
		switch(opcion)
		{
			case 1:
				utn_getNumberInt(&altas,"\n- - - - - - - - - - - - - - - - - - \n1. Alta de jugadores.\n2. Alta de confederaciones.\n3. Volver al menu principal.\n\n Ingrese una opcion: ", "\nIngrese una opcion valida...",1,3,15);
				switch(altas)
				{
					case 1:
						altaJugador(jugadores, confederaciones, LEN, CONF, &idJugador, idConfederacion);
						break;
					case 2:
						altaConfederacion(confederaciones, CONF, &idConfederacion);
						break;
				}
				break;
			case 2:
				utn_getNumberInt(&bajas,"\n- - - - - - - - - - - - - - - - - - \n1. Baja de jugadores.\n2. Baja de confederaciones.\n3. Volver al menu principal.\n\n Ingrese una opcion: ", "\nIngrese una opcion valida...",1,3,15);
				switch(bajas)
				{
					case 1:
						bajarJugador(jugadores, confederaciones, LEN, CONF);
						break;
					case 2:
						bajaConfederacion(confederaciones, CONF);
						break;
				}
				break;
			case 3:
				utn_getNumberInt(&modificacion,"\n- - - - - - - - - - - - - - - - - - \n1. Modificar jugadores.\n2. Modificar confederaciones.\n3. Volver al menu principal.\n\n Ingrese una opcion: ", "\nIngrese una opcion valida...",1,3,15);
				switch(modificacion)
				{
					case 1:
						modificarJugador(jugadores, confederaciones, LEN, CONF);
						break;
					case 2:
						modifcarConfederacion(confederaciones, CONF);
						break;
				}
				break;
			case 4:
				if(buscarJugadorOcupado(jugadores, LEN) != 0)
				{
					utn_getNumberInt(&informes,"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n1. Listado de los jugadores ordenados alfabeticamente por nombre de confederacion y nombre de jugador.\n2. Listado de confederaciones con sus jugadores.\n3. Total y promedio de todos los salarios y cuantos jugadores cobran mas del salario promedio.\n"
					"4. Informar la confederacion con mayor cantidad de anios de contratos total.\n5. Informar porcentaje de jugadores por cada confederacion.\n6. Informar cual es la region con mas jugadores y el listado de los mismos.\n7. Volver al menu principal.\n Ingrese una opcion: ","\nIngrese una opcion valida...",1,7,15);
					switch(informes)
					{
						case 1:
							ordenarPorConfederacionYNombre(jugadores, confederaciones, LEN, CONF);
							break;
						case 2:
							listadoPorConfederacion(jugadores, confederaciones, LEN, CONF);
							break;
						case 3:
							promediarSalarios(jugadores, confederaciones, LEN, CONF);
							break;
						case 4:
							confederacionConMasAnios(jugadores, confederaciones, LEN, CONF);
							break;
						case 5:
							porcentajePorConfederacion(jugadores, confederaciones, LEN, CONF);
							break;
						case 6:
							regionConMasJugadores(jugadores, confederaciones, LEN, CONF);
							break;
					}
				}
				else{
					printf("\nPrimero tenes que cargar jugadores...\n");
				}
				break;
		}
	}while(opcion!=5);
	printf("\nGracias por usar el programa...\n");
	return 0;
}
