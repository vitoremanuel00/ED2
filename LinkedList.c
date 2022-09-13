# include <stdio.h>
# include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

/* lista encadeada, inserindo no inicio */

typedef struct node{
    int data;
    struct node *proximo;  
}node;

/* procedimento pra inserir no incio*/

void init (LinkedList *list) { 
    list -> first = NULL;
    list -> size = 0;   
}

void enqueue(node *list, int num){ //inserindo no final da lista
    node *aux, *newnode = (node*)malloc(sizeof(node));

    if (newnode == NULL) return -1;{
        newnode -> data = data ;
        newnode -> next = NULL;
    }
//é o primeiro?
//verificando se a lista esta vazia
        if( isEmpty(list)){             //se o conteudo da lista for nulo, nao tem ninguem nessa posicao, mesmo que a inserçao seja no fim, o fim da lista é essa posiçao
            list -> first = newnode;    //se tiver vazia, basta isso que insere
        }
        else{                               //se a lista nao estiver vazia, precisamos de uma repetiçao para percorrer ate o ultimo no, pra fazer ele apontar pro novo
            aux = *list;                    //ponteiro auxiliar para o primeiro no
            while (aux -> next != NULL){    //usar o ponteiro pra percorrer a lista,
                                            // enquanto existir um proximo ou nao for o ultimo a lista vai caminhar
                    aux = aux -> next;      //aux avança para o no seguinte
                    aux -> next = newnode;  //aux recebe o proximo que é nulo, e recebera o novo nó
            }
        }
    else{
        printf("erro ao alocar memoria");
    }
    
}
int main(){


}