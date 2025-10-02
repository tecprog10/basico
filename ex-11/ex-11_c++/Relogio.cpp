#include "Relogio.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace chrono;

// Construtora com parâmetros
Relogio::Relogio(int ano, int mes, int dia, int hora, int minutos, int segundos, long long nanossegundos) {
    this->ano = ano;
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->minutos = minutos;
    this->segundos = segundos;
    this->nanossegundos = nanossegundos;
    this->tempoInicial = steady_clock::now();
}
Relogio::Relogio() {
    // Obtém o tempo atual do sistema
    auto agora = system_clock::now();
    time_t tempo = system_clock::to_time_t(agora);
    tm* tempoLocal = localtime(&tempo);
    
    this->ano = tempoLocal->tm_year + 1900;
    this->mes = tempoLocal->tm_mon + 1;
    this->dia = tempoLocal->tm_mday;
    this->hora = tempoLocal->tm_hour;
    this->minutos = tempoLocal->tm_min;
    this->segundos = tempoLocal->tm_sec;
    // Obtém os milissegundos e converte para nanossegundos
    auto ms = duration_cast<milliseconds>(agora.time_since_epoch()) % 1000;
    this->nanossegundos = ms.count() * 1000000; // 1 ms = 10^6 ns
    
    this->tempoInicial = steady_clock::now();
}
void Relogio::getAgora() {
    // Calcula o tempo decorrido desde a criação do relógio
    auto tempoAtual = steady_clock::now();
    auto tempoDecorrido = duration_cast<nanoseconds>(tempoAtual - tempoInicial);
    
    // Adiciona o tempo decorrido ao tempo original
    long long nsTotal = nanossegundos + tempoDecorrido.count();
    int segTotal = segundos;
    int minTotal = minutos;
    int horaTotal = hora;
    int diaTotal = dia;
    
    // Ajusta nanossegundos (1 segundo = 10^9 nanossegundos)
    segTotal += nsTotal / 1000000000;
    nsTotal = nsTotal % 1000000000;
    
    // Ajusta segundos
    minTotal += segTotal / 60;
    segTotal = segTotal % 60;
    
    // Ajusta minutos
    horaTotal += minTotal / 60;
    minTotal = minTotal % 60;
    
    // Ajusta horas
    diaTotal += horaTotal / 24;
    horaTotal = horaTotal % 24;
    
    // Exibe o resultado
    cout << setfill('0') 
         << setw(4) << ano << "-"
         << setw(2) << mes << "-"
         << setw(2) << diaTotal << " "
         << setw(2) << horaTotal << ":"
         << setw(2) << minTotal << ":"
         << setw(2) << segTotal << "."
         << setw(9) << nsTotal << " ns" << endl;
}

// Método para exibir o tempo inicial
void Relogio::exibirTempoInicial() {
    cout << setfill('0') 
         << setw(4) << ano << "-"
         << setw(2) << mes << "-"
         << setw(2) << dia << " "
         << setw(2) << hora << ":"
         << setw(2) << minutos << ":"
         << setw(2) << segundos << "."
         << setw(9) << nanossegundos << " ns" << endl;
}
