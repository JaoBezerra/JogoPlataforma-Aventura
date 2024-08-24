#include "../include/Entidades/Personagens/Inimigos/Perseguidor.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

Entidades::Personagens::Jogadores::Jogador* Perseguidor::pJogador = nullptr;
Entidades::Personagens::Jogadores::Jogador* Perseguidor::pJogador2 = nullptr;

Perseguidor::Perseguidor(const Vector2f pos, const Vector2f tam) :Inimigo(pos, tam, IDs::ID::perseguidor)
{
	corpo.setFillColor(Color::Magenta);
	void inicializa();
}

Perseguidor::~Perseguidor()
{

}

void Perseguidor::inicializa()
{
	//animacao.addAnimacao("./Assets/RinoParado.png", "PARADO", 11, 0.12f, sf::Vector2f(2, 2));
	//animacao.addAnimacao("./Assets/RinoAndando.png", "RINOANDANDO", 6, 0.12f, sf::Vector2f(2, 2));
	//corpo.setOrigin(sf::Vector2f(tam.x / 2.5f, tam.y / 2.0f));
}

void Perseguidor::setJogador(Entidades::Personagens::Jogadores::Jogador* j)
{
	pJogador = j;
}

void Perseguidor::setJogador2(Entidades::Personagens::Jogadores::Jogador* j)
{
	pJogador2 = j;
}

void Perseguidor::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	if (posJogador.x - posInimigo.x > 0.f) {
		paraEsquerda = false;
		andar(paraEsquerda);
		//animacao.atualizar(paraEsquerda, "RINOANDANDO");
	}
	else {
		paraEsquerda = true;
		andar(paraEsquerda);
		//animacao.atualizar(paraEsquerda, "RINOANDANDO");
	}
}

void Perseguidor::moveInimigo()
{
	sf::Vector2f posJogador1 = pJogador->getCorpo().getPosition();
	sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();
	float dist1 = fabs(posJogador1.x - posInimigo.x);
	float dist2 = fabs(posJogador2.x - posInimigo.x);

	if (dist1 <= ALCANCE_X && dist1 <= ALCANCE_Y  &&
		(dist1 < dist2 || dist2 > ALCANCE_X || dist2 > ALCANCE_Y))
	{
		persegueJogador(posJogador1, posInimigo);
	}
	else if (dist2 <= ALCANCE_X && dist2 <= ALCANCE_Y)
	{
		persegueJogador(posJogador2, posInimigo);
	}
	else
	{
		atualizaMovimentoAleatorio();
	}
	
}

void Perseguidor::atualizarAnimacao()
{
	if (moveAleatorio == 0)
	{
		paraEsquerda = false;
		//animacao.atualizar(paraEsquerda, "RINOANDANDO");
	}
	else
	{
		paraEsquerda = true;
		//animacao.atualizar(paraEsquerda, "RINOANDANDO");
	}
}

