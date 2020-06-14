//#include "jogador.c"

typedef struct jogador Jogador;

Jogador *inicia_jogador(char *nome);
void jogador_pontua(Jogador *jogador);
void jogador_penaliza(Jogador *jogador);
void apresenta_cabecalho(int numero_jogadores, int tipo, Jogador *jogador1, Jogador *jogador2);
void salva_pontuacao(FILE *arquivo, Jogador *jogador, int tipo);