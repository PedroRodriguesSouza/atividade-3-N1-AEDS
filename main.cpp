/*+--------------------------------------------------------+
  | Arvore Binaria de Busca - 2022                         |
  +--------------------------------------------------------+*/

#include <iostream>

using namespace std;

struct No {     // DEFINICAO DO NO
     int Info; // INFORMACAO ARMAZENADA NO NO
     No* esq;   // PONTEIRO PARA A SUB-ARVORE ESQUERDA
     No* dir;   // PONTEIRO PARA A SUB-ARVORE DIREITA
};

typedef No* Arvore; // DEFINICAO DO TIPO ARVORE


// INSERCAO DE UM NO NA ARVORE - RECURSIVA
void insereAbbRec (Arvore& A, int Info){
     if(A == NULL){ // SE O PONTEIRO A E NULO, INSERIR UM NOVO NO
         A = new No;
         A->Info = Info;
         A->esq = A->dir = NULL;
      }
      else if(Info > A->Info)
              insereAbbRec(A->dir, Info); //INSERINDO NO RAMO DIREITO
           else
              insereAbbRec(A->esq, Info); //INSERINDO NO RAMO ESQUERDO
}

// CAMINHAMENTO EM PRE-ORDEM
void preordem (Arvore A) {
  if(A) {

    cout << A->Info << "  "; // PROCESSA O NO
    preordem (A->esq);   // CAMINHA PARA ESQUERDA
    preordem (A->dir);   // CAMINHA PARA DIREITA
  }
}

void ordem (Arvore A) {
  if(A) {

    ordem (A->esq);   // CAMINHA PARA ESQUERDA
    cout << A->Info << "  "; // PROCESSA O NO
    ordem (A->dir);   // CAMINHA PARA DIREITA
  }
}

void posordem (Arvore A) {
  if(A) {

    posordem (A->esq);   // CAMINHA PARA ESQUERDA
    posordem (A->dir);   // CAMINHA PARA DIREITA
    cout << A->Info << "  "; // PROCESSA O NO
  }
}

int MaiorEsquerda(Arvore& A){
    No *aux = A->esq;
    while(aux->dir)
        aux = aux->dir;
    return aux->Info;
}

int MenorDireita(Arvore& A){
    No *aux = A->dir;
    while(aux->esq)
        aux = aux->esq;
    return aux->Info;
}

void RemoveAbbRec(Arvore& A, int Info){
    if(A){
        if(Info < A->Info){
            No *aux = A->esq;
            if(Info == aux->Info){
                if(!aux->dir){//direita == NULL
                    A->esq = aux->esq;
                    delete aux;
                }
                else if(!aux->esq){//esquerda == NULL
                    A->esq = aux->dir;
                    delete aux;
                }
                else{//tem 2 filhos não nulos
                    int Info2 = MaiorEsquerda(aux);
                    //int Info2 = MenorDireita(aux);
                    RemoveAbbRec(aux, Info2);
                    aux->Info = Info2;
                }
            }
            else
                RemoveAbbRec(aux, Info);
        }
        else if(Info > A->Info){
            No *aux = A->dir;
            if(Info == aux->Info){
                if(!aux->dir){//direita == NULL
                    A->dir = aux->esq;
                    delete aux;
                }

                else if(!aux->esq){//esquerda == NULL
                    A->dir = aux->dir;
                    delete aux;
                }
                else{ //tem 2 filhos não nulos
                    int Info2 = MaiorEsquerda(aux);
                    //int Info2 = MenorDireita(aux);
                    RemoveAbbRec(aux, Info2);
                    aux->Info = Info2;
                }
            }
            else
                RemoveAbbRec(aux, Info);
        }
        else{//o numero é a raiz da arvore
            int Info2 = 0;
            if(A->esq)
                Info2 = MaiorEsquerda(A);
            else if(A->dir)
                Info2 = MenorDireita(A);
            else
                A = NULL;
            if(Info2){
                RemoveAbbRec(A, Info2);
                A->Info = Info2;
            }
        }
    }
}





int main () {

   Arvore t = NULL;

   insereAbbRec(t, 3);
   insereAbbRec(t, 1);
   insereAbbRec(t, 2);
   insereAbbRec(t, 5);
   insereAbbRec(t, 4);
   insereAbbRec(t, 7);
   insereAbbRec(t, 6);
   insereAbbRec(t, 8);

   RemoveAbbRec(t, 5);
   RemoveAbbRec(t, 3);
   RemoveAbbRec(t, 8);


   cout << endl << "preordem: ";
   preordem(t);
   cout << endl << "   ordem: ";
   ordem(t);
   cout << endl << "posordem: ";
   posordem(t);

    return 0;
}
