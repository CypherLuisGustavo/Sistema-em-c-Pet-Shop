#include <stdio.h>
#include <string.h>
#include "petshop.h"


void lerDadosDoArquivo(pet_agendamento pet_agendamentos[], int *quantidade) {
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de dados.\n");
        return;
    }

    while (fscanf(arquivo, "%49[^,], %29[^,], %29[^,], %d, %d\n", 
                  pet_agendamentos[*quantidade].pet_info.nome_pet, 
                  pet_agendamentos[*quantidade].pet_info.tipo_pet,
                  pet_agendamentos[*quantidade].pet_info.raca_animal, 
                  &pet_agendamentos[*quantidade].pet_info.peso, 
                  &pet_agendamentos[*quantidade].pet_info.idade) == 5) {
        fscanf(arquivo, "%49[^,], %d/%d/%d, %49[^\n]\n", 
                pet_agendamentos[*quantidade].agendamento_info.nome_tutor,
                &pet_agendamentos[*quantidade].agendamento_info.dia, 
                &pet_agendamentos[*quantidade].agendamento_info.mes,
                &pet_agendamentos[*quantidade].agendamento_info.ano, 
                pet_agendamentos[*quantidade].agendamento_info.tipo_servico);
        (*quantidade)++;
    }

    fclose(arquivo);
}


void cadastrar_pet_agendamento(pet_agendamento pet_agendamentos[], int *quantidade) {
    if (*quantidade >= MAXIMO_PET) {
        printf("Limite de pets alcançado.\n");
        return;
    }


    printf("Cadastrar Pet:\n");
    printf("Nome: ");
    scanf(" %49[^\n]", pet_agendamentos[*quantidade].pet_info.nome_pet);
    printf("Tipo: ");
    scanf(" %29[^\n]", pet_agendamentos[*quantidade].pet_info.tipo_pet);
    printf("Raça (se não souber, digite 'n'): ");
    scanf(" %29[^\n]", pet_agendamentos[*quantidade].pet_info.raca_animal);
    printf("Peso: ");
    scanf("%d", &pet_agendamentos[*quantidade].pet_info.peso);
    printf("Idade: ");
    scanf("%d", &pet_agendamentos[*quantidade].pet_info.idade);


    printf("Cadastrar Agendamento para o Pet:\n");
    printf("Nome do Tutor: ");
    scanf(" %49[^\n]", pet_agendamentos[*quantidade].agendamento_info.nome_tutor);
    printf("Data (DD MM AAAA) usar o espaço: ");
    scanf("%d %d %d", 
          &pet_agendamentos[*quantidade].agendamento_info.dia, 
          &pet_agendamentos[*quantidade].agendamento_info.mes,
          &pet_agendamentos[*quantidade].agendamento_info.ano);
    printf("Tipo de Serviço: ");
    scanf(" %49[^\n]", pet_agendamentos[*quantidade].agendamento_info.tipo_servico);

    (*quantidade)++;
}


void listar_pet(pet_agendamento pet_agendamentos[], int quantidade) {
    printf("Lista de Pets:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Nome: %s, Tipo: %s, Raça: %s, Peso: %d, Idade: %d\n",
               pet_agendamentos[i].pet_info.nome_pet, 
               pet_agendamentos[i].pet_info.tipo_pet, 
               pet_agendamentos[i].pet_info.raca_animal, 
               pet_agendamentos[i].pet_info.peso, 
               pet_agendamentos[i].pet_info.idade);
    }
}


void listar_agendamento(pet_agendamento pet_agendamentos[], int quantidade) {
    printf("Lista de Agendamentos:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Nome do Tutor: %s\n, Data: %02d/%02d/%04d, Serviço: %s\n",
               pet_agendamentos[i].agendamento_info.nome_tutor,
               pet_agendamentos[i].agendamento_info.dia,
               pet_agendamentos[i].agendamento_info.mes,
               pet_agendamentos[i].agendamento_info.ano,
               pet_agendamentos[i].agendamento_info.tipo_servico);
    }
}


void alterar_agendamento(pet_agendamento pet_agendamentos[], int quantidade) {
    char nome_tutor[50];
    printf("Informe o nome do tutor para alterar o agendamento: ");
    scanf(" %49[^\n]", nome_tutor);

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(pet_agendamentos[i].agendamento_info.nome_tutor, nome_tutor) == 0) {
            printf("Nova Data (DD MM AAAA): ");
            scanf("%d %d %d", &pet_agendamentos[i].agendamento_info.dia, 
                  &pet_agendamentos[i].agendamento_info.mes, 
                  &pet_agendamentos[i].agendamento_info.ano);
            printf("Novo Tipo de Serviço: ");
            scanf(" %49[^\n]", pet_agendamentos[i].agendamento_info.tipo_servico);
            printf("Agendamento alterado com sucesso!\n");
            return;
        }
    }

    printf("Agendamento não encontrado para o tutor %s.\n", nome_tutor);
}


