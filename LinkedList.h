# ifndef DataStructure_LinkedList_h
# define  DataStructure_LinkedList_h

# inclui < stdbool.h  >

typedef  struct Nó {
    void *dados;
    struct Nó *próximo;
}Não;

typedef  struct LinkedList {
    Nó *primeiro;
    tamanho inteiro ;
}LinkedList;

typedef  bool (*compare)( void *, void *);

void  init (LinkedList *list);
int  enqueue (LinkedList *list, void *data);
void * desenfileirar (LinkedList *list);
void * primeiro (LinkedList *list);
void * último (LinkedList *list);
int  push (LinkedList *list, void *data);
void * pop (LinkedList *list);
void * top (LinkedList *list);
bool  isEmpty (LinkedList *list);
int  indexOf (LinkedList *list, void *data, compare igual);
void * getPos (LinkedList *list, int pos);
Node* getNodeByPos (LinkedList *list, int pos);
int  add (LinkedList *list, int pos, void *data);
int  addAll (LinkedList *listDest, int pos, LinkedList *listSource);
void * removePos (LinkedList *list, int pos);
bool  removeData (LinkedList *lista, void *dados, comparando igual);

# endif
