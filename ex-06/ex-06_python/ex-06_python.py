#Feito pelo Monitor Voluntario Washington Ying Ye Wu  - 30/05/2025
#Versao do Python Utilizada Python 3
#Matéria Técnicas de Programação - Prof. Jean Marcelo Simao

#Exercicio 6
class Pessoa:           
    def __init__(self,nome,dia,mes,ano): #inicializamos os atributos e atribuimos idade para 0
        self.idade = 0
        self.nome = nome
        self.dia = dia
        self.mes = mes
        self.ano = ano

    def getIdade(self): #retorna idade (metodo getter)
        return self.idade

    def getNome(self): #retorna nome (metodo getter)
        return self.nome


    def calculaIdade(self, diaatual, mesatual, anoatual): #calcula idade e seta o atributo idade
        
        self.idade = anoatual - self.ano

        if mesatual < self.mes or (mesatual == self.mes and diaatual < self.dia):
            self.idade -= 1

def main():
    p1 = Pessoa("Isaac Newton",4,1,1643)
    p2 = Pessoa("Albert Einstein",14,3,1879)  #criacao dos objetos

    p1.calculaIdade(30, 9, 2010)  #calcula idade e atribui valor p atributo idade
    p2.calculaIdade(30, 9, 2010)

    print(f"{ int(p1.getIdade())}")  
    print(f"{ int(p2.getIdade())}")    #printa as idades

if __name__ == "__main__":  #inicializacao da main
    main()
