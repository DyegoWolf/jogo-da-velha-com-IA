#include <stdio.h>

/*	Função que atualiza os dados de uma Matriz de acordo com o índice correspondente no vetor.
	São recebidos como entrada do indice, a matriz a ser atualizada e um identificador do jogador (X ou O).
	A saída é a própria matriz atualizada corretamente. */
void AtualizaMatriz(int movimento, MatConteudo matriz[][3], MatConteudo jogador)
{
	// De acordo com o valor de movimento
	switch(movimento)
	{
		case 0:
			if(jogador == X) // O jogador é X?
			{
				matriz[0][0] = X;
			}
			else // Senão, o jogador é O!
			{
				matriz[0][0] = O;
			}
			break;
		case 1:
			if(jogador == X)
			{
				matriz[0][1] = X;
			}
			else
			{
				matriz[0][1] = O;
			}
			break;
		case 2:
			if(jogador == X)
			{
				matriz[0][2] = X;
			}
			else
			{
				matriz[0][2] = O;
			}
			break;
		case 3:
			if(jogador == X)
			{
				matriz[1][0] = X;
			}
			else
			{
				matriz[1][0] = O;
			}
			break;
		case 4:
			if(jogador == X)
			{
				matriz[1][1] = X;
			}
			else
			{
				matriz[1][1] = O;
			}
			break;
		case 5:
			if(jogador == X)
			{
				matriz[1][2] = X;
			}
			else
			{
				matriz[1][2] = O;
			}
			break;
		case 6:
			if(jogador == X)
			{
				matriz[2][0] = X;
			}
			else
			{
				matriz[2][0] = O;
			}
			break;
		case 7:
			if(jogador == X)
			{
				matriz[2][1] = X;
			}
			else
			{
				matriz[2][1] = O;
			}
			break;
		case 8:
			if(jogador == X)
			{
				matriz[2][2] = X;
			}
			else
			{
				matriz[2][2] = O;
			}
			break;
	}
}

/* 	Esta função determina uma possível vitória de acordo com a combinação dos índices pré-definidos.
	É recebido como entrada o vetor de índices da matriz.
	A saída é o maior valor entre a combinação dos índices da matriz. */
