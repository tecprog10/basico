#include "../include/Principal.h"
#include <iostream>
#include <random>

Principal::Principal() {
    simulacao = nullptr;
    renderizador = nullptr;
}

Principal::~Principal() {
    finalizar();
}

void Principal::inicializar() {
    janela.create(sf::VideoMode({static_cast<unsigned int>(larguraJanela), static_cast<unsigned int>(alturaJanela)}), "Simulacao Gravitacional");
    janela.setFramerateLimit(60);
    obterDadosUsuario();
}

void Principal::obterDadosUsuario() {
    std::cout << "=== SIMULACAO DE ATRACAO GRAVITACIONAL ===" << std::endl;
    std::cout << std::endl;
    
    double larguraEspaco, alturaEspaco;
    std::cout << "Digite a largura do espaco (em metros, ex: 100e9 para 100 milhoes de km): ";
    std::cin >> larguraEspaco;
    std::cout << "Digite a altura do espaco (em metros): ";
    std::cin >> alturaEspaco;
    
    double dt;
    std::cout << "Digite o intervalo de tempo (em segundos, ex: 3600 para 1 hora): ";
    std::cin >> dt;
    
    simulacao = new Simulacao(larguraEspaco, alturaEspaco, dt);
    renderizador = new Renderizador(janela, larguraEspaco, alturaEspaco);
    
    std::cout << std::endl;
    std::cout << "Deseja posicionar os corpos aleatoriamente? (1-Sim, 0-Nao): ";
    int aleatorio;
    std::cin >> aleatorio;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> disX(0, larguraEspaco);
    std::uniform_real_distribution<> disY(0, alturaEspaco);
    
    for (int i = 0; i < 2; i++) {
        std::cout << std::endl;
        std::cout << "=== CORPO " << (i + 1) << " ===" << std::endl;
        
        double posX, posY;
        if (aleatorio == 1) {
            posX = disX(gen);
            posY = disY(gen);
            std::cout << "Posicao aleatoria: X=" << posX << " m, Y=" << posY << " m" << std::endl;
        } else {
            std::cout << "Digite a posicao X (em metros): ";
            std::cin >> posX;
            std::cout << "Digite a posicao Y (em metros): ";
            std::cin >> posY;
        }
        
        double velX, velY;
        std::cout << "Digite a velocidade X (em m/s, ex: 30000 para 30 km/s): ";
        std::cin >> velX;
        std::cout << "Digite a velocidade Y (em m/s): ";
        std::cin >> velY;
        
        double massa;
        std::cout << "Digite a massa (em kg, ex: 6e27): ";
        std::cin >> massa;
        
        double raio = 10.0 + i * 5.0;
        sf::Color cor = (i == 0) ? sf::Color::Yellow : sf::Color::Cyan;
        
        Vetor2D posicao(posX, posY);
        Vetor2D velocidade(velX, velY);
        
        CorpoCeleste corpo(posicao, velocidade, massa, raio, cor);
        simulacao->adicionarCorpo(corpo);
    }
    
    std::cout << std::endl;
    std::cout << "Simulacao iniciada! Pressione ESC para sair." << std::endl;
    std::cout << "Pressione ESPACO para pausar/continuar." << std::endl;
    std::cout << "Pressione R para reiniciar." << std::endl;
}

void Principal::processarEventos() {
    while (const std::optional evento = janela.pollEvent()) {
        if (evento->is<sf::Event::Closed>()) {
            janela.close();
        }
        
        if (const auto* keyPressed = evento->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->code == sf::Keyboard::Key::Escape) {
                janela.close();
            }
            if (keyPressed->code == sf::Keyboard::Key::R) {
                finalizar();
                obterDadosUsuario();
            }
        }
    }
}

void Principal::atualizar() {
    if (simulacao) {
        simulacao->atualizar();
        
        for (size_t i = 0; i < simulacao->getCorpos().size(); i++) {
            const CorpoCeleste& corpo = simulacao->getCorpos()[i];
            sf::Vector2u tamanhoJanela = janela.getSize();
            
            double escalaX = tamanhoJanela.x / simulacao->getLarguraEspaco();
            double escalaY = tamanhoJanela.y / simulacao->getAlturaEspaco();
            
            float x = static_cast<float>(corpo.getPosicao().getX() * escalaX);
            float y = static_cast<float>(corpo.getPosicao().getY() * escalaY);
            
            sf::Vector2f posicaoTela(x, y);
            
            const_cast<CorpoCeleste&>(corpo).adicionarPontoTrajetoria(posicaoTela);
        }
    }
}

void Principal::renderizar() {
    if (renderizador && simulacao) {
        renderizador->renderizar(*simulacao);
    }
}

void Principal::finalizar() {
    if (simulacao) {
        delete simulacao;
        simulacao = nullptr;
    }
    if (renderizador) {
        delete renderizador;
        renderizador = nullptr;
    }
}

void Principal::executar() {
    inicializar();
    
    while (janela.isOpen()) {
        processarEventos();
        atualizar();
        renderizar();
    }
    
    finalizar();
}