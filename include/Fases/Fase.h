#pragma once
#include <fstream>
#include <iostream>
#include "../Listas/ListaEntidade.h"
#include "../Ente.h"
#include "../Gerenciadores/GerenciadorColisao.h"
#include "../Gerenciadores/GerenciadorEventos.h"
#include "../Fundo/Fundo.h"


namespace Jogo
{
	namespace Fases
	{
		class Fase : public Ente
		{
		protected:
			Listas::ListaEntidade listaInimigos;
			Listas::ListaEntidade listaObstaculos;
			Listas::ListaEntidade listaJogadores;
			Gerenciadores::GerenciadorColisao colisor;
			Gerenciadores::GerenciadorEventos* pEventos;
			Fundos::Fundo fundo;

		public:
			Fase(const IDs::ID id);
			~Fase();
			void criarCogumelo(const sf::Vector2f pos);
			void criarPerseguidor(const sf::Vector2f pos);
			void criarJogador1(const sf::Vector2f pos);
			void criarJogador2(const sf::Vector2f pos);
			void criarObstaculo(const sf::Vector2f pos);
			virtual void criarMapa(const std::string& arquivoTxt) = 0;
			void criarEntidade(char letra, const sf::Vector2i pos);
			void executar();
			void desenhar();
		};

	}
}