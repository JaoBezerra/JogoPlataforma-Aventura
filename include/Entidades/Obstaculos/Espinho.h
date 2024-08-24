#pragma once

#include "Obstaculo.h"  //ver include

#define DANO_ESPINHO_PADRAO 35.0f
#define CAMINHO_TEXTURA_ESPINHO ""

namespace Jogo
{

    namespace Entidades
    {

        namespace Obstaculos
        {

            class Espinho : public Obstaculo {
            private:
                float dano;
                //void inicializarAnimacao();

            public:
                Espinho(const sf::Vector2f pos, const sf::Vector2f tam);
                Espinho(const std::vector<std::string> atributos);
                ~Espinho();
                void setDano(const float dano);
                const float getDano() const;
                void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)); // ver depois
                //const std::string salvar();
            };
        }
    }
}