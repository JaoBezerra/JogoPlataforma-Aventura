#pragma once

#include "../Personagem.h"

using namespace sf;

#define VELOCIDADE_INIMIGO_X 75.0f
#define TEMPO_MOVER_ALEATORIO 1.0f

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			namespace Inimigos
			{
				class Inimigo : public Personagem
				{
				protected:
					//Texture textura;
					short moveAleatorio;
					float tempoMover;

					virtual void moveInimigo();
					void atualizaMovimentoAleatorio();
					void inicializa();

				public:
					Inimigo(const Vector2f pos, const Vector2f tam, const IDs::ID id);
					~Inimigo();
					void atualizar();
					void desenhar();
					void colisao(Entidade* outra, sf::Vector2f ds = sf::Vector2f(0.f, 0.f));
				};
			}
		}
	}
}