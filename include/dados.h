#ifndef dados_h
#define dados_h

#define maximo_pet 100;
typedef struct{
  char nome_pet[50];
  char tipo_pet[30];
  char raca_animal[30];
  int peso ;
  int idade;
  }Pet;

typedef struct{
char nome_tutor[50];
int dia,mes,ano;
char tipo_servico[50];
}Agendamento;

typedef struct{
Pet pet ;
Agendamento agendamento;
}PetAgendamento;

#endif
