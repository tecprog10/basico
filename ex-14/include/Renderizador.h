#ifndef RENDERIZADOR_H
#define RENDERIZADOR_H

#include <SFML/Graphics.hpp>
#include "Simulacao.h"

class Renderizador {
private:
    sf::RenderWindow& janela;
    double escalaX;
    double escalaY;
    
    sf::Vector2f converterParaTela(const Vetor2D& posicaoEspaco);

public:
    Renderizador(sf::RenderWindow& janela, double larguraEspaco, double alturaEspaco);
    
    void renderizar(const Simulacao& simulacao);
    void atualizarEscala(double larguraEspaco, double alturaEspaco);
};

#endif