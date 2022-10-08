#include <stdio.h>
#include <string.h>

typedef struct { //cria um struct com nome contato
  char nome[51];
  char endereco[101];
  char telefone[13];
  char aniversario[9];
  int num; //controla para nao passar de mil
}contato ;

void novo_contato();//i - inserir
void remover_nome();//r - remoção
void busca();//b - busca
void imprimir();//p - impressão

int main(void) { //funcao principal
  contato agenda[1002];
  agenda[0].num = 0;
  int x = 0;
  int c = 0; 
  char comando;
  fflush(stdin);
  while(c != -1){
    scanf(" %c", &comando); //le os comando inseridos no programa
    if((comando == 'i') && (agenda[0].num == 1000)){
      novo_contato(agenda);
      printf("O contato nao foi inserido.\n");
      printf("\n");
    }    
    if((comando == 'i') && (agenda[0].num < 1000)){
      x = agenda[0].num;
      novo_contato(agenda);
      printf("Contato para %s inserido.\n", agenda[x].nome);
      printf("\n");
      agenda[0].num++;
    }
    if(comando == 'r'){ //para cada comando, ha uma funcao com um apontador da agenda, que com os structs dos contatos
      remover_nome(agenda);
      printf("\n");
    }
    if(comando == 'b'){
      busca(agenda);
      printf("\n");
    }
    if(comando == 'p'){
      imprimir(agenda);
      printf("\n");
    }
    if(comando == 'f'){  //f - finalizar
      c = -1;
    }
  }
  return 0;
}

void novo_contato(contato agenda[]){//i - inserir
  int x = agenda[0].num;
  scanf(" %[^\n]", agenda[x].nome);
  scanf(" %[^\n]", agenda[x].endereco);
  scanf(" %[^\n]", agenda[x].telefone);
  scanf(" %[^\n]", agenda[x].aniversario);
  return;
}

void remover_nome(contato agenda[]){//r - remoção
  char remover[51];
  int x = agenda[0].num, removidos = 0, k = 0, l = 0, p = 0;
  scanf(" %[^\n]", remover);
  int h = strlen(remover);
  for(int i = 0; i < x - removidos; i++){
    int letras = 0;
    if(remover[0] == agenda[i].nome[0]){
      for(int j = 1; j <= h ; j++){
        if(remover[j] == agenda[i].nome[j]){
          letras++;
        }
        if(letras == h){ //procura se alguma paralra igual
          for(k = i; k < x - removidos; k++){ //reorganiza o vetor e todos os structs de cada vetor seguinte ao que foi removido
            l = strlen(agenda[k + 1].nome);
            agenda[k].nome[l] = '\0';
            for(p = 0; p < l; p++){
              agenda[k].nome[p] = agenda[k + 1].nome[p];
            }
            l = strlen(agenda[k + 1].endereco);
            agenda[k].endereco[l] = '\0';
            for(p = 0; p < l; p++){
              agenda[k].endereco[p] = agenda[k + 1].endereco[p];
            }
            l = strlen(agenda[k + 1].telefone);
            agenda[k].telefone[l] = '\0';
            for(p = 0; p < l; p++){
              agenda[k].telefone[p] = agenda[k + 1].telefone[p];
            }
            l = strlen(agenda[k + 1].aniversario);
            agenda[k].aniversario[l] = '\0';
            for(p = 0; p < l; p++){
              agenda[k].aniversario[p] = agenda[k + 1].aniversario[p];
            }
          }
          i = i - 1;
          removidos++;
        }
      }
    }
  }
  if(removidos > 0){
    agenda[0].num = agenda[0].num - removidos;
    printf("Contatos de %s removidos: %d.\n", remover, removidos);
  }
  return;
}

void busca(contato agenda[]){//b - busca
  char search[51];
  char jaimpr[1001];
  int iguais = 0, x = agenda[0].num;
  for(int r = 0; r < x; r++){
    jaimpr[r] = 0;
  }
  scanf(" %[^\n]", search);
  int f = strlen(search);
  printf("Resultado da busca:\n");
  for(int i = 0; i < x; i++){
    int h = strlen(agenda[i].nome);
    for(int s = 0; s <= h - f; s++){
      int letras = 0;
      if(search[0] == agenda[i].nome[s]){
        letras = 1;
        for(int j = s + 1; j < h ; j++){
          if(search[j - s] == agenda[i].nome[j]){
            letras++;
          }
          if(letras == f){
            if(jaimpr[i] == 0){
              printf("(%d) ", i + 1);
              printf("%s\t", agenda[i].nome);
              printf("%s\t", agenda[i].endereco);
              printf("%s\t", agenda[i].telefone);
              printf("%s\n", agenda[i].aniversario);
              iguais++;
              jaimpr[i] = 1;
            }
          }
        }
      }
    }
    if((i + 1 == x) && (iguais == 0)){
      printf("Nenhum contato.\n");
    }
  }
  return;
}

void imprimir(contato agenda[]){//p - impressão
  int x = agenda[0].num;
  printf("Listagem:\n");
  if(x > 0){
    for(int i = 0; i < x; i++){
      printf("(%d) ", i + 1);
      printf("%s\t", agenda[i].nome);
      printf("%s\t", agenda[i].endereco);
      printf("%s\t", agenda[i].telefone);
      printf("%s\n", agenda[i].aniversario);
    }
  }
  if(x == 0){
    printf("Nenhum contato.\n");
  }
  return;
}
