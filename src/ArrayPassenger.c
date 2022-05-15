/*
 * ArrayPassenger.c
 *
 *  Created on: 7 may. 2022
 *      Author: micha
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"


int initPassengers(Passenger* list, int len){
	int respuesta = -1;
	int i;
	if(list != NULL && len > 0){
		for(i=0; i<len; i++){
			list[i].isEmpty = 1;
		}
		respuesta = 0;
	}
	return respuesta;
}

int addPassenger(Passenger* list, int len, int id, char name[],char
		lastName[],float price,int typePassenger, char flycode[]){
	int bufferPosicion=-1;
	int retorno=-1;
	int i;

	if(list != NULL && len >0 && id >=0){
		for(i=0; i<len; i++){
			if(list[i].isEmpty == 1){
				bufferPosicion = i;
				break;
			}
		}
		if(bufferPosicion != -1){
			list[bufferPosicion].id = id;
			strcpy(list[bufferPosicion].name,name);
			strcpy(list[bufferPosicion].lastName,lastName);
			list[bufferPosicion].price = price;
			list[bufferPosicion].typePassenger = typePassenger;
			strcpy(list[bufferPosicion].flycode,flycode);
			list[bufferPosicion].isEmpty = 0;
			retorno = 0;
		}
	}
	return retorno;
}

int findPassengerById(Passenger* list, int len,int id){
	int respuesta = -1;
	int i;
	if(list != NULL && len > 0 && id >= 0){
		for(i=0; i<len; i++){
			if(list[i].id == id){
				respuesta= i;
				break;
			}
		}
	}
	return respuesta;
}

int removePassenger(Passenger* list, int len, int id){
	int respuesta = -1;
	int i;
	int bufferPosicion=-1;
	if(list != NULL && len> 0 && id >=0){
		for(i=0; i<len; i++){
			if(list[i].id == id){
				bufferPosicion = i;
				break;
			}
		}
		if(bufferPosicion < len && bufferPosicion >= 0 && list[bufferPosicion].isEmpty == 0){
		list[bufferPosicion].isEmpty = 1;
		respuesta = 0;
		}
	}
	return respuesta;
}

int sortPassengers(Passenger* list, int len, int order){
	int respuesta=-1;
	int flagSwap;
	int i;
	int auxCmp;
	Passenger buffer;
	if(list != NULL && len > 0){
		do{
			flagSwap=0;
			for (i=0;i<len-1; i++){
				respuesta = 0;
				if(list[i].isEmpty || list[i+1].isEmpty){
					continue;
				}
				auxCmp = (strncmp(list[i].lastName, list[i+1].lastName, len));
				if(order == 1){
					if( auxCmp > 0 ||
						(auxCmp == 0 && list[1].typePassenger > list[2].typePassenger)){
						flagSwap = 1;
						buffer= list[i];
						list[i] = list[i+1];
						list[i+1]=buffer;
					}
				}
				else{
					if(  auxCmp < 0 ||
						(auxCmp == 0 && list[1].typePassenger < list[2].typePassenger)){
						flagSwap = 1;
						buffer= list[i];
						list[i] = list[i+1];
						list[i+1]=buffer;
					}
				}
			 len--;
			}
		}while(flagSwap);
	}
	return respuesta;
}

int printPassenger(Passenger* list, int length){
		int respuesta = -1;
		int i;
		int j;
		char auxTypePassenger[51];
		char auxStatusFlight[51];
		if(list != NULL && length > 0){
			respuesta = 0;
			printf("+----+--------------------+--------------------+----------------+------------+--------------------+----------+\n");
			printf("|%4s|%20s|%20s|%10s|%12s|%20s|%10s|\n","ID","Apellido","Nombre","Tipo de pasajero","Cod de vuelo","Precio","Estado");
			printf("+----+--------------------+--------------------+----------------+------------+--------------------+----------+\n");
			for(i=0; i<length; i++){
				if(list[i].isEmpty == 0){
					for(j=0;j<5;j++){
						if(list[i].typePassenger == TipoDePasajero[j].code){
							strcpy(auxTypePassenger,TipoDePasajero[j].descripcion);
						}
						if(strcmp(list[i].flycode,EstadoDeVuelo[j].code)==0){
							strcpy(auxStatusFlight,EstadoDeVuelo[j].statusFlight);
						}

					}

					printf("|%4d|%20s|%20s|%16s|%12s|%20f|%10s|\n",list[i].id, list[i].lastName, list[i].name, auxTypePassenger, list[i].flycode, list[i].price, auxStatusFlight);
				}
			}
			printf("+----+--------------------+--------------------+----------------+------------+--------------------+----------+\n");
		}
	return respuesta;
}

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order){
	int respuesta=-1;
	int flagSwap;
	int i;
	int auxCmp;
	Passenger buffer;
	if(list != NULL && len > 0){
		do{
			flagSwap=0;
			for (i=0;i<len-1; i++){
				respuesta = 0;
				if(list[i].isEmpty || list[i+1].isEmpty){
					continue;
				}
				auxCmp = strncmp(list[i].flycode,list[i+1].flycode,10);
				if(order == 1){
					if(auxCmp > 0 ||
					(auxCmp = 0 && list[i].typePassenger > list[i+1].typePassenger)){
					flagSwap=1;
					buffer=list[i];
					list[i]=list[i+1];
					list[i+1]=buffer;
					}
				}
				else{
					if(auxCmp < 0 ||
					(auxCmp = 0 && list[i].typePassenger < list[i+1].typePassenger)){
					flagSwap=1;
					buffer=list[i];
					list[i]=list[i+1];
					list[i+1]=buffer;
					}
				}
			}
			 len--;
		}while(flagSwap);
	}
	return respuesta;
}



int thereIsAPassenger(Passenger* list, int len){
	int i;
	int retorno=-1;
	if(list != NULL && len >0){
		for(i=0; i<len; i++){
			if(list[i].isEmpty == 0){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

float fullImport(Passenger* list, int len){
	float respuesta = -1;
	float buffer = 0;
	int i;
	if(list != NULL && len > 0){
		for(i=0;i<len;i++){
			if(list[i].isEmpty == 0){
				buffer = buffer + list[i].price;
			}
		}
		respuesta = buffer;
	}
return respuesta;
}

float average(Passenger* list, int len){
	float respuesta = -1;
	float buffer = 0;
	int i;
	int j=0;
	if(list != NULL && len > 0){
		for(i=0;i<len;i++){
			if(list[i].isEmpty == 0){
				buffer = buffer + list[i].price;
			     j++;
			}
		}
		respuesta = buffer / j;
	}
return respuesta;
}
int limitAverage(Passenger* list, int len, float limitAverage){
	int retorno=-1;
	int contador=0;
	int i;
	if(list != NULL && limitAverage > 0 && len >=0){
		for(i=0;i<len;i++){
			if(list[i].price < limitAverage && list[i].isEmpty == 0){
				contador++;
			}
		}
		retorno=contador;
	}
	return retorno;
}

int printPassengerActive(Passenger* list, int length){
		int respuesta = -1;
		int i;
		int j;
		char auxTypePassenger[51];
		char auxStatusFlight[51];
		if(list != NULL && length > 0){
			respuesta = 0;
			printf("+----+--------------------+--------------------+----------------+------------+--------------------+----------+\n");
			printf("|%4s|%20s|%20s|%10s|%12s|%20s|%10s|\n","ID","Apellido","Nombre","Tipo de pasajero","Cod de vuelo","Precio","Estado");
			printf("+----+--------------------+--------------------+----------------+------------+--------------------+----------+\n");
			for(i=0; i<length; i++){
				if(list[i].isEmpty == 0){
					for(j=0;j<6;j++){
						if(list[i].typePassenger == TipoDePasajero[j].code){
							strcpy(auxTypePassenger,TipoDePasajero[j].descripcion);
						}
						if(strcmp(list[i].flycode,EstadoDeVuelo[j].code)==0){
							strcpy(auxStatusFlight,EstadoDeVuelo[j].statusFlight);
						}

					}
					printf("|%4d|%20s|%20s|%16s|%12s|%20f|%10s|\n",list[i].id, list[i].lastName, list[i].name, auxTypePassenger, list[i].flycode, list[i].price, auxStatusFlight);
					}
				strcpy(auxTypePassenger,"Sin Dato");
				strcpy(auxStatusFlight,"Sin Dato");
			}
			printf("+----+--------------------+--------------------+----------------+------------+--------------------+----------+\n");
		}
	return respuesta;
}


void harcoderStatus(Status list[], int len){
	char codigo[5][100]= {"vuelo0001","vuelo0002","vuelo0003","vuelo0004","vuelo0005"};
	char descripcion[5][51]={"Activo","Demorado","Cancelado","Activo","Activo"};
	int i;

	 for(i=0;i<len;i++)
	 {
		 strncpy(list[i].code,codigo[i],CANT);
		 strcpy(list[i].statusFlight , descripcion[i]);
	 }
 }

void harcoderTypePassenger(typePassenger list[], int len){
	int codigo[3]= {1,2,3};
	char descripcion[3][51]={"Ocasional","Poco frecuente","Frecuente"};
	int i;

	 for(i=0;i<len;i++)
	 {
		 list[i].code = codigo[i];
		 strcpy(list[i].descripcion , descripcion[i]);
	 }

 }

void hardcoderPassenger(Passenger list[]){

	int id [5] = {1990,1991,1992,1993,1994};
	char name[5][51] = {"Juan","Maria","Ana","Pedro","Jorge"};
	char lastName[5][51] = {"Villareal","Ortiz","Coronel","Saucedo","Pinto"};
	float price[5] = {142456.25, 120325.12, 123478.23, 101325.96, 96321.32};
	char flycode[5][100] = {"vuelo0001","vuelo0002","vuelo0003","vuelo0004","vuelo0005"};
	int typePassenger[5] = {1,3,2,1,3};
	int isEmpty[5] = {0,0,0,0,0};
	int i;

	 for(i=0;i<5;i++)
	 {
		 list[i+1990].id = id[i];
		 strcpy(list[i+1990].name,name[i]);
		 strcpy(list[i+1990].lastName,lastName[i]);
		 list[i+1990].price = price[i];
		 strncpy(list[i+1990].flycode,flycode[i],CANT);
		 list[i+1990].typePassenger = typePassenger[i];
		 list[i+1990].isEmpty = isEmpty[i];

	 }


 }
