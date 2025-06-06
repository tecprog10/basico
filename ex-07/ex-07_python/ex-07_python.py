#Feito pelo Monitor Voluntario Washington Ying Ye Wu  - 06/06/2025
#Versao do Python Utilizada Python 3
#Matéria Técnicas de Programação - Prof. Jean Marcelo Simao

#exercicio 7
class PolReg:
    def __init__(self,nlados,tamlados): #inicializa os valores dos atributos
        self.lados = nlados
        self.tamanholados = tamlados
    def perimetro(self):
        return self.lados*self.tamanholados #retorna perimetro
    def angulointerno(self):
        if self.lados<3:  #tem que ter 3 lados ou mais para existir
            return 0
        return((self.lados-2)*180)/self.lados
    def area(self):
        return 0 #area regular generico = 0, impossivel calcular


def main():
    try:
        numerodelados=int(input(f"insira o numero de lados do poligono :")) #pega os valores
        tamanholados= float(input(f"insira o tamanho de cada lado :"))

        poligono = PolReg(numerodelados,tamanholados) #cria o objeto

        print(f"perimetro : {poligono.perimetro()}")  #chama e printa as funcoes
        print(f"angulo interno : {poligono.angulointerno()}")
        print(f"area calculada : {poligono.area()}")
    except ValueError:
        print(f"entrada invalida") 

if __name__ == "__main__": #inicializa a main
    main()