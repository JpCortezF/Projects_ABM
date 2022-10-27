#ifndef BIBLIOTECAJUGADORES_H_
#define BIBLIOTECAJUGADORES_H_
#include "confederaciones.h"

#define LEN 3000
#define CONF 3000
#define ERROR -1

typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

/**
 * Harcodeo los campos de la entidad de jugadores
 * @param jugadores un puntero de tipo eJugador
 */
void hardcodeoJugadores(eJugador* jugadores);
/**
 * Inicializo el campo isEmpty de la entidad eJugador en 1(LIBRE)
 * @param jugadores es un puntero de tipo eJugador
 * @param len es la longitud del array de jugadores
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int inicializarJugadores(eJugador* jugadores, int len);
/**
 * Recorre con un for el campo isEmpty de jugadores y en la primera posicion que encuentra libre hace un break
 * @param jugadores es un puntero de tipo eJugador
 * @param len es la longitud del array jugadores
 * @return retorna indice, que es la primera posicion libre
 */
int buscarJugadorLibre(eJugador* jugadores, int len);
/**
 * Recorre con un for el campo isEmpty de jugadores y en la primera posicion que encuentra un 0, hace un break
 * @param jugadores es un puntero de tipo eJugador
 * @param len es la longitud del array jugadores
 * @return retorna indice -1 si encontro un jugador y 0 si no encontro ningun jugador
 */
int buscarJugadorOcupado(eJugador* jugadores, int len);
/**
 * Recorre con un for el len de jugadores.
 * Compara el id recibido por parametro con el id de la entidad y devuelve la posicion de coindencia
 * @param jugadores es un puntero de tipo eJugador
 * @param len es la longitud del array jugadores
 * @param id es una variable de tipo int
 * @return retorna la posicion donde indice coincida con el parametro id
 */
int buscarJugadorPorId(eJugador* jugadores, int len, int id);
/***
 * Se crea un nuevoJugador de tipo eJugador y se cargan todos los campos de la entidad
 * @param jugadores es un puntero de tipo eJugador
 * @param confederaciones es un puntero de tipo eConfederacion
 * @param len es la longitud del array jugadores
 * @param lenConf es la longitud del array confederaciones
 * @param idJugador es un puntero que aumenta +1 cada vez que se llama a la funcion
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int altaJugador(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf, int* idJugador, int idConfederacion);
/**
 * Se le pide al usuario que ingrese un ID a modificar (valida que exista),
 * permitiendole dar de baja el jugador actualizando el valor de isEmpty a 1
 * @param jugadores es un puntero de tipo eJugador
 * @param confederaciones es un puntero de tipo eConfederacion
 * @param len es la longitud del array jugadores
 * @param lenConf es la longitud del array confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int bajarJugador(eJugador* jugadores,  eConfederacion* confederaciones, int len, int lenConf);
/**
 * Se le pide al usuario que ingrese un ID a modificar (valida que exista),
 * permitiendole modificar todos los campos de la entidad eJugador
 * @param jugadores es un puntero de tipo eJugador
 * @param confederaciones es un puntero de tipo eConfederacion
 * @param len es la longitud del array jugadores
 * @param lenConf es la longitud del array confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int modificarJugador(eJugador* jugadores,  eConfederacion* confederaciones, int len, int lenConf);
/**
 * Imprime la cabecera de jugadores
 */
void imprimirCabeceraJugadores(void);
/**
 * Imprime los todos campos del jugador cargado con su conferencia correspondiente
 * @param jugador una variable de tipo eJugador
 * @param confederaciones es un puntero de tipo eConfederacion
 * @param lenConf es la longitud del array de confederaciones
 */
void mostrarJugador(eJugador jugador, eConfederacion* confederaciones, int lenConf);
/**
 * Recorre con un for la longitud del array de jugadores y de confederaciones y muestra solo si el campo isEmpty es 0
 * @param jugadores es un puntero de tipo eJugador
 * @param confederaciones es un puntero de tipo eConfederacion
 * @param len es la longitud del array de jugadores
 * @param lenConf es la longitud del array de confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int listarJugadores(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf);
/**
 * Por el metodo de burbujeo ordena la la lista de jugadores por ID
 * @param jugadores es un puntero de tipo eJugador
 * @param confederaciones es un puntero de tipo eConfederacion
 * @param len es la longitud del array jugadores
 * @param lenConf es la longitud del array confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int ordenarPorId(eJugador* jugadores, eConfederacion* confederaciones, int len, int lenConf);

#endif /* BIBLIOTECAJUGADORES_H_ */
