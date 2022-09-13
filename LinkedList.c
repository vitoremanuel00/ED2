# include <stdio.h>
# include <stdlib.h>

/* lista encadeada, inserindo no inicio */

typedef struct no{
    int valor;
    struct no *proximo;  
}no;

/* procedimento pra inserir no incio*/

void init (LinkedList *list) { /*receber como parametro um elemento do tipo no, que sera a nossa lista, porem,
                                 sera um ponteiro pra ponteiro, pq é o endereço de uma variavel que estara apontando pra um ponteiro.*/
    no *novo = malloc(sizeof(no));
    if(novo){
        novo->valor = num;
        novo->proximo = *list;
        *list= novo;

    }
    else
        printf("erro ao alocar memoria!\n");
}

//inserindo no final da lista

void enqueue(no **list, int num){
    no *aux, *newnode = malloc(sizeof(no));

    if (novo){
        
        //é o primeiro?
        //verificando se a lista esta vazia

        if(*list == NULL){  //se o conteudo da lista for nulo, nao tem ninguem nessa posicao, mesmo que a inserçao seja no fim, o fim da lista é essa posiçao
            *list = newnode;
        }
        else{
            aux = *list;
            while (aux->next) //enquanto existir um proximo a lista vai caminhar
                    aux = aux->next;
                    aux->next = newnode;
        }
    }
    else
        printf("erro ao alocar memoria");
}

int main(){


}