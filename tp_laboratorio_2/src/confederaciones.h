#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int isEmpty;
}eConfederacion;

/**
 * Harcodeo los campos de la entidad de jugadores
 * @param confederaciones un puntero de tipo eConfederacion
 */
void hardcodeoConfederacion(eConfederacion* confederaciones);
/**
 * Imprime la cabecera de los campos de la entidad de confederaciones
 */
void imprimirCabecera(void);
/**
 * Imprime los campos de la entidad confederacion
 * @param confederacion es una variable de tipo eConfederacion
 */
void mostrarConfederacion(eConfederacion confederacion);
/**
 * Recorre con un for la longitud del array de confederaciones y muestra solo si el campo isEmpty es 0
 * @param confederaciones un puntero de tipo eConfederacion
 * @param lenConf es la longitud del array de confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int listarConfederaciones(eConfederacion* confederaciones, int lenConf);
/**
 * Recorre con un for y comparo el entero regionMax con el id de confederaciones.
 * con un strcpy guardo en char* nombre el nombre de la region con mas jugadores
 * @param confederaciones un puntero de tipo eConfederacion
 * @param regionMax es un entero
 * @param lenConf es la longitud del array de confederaciones
 * @param region es un array de caracteres
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int regionDescripcion(eConfederacion* confederaciones, int regionMax, int lenConf, char* region);
/**
 * Recorre con un for y comparo el entero regionMax con el id de confederaciones.
 * con un strcpy guardo en char* nombre el nombre de la region con mas jugadores
 * @param confederaciones un puntero de tipo eConfederacion
 * @param regionMax es un entero
 * @param lenConf es la longitud del array de confederaciones
 * @param nombre es un array de caracteres
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int nombreDescripcion(eConfederacion* confederaciones, int regionMax, int lenConf, char* nombre);
/**
 * Inicializo el campo isEmpty de la entidad eConfederacion en 1(LIBRE)
 * @param confederaciones un puntero de tipo eConfederacion
 * @param lenConf es la longitud del array de confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int inicializarConfederacion(eConfederacion* confederaciones, int lenConf);
/**
 * Recorre con un for el campo isEmpty de confederaciones y en la primera posicion que encuentra hace un break
 * @param confederaciones un puntero de tipo eConfederacion
 * @param lenConf es la longitud del array de confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int buscarConfederacionLibre(eConfederacion* confederaciones, int lenConf);
/**
 * Recorre con un for la longitud de las confederaciones.
 * Compara el id recibido por parametro con el id de la entidad y devuelve la posicion de coindencia
 * @param confederaciones un puntero de tipo eConfederacion
 * @param lenConf es la longitud del array de confederaciones
 * @param id es una variable de tipo int
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int buscarConfederacionPorId(eConfederacion* confederaciones, int lenConf, int id);
/**
 * Se crea una nueva confederacion de tipo eConfederacion y se cargan todos los campos de la entidad
 * @param confederaciones un puntero de tipo eConfederacion
 * @param lenConf es la longitud del array de confederaciones
 * @param idConfederacion un puntero
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int altaConfederacion(eConfederacion* confederaciones, int lenConf, int* idConfederacion);
/**
 * Se le pide al usuario que ingrese un ID a modificar (valida que exista),
 * permitiendole dar de baja de la confederacion actualizando el valor de isEmpty a 1
 * @param confederaciones un puntero de tipo eConfederacion
 * @param lenConf es la longitud del array de confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int bajaConfederacion(eConfederacion* confederaciones, int lenConf);
/**
 * Se le pide al usuario que ingrese un ID a modificar (valida que exista),
 * permitiendole modificar todos los campos de la entidad eConfederacion
 * @param confederaciones un puntero de tipo eConfederacion
 * @param lenConf es la longitud del array de confederaciones
 * @return retorna -1 como ERROR y 0 como BIEN
 */
int modifcarConfederacion(eConfederacion* confederaciones, int lenConf);

#endif /* CONFEDERACIONES_H_ */
