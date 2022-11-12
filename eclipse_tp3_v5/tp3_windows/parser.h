#include "LinkedList.h"

#ifndef PARSER_H_
#define PARSER_H_


/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char* recibe la ruta del archivo
 * \param pArrayListJugador LinkedList*
 * \return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char* recibe la ruta del archivo
 * \param pArrayListJugador LinkedList*
 * \return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 */
int parser_JugadorFromBinary(FILE* pFile, LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char* recibe la ruta del archivo
 * \param pArrayListSeleccion LinkedList*
 * \return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);


#endif /* PARSER_H_ */
