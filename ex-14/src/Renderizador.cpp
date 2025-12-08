#include "../include/Renderizador.h"

Renderizador::Renderizador(sf::RenderWindow& janela, double larguraEspaco, double alturaEspaco)
    : janela(janela) {
    atualizarEscala(larguraEspaco, alturaEspaco);
}

void Renderizador::atualizarEscala(double larguraEspaco, double alturaEspaco) {
    sf::Vector2u tamanhoJanela = janela.getSize();
    escalaX = tamanhoJanela.x / larguraEspaco;
    escalaY = tamanhoJanela.y / alturaEspaco;
}

sf::Vector2f Renderizador::converterParaTela(const Vetor2D& posicaoEspaco) {
    float x = static_cast<float>(posicaoEspaco.getX() * escalaX);
    float y = static_cast<float>(posicaoEspaco.getY() * escalaY);
    return sf::Vector2f(x, y);
}

void Renderizador::renderizar(const Simulacao& simulacao) {
    janela.clear(sf::Color::Black);
    
    const std::vector<CorpoCeleste>& corpos = simulacao.getCorpos();
    
    for (const auto& corpo : corpos) {
        const std::vector<sf::Vector2f>& trajetoria = corpo.getTrajetoria();
        
        if (trajetoria.size() > 1) {
            sf::VertexArray linhas(sf::PrimitiveType::LineStrip, trajetoria.size());
            for (size_t i = 0; i < trajetoria.size(); i++) {
                linhas[i].position = trajetoria[i];
                sf::Color corTrajetoria = corpo.getCor();
                corTrajetoria.a = 100;
                linhas[i].color = corTrajetoria;
            }
            janela.draw(linhas);
        }
        
        sf::Vector2f posicaoTela = converterParaTela(corpo.getPosicao());
        
        sf::CircleShape circulo(static_cast<float>(corpo.getRaio()));
        circulo.setFillColor(corpo.getCor());
        circulo.setOrigin(sf::Vector2f(static_cast<float>(corpo.getRaio()), static_cast<float>(corpo.getRaio())));
        circulo.setPosition(posicaoTela);
        
        janela.draw(circulo);
    }
    
    janela.display();
}