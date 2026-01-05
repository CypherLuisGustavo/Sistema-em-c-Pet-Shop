#include <stdio.h>
#include "../include/arquivo_txt.h"

void salvar_txt(PetAgendamento lista[], int qtd) {
    FILE *arq = fopen("data/dados.txt", "w");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        fprintf(arq,
            "%d;%s;%s;%s;%d;%d;%s;%02d/%02d/%04d;%s\n",
            lista[i].pet.id,
            lista[i].pet.nome_pet,
            lista[i].pet.tipo_pet,
            lista[i].pet.raca_animal,
            lista[i].pet.peso,
            lista[i].pet.idade,
            lista[i].agendamento.nome_tutor,
            lista[i].agendamento.dia,
            lista[i].agendamento.mes,
            lista[i].agendamento.ano,
            lista[i].agendamento.tipo_servico
        );
    }

    fclose(arq);
    printf("Dados salvos em data/dados.txt\n");
}

int carregar_txt(PetAgendamento lista[]) {
    FILE *arq = fopen("data/dados.txt", "r");
    int qtd = 0;

    if (arq == NULL) {
        // Arquivo ainda não existe (primeira execução)
        return 0;
    }

    while (fscanf(arq,
        "%d;%49[^;];%29[^;];%29[^;];%d;%d;%49[^;];%d/%d/%d;%49[^\n]\n",
        &lista[qtd].pet.id,
        lista[qtd].pet.nome_pet,
        lista[qtd].pet.tipo_pet,
        lista[qtd].pet.raca_animal,
        &lista[qtd].pet.peso,
        &lista[qtd].pet.idade,
        lista[qtd].agendamento.nome_tutor,
        &lista[qtd].agendamento.dia,
        &lista[qtd].agendamento.mes,
        &lista[qtd].agendamento.ano,
        lista[qtd].agendamento.tipo_servico
    ) == 11) {
        qtd++;
    }

    fclose(arq);
    return qtd;
}

