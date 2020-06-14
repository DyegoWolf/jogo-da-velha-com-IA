

typedef enum{
	VAZIO = ' ',
	O = 'O',
	X = 'X'
} MatConteudo;


void DeterminaJogada(MatConteudo matriz[][3], char jogador);
void JogadaAleatoria(MatConteudo matriz[][3], char jogador);
void inicializa(MatConteudo matriz[][3]);
void mostra(MatConteudo matriz[][3]);
int checa_vencedoresX(MatConteudo matriz[][3]);
int checa_vencedoresO(MatConteudo matriz[][3]);
void Ajuda_matriz();