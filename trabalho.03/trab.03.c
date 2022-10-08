#include <stdio.h>

int main(void) {
  int n, i;
  scanf(" %d", &n); //ler quantidade de numeros
  
  if(n <= 30){ 
  float acoes[n];
  
  for(i=0;i<n;i++){
  float x;
  scanf(" %f", &x); //ler numeros
  acoes[i] = x;
  }

  int dias;
  scanf(" %d", &dias); //ler dias
  float grana;
  scanf(" %f", &grana); //ler grana levada na viagem

  int a, b, dc, dv, q;
  dc = 0;
  dv = 0;
  a = 0;
  b = 1;
  float l, max, vv, vc;
  vv = 0.00;
  vc = 0.00;
  max = -0.01;
  while(a < n){
    while((b <= a + dias) && (b < n)){
      if(acoes[a] <= grana){
        q = grana / acoes[a];
        l = (acoes[b] - acoes[a]) * q; //ver o lucro obtido em tal diferença de dias
        if(l>max){
          max = l; //caso seja maior que o anterior, altera-se
          dv = b + 1;
          dc = a + 1;
          vv = acoes[b];
          vc = acoes[a];
        }
      
      }
      b++;
    }
  a++;
  b = a + 1;
  }

  int quantidade;
  quantidade = 0;
  float lucro;
  if(max <= 0){ //ver se a resposta é positiva ou não
  dc = 1;
  dv = 1;
  vc = acoes[0];
  vv = acoes[0];
  quantidade = grana / vc;
  lucro = 0.00;
  }
  if (max > 0){
  quantidade = grana / vc; //ver a quantidade de acoes compradas
  lucro = (vv - vc) * quantidade; //ver o lucro obtido
  }

  printf("Dia da compra: %d\n", dc);
  printf("Valor de compra: R$ %.2f\n", vc);
  printf("Dia da venda: %d\n", dv);
  printf("Valor de venda: R$ %.2f\n", vv);
  printf("Quantidade de acoes compradas: %d\n", quantidade);
  printf("Lucro: R$ %.2f\n", lucro);
     
  }

  return 0;
}