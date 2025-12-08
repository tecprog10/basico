#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <SFML/Graphics.hpp>
#include "Simulacao.h"
#include "Renderizador.h"

class Principal {
private:
    sf::RenderWindow janela;
    Simulacao* simulacao;
    Renderizador* renderizador;
    
    const int larguraJanela = 1200;
    const int alturaJanela = 800;
    
    void inicializar();
    void processarEventos();
    void atualizar();
    void renderizar();
    void obterDadosUsuario();
    void finalizar();

public:
    Principal();
    ~Principal();
    
    void executar();
};

#endif