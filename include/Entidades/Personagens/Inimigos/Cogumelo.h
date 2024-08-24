#pragma once

#include "Inimigo.h"


namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			namespace Inimigos
			{
				class Cogumelo :public Inimigo
				{
				private:
					void inicializa();
				public:
					Cogumelo(const Vector2f pos, const Vector2f tam);
					~Cogumelo();
					void atualizarAnimacao();
					void moveInimigo();
				};
			}
		}
	}
}