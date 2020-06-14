#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "jogador.h"

struct jogador{
	char nome[120];
	int pontuacao;
};

Jogador *inicia_jogador(char *nome)
{
	Jogador *jog = (Jogador *) malloc(sizeof(Jogador));
	if(jog == NULL)
	{
		printf("\n\nOcorreu um erro ao criar um perfil de jogador. O programa ser� abortado em 3, 2, 1...\n\n");
		system("pause");
		exit(1);
	}
	
	strcpy(jog->nome, nome);
	jog->pontuacao = 0;
	
	return(jog);
}

void jogador_pontua(Jogador *jogador)
{
	jogador->pontuacao++;
}

void jogador_penaliza(Jogador *jogador)
{
	if(jogador->pontuacao > 0)
	{
		jogador->pontuacao--;
	}
}

void apresenta_cabecalho(int numero_jogadores, int tipo, Jogador *jogador1, Jogador *jogador2)
{
	setlocale(LC_ALL, "");
	
	if(numero_jogadores == 1)
	{
		printf("\tJogo da Velha com �rvore de Decis�o\n\n");
		printf("Jogador: %s\tPontua��o: %d\n", jogador1->nome, jogador1->pontuacao);
		
		if(tipo == 1)
			printf("N�vel de dificuldade: F�CIL\n\n");
		else if(tipo == 2)
			printf("N�vel de dificuldade: INTERMEDI�RIO\n\n");
		else if(tipo == 3)
			printf("N�vel de dificuldade: DIF�CIL\n\n");
	}
	else if(numero_jogadores == 2)
	{
		printf("\tJogo da Velha com �rvore de Decis�o\n\n");
		printf("Jogador 1: %s\tPontua��o: %d\n", jogador1->nome, jogador1->pontuacao);
		printf("\nJogador 2: %s\tPontua��o: %d\n", jogador2->nome, jogador2->pontuacao);
	}
	else
	{
		printf("\tJogo da Velha com �rvore de Decis�o\n\n");
	}
}

void salva_pontuacao(FILE *arquivo, Jogador *jogador, int tipo)
{
	if(arquivo == NULL)
	{
		printf("\n\nOcorreu um erro ao tentar salvar sua pontua��o no arquivo =[\n\n");
	}
	
	fprintf(arquivo, "\nNome: %s\tPontua��o: %d", jogador->nome, jogador->pontuacao);
	
	if(tipo == 1)
		fprintf(arquivo, "\tModo de jogo: Jogador x IA(F�CIL)\n");
	else if(tipo == 2)
		fprintf(arquivo, "\tModo de jogo: Jogador x IA(INTERMEDI�RIO)\n");
	else if(tipo == 3)
		fprintf(arquivo, "\tModo de jogo: Jogador x IA(DIF�CIL)\n");
	else if(tipo == 4)
		fprintf(arquivo, "\tModo de jogo: Multiplayer\n");
}
