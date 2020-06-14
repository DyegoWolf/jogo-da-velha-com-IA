#include <stdio.h>

/*	Fun��o que atualiza os dados de uma Matriz de acordo com o �ndice correspondente no vetor.
	S�o recebidos como entrada do indice, a matriz a ser atualizada e um identificador do jogador (X ou O).
	A sa�da � a pr�pria matriz atualizada corretamente. */
void AtualizaMatriz(int movimento, MatConteudo matriz[][3], MatConteudo jogador)
{
	// De acordo com o valor de movimento
	switch(movimento)
	{
		case 0:
			if(jogador == X) // O jogador � X?
			{
				matriz[0][0] = X;
			}
			else // Sen�o, o jogador � O!
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

/* 	Esta fun��o determina uma poss�vel vit�ria de acordo com a combina��o dos �ndices pr�-definidos.
	� recebido como entrada o vetor de �ndices da matriz.
	A sa�da � o maior valor entre a combina��o dos �ndices da matriz. */
int Vitoria(const int VMatriz[9]) 
{
	// Cria��o de uma matriz com todos os �ndices da vit�ria
	unsigned victory[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    
	/* Percorre todas as linhas da matriz, que ir�o conter os �ndices relativos � uma vit�ria
	no jogo (sendo que cada elemento da matriz representa uma determina combina��o vitoriosa). */
	for(i = 0; i < 8; ++i) 
	{
        // Verifica se � diferente de vazio e se as combina��es s�o v�lidas
		if(VMatriz[victory[i][0]] != 0 &&
           VMatriz[victory[i][0]] == VMatriz[victory[i][1]] &&
           VMatriz[victory[i][0]] == VMatriz[victory[i][2]])
           {
            	// Retorna o maior valor entre a combina��o dos �ndices da matriz
				return (VMatriz[victory[i][2]]);
		   }
    }
    
	return (0);
}

/*	Fun��o que avalia o valor de uma jogada, intercalando entre os dois diferentes tipos de jogadores.
	Esta fun��o recebe como entrada o vetor de �ndices da matriz e um identificador do jogador.
	A sa�da � o valor da avalia��o da posi��o. */
int minimax(int VMatriz[9], int jogador) 
{
    int movimento;
	
	// Verifica��o priorit�ria de vencedores na matriz
	int vencedor = Vitoria(VMatriz);
    
	/* A condi��o de contorno (ou desempilhamento da pilha, quando o algoritmo for chamado recursivamente,
	� uma vit�ria, independente do jogador (X ou O). */
	if(vencedor != 0) 
	{
		return(vencedor * jogador);
	}
	
	/* Sen�o, a vari�vel movimento receber� um valor negativo para diferenciar dos valores que representam
	os �ndices do la�o de repeti��o abaixo. */
    movimento = -1;
    
	// Movimentos perdedores n�o realizam movimentos
	int pontuacao = -2;		
    int i;
    
    // La�o de repeti��o para determinar todos os movimentos e construir a �rvore de Decis�o (implicitamente)
	for(i = 0; i < 9; ++i) 
	{
        // Caso a posi��o seja v�lida, ou seja, vazia
		if(VMatriz[i] == 0) 
		{
            // Testa este movimento recebendo o identificador do jogador
			VMatriz[i] = jogador;
			
			/* A vari�vel EstaPontuacao recebe o retorno recursivo da fun��o MiniMax. O identificador
			do advers�rio � multiplicado por -1 para diferenciar do jogador atual (1 e -1) */
            int PontuacaoTemp = -minimax(VMatriz, jogador*-1);
            
			/* Se o valor do retorno recursivo, obtido ap�s o desempilhamento, for maior
			do que o valor da vari�vel pontuacao, ent�o: */
			if(PontuacaoTemp > pontuacao) 
			{
                pontuacao = PontuacaoTemp;
                movimento = i;		// A vari�vel movimento armazena o �ndice com a maior pontua��o
            }
			
			// Transforma a posi��o em vazio de novo, pois foi feito apenas um teste
            VMatriz[i] = 0;
        }
    }
    
	/* Se n�o encontrou nenhuma posi��o com pontua��o maior do que o valor da vari�vel
	pontuacao, ent�o retorna 0. */
	if(movimento == -1) 
	{
		return 0;
	}
    
    // Sen�o, retorna a pontua��o calculada
	return(pontuacao);
}

/*	Fun��o que determina um movimento para a IA de acordo com o valor de retorno da fun��o MiniMax.
	S�o recebidos como entrada o vetor de �ndices da matriz e a pr�pria matriz.
	As sa�das s�o a atualiza��o do vetor de �ndices de acordo com o valor determinado e a matriz
	atualizada de acordo com esse valor, que corresponder� a um �ndice. */
void ComputadorMovimento(int VMatriz[9], MatConteudo matriz[][3]) 
{
    /* Movimento � declarado como -1 para diferenciar dos �ndices do la�o de repeti��o,
    pois esta vari�vel ir� receber os valores de acordo com a execu��o do la�o, para obter
    o campo com a melhor jogada */
	int movimento = -1;
    int pontuacao = -2;
    int i;
    
	for(i = 0; i < 9; ++i) 
	{
        // Procura uma posi��o v�lida para jogar
		if(VMatriz[i] == 0) 
		{
            // Preenche um campo com o identificador para obter uma poss�vel jogada
			VMatriz[i] = 1;
            
            /* Pontua��o recebe o retorno negativo da fun��o MiniMax.
            S�o passados como argumentos o vetor de �ndices com o �ltimo 
			preenchimento e um identificador do advers�rio */
			int PontuacaoTemp = -minimax(VMatriz, -1);
            
			// Transforma o campo em vazio, pois ele ainda n�o ser� preenchido
			VMatriz[i] = 0;
			
			// Se a pontua��o tempor�ria for superior a pontua��o anterior (ou padr�o)
            if(PontuacaoTemp > pontuacao) 
			{
                pontuacao = PontuacaoTemp;
                movimento = i;
            }
        }
    }
    
	/* Ap�s o c�lculo da melhor posi��o, a vari�vel movimento ir� armazenar o �ndice
	relativo ao n� da �rvore de Decis�o com a melhor jogada para o Computador, utilizando
	este valor para retornar uma pontua��o baseada na �rvore MiniMax em um determinado n�. */
	VMatriz[movimento] = 1;
	
    // Atualiza��o da matriz de acordo com o valor do �ndice
	AtualizaMatriz(movimento, matriz, O);
}

/*	Fun��o que determina e valida uma jogada do usu�rio.
	S�o recebidos como entrada o vetor de �ndices da matriz e a pr�pria matriz.
	As sa�das s�o o vetor atualizado com a pr�pria jogada e a matriz atualizada de acordo com
	o �ndice a que o valor recebido referencia (consultar fun��o AtualizaMatriz). */
void JogadorMovimento(int VMatriz[9], MatConteudo matriz[][3]) 
{
	
	int jogada = 0;
	
	// Valida as jogadas recebidas
	do{
		start: 
		
		printf("\n\nEscolha uma jogada entre 1 e 9: ");
		scanf("%d", &jogada);
		
		// Para condizer com os �ndices do vetor de �ndices da matriz
		jogada--;
		
		if(VMatriz[jogada] != 0)
		{
   			goto start;
		}
		
	}while(((jogada > 9) || jogada < 0) && (VMatriz[jogada] == 0)); 
	
	VMatriz[jogada] = -1;
	
	AtualizaMatriz(jogada, matriz, X);
}
