#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Personagem.h"

#define VELOCIDADE_JOGADOR_X 200.0f
#define TAMANHO_PULO 120.f

using namespace sf;

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			namespace Jogadores
			{
				class Jogador : public Personagem
				{
				private:
					int num_jogador;
					static int cont_j;
					bool noChao;
					void inicializa();

				public:
					Jogador(const Vector2f pos, const Vector2f tam);
					~Jogador();
					const RectangleShape getCorpo();
					void atualizar();
					void atualizarAnimacao();
					void desenhar();
					void colisao(Entidade* outra, sf::Vector2f ds = sf::Vector2f(0.f, 0.f));
					void podePular();
					void pular();
					const bool getAndando() const;
				};
			}
		}
	}
}