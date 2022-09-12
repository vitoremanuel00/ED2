# include <stdio.h>
# include <stdlib.h>

/* lista encadeada, inserindo no inicio */

typedef struct no{
    int valor;
    struct no *proximo; 
}no;

/* procedimento pra inserir no incio*/

void init (no **lista, int num) { /*receber como parametro um elemento do tipo no, que sera a nossa lista, porem,
                        sera um ponteiro pra ponteiro, pq é o endereço de uma variavel que estara apontando pra um ponteiro.*/
    no *novo = malloc(sizeof(no));
    if(novo){

        novo->valor = num;
        novo->proximo = *lista;
        *lista= novo;

    }

    else
        printf("erro ao alocar memoria!\n");
}

//inserindo no final da lista

void final(no **lista, int num){
    no *aux, *novo = malloc(sizeof(no));

    if (novo){
        novo->valor = num;
        novo->proximo = NULL;
        //é o primeiro?
        //verificando se a lista esta vazia

        if(*lista == NULL){  //se o conteudo da lista for nulo, nao tem ninguem nessa posicao, mesmo que a inserçao seja no fim, o fim da lista é essa posiçao
            *lista = novo;
        }
        else{
            aux = *lista;
            while (aux->proximo) //enquanto existir um proximo a lista vai caminhar
                    aux = aux->proximo;
                    aux->proximo= novo;
        }
    }
    else
        printf("erro ao alocar memoria");
}

int main(){


}