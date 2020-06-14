#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "matriz.h"


/*	Esta fun��o recebe como entrada uma matriz a ser preenchida e um identificador do jogador.
	Esta fun��o tem como sa�da a matriz modificada de acordo com a jogada escolhida pelo jogador. */
void DeterminaJogada(MatConteudo matriz[][3], char jogador)
{
	int verifica = 0, escolha;
	
	// La�o de repeti��o que � executado at� a jogada escolhida ser v�lida
	do{
		printf("\n\nEscolha uma jogada entre 1 e 9: ");
		scanf("%d", &escolha);
		
		switch(escolha)
		{
			case 1:
				if(matriz[0][0] == VAZIO)
				{
					matriz[0][0] = jogador;
					verifica = 1;
				}
				break;
            case 2:
            	if(matriz[0][1] == VAZIO)
				{
					matriz[0][1] = jogador;
					verifica = 1;
				}
            	break;
            case 3:
            	if(matriz[0][2] == VAZIO)
				{
					matriz[0][2] = jogador;
					verifica = 1;
				}
            	break;
            case 4:
            	if(matriz[1][0] == VAZIO)
				{
					matriz[1][0] = jogador;
					verifica = 1;
				}
            	break;
            case 5:
            	if(matriz[1][1] == VAZIO)
				{
					matriz[1][1] = jogador;
					verifica = 1;
				}
            	break;
            case 6:
            	if(matriz[1][2] == VAZIO)
				{
					matriz[1][2] = jogador;
					verifica = 1;
				}
            	break;
            case 7:
            	if(matriz[2][0] == VAZIO)
				{
					matriz[2][0] = jogador;
					verifica = 1;
				}
            	break;
            case 8:
            	if(matriz[2][1] == VAZIO)
				{
					matriz[2][1] = jogador;
					verifica = 1;
				}
            	break;
            case 9:
            	if(matriz[2][2] == VAZIO)
				{
					matriz[2][2] = jogador;
					verifica = 1;
				}
            	break;
            default:
            	printf("\n\nTalvez a sua escolha n�o esteja dentro dos par�metros da matriz =[\n\n");
            	printf("Tente novamente!\n\n");
            	system("pause");
            	system("cls");
            	mostra(matriz);
		}
		
	} while(verifica == 0);
}

/*	Esta fun��o � semelhante a fun��o DeterminaJogada, por�m gera valores aleat�rios dentro do
intervalor 0-9 para determinar as jogadas da IA. */
void JogadaAleatoria(MatConteudo matriz[][3], char jogador)
{
	int verifica = 0, escolha;
	
	// La�o de repeti��o que � executado at� a jogada escolhida ser v�lida
	do{
		
		// Gera��o de valores aleat�rios dentro do intervalo 0 a 9 para determinar a jogada da IA
		escolha = 1 + rand() % 9;
		
		switch(escolha)
		{
			case 1:
				if(matriz[0][0] == VAZIO)
				{
					matriz[0][0] = jogador;
					verifica = 1;
				}
				break;
            case 2:
            	if(matriz[0][1] == VAZIO)
				{
					matriz[0][1] = jogador;
					verifica = 1;
				}
            	break;
            case 3:
            	if(matriz[0][2] == VAZIO)
				{
					matriz[0][2] = jogador;
					verifica = 1;
				}
            	break;
            case 4:
            	if(matriz[1][0] == VAZIO)
				{
					matriz[1][0] = jogador;
					verifica = 1;
				}
            	break;
            case 5:
            	if(matriz[1][1] == VAZIO)
				{
					matriz[1][1] = jogador;
					verifica = 1;
				}
            	break;
            case 6:
            	if(matriz[1][2] == VAZIO)
				{
					matriz[1][2] = jogador;
					verifica = 1;
				}
            	break;
            case 7:
            	if(matriz[2][0] == VAZIO)
				{
					matriz[2][0] = jogador;
					verifica = 1;
				}
            	break;
            case 8:
            	if(matriz[2][1] == VAZIO)
				{
					matriz[2][1] = jogador;
					verifica = 1;
				}
            	break;
            case 9:
            	if(matriz[2][2] == VAZIO)
				{
					matriz[2][2] = jogador;
					verifica = 1;
				}
            	break;
		}
		
	} while(verifica == 0);
}

