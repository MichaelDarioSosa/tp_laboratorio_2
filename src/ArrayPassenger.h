/*
 * ArrayPassenger.h
 *
 *  Created on: 7 may. 2022
 *      Author: micha
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define LEN_NAME 51
#define CANT 10

typedef struct{
char code[CANT]; //1100, 1200, 1300
char statusFlight[LEN_NAME]; // activo , demorado, cancelado
}Status;

typedef struct{
int code; //1 2 3
char descripcion[LEN_NAME]; //ocacional frecuente
}typePassenger;

typedef struct{
int id;
char name[LEN_NAME];
char lastName[LEN_NAME];
float price;
char flycode[CANT]; //
int typePassenger;
int isEmpty;
}Passenger;

typePassenger TipoDePasajero[3];
Status EstadoDeVuelo[5];

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addPassenger(Passenger* list, int len, int id, char name[],
				 char lastName[],float price,int typePassenger, char flycode[]);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order);
/** \brief check if there is a passenger
*
* \param list Passenger*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - our position
*
*/
int thereIsAPassenger(Passenger* list, int len);

/**\
*\brief valida los datos ingresados. acumula los precios del array.
*\param array Array
*\param limite Limite del array
*\return Retorna 0 (EXITO) y -1 (ERROR)
*
*/
float fullImport(Passenger* list, int len);
/**\
*\brief valida los datos ingresados. realiza promedio de los precios ingresados
*\param array Array
*\param limite Limite
*\return Retorna 0 (EXITO) y -1 (ERROR)
*
*/
float average(Passenger* list, int len);
///valida los datos ingresados. realiza un conteo de los precios que estan por debajo del promedio
/// @param array array
/// @param limite longitud del array
/// @param valor a comparar
/// @return devuelve lo contabilizado o -1 en caso de error
int limitAverage(Passenger* list, int len, float limitAverage);
/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassengerActive(Passenger* list, int length);
/// establece parametros por hardcodeo
/// @param list
/// @param len
void harcoderTypePassenger(typePassenger list[], int len);
/// establece parametros por hardcodeo
/// @param list
/// @param len
void harcoderStatus(Status list[], int len);
/// establece parametros por hardcodeo
/// @param list
/// @param len
void hardcoderPassenger(Passenger list[]);

#endif /* ARRAYPASSENGER_H_ */
