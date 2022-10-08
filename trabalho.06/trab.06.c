#include <stdio.h>
#include <string.h>

int main(void) {
  char alfabeto[130] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  char codigo[10001]; //le o codigo do et
  scanf(" %[^\n]", codigo);

  int tamanho, a;
  tamanho = strlen(codigo); //mostra o tamanho do codigo

  int recorrencia[26];
  int posicao[tamanho];
  for(a = 0; a < 26; a++){
    recorrencia[a] = 0;
  }
  for(a = 0; a < tamanho; a++){
    posicao[a] = 0;
  }
  for(a = 0; a < tamanho; a++){ //mostra o numero da letra em cada posicao e a quantidade de vezes que a letra aparece no codigo
    if(codigo[a] == 'a'){
      recorrencia[0]++;
      posicao[a] = 52;
    }
    if(codigo[a] == 'b'){
      recorrencia[1]++;
      posicao[a] = 53;
    }
    if(codigo[a] == 'c'){
      recorrencia[2]++;
      posicao[a] = 54;
    }
    if(codigo[a] == 'd'){
      recorrencia[3]++;
      posicao[a] = 55;
    }
    if(codigo[a] == 'e'){
      recorrencia[4]++;
      posicao[a] = 56;
    }
    if(codigo[a] == 'f'){
      recorrencia[5]++;
      posicao[a] = 57;
    }
    if(codigo[a] == 'g'){
      recorrencia[6]++;
      posicao[a] = 58;
    }
    if(codigo[a] == 'h'){
      recorrencia[7]++;
      posicao[a] = 59;
    }
    if(codigo[a] == 'i'){
      recorrencia[8]++;
      posicao[a] = 60;
    }
    if(codigo[a] == 'j'){
      recorrencia[9]++;
      posicao[a] = 61;
    }
    if(codigo[a] == 'k'){
      recorrencia[10]++;
      posicao[a] = 62;
    }
    if(codigo[a] == 'l'){
      recorrencia[11]++;
      posicao[a] = 63;
    }
    if(codigo[a] == 'm'){
      recorrencia[12]++;
      posicao[a] = 64;
    }
    if(codigo[a] == 'n'){
      recorrencia[13]++;
      posicao[a] = 65;
    }
    if(codigo[a] == 'o'){
      recorrencia[14]++;
      posicao[a] = 66;
    }
    if(codigo[a] == 'p'){
      recorrencia[15]++;
      posicao[a] = 67;
    }
    if(codigo[a] == 'q'){
      recorrencia[16]++;
      posicao[a] = 68;
    }
    if(codigo[a] == 'r'){
      recorrencia[17]++;
      posicao[a] = 69;
    }
    if(codigo[a] == 's'){
      recorrencia[18]++;
      posicao[a] = 70;
    }
    if(codigo[a] == 't'){
      recorrencia[19]++;
      posicao[a] = 71;
    }
    if(codigo[a] == 'u'){
      recorrencia[20]++;
      posicao[a] = 72;
    }
    if(codigo[a] == 'v'){
      recorrencia[21]++;
      posicao[a] = 73;
    }
    if(codigo[a] == 'w'){
      recorrencia[22]++;
      posicao[a] = 74;
    }
    if(codigo[a] == 'x'){
      recorrencia[23]++;
      posicao[a] = 75;
    }
    if(codigo[a] == 'y'){
      recorrencia[24]++;
      posicao[a] = 76;
    }
    if(codigo[a] == 'z'){
      recorrencia[25]++;
      posicao[a] = 77;
    }   
  }

  int maisr, letramr;
  maisr = 0;
  letramr = 0;
  for(a = 0; a < 26; a++){
    if(recorrencia[a] > maisr){
      maisr = recorrencia[a];
      letramr = a + 52;
    }
  }
  if((letramr != 52) && (letramr != 77)){
    for(a = 0; a < tamanho; a++){
      if(posicao[a] < letramr){
        posicao[a] = posicao[a] + 26;
      }
    }
  }

  if(letramr == 52){ //se a letra que mais aparece e' a, decifra o codigo 
    for(a = 0; a < tamanho; a++){
      if((posicao[a] != 52) && (posicao[a] != 53) && (codigo[a] != ' ')){
        codigo[a] = alfabeto[posicao[a] - 1];
      }
      if(posicao[a] == 53){
        codigo[a] = 'z';
      }
    }
  }

  if(letramr == 77){ //se a letra que mais aparece e' z, decifra o codigo
    for(a = 0; a < tamanho; a++){
      if((posicao[a] != 52) && (posicao[a] != 77) && (codigo[a] != ' ')){
        codigo[a] = alfabeto[posicao[a] - 1];
      }
      if(posicao[a] == 52){
        codigo[a] = 'y';
      }
    }
  }

  if((letramr != 52) && (letramr != 77)){ //se a letra que mais aparece e' diferente de a e z, decifra o codigo
    for(a = 0; a < tamanho; a++){
      if(posicao[a] == letramr){
        codigo[a] = alfabeto[letramr];
      }
      if(posicao[a] == letramr + letramr - 51){
        codigo[a] = alfabeto[posicao[a] - letramr];
      }
      if((posicao[a] < letramr + letramr - 51) && (codigo[a] != ' ') && (posicao[a] != letramr)){
        codigo[a] = alfabeto[posicao[a] - letramr - 1];
      }
      if((posicao[a] > letramr + letramr - 51) && (codigo[a] != ' ')){
        codigo[a] = alfabeto[posicao[a] - letramr];
      }
      
    }
  }

  for(a = 0; a < tamanho; a++){ //imprime o codigo decifrado
    printf("%c", codigo[a]);
  }
  printf("\n");
  return 0;
}