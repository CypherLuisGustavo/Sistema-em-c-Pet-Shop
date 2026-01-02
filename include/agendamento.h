#ifndef AGENDAMENTOS_H
#define AGENDAMENTOS_H

#include "dados.h"
//*declaração de agendamendos Header*//

void cadastrar_agendamentos(PetAgendamento lista[],int *total);
void listar_agendamentos(PetAgendamento lista[],int total);
int buscar_agendamentos(PetAgendamento lista[], int total, char nome_pet[]);
void editar_agendamento(PetAgendamento lista[], int total);
void excluir_agendamento(PetAgendamento lista[], int *total);

#endif
