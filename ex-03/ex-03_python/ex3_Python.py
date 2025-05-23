#Feito pelo Monitor Voluntario Washington Ying Ye Wu  - 23/05/2025
#Versao do Python Utilizada Python 3
#Matéria Técnicas de Programação - Prof. Jean Marcelo Simao

#Exercicio 3   

class Caixa:   
    def __init__(self):  #Aqui inicializamos todos os valores dos atributos para 0
        self.largura=0
        self.altura=0
        self.profundidade=0
    def setlargura(self,larg):  #Metodo Setters
        self.largura=larg
    def setaltura(self,altu):   #Metodo Setters
        self.altura=altu
    def setprofundidade(self,prof): #Metodo Setters
        self.profundidade = prof
    def calcularAreaExt(self):  #Calcula area externa
        return 2*(self.largura*self.altura+self.largura*self.profundidade + self.altura*self.profundidade)
    def calcularVolume(self): #Calcula Volume
        return (self.largura*self.altura*self.profundidade)

def main():
    caixa1 = Caixa()  #Criamos um objeto da classe Caixa
    caixa1.setaltura(float(input(f"Qual valor da altura ?"))) #Pedimos o valor ao usuario
    caixa1.setlargura(float(input(f"Qual valor da largura ?"))) #Pedimos o valor ao usuario
    caixa1.setprofundidade(float(input(f"Qual valor da profundidade ?"))) #Pedimos o valor ao usuario
    print(f"O Valor da Area Externa da Caixa 1 e {caixa1.calcularAreaExt()}") #printa os valores
    print(f"O Valor do Volume da caixa 1 e {caixa1.calcularVolume()}")

    caixa2 = Caixa() #Criamos um objeto da classe Caixa
    caixa2.setaltura(float(input(f"Qual valor da altura ?"))) #Pedimos o valor ao usuario
    caixa2.setlargura(float(input(f"Qual valor da largura ?")))
    caixa2.setprofundidade(float(input(f"Qual valor da profundidade ?")))
    print(f"O Valor da Area Externa da Caixa 2 e {caixa2.calcularAreaExt()}") #printa os valores
    print(f"O Valor do Volume da caixa 2 e {caixa2.calcularVolume()}")


if __name__ == "__main__":
    main()  #chamamos a main