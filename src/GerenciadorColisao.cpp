#include "../include/Gerenciadores/GerenciadorColisao.h"

using namespace Jogo;
using namespace Gerenciadores;
using namespace sf;

GerenciadorColisao::GerenciadorColisao(Listas::ListaEntidade* lP, Listas::ListaEntidade* lO) :listaPersonagem(lP), listaObstaculos(lO)
{
	
}

GerenciadorColisao::~GerenciadorColisao()
{
	if (listaObstaculos)
		delete listaObstaculos;
	if (listaPersonagem)
		delete listaPersonagem;
}

const Vector2f GerenciadorColisao::calculaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2)
{
	Vector2f pos1 = ent1->getPos();
	Vector2f pos2 = ent2->getPos();

	Vector2f tam1 = ent1->getTam();
	Vector2f tam2 = ent2->getTam();

	Vector2f distanciaCentros(
		fabs((pos1.x + tam1.x / 2.f) - (pos2.x + tam2.x / 2.f)),
		fabs((pos1.y + tam1.y / 2.f) - (pos2.y + tam2.y / 2.f))
	);

	Vector2f somaMetadeRetangulo(tam1.x / 2.f + tam2.x / 2.f, tam1.y / 2.f + tam2.y / 2.f);
	return Vector2f(distanciaCentros.x - somaMetadeRetangulo.x, distanciaCentros.y - somaMetadeRetangulo.y);
}

void GerenciadorColisao::executar()
{
	
	//Verifica colisao entre personagem e personagem

	for (int i = 0; i < listaPersonagem->getTam(); i++)
	{
		Entidades::Entidade* ent1 = listaPersonagem->operator[](i);
		for (int j = i + 1; j < listaPersonagem->getTam(); j++)
		{
			Entidades::Entidade* ent2 = listaPersonagem->operator[](j);
			Vector2f ds = calculaColisao(ent1, ent2);
			if (ds.x < 0.0f && ds.y < 0.0f)
				ent1->colisao(ent2);
		}
	}
	//std::cout << " " << listaPersonagem->getTam() << std::endl;
	//Verifica colisao entre personagem e obstaculo

	for (int i = 0; i < listaPersonagem->getTam(); i++)
	{
		Entidades::Entidade* ent1 = listaPersonagem->operator[](i);
		for (int j = 0; j < listaObstaculos->getTam(); j++)
		{
			Entidades::Entidade* ent2 = listaObstaculos->operator[](j);
			//std::cout << "Id ent1:  " << (int)ent1->getId() << std::endl;
			//std::cout << "Id ent2:  " << (int)ent2->getId() << std::endl;

			Vector2f ds = calculaColisao(ent1, ent2);
			if (ds.x < 0.0f && ds.y < 0.0f) {

				ent2->colisao(ent1, ds);
			}
			/*else {
				
			}*/
		}
		//std::cout << std::endl;
	}
}