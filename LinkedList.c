# include <stdio.h>
# include <stdlib.h>
#include "LinkedList.h"
#include "log.h"
// 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

void init (LinkedList *list) { /* procedimento pra inserir no incio*/
    list -> first = NULL; //se o primeiro for nulo, a lista recebe tamanho 0
    list -> size = 0;   
}


int enqueue(LinkedList *list, void *data){ //inserindo no final da lista
    node *newnode = (node*)malloc(sizeof(node));

    if (newnode == NULL) return -1;

    newnode->data=data;
    newnode -> next = NULL;
    
//é o primeiro?
//verificando se a lista esta vazia
        if( isEmpty(list)){             //se o conteudo da lista for nulo, nao tem ninguem nessa posicao, mesmo que a inserçao seja no fim, o fim da lista é essa posiçao
            list -> first = newnode;    //se tiver vazia, basta isso que insere
        }
        else{                               //se a lista nao estiver vazia, precisamos de uma repetiçao para percorrer ate o ultimo no, pra fazer ele apontar pro novo
            node *aux = list->first;                    //ponteiro auxiliar para o primeiro no
            while (aux -> next != NULL)    //usar o ponteiro pra percorrer a lista,enquanto existir um proximo ou nao for o ultimo a lista vai caminhar
                    aux=aux->next;      //aux avança para o no seguinte
            aux->next=newnode;  //aux recebe o proximo que é nulo, e recebera o novo nó                           
        }
            list->size++; 
            return 1;
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


void *first(LinkedList *list){             //consulta o primeiro da fila 
    if (isEmpty == NULL) return NULL ;
    list->first->data; //se tiver vazia retorna null, se nao, retorna o endereço de memoria do dado do 1º no.    
}


void* last (LinkedList *list) {        //consulta o ultimo da fila
    void *data = NULL;
    if (!isEmpty(list)) {              //se a lista nao estiver vazio
        node *aux = list->first;       //ponteiro aux aponta para o primeiro nó
        while(aux->next != NULL)       //enquanto o proximo nao for nulo, que seria o fim da lista
            aux=aux->next;             //aux avança ate o ultimo
        data=aux->data;                //esse é o endereço de memoria que ira ser mostrado como last.
    }
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

void* top (LinkedList *list){         //mostra o topo da pilha
    return first(list);
}


bool isEmpty(LinkedList *list) {
    return (list->size == 0);
}


int  indexOf (LinkedList *list, void *data, compare equal) {//descobre a posiçao de um elemento especifico
    if(isEmpty(list)) return -1; //se a lsita nao estiver vazia, andamos nela contando as posições
    int count = 0;                  
    node *aux= list->first;      //aux começa percorrer a lista pela primeira posiçao
    while (aux!=NULL && !equal(aux->data,data)) //enquanto o aux nao for o ultimo nó e aux for diferente do dado
    {
        aux=aux->next;          //aux ira avançar na lista
        count++;                //e o contador ira contar mais uma posicao
    }
     return (aux==NULL)?-1:count; //se a lista nao encontrou, retorna -1, se encontrou mostra o valor de count    
}