void gerar_relatorio(pet_agendamento pet_agendamentos[], int quantidade) {
    ordenar_agendamentos(pet_agendamentos, quantidade);

    FILE *relatorio = fopen("relatorio.txt", "w");
    if (relatorio == NULL) {
        printf("Erro ao abrir o arquivo de relatório.\n");
        return;
    }

    fprintf(relatorio, "Relatório de Agendamentos\n");
    fprintf(relatorio, "======================================\n");
    for (int i = 0; i < quantidade; i++) {
        fprintf(relatorio, "Nome do Tutor: %s, Data: %02d/%02d/%04d, Serviço: %s\n",
                pet_agendamentos[i].agendamento_info.nome_tutor,
                pet_agendamentos[i].agendamento_info.dia,
                pet_agendamentos[i].agendamento_info.mes,
                pet_agendamentos[i].agendamento_info.ano,
                pet_agendamentos[i].agendamento_info.tipo_servico);
    }
    fclose(relatorio);
    printf("Relatório gerado com sucesso em relatorio.txt\n");
}


void ordenar_agendamentos(pet_agendamento pet_agendamentos[], int quantidade) {
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            if (pet_agendamentos[j].agendamento_info.ano > pet_agendamentos[j + 1].agendamento_info.ano ||
                (pet_agendamentos[j].agendamento_info.ano == pet_agendamentos[j + 1].agendamento_info.ano && 
                 pet_agendamentos[j].agendamento_info.mes > pet_agendamentos[j + 1].agendamento_info.mes) ||
                (pet_agendamentos[j].agendamento_info.ano == pet_agendamentos[j + 1].agendamento_info.ano && 
                 pet_agendamentos[j].agendamento_info.mes == pet_agendamentos[j + 1].agendamento_info.mes && 
                 pet_agendamentos[j].agendamento_info.dia > pet_agendamentos[j + 1].agendamento_info.dia)) {
                pet_agendamento temp = pet_agendamentos[j];
                pet_agendamentos[j] = pet_agendamentos[j + 1];
                pet_agendamentos[j + 1] = temp;
            }
        }
    }
}


void salvarDadosEmArquivo(pet_agendamento pet_agendamentos[], int quantidade) {
    FILE *arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar os dados.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "nome :%s\n|| tipo :%s\n|| raça:%s\n|| peso :%d\n|| idade:%d\n", pet_agendamentos[i].pet_info.nome_pet, 
                pet_agendamentos[i].pet_info.tipo_pet, pet_agendamentos[i].pet_info.raca_animal, 
                pet_agendamentos[i].pet_info.peso, pet_agendamentos[i].pet_info.idade);
        fprintf(arquivo, "nome de tutor:%s|| data %02d/%02d/%04d||  servico :%s\n", pet_agendamentos[i].agendamento_info.nome_tutor,
                pet_agendamentos[i].agendamento_info.dia, pet_agendamentos[i].agendamento_info.mes,
                pet_agendamentos[i].agendamento_info.ano, pet_agendamentos[i].agendamento_info.tipo_servico);
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso em dados.txt\n");
}
void mostrarConteudoArquivo(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return;
    }

    char linha[256]; 

    printf("Conteúdo do arquivo %s:\n", nome_arquivo);
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    fclose(arquivo);
}

void exibirMenu() {
    printf("\n===========================================\n");
    printf("             Sistema de Pet Shop           \n");
    printf("===========================================\n");
    printf("1. Cadastrar Pet e Agendamento\n");
    printf("2. Listar Pets\n");
    printf("3. Listar Agendamentos\n");
    printf("4. Alterar Agendamento\n");
    printf("5. Gerar Relatório de Agendamentos\n");
    printf("6. Salvar Dados\n");
    printf("7. Mostrar Conteúdo do Arquivo(mostra dados dps de sair (dadoss.txt))\n");
    printf("8. Sair\n");
    printf("(!!! aviso !!!) -- (so aparece o txt quando sair)\n");
    printf("Escolha uma opção: ");
}

int main() {
    pet_agendamento pet_agendamentos[MAXIMO_PET];
    int quantidade = 0;
    int opcao;


    lerDadosDoArquivo(pet_agendamentos, &quantidade);

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_pet_agendamento(pet_agendamentos, &quantidade); 
                break;
            case 2:
                listar_pet(pet_agendamentos, quantidade);
                break;
            case 3:
                listar_agendamento(pet_agendamentos, quantidade);
                break;
            case 4:
                alterar_agendamento(pet_agendamentos, quantidade);
                break;
            case 5:
                gerar_relatorio(pet_agendamentos, quantidade);
                break;
            case 6:
                salvarDadosEmArquivo(pet_agendamentos, quantidade);
                break;
            case 7:

                mostrarConteudoArquivo("dados.txt");
                break;
            case 8:
                printf("Salvando dados antes de sair...\n");
                salvarDadosEmArquivo(pet_agendamentos, quantidade); 
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 8);

    return 0;
}


