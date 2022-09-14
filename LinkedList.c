# include <stdio.h>
# include <stdlib.h>
#include "LinkedList.h"
#include "log.h"


void init (LinkedList *list) { /* procedimento pra inserir no incio*/
    list -> first = NULL; //se o primeiro for nulo, a lista recebe tamanho 0
    list -> size = 0;   
}


int enqueue(LinkedList *list, void *data){ //inserindo no final da lista
    node *newnode = (node*)malloc(sizeof(node));

    if (newnode == NULL) {
        log_error("Memória insuficiente!");
        return -1;
    }

    newnode->data=data;
    newnode -> next = NULL;
    
//é o primeiro?
//verificando se a lista esta vazia
        if( isEmpty(list)){             //se o conteudo da lista for nulo, nao tem ninguem nessa posicao, mesmo que a inserçao seja no fim, o fim da lista é essa posiçao
            list -> first = newnode;    //se tiver vazia, basta isso que insere
        }
        else{                               //se a lista nao estiver vazia, precisamos de uma repetiçao para percorrer ate o ultimo no, pra fazer ele apontar pro novo
            node *aux = list->first;                    //ponteiro auxiliar para o primeiro no
            while (aux -> next != NULL)    //usar o ponteiro pra percorrer a lista,
                                            // enquanto existir um proximo ou nao for o ultimo a lista vai caminhar
                    aux = aux -> next;      //aux avança para o no seguinte
                    aux -> next = newnode;  //aux recebe o proximo que é nulo, e recebera o novo nó
            }
            list->size++; 
            return 1;
}

bool isEmpty(LinkedList *list) {
    return (list->size == 0);
}


void *first(LinkedList *list){             //consulta o primeiro da fila 
    if (isEmpty == NULL) return NULL ;
    list->first->data; //se tiver vazia retorna null, se nao, retorna o endereço de memoria do dado do 1º no.    
}
    

void* dequeue(LinkedList *list){      //remove do inicio
    if(isEmpty == NULL) return NULL; //RETORNA QUE NADA FOI REMOVIDO POIS A LISTA ESTA VAZIA    

    node *trashnode = list->first;       //variável que guarda o endereço do nó que será removido(no caso o primeiro nó da nossa lista)
    list -> first = list->first->next;//o proximo apos o primeiro, passara a ser o primeiro da lista
    //removendo dado do nó
    void *data=trashnode->data;//dado do no removido
    free(trashnode);
    list->size--;

    return data;
}

int  push (LinkedList *list, void *data){   //insere no topo da pilha
     node *newnode = (node*) malloc(sizeof(node));
    if (newnode==NULL) return -1;
    newnode->data= data;
    newnode->next = NULL;
    
    if (isEmpty(list))               //se a lista estiver vazia
        list->first = newnode;       //novo nó é o primeiro
    else {
        newnode->next = list->first; //o topo atual será o segundo da lista
        list->first = newnode;       //o novo nó será o topo
    }
    list->size++;
    return 1;


}


void* pop (LinkedList *list){         //remove do topo da pilha
    return dequeue(list);
}




