#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "matriz.h"


/*	Esta função recebe como entrada uma matriz a ser preenchida e um identificador do jogador.
	Esta função tem como saída a matriz modificada de acordo com a jogada escolhida pelo jogador. */
void DeterminaJogada(MatConteudo matriz[][3], char jogador)
{
	int verifica = 0, escolha;
	
	// Laço de repetição que é executado até a jogada escolhida ser válida
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
            	printf("\n\nTalvez a sua escolha não esteja dentro dos parâmetros da matriz =[\n\n");
            	printf("Tente novamente!\n\n");
            	system("pause");
            	system("cls");
            	mostra(matriz);
		}
		
	} while(verifica == 0);
}

/*	Esta função é semelhante a função DeterminaJogada, porém gera valores aleatórios dentro do
intervalor 0-9 para determinar as jogadas da IA. */
void JogadaAleatoria(MatConteudo matriz[][3], char jogador)
{
	int verifica = 0, escolha;
	
	// Laço de repetição que é executado até a jogada escolhida ser válida
	do{
		
		// Geração de valores aleatórios dentro do intervalo 0 a 9 para determinar a jogada da IA
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

/* Função que inicializa a matriz, atribuindo o caractere espaço para todas as 9 posições
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

// Função que mostra o jogo do velha, com suas casas já demarcadas
void mostra(MatConteudo matriz[][3])
{
	int i, j;
	
	printf("\n");
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf(" %c", matriz[i][j]);
			
			// Caso j seja diferente de 2, pois este valor representa a última coluna, imprimir a barra vertical
			if(j != 2)
				printf(" |");
				
		}
		
		// Caso i seja diferente de 2, pois este valor representa a última linha, imprimir o divisor das linhas
		if(i != 2)
			printf("\n---|---|---");
		
		printf("\n");
	}
}

// Função que verifica se X venceu, retornando um booleano
// Fonte: Livro C Completo e Total, pág. 112
int checa_vencedoresX(MatConteudo matriz[][3])
{
	int i;
	
	/* Faz a verificação SOMENTE para as 3 linhas, pois combina os valores da variável i nos índices
	relativos às linhas com os valores predefinidos nos índices relativos às colunas */
	for(i = 0; i < 3; i++)
	{
		/* Possíveis combinações realizadas neste laço de repetição:
		I - {0, 0} + {0, 1} + {0, 2};
		II - {1, 0} + {1, 1} + {1, 2};
		III - {2, 0} + {2, 1} + {2, 2}. */ 
		if((matriz[i][0] == X) && (matriz[i][1] == X) && (matriz[i][2] == X))
		{
			return(1);
		}
	}
	
	/* Faz a verificação SOMENTE para as 3 colunas, pois combina os valores da variável i nos índices
	relativos às colunas com os valores predefinidos nos índices relativos às linhas */
	for(i = 0; i < 3; i++)
	{
		/* Possíveis combinações realizadas neste laço de repetição:
		I - {0, 0} + {1, 0} + {2, 0};
		II - {0, 1} + {1, 1} + {2, 1};
		III - {0, 2} + {1, 2} + {2, 2}. */
		if((matriz[0][i] == X) && (matriz[1][i] == X) && (matriz[2][i] == X))
		{
			return(1);
		}
	}
	
	/* Testa a diagonal principal, realizando a combinação:
	I - {0, 0} + {1, 1} + {2, 2}. */
	if((matriz[0][0] == X) && (matriz[1][1] == X) && (matriz[2][2] == X))
		{
			return(1);
		}
	
	/* Testa a diagonal secundário, realizando a combinação:
	I - {0, 2} + {1, 1} + {2, 0}. */
	if((matriz[0][2] == X) && (matriz[1][1] == X) && (matriz[2][0] == X))
		{
			return(1);
		}
	
	// Se nenhuma das combinações possíveis for concretizada, retorna 0
	return(0);
}

// Verifica se O venceu
int checa_vencedoresO(MatConteudo matriz[][3])
{
	int i;
	
	/* Faz a verificação SOMENTE para as 3 linhas, pois combina os valores da variável i nos índices
	relativos às linhas com os valores predefinidos nos índices relativos às colunas */
	for(i = 0; i < 3; i++)
	{
		/* Possíveis combinações realizadas neste laço de repetição:
		I - {0, 0} + {0, 1} + {0, 2};
		II - {1, 0} + {1, 1} + {1, 2};
		III - {2, 0} + {2, 1} + {2, 2}. */ 
		if((matriz[i][0] == O) && (matriz[i][1] == O) && (matriz[i][2] == O))
		{
			return(1);
		}
	}
	
	/* Faz a verificação SOMENTE para as 3 colunas, pois combina os valores da variável i nos índices
	relativos às colunas com os valores predefinidos nos índices relativos às linhas */
	for(i = 0; i < 3; i++)
	{
		/* Possíveis combinações realizadas neste laço de repetição:
		I - {0, 0} + {1, 0} + {2, 0};
		II - {0, 1} + {1, 1} + {2, 1};
		III - {0, 2} + {1, 2} + {2, 2}. */
		if((matriz[0][i] == O) && (matriz[1][i] == O) && (matriz[2][i] == O))
		{
			return(1);
		}
	}
	
	/* Testa a diagonal principal, realizando a combinação:
	I - {0, 0} + {1, 1} + {2, 2}. */
	if((matriz[0][0] == O) && (matriz[1][1] == O) && (matriz[2][2] == O))
		{
			return(1);
		}
		
	/* Testa a diagonal secundária, realizando a combinação:
	I - {0, 2} + {1, 1} + {2, 0}. */
	if((matriz[0][2] == O) && (matriz[1][1] == O) && (matriz[2][0] == O))
		{
			return(1);
		}
	
	/*
	if((matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0]) && (matriz[0][2] != VAZIO && matriz[1][1] != VAZIO && matriz[2][0] != VAZIO))
		return(1); */
	
	// Se nenhuma das combinações possíveis for concretizada, retorna 0
	return(0);
}

// Função que apresenta uma ajuda ao usuário, mostrando as funcionalidades e organização do algoritmo
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
	
	printf("Este algoritmo possui três níveis de dificuldade diferentes que determinam a \ncapacidade da IA e um modo Multiplayer. Explore-os!");
	printf("\nO modo Difícil é quase impossível de se vencer, pois utiliza o Algoritmo MiniMaxpara escolher as jogadas do seu oponente. Que tal testa-lo? =] ");
	printf("\n\nPara determinar sua jogada, caro Player, escolha sabiamente de acordo com a \nmatriz abaixo:\n\n");
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf(" %d", matriz[i][j]);
			
			// Caso j seja diferente de 2, pois este valor representa a última coluna, imprimir a barra vertical
			if(j != 2)
				printf(" |");
				
		}
		
		// Caso i seja diferente de 2, pois este valor representa a última linha, imprimir o divisor das linhas
		if(i != 2)
			printf("\n---|---|---");
		
		printf("\n");
	}
	
	printf("\nAh, todas as suas pontuações são salvas em um arquivo denominado Pontuações.txt,que estará na pasta raiz deste sistema. Verifique-o!\n");
	
	printf("\n\nMais alguma dúvida? Entre em contato com o programador deste sistema:");
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
			printf("\n\nVITÓRIA\n\n");
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