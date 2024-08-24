#pragma once

#include <SFML/Graphics.hpp>
#include "../Listas/ListaEntidade.h"
#include <cmath>

namespace Jogo
{
	namespace Gerenciadores
	{
		class GerenciadorColisao
		{
		private:
			Listas::ListaEntidade* listaPersonagem;
			Listas::ListaEntidade* listaObstaculos;

		public:
			GerenciadorColisao(Listas::ListaEntidade* lP, Listas::ListaEntidade* lO);
			~GerenciadorColisao();
			const sf::Vector2f calculaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2);
			void executar();
		};
	}
}
