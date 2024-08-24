#pragma once

#include "../Entidade.h"
#include "../Personagens/Jogadores/Jogador.h"
#include "../Personagens/Inimigos/Inimigo.h"


using namespace sf;

namespace Jogo
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Obstaculo : public Entidade
			{
			protected:
				bool danoso;
				//sf::Texture textura;
			public:
				Obstaculo(const Vector2f pos, const Vector2f tam, const IDs::ID id);
				~Obstaculo();
				virtual void atualizar(); //desenhar
				const bool getDanoso() const;
				virtual void colisao(Entidade* outra, sf::Vector2f ds);
				virtual void colisaoObstaculo(Vector2f ds, Personagens::Personagem* pPersonagem) = 0;
			};
		}
	}
}