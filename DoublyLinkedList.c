#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"
#include "log.h"

void init(DoublyLinkedList *list) {
    Node *trashNode = (Node*)malloc(sizeof(Node));  //reservando espaço na memória suficiente pra armazenar um nó.
    trashNode->data=NULL;                           //trashNode nao armazena nada, pq ele é descartavel
    trashNode->previous=trashNode;                  //antes do trash e depois é ele mesmo, quando a lista esta vazia, ele é o elo de ligaçao entre incio e fim da lista
    trashNode->next=trashNode;                      //trash node é o próximo nó
    list->first=trashNode;                            //trashnode é o primeiro da lista, pq nao é um dado, pra que a lista nunca seja null.
    list->size=0;                                   //a lista tem tamanho 0 pq o trashnode nao guarda um dado
}

int enqueue(DoublyLinkedList *list, void *data) {
    log_info("Adicionando elemento na fila");
    log_trace("enqueue ->");    
    Node *newNode=(Node*)malloc(sizofe(Node));
    if(newNode==NULL){
        log_error("memoria insuficiente");
        return -1;
    }
    newNode->data = data;                       //novo noh recebe um dado  
    newNode->next = list->first;                // novonoh é o proximo da lista e assim se torna o primeiro
    newNode->previous = list->first->previous;  // novonoh é tambem o anterior ao primeiro da lista
    list->first->previous->next = newNode;      
    list->first->previous = newNode;            //o anterior do trashnode sera o novo nó, e o proximo do novo no é o trashnode
    list-> size ++;
    return 1;
}

int dequeue(DoublyLinkedList *list, void *data){
    if(isEmpty(list)) return NULL;               //se a lsita estiver vazia, retorna se nulo
    Node *trashNode = list-> first;             


}
