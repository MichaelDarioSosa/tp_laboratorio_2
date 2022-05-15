/*
 ============================================================================
 Name        : Trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayPassenger.h"
#define CANT_PASAJEROS 2000

int main(void){
	setbuf(stdout, NULL);
	Passenger arrayPassenger[CANT_PASAJEROS];
	Passenger bufferPassenger;
	int opcion_A;
	int opcion_B;
	int opcion_C=0;
	int id=0;
	int initOk;
	int buscarId;
	int posId_A;
	int posId_B;
	float auxTotal;
	float auxPromedio;
	int auxContadorProm;
	int flag_A=0;



	initOk = initPassengers(arrayPassenger, CANT_PASAJEROS);
	do{
		if(utn_getNumero(&opcion_A, "\n1- Alta\n2- Modificar\n3- Baja\n4- Listar\n5- Carga forzada\n6- Salir",
									"Error, Ingrese una opcion valida", 1, 6, 4)==0 && initOk == 0){
			switch(opcion_A){
			case 1:
				if( utn_getNombre(bufferPassenger.name, LEN_NAME, "\nIngrese nombre: ","\nError, ingrese un nombre valido.\n", 4)==0 &&
					utn_getNombre(bufferPassenger.lastName, LEN_NAME, "\nIngrese apellido: ","\nError, ingrese un apellido valido.\n", 4)==0 &&
					utn_getNumeroFlotante(&bufferPassenger.price, "\nIngrese precio: ","\nError. Ingrese un precio valido\n", 0,4)==0 &&
					utn_getNumero(&bufferPassenger.typePassenger, "\nIngrese tipo de pasajero: \n1- Ocasional.\n2- Poco frecuente.\n3- Frecuente ","\nError ingrese una opcion valida\n", 1,3, 4)==0 &&
					utn_getFlyCode(bufferPassenger.flycode, CANT, "\nIngrese codigo de vuelo: vuelo0001, vuelo0002, vuelo0003, vuelo0004, vuelo0005\n","\nIngrese un codigo de vuelo correcto.\n", 10)==0){
					if(addPassenger(arrayPassenger, CANT_PASAJEROS, id, bufferPassenger.name, bufferPassenger.lastName,
							bufferPassenger.price,bufferPassenger.typePassenger, bufferPassenger.flycode)==0){
						printf("Se ah dado de alta correctamente");
						id++;
					}
				}
				break;
			case 2:
				if( utn_getNumero(&buscarId, "\nIngrese ID a MODIFICAR: \n", "\nError, ingreso un ID invalido\n", 0, id, 10)==0 &&
					utn_getNumero(&opcion_B, "\nModificar:\n1- Nombre\n2- Apellido\n3- Precio\n4- Tipo de pasajero\n5- Código de vuelo\n6-Salir","Error. ingreso una opcion invalido", 1, 6, 10)== 0 &&
					thereIsAPassenger(arrayPassenger, CANT_PASAJEROS) >= 0){
					posId_A= findPassengerById(arrayPassenger, CANT_PASAJEROS, buscarId);
					if(posId_A != -1){
						switch(opcion_B){
						case 1:
							if( utn_getNombre(arrayPassenger[posId_A].name, LEN_NAME,"\nIngrese nombre: ","\nError, ingreso un nombre invalido.\n", 10)==0){
								printf("Dato modificado correctamente.");
							}
							break;
						case 2:
							if( utn_getNombre(arrayPassenger[posId_A].lastName, LEN_NAME,"\nIngrese apellido: ","\nError, ingreso un apellido invalido.\n", 10)==0){
								printf("Dato modificado correctamente.");
							}
							break;
						case 3:
							if( utn_getNumeroFlotante(&arrayPassenger[posId_A].price,"\nIngrese precio: ","\nError. ingreso un precio invalido\n", 0,10)==0){
								printf("Dato modificado correctamente.");
							}
							break;
						case 4:
							if( utn_getNumero(&arrayPassenger[posId_A].typePassenger, "\nIngrese tipo de pasajero: \n1-Ocasional.\n2- Frecuente ","\nError ingrese una opcion valida\n", 1,2, 10)==0){
								printf("Dato modificado correctamente.");
							}
							break;
						case 5:
							if( utn_getFlyCode(arrayPassenger[posId_A].flycode, CANT, "\nIngrese codigo de vuelo: vuelo0001, vuelo0002, vuelo0003, vuelo0004, vuelo0005\n","\nIngrese un codigo de vuelo correcto.\n", 10)==0){
								printf("Dato modificado correctamente.");
							}
							break;
						case 6:
							printf("Usted ah salido");
							break;
						}
					}
					else{
						printf("No se encontro el ID");
					}
				}

				break;
			case 3:
				if( utn_getNumero(&buscarId, "\nIngrese ID a dar de BAJA: \n", "\nError, ingreso un ID invalido\n", 0, id, 10)==0 &&
					thereIsAPassenger(arrayPassenger, CANT_PASAJEROS) >= 0){
					posId_B= findPassengerById(arrayPassenger, CANT_PASAJEROS, buscarId);
					if(removePassenger(arrayPassenger, CANT_PASAJEROS, posId_B)!=-1 && posId_B != -1){
						printf("Se ah dado de BAJA correctamente.");
					}
				}
				else{
					printf("No se pudo dar de baja");
				}
				break;
			case 5:
				flag_A = 1;
				opcion_C = 1;
				hardcoderPassenger(arrayPassenger);
				if(flag_A != 1){
					break;
				}
			case 4:
				harcoderStatus(EstadoDeVuelo, 5);
				harcoderTypePassenger(TipoDePasajero, 3);
				if( flag_A ==1 || ( thereIsAPassenger(arrayPassenger, CANT_PASAJEROS) >= 0 &&
					utn_getNumero(&opcion_C,"Ingrese una opcion: \n1-Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n2-Total y promedio de los precios de los pasajes, y cantidad de pasajeros que superan el precio promedio.\n3-Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n", "\nError. opcion invalida\n", 1, 3, 10)== 0)){
					switch(opcion_C){
					case 1:
						sortPassengers(arrayPassenger, CANT_PASAJEROS, 1);
						printPassenger(arrayPassenger, CANT_PASAJEROS);
						if(flag_A != 1){
							break;
						}
					case 2:
						auxTotal = fullImport(arrayPassenger, CANT_PASAJEROS);
						auxPromedio = average(arrayPassenger, CANT_PASAJEROS);
						auxContadorProm = limitAverage(arrayPassenger, CANT_PASAJEROS, auxPromedio);
						printf("Importe total: %.2f\nPromedio: %.2f\nCantidad de precios que no superan el promedio: %d\n",auxTotal,auxPromedio,auxContadorProm);
						if(flag_A != 1){
							break;
						}
					case 3:
						sortPassengersByCode(arrayPassenger, CANT_PASAJEROS, 1);
						printPassengerActive(arrayPassenger, CANT_PASAJEROS);
							break;
					}
				}
				else{
					printf("No se puede enlistar");
				}
				break;
			case 6:
				printf("Usted ah salido");
				break;
			}
		}
	}while(opcion_A != 5);
	return EXIT_SUCCESS;
};
