#include <stdio.h>
#include <string.h>
#include "../include/agendamentos.h"

void cadastrar_agendamento(PetAgendamento lista[], int *total){
  if(*total >= MAXIMO_PET){
    printf("Limite de agendamentos atingido!\n");
    return;
  }
  
  PetAgendamento *p = &lista[*total];
// *Aqui ficam as funções responsáveis pelo cadastro
// *e manipulação dos agendamentos do sistema
  
  printf("Nome do pet");
  scanf(" %[^\n]",p->pet.nome_pet);

  printf("Tipo de pet:");
  scanf(" %[^\n]",p->pet.tipo_pet);

  printf("Raça do animal:");
  scanf(" %[^\n]" , p->pet.raca_animal);

  printf("Peso:");
  scanf("%d",&p->pet.peso);

  printf("Idade:");
  scanf("%d",&p->pet.idade);

  printf("Nome de Tutor:");
  scanf(" %[^\n]",p->agendamento.nome_tutor);
    printf("Data (dia mes ano): ");
    scanf("%d %d %d",
          &p->agendamento.dia,
          &p->agendamento.mes,
          &p->agendamento.ano);

    printf("Tipo de serviço: ");
    scanf(" %[^\n]", p->agendamento.tipo_servico);

    (*total)++;
    printf("Agendamento cadastrado com sucesso!\n");
  
}

void listar_agendamentos(PetAgendameto lista[], int total ){
  if(total == 0){
    printf("Nenhum agendamento cadastrado.\n");
    return;
  }
  for(int i = 0;i<total;i++){
    printf("\n---- Agendamento %d ----\n",i + 1);
    printf("Pet: %s\n",lista[i].agendamento.nome_pet);
    printf("Tutor: %s\n",lista[i].agendamento.nome_tutor);
    printf("Data: %02d/%02d/%04d\n",lista[i].agendamento.dia,lista[i].agendamento.mes,lista[i].agendamento.ano);
    printf("Serviço: %s\n",lista[i].agendamento.tipo_servico);
  }
}

int buscar_agendamento(PetAgendamento lista[],char nome_pet[]) {
for(int i = 0;i< total;i++){
  if(strcmp(lista[i].pet.nome_pet,nome_pet) == 0){
      return i;
    }
  }
  return -1;
}

void editar_agendamento(PetAgendamento lista[],int total[]{
  char nome[50];
  printf("Digite o nome do pet para editar:");
  scanf(" %[^\n]",nome);
  int pos = buscar_agendamento(lista,total,nome);
  if(pos == -1){
    printf("Agendamento não encontrado.\n");
    return;
  }
  printf("Novo tipo de serviço:");
  scanf(" %[^\n]",lista[pos].agendamento.tipo_servico);

  printf("Agendamento Atualizado !!\n");
}

void excluir_agendamento(PetAgendamento lista[], int *total) {
    char nome[50];
    printf("Digite o nome do pet para excluir: ");
    scanf(" %[^\n]", nome);

    int pos = buscar_agendamento(lista, *total, nome);
    if (pos == -1) {
        printf("Agendamento não encontrado.\n");
        return;
    }

    for (int i = pos; i < *total - 1; i++) {
        lista[i] = lista[i + 1];
    }

    (*total)--;
    printf("Agendamento excluído!\n");
}
