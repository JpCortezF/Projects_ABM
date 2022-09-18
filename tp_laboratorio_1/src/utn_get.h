#ifndef UTN_H_
#define UTN_H_

/*--------------------------------------------getString--------------------------------------------*/
int utn_getString(char* pResult, char* message, char* errorMessage, int attemps);
int utn_getChar(char* pResult);
int isAChar(char* string, int limit);

/*--------------------------------------------getNumber--------------------------------------------*/
int utn_getNumberFloat(float* pResult, char* message, char* errorMessage, float min, float max, int attemps);
int utn_getNumberInt(int* pResult, char* message, char* errorMessage, int min, int max, int attemps);
int myGets(char* cadena, int len);
int utn_isNan(char* cadena);
int getInt(int* pResultado);
int getFloat(float* pResult);
int isFloat(char* cadena);

/*--------------------------------------------Random Number--------------------------------------------*/

#endif /* UTN_GET_H_ */



