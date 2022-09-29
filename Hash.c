#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

void initHash(HashStruct *hashStruct){
    for (int i=0; i<MAX; i++){
        init(&(hashStruct->hashes[i]));
    }
    hashStruct-> size = 0;
}

bool isHashEmpty(HashStruct *hashStruct){
    return hashStruct->size==0;
}

int hash(char *key){
    int peso=0;

    for ((int) i = 0; key[i]!=0; i++)
    peso+=key[i]*(i+1); //adcionamos peso a cada letra
    
    return peso%MAX; //para retornar o resto da divisao
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal){
    if (!containsKey(hashStruct,key, equal)) 
    {
        int res= enqueue(&HashStruct->hashes[(key)], data);
        hashStruct->size+=res;
    }
    return 0;
    
}

