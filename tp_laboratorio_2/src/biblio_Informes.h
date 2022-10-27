#ifndef BIBLIO_INFORMES_H_
#define BIBLIO_INFORMES_H_
#include "bibliotecaJugadores.h"
#include "confederaciones.h"

/**
 * Imprime ciertos campos de la cabecera principal
 */
void cabeceraJugadorEnConferencia(void);
/**
 * Imprime ciertos campos de la entidad principal
 * @param jugador una variable de tipo eJugador
 * @param confederaciones es un puntero de tipo eConfederacion
 * @param lenConf es la longitud del array de confederaciones
 */
void mostrarJugadorEnConferencia(eJugador jugador, eConfederacion* confederaciones, int lenConf);
/**
 * Por el metodo de burbujeo ordena la la lista de jugadores por doble criterio (confederacion y nombre)
 * @param jugadores es un puntero de tipo eJugador
 * @param confederaciones es un puntero de tipo eConfederacion
 * @param len es la longitud del array de jugadores
 * @param lenConf es la longitud del array de confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int ordenarPorConfederacionYNombre(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf);
/**
 * Imprime a los jugadores ordenados segun su confederacion
 * @param jugadores es un puntero de tipo eJugador
 * @param confederaciones es un puntero de tipo eConfederacion
 * @param len es la longitud del array de jugadores
 * @param lenConf es la longitud del array de confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int listadoPorConfederacion(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf);
/**
 * Promedia el salario de todos los jugadores cargados
 * @param jugadores es un puntero de tipo eJugador
 * @param confederaciones es un puntero de tipo eConfederacion
 * @param len es la longitud del array de jugadores
 * @param lenConf es la longitud del array de confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int promediarSalarios(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf);
/**
 * Recorre con un for la longitud del array de jugadores.
 * Ingresa cada vez que encuentre el campo isEmpty en 0 y el que el campo idConfederacion coincida con el entero pasado por parametro
 * @param jugadores es un puntero de tipo eJugador
 * @param len es la longitud del array de jugadores
 * @param idConfederacion un entero
 * @return retorna la cantidad de anios que haya contado
 */
int contarAnios(eJugador* jugadores, int len, int idConfederacion);
/**
 * Ingresa cada vez que encuentre el campo isEmpty en 0.
 * Guarda en la primera iteracion de i la cantidad de anios guardados en el primer campo de aniosContrato.
 * Despues comparo la posicion i con la posicion i-1 y si son distintas evaluo los aniosContrato de ese idConferencia
 * @param jugadores es un puntero de tipo eJugador
 * @param confederaciones es un puntero de tipo eConfederacion
 * @param len es la longitud del array de jugadores
 * @param lenConf es la longitud del array de confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int confederacionConMasAnios(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf);
/**
 * Cada vez que encuentre el campo isEmpty en 0 suma en un contador un jugador
 * Cuando coincide el idConferacion con el id de la conferencia suma un jugador a esa conferencia.
 * Despues para hacer el porcentaje simplemente divide la cantidad jugadores en esa conferencia por la cantidad de jugadores total
 * @param jugadores es un puntero de tipo eJugador
 * @param confederaciones es un puntero de tipo eConfederacion
 * @param len es la longitud del array de jugadores
 * @param lenConf es la longitud del array de confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int porcentajePorConfederacion(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf);
/**
 * Recorre con un for la longitud del array de jugadores.
 * Ingresa cada vez que encuentre el campo isEmpty en 0 y el que el campo idConfederacion coincida con el entero pasado por parametro
 * @param jugadores es un puntero de tipo eJugador
 * @param len es la longitud del array de jugadores
 * @param idConfederacion un entero
 * @return retorna la cantidad de jugadores en esa region
 */
int contarRegion(eJugador* jugadores, int len, int region);
/**
 * Ingresa cada vez que encuentre el campo isEmpty en 0.
 * Guarda en la primera iteracion de i la cantidad de anios guardados en el primer campo de aniosContrato.
 * Despues comparo la posicion i con la posicion i-1 y si son distintas evaluo la region de ese idConferencia
 * Una vez guardada la region con mas jugadores, recorro con un for el array de confederaciones y comparo
 * @param jugadores es un puntero de tipo eJugador
 * @param confederaciones es un puntero de tipo eConfederacion
 * @param len es la longitud del array de jugadores
 * @param lenConf es la longitud del array de confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int regionConMasJugadores(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf);

#endif /* BIBLIO_INFORMES_H_ */
