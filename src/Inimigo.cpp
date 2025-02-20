#include "../include/Entidades/Personagens/Inimigos/Inimigo.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

Inimigo::Inimigo(const Vector2f pos, const Vector2f tam, const IDs::ID id) :
	Personagem(pos, tam, VELOCIDADE_INIMIGO_X, id), tempoMover(0.0f)
{
	inicializa();
	//textura = pGG->carregarTextura("./Assets/inimigo.png");
	//corpo.setTexture(&textura);
	moveAleatorio = rand() % 3;

	if (moveAleatorio == 0)
	{
		parar();
	}
	else if (moveAleatorio == 1)
	{
		andar(true);
	}
	else
	{
		andar(false);
	}
}

Inimigo::~Inimigo()
{

}

void Inimigo::inicializa()
{
	
}

void Inimigo::desenhar()
{
	pGG->desenhaElementos(corpo);
}

void Inimigo::colisao(Entidade* outra, sf::Vector2f ds)
{
	switch (outra->getId())
	{
		case(IDs::ID::jogador):
		{
			std::cout << "Colidiu com o jogador" << std::endl;
		}break;
	}
}

void Inimigo::atualizaMovimentoAleatorio()
{
	if (tempoMover > TEMPO_MOVER_ALEATORIO)
	{
		moveAleatorio = rand() % 3;
		if (moveAleatorio == 0) {
			parar();
		}
		else if (moveAleatorio == 1) {
			andar(true);
		}
		else {
			andar(false);
		}
		tempoMover = 0.0f;
	}
}

void Inimigo::moveInimigo()
{
	
}

void Inimigo::atualizar()
{
	moveInimigo();

	atualizarPosicao();

	tempoMover += pGG->getTempo();
}