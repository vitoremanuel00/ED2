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
    
    if (isEmpty(list)) return NULL; //se a lsita estiver vazia, retorna se nulo

    Node *trash = list->first;
    Node *first = list->first->next;
    
    first->next->previous = trash;
    trash->next = first->next;
    
    void *data = first->data;

    free(first);
    list->size--;
    
    return data;
}

void* first(DoublyLinkedList *list) {
    return list->first->next->data;
}

void* last(DoublyLinkedList *list) {
    return list->first->previous->data;
}

int push(DoublyLinkedList *list, void *data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    
    newNode->next = list->first->next;
    newNode->previous = list->first;

    list->first->next->previous = newNode;
    list->first->next = newNode;
    
    list->size++;
    
    return 1;
}

void* pop(DoublyLinkedList *list) {
    return dequeue(list);
}

void* top(DoublyLinkedList *list) {
    return first(list);
}

bool isEmpty(DoublyLinkedList *list) {
    return (list->size==0);
}

int indexOf(DoublyLinkedList *list,void *data,compare equal) {
    if (isEmpty(list)) return -1;
    int count=0;
    Node *aux = list->first->next;
    
    while(aux!=list->first && !equal(aux->data,data)) {
        aux=aux->next;
        count++;
    }
    
    return (aux==list->first)?-1:count;
}

Node* getNodeByPos(DoublyLinkedList *list,int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL;
    Node *aux = list->first->next;
    for (int count=0;(aux!=list->first && count<pos);count++,aux=aux->next);
    return aux;
}

void* getPos(DoublyLinkedList *list,int pos) {
    Node *res = getNodeByPos(list,pos);
    return (res==NULL)?NULL:res->data;
}

int add(DoublyLinkedList *list, int pos, void *data) {
    Node *aux = getNodeByPos(list, pos);
    if (aux==NULL) return -2;
    
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    
    newNode->data = data;

    newNode->next = aux;
    newNode->previous = aux->previous;
    
    aux->previous->next = newNode;
    aux->previous = newNode;
    
    list->size++;
    
    return 1;
}

//REVISAR
int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource) {
    Node *aux = getNodeByPos(listDest, pos);
    if (aux==NULL) return -2;
    
    if (isEmpty(listSource)) return -1;
    
    listSource->first->previous->next = aux;
    listSource->first->next->previous = aux->previous;
    
    aux->previous->next = listSource->first->next;
    aux->previous = listSource->first->previous;
    
    listDest->size+=listSource->size;
    
    return listSource->size;
}

//REVISAR
void* removePos(DoublyLinkedList *list, int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL;
    
    Node *nodeRemove = getNodeByPos(list, pos);
    
    nodeRemove->previous->next = nodeRemove->next;
    nodeRemove->next->previous = nodeRemove->previous;
    
    void* dataRemove = nodeRemove->data;
    free(nodeRemove);
    list->size--;
    
    return dataRemove;
}

bool removeData(DoublyLinkedList *list, void *data, compare equal) {
    if (isEmpty(list)) return -1;
    
    Node *nodeRemove = list->first->next;

    while(nodeRemove!=list->first && !equal(nodeRemove->data,data))
        nodeRemove=nodeRemove->next;
    
    if (nodeRemove!=list->first) {
        nodeRemove->previous->next = nodeRemove->next;
        nodeRemove->next->previous = nodeRemove->previous;
        free(nodeRemove->data);
        free(nodeRemove);
        list->size--;
        return 1;
    } else {
        return 0;
    }
}

void show(DoublyLinkedList *list, printNode print) {
    Node *aux = list->first->next;
    while (aux!=list->first) {
        print(aux->data);
        aux=aux->next;
    }
    printf("\n");
}

void showMem(DoublyLinkedList *list) {
    printf("Trash Node: %p\n\n",list->first);
    Node *aux = list->first->next;
    printf("Node Addr  : Previous    - Data        - Next\n\n");
    while (aux!=list->first) {
        printf("%p: %p - %p - %p\n",aux, aux->previous, aux->data, aux->next);
        aux=aux->next;
    }
}