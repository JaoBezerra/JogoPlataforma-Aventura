#include "../include/Entidades/Obstaculos/Slime.h" //ver include

#include <iostream> //acho que nao tem necessidade

using namespace Jogo;
using namespace Entidades;
using namespace Obstaculos;
using namespace sf;

 Slime::Slime(const sf::Vector2f pos, const sf::Vector2f tam) : Obstaculo(pos, tam, IDs::ID::slime), pegajosidadePulo(-0.13f), pegajosidadeMovimento(0.5f)
{
            //danoso = true;
            corpo = sf::RectangleShape(tam);
            corpo.setPosition(pos);
            corpo.setFillColor(Color::Red);


            /*if (!textura.loadFromFile("")) { //colocar path
                exit(1);
            }
            sprite.setTexture(textura);
            sprite.setPosition(Vector2f(pos.x - 102.0f, pos.y - 75.0f));
            sprite.setScale(0.5f, 0.31f);*/


}

Slime::~Slime()
{
}

        void Slime::atualizar()
        {
            //desenharSprite();
        }

        void Slime::danar(int jogador)
        {
           /* if (jogador == 1)
            {
                jogador1->setLento(true, 300, pegajosidadeMovimento, pegajosidadePulo);
            }
            else if (jogador == 2)
            {
                jogador2->setLento(true, 300, pegajosidadeMovimento, pegajosidadePulo);

            }*/

        }
        /* void Slime::limparArquivo(int save)
        {
            std::ofstream arquivo("Saves/save" + std::to_string(save) + "_slime.txt", std::ofstream::out);

            if (arquivo.is_open())
            {
                arquivo.close();
            }
        }
        void Slime::salvar(int save)
        {
            std::ofstream arquivo("Saves/save" + to_string(save) + "_slime.txt", std::ios::app);

            if (arquivo.is_open())
            {
                arquivo << "Posicao: " << corpo.getPosition().x << " " << corpo.getPosition().y << "\n";

                arquivo.close();
            }
        } */
