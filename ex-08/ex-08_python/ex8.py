#Feito pelo Monitor Voluntario Washington Ying Ye Wu  - 13/06/2025
#Versao do Python Utilizada Python 3
#Matéria Técnicas de Programação - Prof. Jean Marcelo Simao

#exercicio 8
class Carro:
    def __init__(self,consumo,capacidade): #inicializa o atributo consumo,capacidade maxima e nvl combustivel
        self.consumo =consumo
        self.capacidade = capacidade
        self.nvlcombustivel = 0
    def getcombustivel(self): #metodo getter para nvlcombustivel
        return self.nvlcombustivel

    def abastecer(self,qntcombustivel): #metodo apra abastecer 
        self.nvlcombustivel += qntcombustivel
    def andar(self,distancia): #metodo andar para o automovel
        combustivel_necessario = distancia / self.consumo
        if combustivel_necessario <= self.nvlcombustivel:
            self.nvlcombustivel -= combustivel_necessario
            print(f"andou {distancia} km.")
        else:
            # Anda o máximo possível com o combustível restante
            distancia_possivel = self.nvlcombustivel * self.consumo
            self.nvlcombustivel = 0
            print(f"combustivel insuficiente, andou apenas {distancia_possivel:.2f} km.")

if __name__ == "__main__": #inicializacao da main
    gol = Carro(12,45)
    gol.abastecer(20)

    uno = Carro(14,40)
    uno.abastecer(25)
    uno.andar(150)

    print(f"litros restantes no uno: {int(uno.getcombustivel())}")
    gol.andar(80)

    print(f"litros restantes no gol: {int(gol.getcombustivel())}")



