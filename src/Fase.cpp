#include "../include/Fases/Fase.h"
#include "../include/Entidades/Personagens/Inimigos/Cogumelo.h"
#include "../include/Entidades/Personagens/Inimigos/Perseguidor.h"
#include "../include/Entidades/Obstaculos/Plataforma.h"
using namespace Jogo;
using namespace Fases;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;
using namespace Jogadores;
using namespace Obstaculos;


Fase::Fase(const IDs::ID id) :Ente(id), listaObstaculos(), listaInimigos(), listaJogadores(), colisor(&listaJogadores, &listaInimigos, &listaObstaculos), pEventos(pEventos->getGerenciadorEventos()), fundo(Vector2f(800.0, 600.f),pGG->carregarTextura("./Assets/Fundo1.jpg"))
{
	if (!pEventos) {
		std::cout << "Nao foi possivel criar um gerenciador de eventos" << std::endl;
		exit(1);
	}
}

Fase::~Fase()
{
	if (pEventos) 
		pEventos = nullptr;
	
	listaInimigos.limparLista();
	listaObstaculos.limparLista();
	listaJogadores.limparLista();
}

void Fase::criarCogumelo(const sf::Vector2f pos)
{
	Cogumelo* cogumelo = new Entidades::Personagens::Inimigos::Cogumelo(pos, sf::Vector2f(34.f, 50.f));

	if (!cogumelo){
		std::cout << "Nao foi possivel criar o inimigo" << std::endl;
	}

	listaInimigos.addEntidade(static_cast<Entidades::Entidade*>(cogumelo));

}

void Fase::criarPerseguidor(const sf::Vector2f pos)
{
	Perseguidor* inimigo2 = new Entidades::Personagens::Inimigos::Perseguidor(pos, sf::Vector2f(52.f, 34.f));

	if (!inimigo2) {
		std::cout << "Nao foi possivel criar o inimigo" << std::endl;
	}

	listaInimigos.addEntidade(static_cast<Entidades::Entidade*>(inimigo2));

}

void Fase::criarObstaculo(const sf::Vector2f pos)
{
	Entidades::Obstaculos::Plataforma* plataforma1 = new Entidades::Obstaculos::Plataforma(pos, Vector2f(350.0f, 50.0f));


	if (!plataforma1) {
		std::cout << "Nao foi possivel criar a plataforma" << std::endl;
	}

	listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(plataforma1));
}

void Fase::criarJogador1(const sf::Vector2f pos)
{
	Entidades::Personagens::Jogadores::Jogador* jogador1 = new Entidades::Personagens::Jogadores::Jogador(pos, Vector2f(50.f, 50.f));

	if (!jogador1) {
		std::cout << "Nao foi possivel criar o jogador 1" << std::endl;
	}

	listaJogadores.addEntidade(static_cast<Entidades::Entidade*>(jogador1));

	pEventos->setJogador(jogador1);
	Perseguidor::setJogador(jogador1);
}

void Fase::criarJogador2(const sf::Vector2f pos)
{
	Entidades::Personagens::Jogadores::Jogador* jogador2 = new Entidades::Personagens::Jogadores::Jogador(pos, Vector2f(50.f, 50.f));

	if (!jogador2) {
		std::cout << "Nao foi possivel criar o jogador 2" << std::endl;
	}

	listaJogadores.addEntidade(static_cast<Entidades::Entidade*>(jogador2));

	pEventos->setJogador2(jogador2);
	Perseguidor::setJogador2(jogador2);
}

void Fase::criarEntidade(char letra, const sf::Vector2i pos)
{
	switch (letra)
	{
		case('a'):
		{
			criarCogumelo(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
		}
		break;

		case('p'):
		{
			criarPerseguidor(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
		}
		break;

		case('o'):
		{
			criarObstaculo(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
		}
		break;

		case('j'):
		{
			criarJogador1(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
		}
		break;

		case('J'):
		{
			criarJogador2(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
		}
		break;
	}

}

void Fase::desenhar()
{
	listaJogadores.executar();
	listaInimigos.executar();
	listaObstaculos.executar();
}

void Fase::executar()
{
	fundo.desenhar();
	desenhar();
	colisor.executar();
	pGG->resetarRelogio();
}