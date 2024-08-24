#include "../include/Entidades/Personagens/Jogadores/Jogador.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Jogadores;

int Jogador::cont_j(0);

Jogador::Jogador(const Vector2f pos, const Vector2f tam) :
	Personagem(pos, tam, VELOCIDADE_JOGADOR_X, IDs::ID::jogador), noChao(false), num_jogador(cont_j++)
{
	corpo.setFillColor(Color::Cyan);
	corpo.setPosition(pos);
	inicializa();
}

Jogador::~Jogador()
{

}

void Jogador::inicializa()
{
	/*animacao.addAnimacao("./Assets/Parado.png", "PARADO", 11, 0.12f, sf::Vector2f(2, 2));
	animacao.addAnimacao("./Assets/Anda.png", "ANDA", 12, 0.12f, sf::Vector2f(2, 2));
	corpo.setOrigin(sf::Vector2f(tam.x / 2.5f, tam.y / 2.0f));*/
}

const RectangleShape Jogador::getCorpo()
{
	return corpo;
}

void Jogador::atualizar()
{
	atualizarPosicao();
	//atualizarAnimacao();
}

void Jogador::desenhar()
{
	pGG->desenhaElementos(corpo);
}

void Jogador::atualizarAnimacao()
{
	if (andando) {
		animacao.atualizar(paraEsquerda, "ANDA");
	}
	else if (!andando) {
		animacao.atualizar(paraEsquerda, "PARADO");
	}
}

void Jogador::colisao(Entidade* outra, sf::Vector2f ds)
{
	switch (outra->getId())
	{
		case(IDs::ID::cogumelo) :
		{
			std::cout << "Colidiu com o cogumelo" << std::endl;
		}
		break;
		case(IDs::ID::perseguidor):
		{
			std::cout << "Colidiu com o perseguidor" << std::endl;
		}
		break;
		case(IDs::ID::obstaculo):
		{
			std::cout << "Colidiu com obstaculo" << std::endl;
		}
		break;
	}
}

void Jogador::podePular()
{
	noChao = true;
}

void Jogador::pular()
{
	if (noChao) {
		//std::cout << "Pulo realizado" << std::endl;
		velFinal.y = -sqrt(2.f * GRAVIDADE * TAMANHO_PULO);
		noChao = false;
	}
	/*else {
		std::cout << "Nao pode pular, noChao: " << noChao << std::endl;
	}*/
}

const bool Jogador::getAndando() const
{
	return andando;
}