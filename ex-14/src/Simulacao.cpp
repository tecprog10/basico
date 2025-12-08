#include "../include/Simulacao.h"
#include <cmath>

Simulacao::Simulacao(double larguraEspaco, double alturaEspaco, double dt)
    : larguraEspaco(larguraEspaco), alturaEspaco(alturaEspaco), dt(dt) {
}

void Simulacao::adicionarCorpo(const CorpoCeleste& corpo) {
    corpos.push_back(corpo);
}

Vetor2D Simulacao::calcularForcaGravitacional(const CorpoCeleste& corpo1, const CorpoCeleste& corpo2) {
    Vetor2D direcao = corpo2.getPosicao() - corpo1.getPosicao();
    double distancia = direcao.magnitude();
    
    if (distancia < 1e3) {
        distancia = 1e3;
    }
    
    double forcaMagnitude = (G * corpo1.getMassa() * corpo2.getMassa()) / (distancia * distancia);
    
    Vetor2D forcaUnitaria = direcao.normalizado();
    return forcaUnitaria * forcaMagnitude;
}

void Simulacao::atualizar() {
    for (size_t i = 0; i < corpos.size(); i++) {
        Vetor2D forcaTotal(0, 0);
        
        for (size_t j = 0; j < corpos.size(); j++) {
            if (i != j) {
                Vetor2D forca = calcularForcaGravitacional(corpos[i], corpos[j]);
                forcaTotal += forca;
            }
        }
        
        Vetor2D aceleracao = forcaTotal / corpos[i].getMassa();
        corpos[i].setAceleracao(aceleracao);
    }
    
    for (size_t i = 0; i < corpos.size(); i++) {
        corpos[i].atualizar(dt);
    }
}

void Simulacao::limpar() {
    corpos.clear();
}

const std::vector<CorpoCeleste>& Simulacao::getCorpos() const {
    return corpos;
}

double Simulacao::getLarguraEspaco() const {
    return larguraEspaco;
}

double Simulacao::getAlturaEspaco() const {
    return alturaEspaco;
}

double Simulacao::getDt() const {
    return dt;
}

void Simulacao::setDt(double novoDt) {
    dt = novoDt;
}