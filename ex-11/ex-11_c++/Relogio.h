#pragma once

#include <chrono>

class Relogio {
private:
    int ano;
    int mes;
    int dia;
    int hora;
    int minutos;
    int segundos;
    long long nanossegundos;
    
    // Armazena o tempo de criação do relógio
    std::chrono::steady_clock::time_point tempoInicial;
    
public:
    // Construtora com parâmetros
    Relogio(int ano, int mes, int dia, int hora, int minutos, int segundos, long long nanossegundos);
    
    // Construtora com data/hora atuais
    Relogio();
    
    // Método getAgora() - retorna o tempo atual com precisão de nanossegundos
    void getAgora();
    
    // Método para exibir o tempo inicial
    void exibirTempoInicial();
};
