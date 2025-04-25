#include <iostream>
#include <cstring>
#define MAX 150
using namespace std;

class Universidade
{
private:
    char nome[MAX];
public:
    Universidade(const char* n) 
    {
        strncpy(nome, n, MAX - 1);
        nome[MAX - 1] = '\0';
    }

    ~Universidade() {
    }

    const char* getNome() const 
    {
        return nome;
    }
};

class Pessoa
{
private:
    char nome[MAX];
    int idade;
    Universidade* uni;
public:
    Pessoa(const char* n, int idd, Universidade* aux) 
    {
        strncpy(nome, n, MAX - 1);
        nome[MAX - 1] = '\0';

        idade = idd;
        uni = aux;
    }

    
    ~Pessoa() 
    {
    }

    void mostraPessoa() 
    {
        cout << "Meu nome eh " << nome << ", tenho " << idade
             << " anos e trabalho na Universidade " << uni->getNome() << "." << endl;
    }
};

int main()
{
    Universidade Princeton("Princeton");
    Universidade Cambridge("Cambridge");

    Pessoa Albert("Albert Einstein", 146, &Princeton);
    Pessoa Isaac("Isaac Newton", 382, &Cambridge);

    Albert.mostraPessoa();
    Isaac.mostraPessoa();

    return 0;
}
