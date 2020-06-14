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
		printf("\n\nOcorreu um erro ao criar um perfil de jogador. O programa será abortado em 3, 2, 1...\n\n");
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
		printf("\tJogo da Velha com Árvore de Decisão\n\n");
		printf("Jogador: %s\tPontuação: %d\n", jogador1->nome, jogador1->pontuacao);
		
		if(tipo == 1)
			printf("Nível de dificuldade: FÁCIL\n\n");
		else if(tipo == 2)
			printf("Nível de dificuldade: INTERMEDIÁRIO\n\n");
		else if(tipo == 3)
			printf("Nível de dificuldade: DIFÍCIL\n\n");
	}
	else if(numero_jogadores == 2)
	{
		printf("\tJogo da Velha com Árvore de Decisão\n\n");
		printf("Jogador 1: %s\tPontuação: %d\n", jogador1->nome, jogador1->pontuacao);
		printf("\nJogador 2: %s\tPontuação: %d\n", jogador2->nome, jogador2->pontuacao);
	}
	else
	{
		printf("\tJogo da Velha com Árvore de Decisão\n\n");
	}
}

void salva_pontuacao(FILE *arquivo, Jogador *jogador, int tipo)
{
	if(arquivo == NULL)
	{
		printf("\n\nOcorreu um erro ao tentar salvar sua pontuação no arquivo =[\n\n");
	}
	
	fprintf(arquivo, "\nNome: %s\tPontuação: %d", jogador->nome, jogador->pontuacao);
	
	if(tipo == 1)
		fprintf(arquivo, "\tModo de jogo: Jogador x IA(FÁCIL)\n");
	else if(tipo == 2)
		fprintf(arquivo, "\tModo de jogo: Jogador x IA(INTERMEDIÁRIO)\n");
	else if(tipo == 3)
		fprintf(arquivo, "\tModo de jogo: Jogador x IA(DIFÍCIL)\n");
	else if(tipo == 4)
		fprintf(arquivo, "\tModo de jogo: Multiplayer\n");
}
