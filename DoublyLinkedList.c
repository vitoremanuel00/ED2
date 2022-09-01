#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"
#include "log.h"

void init(DoublyLinkedList *list) {
    Node *trashNode = (Node*)malloc(sizeof(Node));//reservando espaço na memória suficiente pra armazenar um nó.
    trashNode->data=NULL;//trashNode nao armazena nada, pq ele é descartavel
    trashNode->previous=trashNode;//antes do trash e depois é ele mesmo, quando a lista esta vazia
    trashNode->next=trashNode;
    list->first=trashNode;
    list->size=0;
}

int enqueue(DoublyLinkedList *list, void *data) {
    log_info("Adicionando elemento na fila");
    log_trace("enqueue ->");    
    Node *newNode=(Node*)malloc(sizofe(Node));
    if(newNode==NULL){
        log_error("memoria insuficiente");
        return-1;
    }
    newNode->data = data; //novo noh recebe um dado  
    newNode->next = list->first;// novo noh é o proximo da lista e assim se torna o primeiro
    newNode->previous = list->first->previous;// novo noh é tambem o anterior ao primeiro da lista
    list->first->previous->next = newNode; //novo noh é tambem o 
    list->first->previous = newNode;
    list-> size ++;
    return -1;
}

int dequeue(DoublyLinkedList *list, void *data){

}
