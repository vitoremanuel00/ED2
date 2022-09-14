# ifndef DataStructure_LinkedList_h
# define  DataStructure_LinkedList_h

#include <stdbool.h>

typedef  struct node {
    void *data;
    struct node *next;
}node;

typedef  struct LinkedList{
    node *first;
    int size;
}LinkedList;

typedef  bool (*compare)( void*, void*);

void  init (LinkedList *list);              //inicializa a lista
bool  isEmpty (LinkedList *list);           //verifica se a fila esta vazia
int  enqueue (LinkedList *list, void *data);//insere no final
void* dequeue (LinkedList *list);           //remove do inicio
void* first(LinkedList *list);             //consulta o primeiro da fila 
void* last (LinkedList *list);              //consulta o ultimo da fila
int  push (LinkedList *list, void *data);   //insere no topo da pilha
void* pop (LinkedList *list);               //remove do topo da pilha
void* top (LinkedList *list);               //mostra quem esta no topo da pilha
int  indexOf (LinkedList *list, void *data, compare igual);//descobre a posiçao de um elemento especifico
void* getPos (LinkedList *list, int pos);   //busca dado em uma posiçao especifica
node* getNodeByPos (LinkedList *list, int pos);//retorna o endereço do nó em uma posicao determinada
int  add (LinkedList *list, int pos, void *data);//adciona em qualquer posiçao
int  addAll (LinkedList *listDest, int pos, LinkedList *listSource);//adciona varios elemneots a partir de qualquer posiçao
void* removePos (LinkedList *list, int pos);//remove o dado de uma determinada posiçao
bool   removeData (LinkedList *lista, void *data, compare equal);//remove determinado dado da lista
# endif 
