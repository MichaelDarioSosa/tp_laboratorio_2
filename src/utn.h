/*
 * utn.h
 *
 *  Created on: 7 may. 2022
 *      Author: micha
 */

#ifndef UTN_H_
#define UTN_H_


/*
*\brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
*\param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
*\param mensaje Es el mensaje a ser mostrado
*\param mensajeError Es el mensaje de Error a ser mostrado
*\param minimo Es el numero maximo a ser aceptado
*\param maximo Es el minimo minimo a ser aceptado
*\return Retorna 0 si se obtuvo el numero y -1 si no
*/
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/*
*\brief Solicita un numero flotante al usuario, leuego de verificarlo devuelve el resultado
*\param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
*\param mensaje Es el mensaje a ser mostrado
*\param mensajeError Es el mensaje de Error a ser mostrado
*\param minimo Es el numero minimo a ser aceptado
*\return Retorna 0 si se obtuvo el numero flotante y -1 si no
*/
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, int reintentos);

/*
*\brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
*\param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
*\param longitud Es la longitud del array resultado
*\param mensaje Es el mensaje a ser mostrado
*\param mensajeError Es el mensaje de Error a ser mostrado
*\param reintentos Cantidad de reintentos
*\return Retorna 0 si se obtuvo el numero flotante y -1 si no
*/
int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);

/*
*\brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
*\param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
*\param longitud Es la longitud del array resultado
*\param mensaje Es el mensaje a ser mostrado
*\param mensajeError Es el mensaje de Error a ser mostrado
*\param reintentos Cantidad de reintentos
*\return Retorna 0 si se obtuvo el numero flotante y -1 si no
*/
int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);
/*
*\brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de longitud - 1' caracteres.
*\param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
*\param longitud Define el tamaño de cadena
*\return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
int myGets (char* cadena, int longitud);
/*
*\brief Solicita un codigo al usuario, luego de verificarlo devuelve el resultado
*\param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
*\param longitud Es la longitud del array resultado
*\param mensaje Es el mensaje a ser mostrado
*\param mensajeError Es el mensaje de Error a ser mostrado
*\param reintentos Cantidad de reintentos
*\return Retorna 0 si se obtuvo el numero flotante y -1 si no
*/
int utn_getFlyCode(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos);


#endif /* UTN_H_ */
