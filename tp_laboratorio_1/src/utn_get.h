#ifndef UTN_H_
#define UTN_H_

/*--------------------------------------------getString--------------------------------------------*/
/**
 * @brief Se le pide al usuario el ingreso de una cadena validando el rango
 *
 * @param pResult guarda la cadena
 * @param message mensaje al usuario
 * @param errorMessage error de mensaje al usuario
 * @param attemps intentos que dispone el usuario
 * @return retorna 0 si esta todo OK, -1 si hay un ERROR
 */
int utn_getString(char* pResult, char* message, char* errorMessage, int attemps);
/*--------------------------------------------getNumber--------------------------------------------*/
/**
 * @brief Se le pide al usario el ingreso de un float validando el rango
 *
 * @param pResult guarda el float ingresado por el usuario
 * @param message mensaje al usuario
 * @param errorMessage error de mensaje al usuario
 * @param min rango minimo
 * @param max rango maximo
 * @param attemps intentos que dispone el usuario
 * @return retorna 0 si esta todo OK, -1 si hay un ERROR
 */
int utn_getNumberFloat(float* pResult, char* message, char* errorMessage, float min, float max, int attemps);
/**
 * @brief Se le pide al usario el ingreso de un int validando el rango
 *
 * @param pResult guarda el int ingresado por el usuario
 * @param message mensaje al usuario
 * @param errorMessage error de mensaje al usuario
 * @param min rango minimo
 * @param max rango maximo
 * @param attemps intentos que dispone el usuario
 * @return retorna 0 si esta todo OK, -1 si hay un ERROR
 */
int utn_getNumberInt(int* pResult, char* message, char* errorMessage, int min, int max, int attemps);
/**
 * @brief cuando llega al final de la cadena cambia el \n por un '\0'
 *
 * @param cadena
 * @param len
 * @return retorna 0 si esta todo OK, -1 si hay un ERROR
 */
int myGets(char* cadena, int len);
/**
 * @brief recibe una cadena,
 * si la primera posicion del numero es un '+' o un '-' continue; Si la cadena va de '0' a '9' break.
 * @param cadena verifica que la cadena sea distinta de NULL y el largo mayor a 0, iniciamos un for en la posicion 0 y sale cuando la cadena sea distinto de '\0'
 * @return retorna 0 si esta todo OK, -1 si hay un ERROR
 */
int utn_isNan(char* cadena);
/**
 * @brief obtiene un numero entero
 *
 * @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @return retorna 0 si esta todo OK, -1 si hay un ERROR
 */
int getInt(int* pResultado);
/**
 * @brief obtiene un numero flotante
 *
 * @param pResult puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @return retorna 0 si esta todo OK, -1 si hay un ERROR
 */
int getFloat(float* pResult);
/**
 * @brief si la primera posicion del numero es un '+' o un '-' continue; Si la cadena va de '0' a '9' incluyendo un '.' retorna retorno.
 *
 * @param cadena verifica que la cadena sea distinta de NULL y el largo mayor a 0, iniciamos un for en la posicion 0 y sale cuando la cadena sea distinto de '\0'
 * @return retorna 0 si esta todo OK, -1 si hay un ERROR
 */
int isFloat(char* cadena);

#endif /* UTN_GET_H_ */



