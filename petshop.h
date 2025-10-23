#ifndef petshop_h
#define petshop_h

#define MAXIMO_PET 100

typedef struct {
    char nome_pet[50];
    char tipo_pet[30];
    char raca_animal[30];
    int peso;
    int idade;
} pet;

typedef struct {
    char nome_tutor[50];
    int dia;
    int mes;
    int ano;
    char tipo_servico[50];
} agendamento_servico;

typedef struct {
    pet pet_info;
    agendamento_servico agendamento_info;
} pet_agendamento;


void lerDadosDoArquivo(pet_agendamento pet_agendamentos[], int *quantidade);
void cadastrar_pet_agendamento(pet_agendamento pet_agendamentos[], int *quantidade);
void listar_pet(pet_agendamento pet_agendamentos[], int quantidade);
void listar_agendamento(pet_agendamento pet_agendamentos[], int quantidade);
void alterar_agendamento(pet_agendamento pet_agendamentos[], int quantidade);
void gerar_relatorio(pet_agendamento pet_agendamentos[], int quantidade);
void salvarDadosEmArquivo(pet_agendamento pet_agendamentos[], int quantidade);
void ordenar_agendamentos(pet_agendamento pet_agendamentos[], int quantidade);

#endif
