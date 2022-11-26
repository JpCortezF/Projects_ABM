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

/** reserva espacio de memoria para UN jugador
 *
 * @return retorna espacio para el nuevo jugador
 */
Jugador* jug_new();

/**
 * Recibe parametros char y los setters se encargan de castearlos al tipo que corresponda
 * @param idStr de tipo char donde se van a settear el ids
 * @param nombreCompletoStr tipo char donde se van a settear el nombres
 * @param edadStr tipo char donde se van a settear la edades
 * @param posicionStr tipo char donde se van a settear la posiciones
 * @param nacionalidadStr tipo char donde se van a settear la nacionalidades
 * @param idSeleccionStr tipo char donde se van a settear los id selecciones
 * @return retorna NULL como ERORR. Si esta OK retorna el Jugador con los campos setteados correctamente
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);

/**
 * Borra la estructura Jugador
 * @param this puntero a la estructura Jugador
 */
void jug_delete(Jugador* this);

/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura Jugador
 * @param id tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int jug_setId(Jugador* this,int id);
/**
 * Le asigna al puntero ID el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura Jugador
 * @param id puntero de tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int jug_getId(Jugador* this,int* id);

/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura Jugador
 * @param nombreCompleto tipo char
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
/**
 * Le asigna a nombreCompleto el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura Jugador
 * @param nombreCompleto tipo char
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura Jugador
 * @param posicion tipo char
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int jug_setPosicion(Jugador* this,char* posicion);
/**
 * Le asigna a posicion el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura Jugador
 * @param posicion tipo char
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int jug_getPosicion(Jugador* this,char* posicion);

/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura Jugador
 * @param nacionalidad tipo char
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad);
/**
 * Le asigna a nacionalidad el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura Jugador
 * @param nacionalidad tipo char
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura Jugador
 * @param edad tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int jug_setEdad(Jugador* this,int edad);
/**
 * Le asigna al puntero edad el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura Jugador
 * @param edad tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int jug_getEdad(Jugador* this,int* edad);

/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura Jugador
 * @param idSeleccion tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int jug_setIdSeleccion(Jugador* this,int idSeleccion);
/**
 * Le asigna al puntero idSeleccion el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura Jugador
 * @param idSeleccion tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

/**
 * Recorre la linkedlist y compara la igualdad con el id que llega por parametro
 * @param pArrayListJugador puntero a la LinkedList
 * @param id tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int searchPlayerById(LinkedList* pArrayListJugador, int id);

/**
 * Se le pide al usuario el ingreso de cada uno de los campos
 * @param pArrayListJugador puntero a la LinkedList
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int addPlayer(LinkedList* pArrayListJugador);

/**
 * abre un archivo binario, lo lee y despues sobreescribe sobre ese archivo
 * @param id tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int player_idGenerator(int* id);

/**
 * Se le pide al usuario que ingrese el ID del jugador a modificar y lo muestra
 * @param pArrayListJugador puntero a la LinkedList
 * @param pArrayListSeleccion puntero a la LinkedList
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int editPlayer(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * Se le pide al usuario que ingrese el ID del jugador a eliminar y lo muestra
 * @param pArrayListJugador puntero a la LinkedList
 * @param pArrayListSeleccion puntero a la LinkedList
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int removePlayer(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * Compara por nacionalidad
 * @param jugadorUno puntero a void
 * @param jugadorDos puntero a void
 * @return retorna lo devuelto por la comparacion
 */
int compareByNacionality(void* jugadorUno, void* jugadorDos);
/**
 * compara por confederacion
 * @param seleccionUno puntero a void
 * @param seleccionDos puntero a void
 * @return retorna lo devuelto por la comparacion
 */
int compareByConference(void* seleccionUno,void* seleccionDos);
/**
 * compara por edad
 * @param jugadorUno puntero a void
 * @param jugadorDos puntero a void
 * @return retorna lo devuelto por la comparacion
 */
int compareByAge(void* jugadorUno,void* jugadorDos);
/**
 * compara por nombre
 * @param jugadorUno puntero a void
 * @param jugadorDos puntero a void
 * @return retorna lo devuelto por la comparacion
 */
int compareByName(void* jugadorUno,void* jugadorDos);

#endif // jug_H_INCLUDED
