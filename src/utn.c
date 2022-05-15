/*
 * utn.c
 *
 *  Created on: 7 may. 2022
 *      Author: micha
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



static int getInt(int* pResultado);
static int esNumerica (char* cadena);
static int getFloat(float* pResultado);
static int esFlotante (char* cadena);
static int getNombre(char* pResultado, int longitud);
static int esNombre(char* cadena, int longitud);
static int esFlotante (char* cadena);
static int getFloat(float* pResultado);
static int getDescripcion(char* pResultado, int longitud);
static int esDescripcion(char* cadena, int longitud);
static int getString(char* cadena, int longitud);
static int getFlyCode(char* pResultado, int longitud);
static int esFlyCode(char* cadena);

/*
*\brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de 'longitud 1' caracteres.
*\param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
*\param longitud Define el tamaño de cadena
*\return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
static int getString(char* cadena, int longitud){
	int retorno=-1;
	char bufferString [4096];
	if (cadena != NULL && longitud > 0){
		fflush(stdin);
		if(fgets (bufferString, sizeof(bufferString), stdin) != NULL){
			if(bufferString [strnlen(bufferString, sizeof(bufferString))-1] == '\n'){
				bufferString [strnlen (bufferString, sizeof (bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= longitud){
					strncpy(cadena, bufferString, longitud);
					retorno=0;
			}
		}
	}
return retorno;
}


int myGets (char* cadena, int longitud){
	if (cadena != NULL && longitud >0 && fgets (cadena, longitud, stdin) == cadena){
		fflush(stdin); // fflush o fpurge
		if(cadena[strlen(cadena)-1] == '\n'){
			cadena [strlen(cadena)-1] = '\0';
		}
		return 0;
	}
return -1;
}
/*
*\brief Verifica si la cadena ingresada es numerica
*\param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
*\return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getInt(int* pResultado){
	int retorno=-1;
	char buffer [64];
	if(pResultado != NULL){
		if (myGets(buffer, sizeof (buffer))==0 && esNumerica(buffer)){
			*pResultado = atoi (buffer);
			retorno = 0;
		}
	}
return retorno;
}

/*
*\brief Verifica si la cadena ingresada es numerica
*\param cadena Cadena de caracteres a ser analizada
*\return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*
*/
static int esNumerica (char* cadena){
	int i=0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0){
		for(i=0; cadena[i] != '\0'; i++){
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+')){
				continue;
				if (cadena [i]<'0' || cadena[i]> '9' ){
					retorno = 0;
					break;
				}
			}
		}
	}
