#pragma once

#include "../Obstaculos/Obstaculo.h" //ver include

namespace Jogo
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Slime : public Obstaculo
            {
            private:
                sf::Texture textura;
                float pegajosidadePulo;
                float pegajosidadeMovimento;

            public:
                Slime(const Vector2f pos, const Vector2f tam);
                ~Slime();
                void atualizar();
                void danar(int jogador);
                //void Save(std::ofstream& savefile);
            	//void Load(std::ifstream& savefile);
            };
        }
    }
}

