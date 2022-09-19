#ifndef ADMINISTRAREQUIPO_H_
#define ADMINISTRAREQUIPO_H_

#define LEN 22
/**
 * Pide al usuario el ingreso de un costo, guarda el dato en un puntero
 * @param pHospedaje Es un puntero que guarda el costo del hospedaje
 * @param pComida Es un puntero que guarda el costo de la comida
 * @param pTransporte Es un puntero que guarda el costo del transporte
 * @param pMantenimiento Es un puntero que guarda el costo del mantenimiento
 * @return retorna 0 si  OK. retorna -1 si hay un ERROR.
 */
int calcularCosto(float* pHospedaje, float* pComida, float* pTransporte, float* pMantenimiento);
/**
 * Pide al usuario que ingrese la posicion, dorsal y confederacion del jugador y lo guarda en un puntero.
 * @param arquero Es un puntero que guarda un jugador en la posicion arquero
 * @param defensor Es un puntero que guarda un jugador en la posicion defensor
 * @param mediocampista Es un puntero que guarda un jugador en la posicion mediocampista
 * @param delantero Es un puntero que guarda un jugador en la posicion delantero
 * @param confederacionAfc Es un puntero que cuenta las veces que se seleccione la confederacion
 * @param confederacionCaf Es un puntero que cuenta las veces que se seleccione la confederacion
 * @param confederacionConcacaf Es un puntero que cuenta las veces que se seleccione la confederacion
 * @param confederacionConmebol Es un puntero que cuenta las veces que se seleccione la confederacion
 * @param confederacionUefa Es un puntero que cuenta las veces que se seleccione la confederacion
 * @param confederacionOfc Es un puntero que cuenta las veces que se seleccione la confederacion
 * @return retorna 0 si  OK. retorna -1 si  MAL.
 */
int cargarEquipo(int* arquero, int* defensor, int* mediocampista, int* delantero,  int* confederacionAfc, int* confederacionCaf, int* confederacionConcacaf, int* confederacionConmebol, int* confederacionUefa, int* confederacionOfc);
/**
 * Se le pide al usuario en un menu elegir la confederacion del jugador
 * @param confederacion Es un puntero que guarda la confederacion seleccionada
 * @param confederacionAfc Es un puntero que guarda la confederacion
 * @param confederacionCaf Es un puntero que guarda la confederacion
 * @param confederacionConcacaf Es un puntero que guarda la confederacion
 * @param confederacionConmebol Es un puntero que guarda la confederacion
 * @param confederacionEufa Es un puntero que guarda la confederacion
 * @param confederacionOfc Es un puntero que guarda la confederacion
 * @return retorna 0 si  OK. retorna -1 si hay un ERROR.
 */
int elegirConfederacion(char* confederacion, int* confederacionAfc, int* confederacionCaf, int* confederacionConcacaf, int* confederacionConmebol, int* confederacionEufa, int* confederacionOfc);
/**
 * Guarda el porcentaje de la confederacion
 * @param porcentaje Es un puntero que guarda el porcentaje de la confederacion
 * @param sumaTotal Es un entero que guarda la cuenta de cada confederacion
 * @param len El 100% de jugadores posibles a cargar
 * @return retorna 0 si  OK. retorna -1 si hay un ERROR.
 */
int porcentajeTotal(float* porcentaje, int sumaTotal, int len);

#endif /* ADMINISTRAREQUIPO_H_ */
