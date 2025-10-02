#include <iostream>
#include <thread>
#include "Relogio.h"

using namespace std;
int main() {
    cout << "=== TESTE DA CLASSE RELOGIO ===" << endl << endl;
    
    // Teste 1: Criar relógio com data/hora atuais
    cout << "1. Criando relogio com data/hora atuais:" << endl;
    Relogio relogio1;
    cout << "   Tempo inicial: ";
    relogio1.exibirTempoInicial();
    
    cout << "\n   Aguardando 1 segundo..." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "   Tempo atual: ";
    relogio1.getAgora();
    
    cout << "\n   Aguardando mais 2 segundos..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "   Tempo atual: ";
    relogio1.getAgora();
    
    // Teste 2: Criar relógio com parâmetros específicos
    cout << "\n\n2. Criando relogio com parametros especificos:" << endl;
    Relogio relogio2(2025, 10, 2, 14, 30, 45, 123456789);
    cout << "   Tempo inicial: ";
    relogio2.exibirTempoInicial();
    
    cout << "\n   Aguardando 500 ms..." << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "   Tempo atual: ";
    relogio2.getAgora();
    
    // Teste 3: Verificar precisão com múltiplas leituras rápidas
    cout << "\n\n3. Teste de precisao - 5 leituras consecutivas:" << endl;
    Relogio relogio3;
    cout << "   Tempo inicial: ";
    relogio3.exibirTempoInicial();
    cout << endl;
    
    for (int i = 1; i <= 5; i++) {
        cout << "   Leitura " << i << ": ";
        relogio3.getAgora();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    
    // Teste 4: Verificar incremento gradual
    cout << "\n\n4. Verificando incremento gradual (10 leituras com 200ms):" << endl;
    Relogio relogio4;
    for (int i = 1; i <= 10; i++) {
        cout << "   Leitura " << i << ": ";
        relogio4.getAgora();
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    
    cout << "\n=== TESTES CONCLUIDOS ===" << endl;
    
    return 0;
}
