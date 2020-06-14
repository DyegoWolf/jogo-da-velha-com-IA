#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "jogador.c"
#include "matriz.c"
#include "MiniMaxVetor.c"

int main()
{
	setlocale(LC_ALL, "");
	
	char nome_jogador[120];
	Jogador *jogador;
	Jogador *jogador2;
	
	MatConteudo mat[3][3];
	MatConteudo player = X, player2 = O;
	int i, opcao, escolha, decisao;
	
	FILE *arquivo = fopen("Pontuações.txt", "at");
	if(arquivo == NULL)
	{
		printf("\nErro ao criar arquivo. Infelizmente, o programa será abortado =[\n");
		printf("\nAbortando em 3, 2, 1...\n\n");
		system("pause");
		exit(1);
	}
	
	printf("\t\tProjeto Final\n\n");
	printf("Universidade Federal Rural do Semiárido (UFERSA) - Campus Pau dos Ferros");
	printf("\nDisciplina: Algoritmos e Estruturas de Dados II\n");
	printf("Docente: Thiago Pereira Rique\n");
	printf("Data: Março de 2017\n");
	printf("Discente: Dyego Magno Oliveira Souza\n\n");
	system("pause");
	system("cls");
	
	printf("Por favor, entre com o nome do Jogador: ");
	scanf(" %[^\n]s", nome_jogador);
	
	jogador = inicia_jogador(nome_jogador);
	
	do{
	
	system("cls");
	
	printf("\tMENU\n\n");
	printf("1 - Nível Fácil\n");
	printf("2 - Nível Intermediário\n");
	printf("3 - Nível Difícil\n");
	printf("4 - Modo Multiplayer\n");
	printf("5 - Ajuda\n");
	printf("6 - Sair\n");
	printf("\nESCOLHA: ");
		
	do{
		scanf("%d", &escolha);
		
		if(escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4 && escolha != 5 && escolha != 6)
		{
			printf("\nOpção inválida. Por favor, realize sua escolha de acordo com as opções!");
			printf("\n\nEscolha: ");
		}
		
		// Caso a escolha seja o modo Multiplayer, é necessário obter o nome do segundo jogador
		if(escolha == 4)
		{
			system("cls");
			
			printf("Por favor, entre com o nome do segundo Jogador: ");
			scanf(" %[^\n]s", nome_jogador);
			
			jogador2 = inicia_jogador(nome_jogador);
		}
		
	} while(escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4 && escolha != 5 && escolha != 6);
	
	system("cls");
	
	inicializa(mat);
	
	switch(escolha)
	{
		// Modo Fácil
		case 1:
			
			opcao = 1;
			
			/* Caso o jogador já tenha jogado algum outro modo, é necessário zerar a sua
			pontuação para que o seu score seja equivalente SOMENTE ao modo em execução! */
			jogador->pontuacao = 0;
			
			// Laço de repetição para repetir a jogatina, caso o jogador tenha vontade
			while(opcao == 1)
			{
				
				// Verifica se o usuário deseja jogar novamente NESTE modo
				do{
					printf("\nDeseja ser o primeiro a jogar? Escolha 1 para SIM e 2 para NÃO.\n\nEscolha: ");
					scanf("%d", &decisao);
					
					system("cls");
				} while(decisao != 1 && decisao != 2);

				// Caso o usuário deseje jogar novamente, é preciso reinicializar a matriz
				inicializa(mat);
				
				/* Laço de repetição para obter as nove jogadas referentes ao jogo. OBS: a cada iteração,
				duas jogadas são obtidas (jogador e IA)! */
				for(i = 0; i < 9 && checa_vencedoresX(mat) == 0 && checa_vencedoresO(mat) == 0; i++)
				{
					system("cls");
				
					apresenta_cabecalho(1, escolha, jogador, NULL);
				
					mostra(mat);
				
					// O jogador X sempre será X
					if((i + decisao) % 2 != 0)
					{
						printf("\n\nJogador X");
						DeterminaJogada(mat, player);
						
						system("cls");
						mostra(mat);
					}
					
					// O adversário será O
					else
					{
						printf("\n\nJogador O");
						JogadaAleatoria(mat, player2);
						
						system("cls");
						
						mostra(mat);
					}
					
					system("cls");
					mostra(mat);
			
					if(checa_vencedoresX(mat))
					{
						printf("\n\nVITÓRIA!\n\n");
						jogador_pontua(jogador);
						system("pause");
						break;
					}
					
					if(checa_vencedoresO(mat))
					{
						printf("\n\nDERROTA!\n\n");
						jogador_penaliza(jogador);
						system("pause");
						break;
					}
				
					printf("\n");
	    			system("pause");
	    			system("cls");
	    			mostra(mat);
				}
				
				if(i == 9 && checa_vencedoresX(mat) == 0 && checa_vencedoresO(mat) == 0)
				{
					printf("\n\nIHHH, parece que deu velha!\n\n");
					system("pause");
					system("cls");
				}
				
				// Verifica se o usuário deseja jogar novamente NESTE modo
				do{
					printf("\nDeseja jogar novamente? Escolha 1 para SIM e 2 para NÃO.\n\nEscolha: ");
					scanf("%d", &opcao);
					
					system("cls");
				} while(opcao != 1 && opcao != 2);
			}
			
			// Verifica se o jogador obteve uma pontuação
			if(jogador->pontuacao > 0)
			{
				printf("\nSua pontuação foi salva em um arquivo. Confira-o! =]\n\n");
				salva_pontuacao(arquivo, jogador, escolha);
			}
			else
			{
				printf("\n\nPoxa, parece que você não obteve uma pontuação. Que tal jogar outros modos? =]\n\n");
			}

			system("pause");
			break;
		
		// O Modo Intermediário ficará intercalando jogadas aleatórias com jogadas calculadas pelo alg. MiniMax para a IA
		case 2:
			
			opcao = 1;
			
			/* Caso o jogador já tenha jogado algum outro modo, é necessário zerar a sua
			pontuação para que o seu score seja equivalente SOMENTE ao modo em execução! */
			jogador->pontuacao = 0;
			
			// Laço de repetição para repetir a jogatina, caso o jogador tenha vontade
			while(opcao == 1)
			{
				// Verifica se o usuário deseja jogar novamente NESTE modo
				do{
					printf("\nDeseja ser o primeiro a jogar? Escolha 1 para SIM e 2 para NÃO.\n\nEscolha: ");
					scanf("%d", &decisao);
					
					system("cls");
				} while(decisao != 1 && decisao != 2);

				
				/* Laço de repetição para obter as nove jogadas referentes ao jogo. OBS: a cada iteração,
				duas jogadas são obtidas (jogador e IA)! */
				int VMatriz[9] = {0,0,0,0,0,0,0,0,0};
				MatConteudo matriz[3][3];
				
				// Caso o usuário deseje jogar novamente, é preciso reinicializar a matriz
				inicializa(matriz);
				
				// Laço de repetição para obter as jogadas
				for(i = 0; i < 9 && Vitoria(VMatriz) == 0; ++i) 
				{
  					system("cls");
					
					apresenta_cabecalho(1, escolha, jogador, NULL);
					  
					  // Computador jogará nos índices positivos
					if((i + decisao) % 2 == 0)
					{
            			// Calcula o melhor movimento para a IA
						if(i % 2 == 0)
						{
							ComputadorMovimento(VMatriz, matriz);
						}
						
						// Calcula uma jogada aleatória para a IA
						else
						{
							int indice = 1 + rand() % 8;
							VMatriz[indice] = 1;
							AtualizaMatriz(indice, matriz, O);
						}
					}
        
   					// Jogador, nos índices negativos
					else 
					{
            			mostra(matriz);
            			JogadorMovimento(VMatriz, matriz);
  					}
 				}
    
    			mostra(matriz);
    
			    switch(Vitoria(VMatriz)) 
				{
			        case 0:
			            printf("\n\nIHH, parece que deu velha!\n\n");
			            break;
			        case 1:
      			      //mostra(matriz);
			            printf("\n\nDERROTA!\n\n");
			            jogador_penaliza(jogador);
			            break;
			        case -1:
			            printf("\n\nVITÓRIA\n\n");
			            jogador_pontua(jogador);
			            break;
				}
				
				// Verifica se o usuário deseja jogar novamente NESTE modo
				do{
					printf("\nDeseja jogar novamente? Escolha 1 para SIM e 2 para NÃO.\n\nEscolha: ");
					scanf("%d", &opcao);
					
					system("cls");
				} while(opcao != 1 && opcao != 2);
			}
			
			// Verifica se o jogador obteve uma pontuação
			if(jogador->pontuacao > 0)
			{
				printf("\nSua pontuação foi salva em um arquivo. Confira-o! =]\n\n");
				salva_pontuacao(arquivo, jogador, escolha);
			}
			else
			{
				printf("\n\nPoxa, parece que você não obteve uma pontuação. Que tal jogar outros modos? =]\n\n");
			}

			system("pause");
			break;
		
		// O Modo Difícil utilizará o algoritmo MiniMax para calcular as melhores jogadas para a IA
		case 3:
			//apresenta_cabecalho(1, escolha, jogador, NULL);
			
			opcao = 1;
			
			/* Caso o jogador já tenha jogado algum outro modo, é necessário zerar a sua
			pontuação para que o seu score seja equivalente SOMENTE ao modo em execução! */
			jogador->pontuacao = 0;
			
			// Laço de repetição para repetir a jogatina, caso o jogador tenha vontade
			while(opcao == 1)
			{
				
				// Verifica se o usuário deseja jogar novamente NESTE modo
				do{
					printf("\nDeseja ser o primeiro a jogar? Escolha 1 para SIM e 2 para NÃO.\n\nEscolha: ");
					scanf("%d", &decisao);
					
					system("cls");
				} while(decisao != 1 && decisao != 2);

				
				/* Laço de repetição para obter as nove jogadas referentes ao jogo. OBS: a cada iteração,
				duas jogadas são obtidas (jogador e IA)! */
				//int turno;
				int VMatriz[9] = {0,0,0,0,0,0,0,0,0};
				MatConteudo matriz[3][3];
				
				// Caso o usuário deseje jogar novamente, é preciso reinicializar a matriz
				inicializa(matriz);
				
				for(i = 0; i < 9 && Vitoria(VMatriz) == 0; ++i) 
				{
  					system("cls");
					
					apresenta_cabecalho(1, escolha, jogador, NULL);
					  
					  // Computador jogará nos índices positivos
					if((i + decisao) % 2 == 0)
					{
            			ComputadorMovimento(VMatriz, matriz);
					}
        
   					else 
					{
            			mostra(matriz);
            			JogadorMovimento(VMatriz, matriz);
  					}
 				}
    
    			mostra(matriz);
    
			    switch(Vitoria(VMatriz)) 
				{
			        case 0:
			            printf("\n\nIHH, parece que deu velha!\n\n");
			            break;
			        case 1:
			            printf("\n\nDERROTA!\n\n");
			            jogador_penaliza(jogador);
			            break;
			        case -1:
			            printf("\n\nVITÓRIA\n\n");
			            jogador_pontua(jogador);
			            break;
				}
				
				// Verifica se o usuário deseja jogar novamente NESTE modo
				do{
					printf("\nDeseja jogar novamente? Escolha 1 para SIM e 2 para NÃO.\n\nEscolha: ");
					scanf("%d", &opcao);
					
					system("cls");
				} while(opcao != 1 && opcao != 2);
			}
			
			// Verifica se o jogador obteve uma pontuação
			if(jogador->pontuacao > 0)
			{
				printf("\nSua pontuação foi salva em um arquivo. Confira-o! =]\n\n");
				salva_pontuacao(arquivo, jogador, escolha);
			}
			else
			{
				printf("\n\nPoxa, parece que você não obteve uma pontuação. Que tal jogar outros modos? =]\n\n");
			}

			system("pause");
			break;
		
		// Modo Multiplayer
		case 4:
			
			opcao = 1;
			
			// Reseta pontuações anteriores
			jogador->pontuacao = 0;
			jogador2->pontuacao = 0;
			while(opcao == 1)
			{
				// Caso o usuário deseje jogar novamente, é preciso reinicializar a matriz
				inicializa(mat);
			
				for(i = 0; i < 9 && checa_vencedoresX(mat) == 0 && checa_vencedoresO(mat) == 0; i++)
				{
					system("cls");
					
					apresenta_cabecalho(2, 0, jogador, jogador2);
					printf("\n");
					
					mostra(mat);
					
					if(i % 2 == 0)
					{
						printf("\n\nJogador X");
						DeterminaJogada(mat, player);
					}
					else
					{
						printf("\n\nJogador O");
						DeterminaJogada(mat, player2);
					}
			
					system("cls");
					mostra(mat);
			
					if(checa_vencedoresX(mat))
					{
						printf("\n\nVITÓRIA DO JOGADOR X!\n\n");
						jogador_pontua(jogador);
						jogador_penaliza(jogador2);
						system("pause");
						break;
					}
					
					if(checa_vencedoresO(mat))
					{
						printf("\n\nVITÓRIA DO JOGADOR O!\n\n");
						jogador_pontua(jogador2);
						jogador_penaliza(jogador);
						system("pause");
						break;
					}
					printf("\n");
	    			system("pause");
	    			system("cls");
	    			mostra(mat);
				}
			
			if(i == 9 && checa_vencedoresX(mat) == 0 && checa_vencedoresO(mat) == 0)
			{
					printf("\n\nIHHH, parece que deu velha!\n\n");
					system("pause");
					system("cls");
			}
			
				// Verifica se o usuário deseja jogar novamente NESTE modo
				do{
					printf("\nDeseja jogar novamente? Escolha 1 para SIM e 2 para NÃO.\n\nEscolha: ");
					scanf("%d", &opcao);
					
					system("cls");
				} while(opcao != 1 && opcao != 2);
			}
			
			salva_pontuacao(arquivo, jogador, escolha);
			salva_pontuacao(arquivo, jogador2, escolha);
			break;
		case 5:
			apresenta_cabecalho(-1, 0, NULL, NULL);
			
			Ajuda_matriz();
			
			printf("\n\n");
			system("pause");
			system("cls");
			break;
		case 6:
			//jogador_pontua(jogador);
			
			if(jogador->pontuacao > 0)
				printf("\nTodas as suas pontuações foram salvas em um arquivo. Confira-o! =]\n");
			
			printf("\nObrigado por utilizar o sistema!\n\n");
			system("pause");
			system("cls");
			break;
	}
	
	} while(escolha != 6);
	
	fclose(arquivo);

	return(0);
}