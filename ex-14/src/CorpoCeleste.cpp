#include "../include/CorpoCeleste.h"

CorpoCeleste::CorpoCeleste(Vetor2D posicao, Vetor2D velocidade, double massa, double raio, sf::Color cor)
    : posicao(posicao), velocidade(velocidade), massa(massa), raio(raio), cor(cor) {
    aceleracao = Vetor2D(0, 0);
}

Vetor2D CorpoCeleste::getPosicao() const {
    return posicao;
}

Vetor2D CorpoCeleste::getVelocidade() const {
    return velocidade;
}

double CorpoCeleste::getMassa() const {
    return massa;
}

double CorpoCeleste::getRaio() const {
    return raio;
}

sf::Color CorpoCeleste::getCor() const {
    return cor;
}

const std::vector<sf::Vector2f>& CorpoCeleste::getTrajetoria() const {
    return trajetoria;
}

void CorpoCeleste::setPosicao(const Vetor2D& pos) {
    posicao = pos;
}

void CorpoCeleste::setVelocidade(const Vetor2D& vel) {
    velocidade = vel;
}

void CorpoCeleste::setAceleracao(const Vetor2D& acel) {
    aceleracao = acel;
}

void CorpoCeleste::atualizar(double dt) {
    velocidade += aceleracao * dt;
    posicao += velocidade * dt;
}

void CorpoCeleste::adicionarPontoTrajetoria(const sf::Vector2f& ponto) {
    trajetoria.push_back(ponto);
    if (trajetoria.size() > maxPontosTrajetoria) {
        trajetoria.erase(trajetoria.begin());
    }
}

void CorpoCeleste::limparTrajetoria() {
    trajetoria.clear();
}