/* Fun��o que inicializa a matriz, atribuindo o caractere espa�o para todas as 9 posi��es
   livres da matriz */
void inicializa(MatConteudo matriz[][3])
{
	int i, j;
	
	for(i = 0; i < 3; i++)
		{
			for(j = 0; j < 3; j++)
			{
				matriz[i][j] = VAZIO;
			}
		}
}

// Fun��o que mostra o jogo do velha, com suas casas j� demarcadas
void mostra(MatConteudo matriz[][3])
{
	int i, j;
	
	printf("\n");
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf(" %c", matriz[i][j]);
			
			// Caso j seja diferente de 2, pois este valor representa a �ltima coluna, imprimir a barra vertical
			if(j != 2)
				printf(" |");
				
		}
		
		// Caso i seja diferente de 2, pois este valor representa a �ltima linha, imprimir o divisor das linhas
		if(i != 2)
			printf("\n---|---|---");
		
		printf("\n");
	}
}

// Fun��o que verifica se X venceu, retornando um booleano
// Fonte: Livro C Completo e Total, p�g. 112
int checa_vencedoresX(MatConteudo matriz[][3])
{
	int i;
	
	/* Faz a verifica��o SOMENTE para as 3 linhas, pois combina os valores da vari�vel i nos �ndices
	relativos �s linhas com os valores predefinidos nos �ndices relativos �s colunas */
	for(i = 0; i < 3; i++)
	{
		/* Poss�veis combina��es realizadas neste la�o de repeti��o:
		I - {0, 0} + {0, 1} + {0, 2};
		II - {1, 0} + {1, 1} + {1, 2};
		III - {2, 0} + {2, 1} + {2, 2}. */ 
		if((matriz[i][0] == X) && (matriz[i][1] == X) && (matriz[i][2] == X))
		{
			return(1);
		}
	}
	
	/* Faz a verifica��o SOMENTE para as 3 colunas, pois combina os valores da vari�vel i nos �ndices
	relativos �s colunas com os valores predefinidos nos �ndices relativos �s linhas */
	for(i = 0; i < 3; i++)
	{
		/* Poss�veis combina��es realizadas neste la�o de repeti��o:
		I - {0, 0} + {1, 0} + {2, 0};
		II - {0, 1} + {1, 1} + {2, 1};
		III - {0, 2} + {1, 2} + {2, 2}. */
		if((matriz[0][i] == X) && (matriz[1][i] == X) && (matriz[2][i] == X))
		{
			return(1);
		}
	}
	
	/* Testa a diagonal principal, realizando a combina��o:
	I - {0, 0} + {1, 1} + {2, 2}. */
	if((matriz[0][0] == X) && (matriz[1][1] == X) && (matriz[2][2] == X))
		{
			return(1);
		}
	
	/* Testa a diagonal secund�rio, realizando a combina��o:
	I - {0, 2} + {1, 1} + {2, 0}. */
	if((matriz[0][2] == X) && (matriz[1][1] == X) && (matriz[2][0] == X))
		{
			return(1);
		}
	
	// Se nenhuma das combina��es poss�veis for concretizada, retorna 0
	return(0);
}

