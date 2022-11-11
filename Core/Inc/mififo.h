/*
 * mififo.h
 *
 *  Created on: Oct 29, 2022
 *      Author: Fede
 */

#ifndef INC_MIFIFO_H_
#define INC_MIFIFO_H_

/*
 * Configurar tamaño de buffer
 * */
#define MF_TAM 20

/*
 * Configurar tipo de dato
 * */
typedef char mififo_tipo_t;

/*
 * Estructura mififo_t contiene el buffer de datos, el índice
 * de lectura y el de escritura. Debe declararse una copia
 * de esta estructura por cada buffer que se quiera implementar.
 * */
struct mififo_t {
	mififo_tipo_t arr[MF_TAM];
    int idxr;
    int idxw;

};

/* mififo_leerdato()
 * Devuelve el dato más antiguo del buffer (FIFO), quitándolo
 * de la lista y actualizando los índices.
 * Parámetros:
 *  - struct mififo_t *mf: referencia al buffer
 * Retorna:
 *  - mififo_tipo_t: El dato
 *  */
mififo_tipo_t mififo_leerdato(struct mififo_t *mf);

/* mififo_cargardato()
 * Almacena un dato en el buffer (FIFO), actualizando los índices.
 * Parámetros:
 *  - struct mififo_t *mf: referencia al buffer
 *  - mififo_tipo_t dato: Dato que se quiere almacenar, por valor
 *  */
void mififo_cargardato(struct mififo_t *mf, mififo_tipo_t dato);

/* mififo_haydatos()
 * Chequea si hay datos en el buffer
 * Parámetros:
 *  - struct mififo_t *mf: referencia al buffer
 * Returna:
 *  - int: 1 si hay datos, 0 si no hay.
 *  */
int mififo_haydatos(struct mififo_t *mf);




#endif /* INC_MIFIFO_H_ */