int Vitoria(const int VMatriz[9]) 
{
	// Criação de uma matriz com todos os índices da vitória
	unsigned victory[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    
	/* Percorre todas as linhas da matriz, que irão conter os índices relativos à uma vitória
	no jogo (sendo que cada elemento da matriz representa uma determina combinação vitoriosa). */
	for(i = 0; i < 8; ++i) 
	{
        // Verifica se é diferente de vazio e se as combinações são válidas
		if(VMatriz[victory[i][0]] != 0 &&
           VMatriz[victory[i][0]] == VMatriz[victory[i][1]] &&
           VMatriz[victory[i][0]] == VMatriz[victory[i][2]])
           {
            	// Retorna o maior valor entre a combinação dos índices da matriz
				return (VMatriz[victory[i][2]]);
		   }
    }
    
	return (0);
}

/*	Função que avalia o valor de uma jogada, intercalando entre os dois diferentes tipos de jogadores.
	Esta função recebe como entrada o vetor de índices da matriz e um identificador do jogador.
	A saída é o valor da avaliação da posição. */
int minimax(int VMatriz[9], int jogador) 
{
    int movimento;
	
	// Verificação prioritária de vencedores na matriz
	int vencedor = Vitoria(VMatriz);
    
	/* A condição de contorno (ou desempilhamento da pilha, quando o algoritmo for chamado recursivamente,
	é uma vitória, independente do jogador (X ou O). */
	if(vencedor != 0) 
	{
		return(vencedor * jogador);
	}
	
	/* Senão, a variável movimento receberá um valor negativo para diferenciar dos valores que representam
	os índices do laço de repetição abaixo. */
    movimento = -1;
    
	// Movimentos perdedores não realizam movimentos
	int pontuacao = -2;		
    int i;
    
    // Laço de repetição para determinar todos os movimentos e construir a Árvore de Decisão (implicitamente)
	for(i = 0; i < 9; ++i) 
	{
        // Caso a posição seja válida, ou seja, vazia
		if(VMatriz[i] == 0) 
		{
            // Testa este movimento recebendo o identificador do jogador
			VMatriz[i] = jogador;
			
			/* A variável EstaPontuacao recebe o retorno recursivo da função MiniMax. O identificador
			do adversário é multiplicado por -1 para diferenciar do jogador atual (1 e -1) */
            int PontuacaoTemp = -minimax(VMatriz, jogador*-1);
            
			/* Se o valor do retorno recursivo, obtido após o desempilhamento, for maior
			do que o valor da variável pontuacao, então: */
			if(PontuacaoTemp > pontuacao) 
			{
                pontuacao = PontuacaoTemp;
                movimento = i;		// A variável movimento armazena o índice com a maior pontuação
            }
			
			// Transforma a posição em vazio de novo, pois foi feito apenas um teste
            VMatriz[i] = 0;
        }
    }
    
	/* Se não encontrou nenhuma posição com pontuação maior do que o valor da variável
	pontuacao, então retorna 0. */
	if(movimento == -1) 
	{
		return 0;
	}
    
    // Senão, retorna a pontuação calculada
	return(pontuacao);
}

/*	Função que determina um movimento para a IA de acordo com o valor de retorno da função MiniMax.
	São recebidos como entrada o vetor de índices da matriz e a própria matriz.
	As saídas são a atualização do vetor de índices de acordo com o valor determinado e a matriz
	atualizada de acordo com esse valor, que corresponderá a um índice. */
void ComputadorMovimento(int VMatriz[9], MatConteudo matriz[][3]) 
{
    /* Movimento é declarado como -1 para diferenciar dos índices do laço de repetição,
    pois esta variável irá receber os valores de acordo com a execução do laço, para obter
    o campo com a melhor jogada */
	int movimento = -1;
    int pontuacao = -2;
    int i;
    
	for(i = 0; i < 9; ++i) 
	{
        // Procura uma posição válida para jogar
		if(VMatriz[i] == 0) 
		{
            // Preenche um campo com o identificador para obter uma possível jogada
			VMatriz[i] = 1;
            
            /* Pontuação recebe o retorno negativo da função MiniMax.
            São passados como argumentos o vetor de índices com o último 
			preenchimento e um identificador do adversário */
			int PontuacaoTemp = -minimax(VMatriz, -1);
            
			// Transforma o campo em vazio, pois ele ainda não será preenchido
			VMatriz[i] = 0;
			
			// Se a pontuação temporária for superior a pontuação anterior (ou padrão)
            if(PontuacaoTemp > pontuacao) 
			{
                pontuacao = PontuacaoTemp;
                movimento = i;
            }
        }
    }
    
	/* Após o cálculo da melhor posição, a variável movimento irá armazenar o índice
	relativo ao nó da Árvore de Decisão com a melhor jogada para o Computador, utilizando
	este valor para retornar uma pontuação baseada na árvore MiniMax em um determinado nó. */
	VMatriz[movimento] = 1;
	
    // Atualização da matriz de acordo com o valor do índice
	AtualizaMatriz(movimento, matriz, O);
}

/*	Função que determina e valida uma jogada do usuário.
	São recebidos como entrada o vetor de índices da matriz e a própria matriz.
	As saídas são o vetor atualizado com a própria jogada e a matriz atualizada de acordo com
	o índice a que o valor recebido referencia (consultar função AtualizaMatriz). */
void JogadorMovimento(int VMatriz[9], MatConteudo matriz[][3]) 
{
	
	int jogada = 0;
	
	// Valida as jogadas recebidas
	do{
		start: 
		
		printf("\n\nEscolha uma jogada entre 1 e 9: ");
		scanf("%d", &jogada);
		
		// Para condizer com os índices do vetor de índices da matriz
		jogada--;
		
		if(VMatriz[jogada] != 0)
		{
   			goto start;
		}
		
	}while(((jogada > 9) || jogada < 0) && (VMatriz[jogada] == 0)); 
	
	VMatriz[jogada] = -1;
	
	AtualizaMatriz(jogada, matriz, X);
}
