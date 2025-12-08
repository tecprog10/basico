#ifndef SIMULACAO_H
#define SIMULACAO_H

#include "CorpoCeleste.h"
#include <vector>

class Simulacao {
private:
    std::vector<CorpoCeleste> corpos;
    double dt;
    double larguraEspaco;
    double alturaEspaco;
    const double G = 6.67430e-11;
    
    Vetor2D calcularForcaGravitacional(const CorpoCeleste& corpo1, const CorpoCeleste& corpo2);

public:
    Simulacao(double larguraEspaco, double alturaEspaco, double dt);
    
    void adicionarCorpo(const CorpoCeleste& corpo);
    void atualizar();
    void limpar();
    
    const std::vector<CorpoCeleste>& getCorpos() const;
    double getLarguraEspaco() const;
    double getAlturaEspaco() const;
    double getDt() const;
    void setDt(double novoDt);
};

#endif