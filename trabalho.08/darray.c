#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "darray.h"

typedef struct modificar {
  char** pasta; // The array of pointers to char, that is, the array of string.
  int first; // The index of the first element in the sequence.
  int size;  // The sequence size.
  int capacity; // The array size.
  int min_cap;  // The minimum array size.
} modificar;

/**
  Aloque um darray e a matriz de ponteiros para strings com
   capacidade inicial. Defina o estado inicial do darray corretamente.

   capacidade Ã© o tamanho inicial do array. Ã‰ tambÃ©m o tamanho mÃ­nimo da matriz.

   Ele retorna o endereÃ§o de um novo darray. Em caso de falha, ele retorna NULL.
**/
darray* da_alloc(int capacity){
  darray * A = malloc(sizeof(darray));
  A -> data = (char **) malloc(capacity * sizeof(char*));
  A -> size = 0;
  A -> first = 0;
  A -> min_cap = 64;
  A -> capacity = capacity;
  return A;
}

int da_exp(darray* A, int capacity, int size){
  modificar* B = malloc(sizeof(modificar));
  B -> pasta = (char **) malloc(capacity * sizeof(char*));
  B -> size = 0;
  B -> first = 0;
  B -> min_cap = 64;
  B -> capacity = capacity;
  int l;
  for(int i = 0; i < A->size; i++){
    l = strlen(A->data[(A->first + i) % A->capacity]) + 1;
    B->pasta[i] = (char*)malloc(l*sizeof(char));
    strcpy(B->pasta[i], A->data[(A->first + i) % A->capacity]);
    B->size++;
  }
  free(A->data);
  A->size = 0;
  A->first = 0;
  A->capacity = capacity;
  A->data = B->pasta;
  A->size = B->size;
  free(B);
  return 1;
}


/**
   Adicione uma cÃ³pia de uma string ao inÃ­cio da sequÃªncia.

   Se a matriz estiver cheia, ele tenta dobrar sua capacidade e, em seguida, adiciona o
   fragmento.

   Em caso de sucesso, ele retorna 1. Quando o redimensionamento da matriz nÃ£o Ã© possÃ­vel, ele nÃ£o
   injetar e retornarÃ¡ 0.
**/
int da_inject(darray* A, char* string){
  //ver se o vetor esta cheio, se estiver, dobra o tamanho se nao estiver, insere
  int s = A->size;
  int c = A->capacity; 
  int l = strlen(string) + 1;
  if(s == c){
    da_exp(A,2 * c, s);
    c = 2 * c;
  }
  int p = (A->first - 1 + c) % c;
  if(s == 0){
    p = 0;
  }
  A->data[p] = (char*)malloc(l*sizeof(char));
  strcpy(A->data[p], string);
  A->first = p;
  A->size++;


  return 1;
}


/**
   Remova uma string do inÃ­cio da sequÃªncia e retorne um ponteiro para ela.

   Se a matriz estiver 1/4 cheia, esta funÃ§Ã£o divide sua capacidade pela metade e, em seguida, remove
   a corda. A capacidade nunca serÃ¡ menor do que a capacidade inicial.
**/
char* da_eject(darray* A){
  int s = A->size;
  int c = A->capacity;
  int y;
  if((s == c / 4) && (c % 64 == 0) && (c / 2 >= A->min_cap)){
    da_exp(A, c/2, s);
    c = c/2;
  }
  if(A -> size > 0){
    A->first = (A->first + 1) % c;
    y = (A->first - 1) % c;
    if(y <0){
      y = c - 1;
    }
    A->size--;
    s--;
    }

  
  return A->data[y];
}

/**
   Adicione uma cÃ³pia de uma string ao final da sequÃªncia.

   Se a matriz estiver cheia, ele tenta dobrar sua capacidade e, em seguida, adiciona o
   fragmento.

   Em caso de sucesso, ele retorna 1. Quando o redimensionamento da matriz nÃ£o Ã© possÃ­vel, ele nÃ£o
   push e retornarÃ¡ 0.
**/
int da_push(darray* A, char* string){
  //ver se o vetor esta cheio, se estiver, dobra o tamanho se nao estiver, insere
  int s = A->size;
  int c = A->capacity;    
  int f;
  int l = strlen(string) + 1;
  if(s == c){
    da_exp(A,2 * c, s);
    c = 2*c;
  }
  f = (A->first + s) % c;
  A->data[f] = (char*)malloc(l*sizeof(char));
  strcpy(A->data[f], string);
  A->size++;
  s++;
  
  
  return 1;
}

/**
   Remova uma string do final da sequÃªncia e retorne um ponteiro para ela.

   Se a matriz estiver 1/4 cheia, esta funÃ§Ã£o divide sua capacidade pela metade e, em seguida, remove
   a corda. A capacidade nunca serÃ¡ menor do que a capacidade inicial.
**/
char* da_pop(darray* A){
  int s = A->size;
  int c = A->capacity; 
  if((s == c / 4) && (c % 64 == 0) && (c / 2 >= A->min_cap)){
    da_exp(A, c/2, s);
    c = c/2;
  }
  if(A -> size > 0){
    A->size--;
    s--;
  }

  
  return A->data[(A->first + A->size) % A->capacity];
}


/**
  Solte todas as cordas em um darray e o prÃ³prio darray.
**/
void da_free(darray* A){
  free(A);
  return;
}

/**
   Retorne um ponteiro para a primeira string na sequÃªncia.
**/
char* da_first(darray* A){
  //for(int i=0; i<3; i++){
  //  printf("%s\n", A->data[i]);
  //}
  return A->data[A->first];
}



/**
   Retorne um ponteiro para a Ãºltima string na sequÃªncia.
**/
char* da_last(darray* A){
  //for(int i = 0; i < A->size; i ++){
  //  printf("%s\n", A->data[i]);
  //printf("%d\n", A->size);
  //printf("%d\n", A->first);
  //printf("%d\n", A->capacity);
  //printf("%d\n", last);
  //}

  return A->data[(A->first + A->size - 1) % A->capacity];
}



/**
   Return 1 if the sequence is empty, otherwise return 0.
**/
int da_is_empty(darray* A){
  int x = 0;
  if(A->size == 0){
    x = 1;
  }
  if(A->size > 0){
    x = 0;
  }
  return x;
}