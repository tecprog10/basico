#ifndef CORPO_CELESTE_H
#define CORPO_CELESTE_H

#include "Vetor2D.h"
#include <SFML/Graphics.hpp>
#include <vector>

class CorpoCeleste {
private:
    Vetor2D posicao;
    Vetor2D velocidade;
    Vetor2D aceleracao;
    double massa;
    double raio;
    sf::Color cor;
    std::vector<sf::Vector2f> trajetoria;
    const size_t maxPontosTrajetoria = 1000;

public:
    CorpoCeleste(Vetor2D posicao, Vetor2D velocidade, double massa, double raio, sf::Color cor);
    
    Vetor2D getPosicao() const;
    Vetor2D getVelocidade() const;
    double getMassa() const;
    double getRaio() const;
    sf::Color getCor() const;
    const std::vector<sf::Vector2f>& getTrajetoria() const;
    
    void setPosicao(const Vetor2D& pos);
    void setVelocidade(const Vetor2D& vel);
    void setAceleracao(const Vetor2D& acel);
    
    void atualizar(double dt);
    void adicionarPontoTrajetoria(const sf::Vector2f& ponto);
    void limparTrajetoria();
};

#endif