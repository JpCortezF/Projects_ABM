#include "LinkedList.h"
#include "Seleccion.h"
#include "Jugador.h"

#ifndef INFORMES_H_
#define INFORMES_H_

/**
 * Una cabecera para los campos de la estructura Jugadores
 */
void printHeadboard(void);

/**
 * Imprime UN jugador
 * @param unJugador puntero a la estructura Jugador
 */
void printOnePlayer(Jugador* unJugador);
/**
 * Recorre la lista y va imprimiendo los jugadores
 * @param pArrayListJugador puntero a la lista LinkedList
 * @param pArrayListSeleccion puntero a la lista LinkedList
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int printListPlayers(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
/**
 * Imprime UN jugador con su pais
 * @param unJugador puntero a la estructura Jugador
 * @param pArrayListSeleccion puntero a la lista LinkedList
 */
void printOneSummonedPlayer(Jugador* unJugador, LinkedList* pArrayListSeleccion);

int printSummonedPlayers(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/*-----------------------------------------------------------------Informes de selecciones------------------------------------------------------------------*/

/**
 * Una cabecera para los campos de la estructura Seleccion
 */
void printHeadboardSeleccion();

/**
 * Imprime UNA seleccion
 * @param unaSeleccion puntero a la estructura Seleccion
 */
void printOneSeleccion(Seleccion* unaSeleccion);

/**
 * Recorre la lista y va imprimiendo las selecciones
 * @param pArrayListSeleccion puntero a la lista LinkedList
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int printListSeleccion(LinkedList* pArrayListSeleccion);
#endif /* INFORMES_H_ */
