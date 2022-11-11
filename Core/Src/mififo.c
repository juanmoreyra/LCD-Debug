/*
 * mififo.c
 *
 *  Created on: 31 oct. 2022
 *      Author: Fede
 */
#include "mififo.h"


int mififo_haydatos(struct mififo_t *mf){
    return mf->idxr != mf->idxw;
}

void mififo_cargardato(struct mififo_t *mf, mififo_tipo_t dato){

    int prox = (mf->idxw+1)%MF_TAM;

    if(mf->idxr == prox){
        return;
    }
    else{
    mf->arr[mf->idxw] = dato;
    mf->idxw = prox;
    }

}

mififo_tipo_t mififo_leerdato(struct mififo_t *mf){
    if(mf->idxw == mf->idxr){
        return -1;
    }

    mififo_tipo_t dato = mf->arr[mf->idxr];
    mf->idxr = (mf->idxr+1)%MF_TAM;

    return dato;
}
