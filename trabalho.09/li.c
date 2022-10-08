#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "li.h"

//Aloque uma lista vazia de ints. Retorna um ponteiro para a nova lista ou NULL se a alocação de memória falha.
li* li_alloc() {
  return calloc(1,sizeof(li));
}


//Libere uma lista de ints e todos os seus nós.
void li_free(li* L) {

  node* p = L->head;
  node* n = NULL;

  while (p != NULL) {
    n = p->next;
    free(p);
    p = n;
  }

  free(L);
}


//Insira um novo nó no início de uma lista de ints. Retorne 1 em caso de sucesso ou 0 se a alocação de memória falhar.
int li_insert(li* L, int data) {

  node* n = malloc(sizeof(node));
  if (n == NULL)
    return 0;

  n->data = data;
  n->next = L->head;
  L->head = n;

  return 1;
}


//Imprima o conteúdo de uma lista de ints.
void li_print(li* L) {

  node* p = L->head;
  printf("{");

  while (p != NULL && p->next != NULL) {
    printf("%d, ",p->data);
    p = p->next;
  }

  if (p != NULL)
    printf("%d",p->data);

  printf("}");
}


//Avalie a união das listas de ints A e B. Retorne uma nova lista de sucesso. Se a alocação de memória falhar, qualquer lista parcialmente construída é liberada e retorna NULL.
li* li_union(li* A, li* B){
  li* C = li_alloc();
  //node * c = C->head;
  node * p = A->head;
  //node * s = B->head;
  while(p != NULL){
    node* c = malloc(sizeof(node));
    c->data = p->data;
    c->next = C->head;
    C->head = c;
    p = p->next;
  }
 

  li* T = li_alloc();
  node * t = T->head;
  T = li_difference(B, A);
  
  t = T->head;
  while(t != NULL){
    node* c = malloc(sizeof(node));
    c->data = t->data;
    c->next = C->head;
    C->head = c;
    t = t->next;
  }
  
  return C;
}



//Avalie a interseção das listas de ints A e B. Retorne uma nova lista em sucesso. Se a alocação de memória falhar, qualquer lista parcialmente construída é liberada e retorna NULL.
li* li_intersection(li* A, li* B){
  li* G = li_alloc();
  //node * g = G->head;
  node * p = A->head;
  node * s = B->head;
  while(p!= NULL){
    s = B->head;
    while(s!= NULL){
      if(s->data == p->data){
        node* g = malloc(sizeof(node));
        g->data = s->data;
        g->next = G->head;
        G->head = g;
        s = s->next;
      }
      else{
        s = s->next;
      }
  }
    p = p->next;
  }
  
  return G;
}


//Avalie a diferença A-B das listas de ints. Retorne uma nova lista de sucesso. Se a alocação de memória falhar, qualquer lista parcialmente construída é liberada e retorna NULL.
li* li_difference(li* A, li* B){
  li* G = li_alloc();
  //node * g = G->head;
  node * p = A->head;
  node * s = B->head; 
  int i = 0; 
  while(p != NULL){
    s = B->head;
    i = 0;
    while(s != NULL){
      if(s->data == p->data){
        i = 1;
        s = s->next;
      }
      else{
        s = s->next;
      }
      }
    if(i == 0){
      node* g = malloc(sizeof(node));
      g->data = p->data;
      g->next = G->head;
      G->head = g;
    }
    p = p->next;
  }
  return G;
}
