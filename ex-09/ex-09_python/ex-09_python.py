#Feito pelo Monitor Voluntario Washington Ying Ye Wu  - 13/06/2025
#Versao do Python Utilizada Python 3
#Matéria Técnicas de Programação - Prof. Jean Marcelo Simao

#exercicio 9
class Carro:
    def __init__(self,consumourbano,consumoestrada,capacidade): #inicializa o atributo consumourbano e estrada, capacidade maxima e nvl combustivel
        self.consumourbano =consumourbano
        self.consumoestrada = consumoestrada
        self.capacidade = capacidade
        self.nvlcombustivel = 0
    def getcombustivel(self): #metodo getter para nvlcombustivel
        return self.nvlcombustivel

    def abastecer(self,qntcombustivel): #metodo apra abastecer 
        self.nvlcombustivel += qntcombustivel
        if self.nvlcombustivel > self.capacidade:
            self.nvlcombustivel = self.capacidade
    def andar(self, distancia, tipo_trajeto):
        if tipo_trajeto == "cidade":  #verifica o tipo do trajeto
            consumo = self.consumourbano
        elif tipo_trajeto == "estrada":
            consumo = self.consumoestrada
        else:
            print("tipo invalido")
            return

        combustivel_necessario = distancia / consumo
        if combustivel_necessario <= self.nvlcombustivel:
            self.nvlcombustivel -= combustivel_necessario
        else:
            distancia_possivel = self.nvlcombustivel * consumo
            print(f"combustivel insuficiente, o carro somente andou {distancia_possivel:.2f} km.")
            self.nvlcombustivel = 0

if __name__ == "__main__": #inicializacao da main
    gol = Carro(12,15,45)
    gol.abastecer(20)

    uno = Carro(14,17,40)
    uno.abastecer(25)
    uno.andar(150,"estrada")

    print(f"litros restantes no uno: {int(uno.getcombustivel())}")
    gol.andar(80,"cidade")

    print(f"litros restantes no gol: {int(gol.getcombustivel())}")



