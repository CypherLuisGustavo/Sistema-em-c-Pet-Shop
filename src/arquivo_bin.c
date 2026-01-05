#include <stdio.h>
#include "../include/arquivo_bin.h"

void salvar_bin(PetAgendamento lista[], int qtd){
  FILE *arq = fopen("data/dados.dat","wb");

  if(arq == NULL){
    printf("Erro ao abrir arquivo binario.\n");
    return;
  }

fwrite(%qtd,sizeof(int),1,arq);
fwrite("lista,sizeof(petAgendamento),qtd,arq);

fclose(arq);
printf("Dados salvos em binario (dados.dat).\n");
}

int carregar_bin(PetAgendamento lista[]){
  FILE *arq = fopen("data/dados.dat","rb");0
  int qtd = 0;

if(arq == NULL){
  return 0;
}
fread(&qtd, sizeof(int), 1, arq);
    fread(lista, sizeof(PetAgendamento), qtd, arq);

    fclose(arq);
    return qtd;
}
