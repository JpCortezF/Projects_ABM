#ifndef ADMINISTRAREQUIPO_H_
#define ADMINISTRAREQUIPO_H_

#define LEN 22
/**
 * Pide al usuario el ingreso de un costo, guarda el dato en un puntero
 * @param pHospedaje
 * @param pComida
 * @param pTransporte
 * @param pMantenimiento
 * @return retorna 0 si todo OK. retorna -1 si todo MAL.
 */
int calcularCosto(float* pHospedaje, float* pComida, float* pTransporte, float* pMantenimiento);
/**
 * Pide al usuario que ingrese la posicion, dorsal y confederacion del jugador y lo guarda en un puntero.
 * @param arquero
 * @param defensor
 * @param mediocampista
 * @param delantero
 * @param confederacionAfc
 * @param confederacionCaf
 * @param confederacionConcacaf
 * @param confederacionConmebol
 * @param confederacionUefa
 * @param confederacionOfc
 * @return retorna 0 si todo OK. retorna -1 si todo MAL.
 */
int cargarEquipo(int* arquero, int* defensor, int* mediocampista, int* delantero,  int* confederacionAfc, int* confederacionCaf, int* confederacionConcacaf, int* confederacionConmebol, int* confederacionUefa, int* confederacionOfc);
/**
 * Se le pide al usuario en un menu elegir la confederacion del jugador
 * @param confederacion
 * @param confederacionAfc
 * @param confederacionCaf
 * @param confederacionConcacaf
 * @param confederacionConmebol
 * @param confederacionEufa
 * @param confederacionOfc
 * @return retorna 0 si todo OK. retorna -1 si todo MAL.
 */
int elegirConfederacion(char* confederacion, int* confederacionAfc, int* confederacionCaf, int* confederacionConcacaf, int* confederacionConmebol, int* confederacionEufa, int* confederacionOfc);
/**
 *
 * @param porcentaje
 * @param sumaTotal
 * @param len
 * @return retorna 0 si todo OK. retorna -1 si todo MAL.
 */
int porcentajeTotal(float* porcentaje, int sumaTotal, int len);

#endif /* ADMINISTRAREQUIPO_H_ */
