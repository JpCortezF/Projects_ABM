#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

void printHeadboard(void);
void printHeadboardSeleccionado(void);

void printOnePlayer(Jugador* unJugador);
int printListPlayers(LinkedList* pArrayListJugador);

void printOneSummonedPlayer(Jugador* unJugador, LinkedList* pArrayListSeleccion);
int printSummonedPlayers(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

int searchPlayerById(LinkedList* pArrayListJugador, int id);

int addPlayer(LinkedList* pArrayListJugador);
int player_idGenerator(int* id);

int removePlayer(LinkedList* pArrayListJugador);
int editPlayer(LinkedList* pArrayListJugador);

int compareByNacionality(void* jugadorUno, void* jugadorDos);
int compareByConference(void* seleccionUno,void* seleccionDos);

int compareByAge(void* jugadorUno,void* jugadorDos);
int compareByName(void* jugadorUno,void* jugadorDos);

#endif // jug_H_INCLUDED