// Verifica se O venceu
int checa_vencedoresO(MatConteudo matriz[][3])
{
	int i;
	
	/* Faz a verifica��o SOMENTE para as 3 linhas, pois combina os valores da vari�vel i nos �ndices
	relativos �s linhas com os valores predefinidos nos �ndices relativos �s colunas */
	for(i = 0; i < 3; i++)
	{
		/* Poss�veis combina��es realizadas neste la�o de repeti��o:
		I - {0, 0} + {0, 1} + {0, 2};
		II - {1, 0} + {1, 1} + {1, 2};
		III - {2, 0} + {2, 1} + {2, 2}. */ 
		if((matriz[i][0] == O) && (matriz[i][1] == O) && (matriz[i][2] == O))
		{
			return(1);
		}
	}
	
	/* Faz a verifica��o SOMENTE para as 3 colunas, pois combina os valores da vari�vel i nos �ndices
	relativos �s colunas com os valores predefinidos nos �ndices relativos �s linhas */
	for(i = 0; i < 3; i++)
	{
		/* Poss�veis combina��es realizadas neste la�o de repeti��o:
		I - {0, 0} + {1, 0} + {2, 0};
		II - {0, 1} + {1, 1} + {2, 1};
		III - {0, 2} + {1, 2} + {2, 2}. */
		if((matriz[0][i] == O) && (matriz[1][i] == O) && (matriz[2][i] == O))
		{
			return(1);
		}
	}
	
	/* Testa a diagonal principal, realizando a combina��o:
	I - {0, 0} + {1, 1} + {2, 2}. */
	if((matriz[0][0] == O) && (matriz[1][1] == O) && (matriz[2][2] == O))
		{
			return(1);
		}
		
	/* Testa a diagonal secund�ria, realizando a combina��o:
	I - {0, 2} + {1, 1} + {2, 0}. */
	if((matriz[0][2] == O) && (matriz[1][1] == O) && (matriz[2][0] == O))
		{
			return(1);
		}
	
	/*
	if((matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0]) && (matriz[0][2] != VAZIO && matriz[1][1] != VAZIO && matriz[2][0] != VAZIO))
		return(1); */
	
	// Se nenhuma das combina��es poss�veis for concretizada, retorna 0
	return(0);
}

// Fun��o que apresenta uma ajuda ao usu�rio, mostrando as funcionalidades e organiza��o do algoritmo
void Ajuda_matriz()
{
	int i, j, valor = 0, matriz[3][3];
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			valor++;
			matriz[i][j] = valor;
		}
	}
	
	printf("Este algoritmo possui tr�s n�veis de dificuldade diferentes que determinam a \ncapacidade da IA e um modo Multiplayer. Explore-os!");
	printf("\nO modo Dif�cil � quase imposs�vel de se vencer, pois utiliza o Algoritmo MiniMaxpara escolher as jogadas do seu oponente. Que tal testa-lo? =] ");
	printf("\n\nPara determinar sua jogada, caro Player, escolha sabiamente de acordo com a \nmatriz abaixo:\n\n");
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf(" %d", matriz[i][j]);
			
			// Caso j seja diferente de 2, pois este valor representa a �ltima coluna, imprimir a barra vertical
			if(j != 2)
				printf(" |");
				
		}
		
		// Caso i seja diferente de 2, pois este valor representa a �ltima linha, imprimir o divisor das linhas
		if(i != 2)
			printf("\n---|---|---");
		
		printf("\n");
	}
	
	printf("\nAh, todas as suas pontua��es s�o salvas em um arquivo denominado Pontua��es.txt,que estar� na pasta raiz deste sistema. Verifique-o!\n");
	
	printf("\n\nMais alguma d�vida? Entre em contato com o programador deste sistema:");
	printf("\n\nE-mail: dyegowolf@gmail.com");
}

/*
int main()
{
	setlocale(LC_ALL, "");
	
	MatConteudo mat[3][3];
	MatConteudo jogador1 = X, jogador2 = O;
	int i, verifica = 0;
	
	inicializa(mat);
	mostra(mat);
	
	for(i = 0; i < 9; i++)
	{
		if(i % 2 == 0)
		{
			printf("\n\nJogador X");
			DeterminaJogada(mat, jogador1);
		}
		else
		{
			printf("\n\nJogador O");
			DeterminaJogada(mat, jogador2);
		}
		
		system("cls");
		mostra(mat);
		
		if((verifica = checa_vencedores(mat)))
		{
			printf("\n\nVIT�RIA\n\n");
			return(0);
		}
		
		printf("\n");
    	system("pause");
    	system("cls");
    	mostra(mat);
	}
		
    mostra(mat);

	return(0);
}
*/