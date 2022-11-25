#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

/** reserva espacio de memoria para UNA seleccion
 *
 * @return retorna espacio para la nueva seleccion
 */
Seleccion* selec_new();
/**
 * Recibe parametros char y los setters se encargan de castearlos al tipo que corresponda
 * @param idStr tipo de char donde se van a settear los ids
 * @param paisStr tipo char donde se van a settear los paises
 * @param confederacionStr tipo char donde se van a settear las confederaciones
 * @param convocadosStr tipo char donde se van a settear los convocados
 * @return retorna NULL como ERORR. Si esta OK retorna el Jugador con los campos setteados correctamente
 */
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
/**
 * Borra la estructura Seleccion
 * @param seleccion puntero a la estructura Seleccion
 */
void selec_delete(Seleccion* seleccion);
/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura Seleccion
 * @param id tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int selec_setId(Seleccion* this,int id);
/**
 * Le asigna al puntero ID el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura Seleccion
 * @param id puntero de tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int selec_getId(Seleccion* this,int* id);
/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura Seleccion
 * @param id tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int selec_setPais(Seleccion* this,char* pais);
/**
 * Le asigna al puntero ID el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura Seleccion
 * @param id puntero de tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int selec_getPais(Seleccion* this,char* pais);
/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura Seleccion
 * @param confederacion tipo char
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int selec_setConfederacion(Seleccion* this, char* confederacion);
/**
 * Le asigna a nombreCompleto el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura Seleccion
 * @param confederacion tipo char
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int selec_getConfederacion(Seleccion* this,char* confederacion);
/**
 * Le asigna a this en el campo que corresponda lo que recibe por parametro
 * @param this puntero a la estructura Seleccion
 * @param convocados tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int selec_setConvocados(Seleccion* this,int convocados);
/**
 * Le asigna a posicion el valor que tiene this en el campo que corresponda
 * @param this puntero a la estructura Seleccion
 * @param convocados puntero tipo int
 * @return retorna -1 como ERROR y 0 para indicar que no hubo errores
 */
int selec_getConvocados(Seleccion* this,int* convocados);

/**
 * recibe dos strings y compara las primeras 3 letras
 * @param pais tipo char
 * @param nacionalidad tipo char
 * @return retorna -1 como ERROR y 0 indicando que hubo exito
 */
int compareStrings(char* pais, char* nacionalidad);
/**
 * Se le pregunta al usuario para la convocatoria de un jugador o la desconvocatoria
 * @param pArrayListSeleccion puntero a la lista LinkedList de selecciones
 * @param pArrayListJugador puntero a la lista LinkedList de jugadores
 * @return retorna -1 como ERROR y 0 indicando que hubo exito
 */
int convocarJugadores(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador);

#endif // selec_H_INCLUDED