return retorno;
}


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int bufferInt;
	int retorno = -1;
	while(reintentos>=0){
		reintentos--;
		printf("%s", mensaje);
		if(getInt(&bufferInt) == 0){
			if (bufferInt >= minimo && bufferInt <= maximo){
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
return retorno;
}

/*
*\brief Verifica si la cadena ingresada es flotante
*\param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
*\return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
*
*/
static int getFloat(float* pResultado){
	int retorno=-1;
	char buffer [64];
	if(pResultado != NULL){
		if (myGets(buffer, sizeof (buffer))==0 && esFlotante(buffer)){
			*pResultado = atof (buffer);
			retorno = 0;
		}
	}
return retorno;
}

/*
*\brief Verifica si la cadena ingresada es flotante
*\param cadena Cadena de caracteres a ser analizada
*\return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
*
*/
static int esFlotante (char* cadena){
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;
	if(cadena != NULL && strlen(cadena) > 0){
		for(i=0; cadena[i] != '\0'; i++){
			if((i == 0 && cadena[i] != '+')&& (cadena[i]!= '.' && contadorPuntos == 0) && (cadena [i]<'0' || cadena[i]> '9')){
				retorno = 0;
				break;
			}
			if(cadena[i]== '.' && contadorPuntos == 0){
				contadorPuntos++;
			}
		}
	}
return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, int reintentos){
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0){
		reintentos--;
		printf("%s", mensaje);
		if(getFloat(&bufferFloat) == 0){
			if (bufferFloat >= minimo){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
return retorno;
}

/*
* \brief Obtiene un string valido como nombre
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
*
*/
static int getNombre(char* pResultado, int longitud){
	int retorno=-1;
	char buffer [4096];
	if(pResultado != NULL){
		if( getString (buffer, sizeof(buffer)) ==0 && esNombre(buffer, sizeof(buffer)) && strnlen (buffer, sizeof(buffer)) <longitud){
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
return retorno;
}


/*
* \brief Verifica si la cadena ingresada es un nombre valido
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
*/
static int esNombre(char* cadena, int longitud){
	int i=0;
	int retorno = 1;
	if(cadena != NULL && longitud > 0){
		for(i=0; cadena[i] != '\0' && i < longitud; i++)
			if((cadena[i]< 'A' || cadena [i]> 'Z') && (cadena[i] < 'a' || cadena [i]> 'z' )){
				retorno = 0;
				break;
			}
		}
return retorno;
}


int utn_getNombre(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos){
	char bufferString [4096];
	int retorno = -1;
	while(reintentos >= 0){
		reintentos--;
		printf("%s", mensaje);
		if(getNombre(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud){
			strncpy (pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
return retorno;
}


/*
* \brief Obtiene un string valido como descripcion
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
*
*/
static int getDescripcion(char* pResultado, int longitud){
	int retorno=-1;
	char buffer [4096];
	if(pResultado != NULL){
		if( getString (buffer, sizeof(buffer)) ==0 && esDescripcion(buffer, sizeof(buffer)) && strnlen (buffer, sizeof(buffer)) <longitud){
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
return retorno;
}


/*
* \brief Verifica si la cadena ingresada es una descripcion valida
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
*/
static int esDescripcion(char* cadena, int longitud){
	int i=0;
	int retorno = 1;
	if(cadena != NULL && longitud > 0){
		for(i=0; cadena[i] != '\0' && i < longitud; i++)
			if(cadena[i] != '.' && cadena[i] != ' ' &&( cadena[i]< 'A' || cadena [i]> 'Z') && (cadena[i] < 'a' || cadena [i]> 'z' )){
				retorno = 0;
				break;
			}
		}
return retorno;
}

int utn_getDescripcion(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos){
	char bufferString [4096];
	int retorno = -1;
	while(reintentos >= 0){
		reintentos--;
		printf("%s", mensaje);
		if(getDescripcion(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud){
			strncpy (pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
return retorno;
}

/*
* \brief Obtiene un string valido como descripcion
* \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
*
*/
static int getFlyCode(char* pResultado, int longitud){
	int retorno=-1;
	char buffer [4096];
	if(pResultado != NULL){
		if( getString (buffer, sizeof(buffer)) ==0 && esFlyCode(buffer)==1 && strnlen (buffer, sizeof(buffer)) <longitud){
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
return retorno;
}


/*
* \brief Verifica si la cadena ingresada es una descripcion valida
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
*/
static int esFlyCode(char* cadena){
	int retorno = 1;
	char flyCode[][51]={"vuelo0001","vuelo0002","vuelo0003","vuelo0004","vuelo0005"};
	if(cadena != NULL){
		if( strcmp(cadena,flyCode[0])!=0 && strcmp(cadena,flyCode[1])!=0 && strcmp(cadena,flyCode[2])!=0 &&
			strcmp(cadena,flyCode[3])!=0 && strcmp(cadena,flyCode[4])!=0){
			retorno = 0;
		}
	}
return retorno;
}

int utn_getFlyCode(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos){
	char bufferString [4096];
	int retorno = -1;
	while(reintentos >= 0){
		reintentos--;
		printf("%s", mensaje);
		if(getFlyCode(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < longitud){
			strncpy (pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
return retorno;
}
