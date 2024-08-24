#include "../include/Entidades/Obstaculos/Obstaculo.h"

using namespace Jogo;
using namespace Entidades;
using namespace Obstaculos;

Obstaculo::Obstaculo(const Vector2f pos, const Vector2f tam, const IDs::ID id) : Entidade(pos, tam, id), danoso(false)
{
	//corpo.setPosition(pos);
	//textura = pGG->carregarTextura("./Assets/plataforma.png");
	//corpo.setTexture(&textura);
}

Obstaculo::~Obstaculo()
{

}

void Obstaculo::atualizar()
{
    // desenhar();
}

void Obstaculo::colisao(Entidade* outra, sf::Vector2f ds)
{

	/*if (outra->getId() == IDs::ID::jogador ||
        outra->getId() == IDs::ID::aleatorio ||
        outra->getId() == IDs::ID::perseguidor
		)
	{
		colisaoObstaculo(ds, static_cast<Personagens::Personagem*>(outra));
	}*/
}

const bool Obstaculo::getDanoso() const
{
    return danoso;
}

/*void Obstaculo::colisaoObstaculo(sf::Vector2f ds, Personagens::Personagem* pPersonagem) {
    sf::Vector2f posOutro = pPersonagem->getPos();
    sf::Vector2f tamOutro = pPersonagem->getTam();
    sf::Vector2f velFinal = pPersonagem->getVelFinal();
    if (ds.x < 0.0f && ds.y < 0.0f) { //houve colisao
        if (ds.x > ds.y) {
            if (posOutro.x < pos.x) { //colisão em x
                posOutro.x += ds.x;
                std::cout << "Colidiu com jogador" << std::endl;
            }
            else {
                posOutro.x -= ds.x;
                std::cout << "Colidiu com jogador" << std::endl;
            }
            velFinal.x = 0.0f;
        }
        else {
            if (posOutro.y < pos.y) { //colisão em y
                posOutro.y += ds.y;
                if (pPersonagem->getId() == IDs::ID::jogador) {
                    Personagens::Jogadores::Jogador* pJogador = static_cast<Personagens::Jogadores::Jogador*>(pPersonagem);
                    pJogador->podePular();
                }
            }
            else {
                posOutro.y -= ds.y;
            }
            velFinal.y = 0.0f;
        }
    }
    pPersonagem->setPos(posOutro);
    pPersonagem->setVelFinal(velFinal);
}

const std::string Obstaculo::salvar() {
    std::string linha = salvarEntidade();
    return linha;
}

}*/