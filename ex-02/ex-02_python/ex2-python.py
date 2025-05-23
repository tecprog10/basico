#Feito pelo Monitor Voluntario Washington Ying Ye Wu  - 16/05/2025
#Versao do Python Utilizada Python 3
#Matéria Técnicas de Programação - Prof. Jean Marcelo Simao

#Exercicio 2   
#Método 1 : Se um dos valores não for válido, vai gerar um erro notificaando que não é válido
class Horario:
    def __init__(self,hora,min):
        #inicializacao pela construtora, realizamos a verificacao por aqui
        if not self.setHora(hora) or not self.setMin(min):
            raise ValueError("Hora ou minuto inválido.")

    def setHora(self,hora):
       if 0 <= hora < 24:      #retorna True ou False se for válido ou não
            self.hora = hora
            return True
       return False

    def setMin(self, min):      #retorna True ou False se for válido ou não
        if 0 <= min < 60:
            self.min = min
            return True
        return False

#Método 2 : A classe vai ter um atributo que verifica se o horário é válido ou não, e vai retornar o valor True ou False
class horario1:
    def __init__(self, hora, min):
        self.valido = self.setHora(hora) and self.setMin(min)

    def setHora(self, hora):
        if 0 <= hora < 24:
            self.hora = hora
            return True
        return False

    def setMin(self, min):
        if 0 <= min < 60:
            self.min = min
            return True
        return False

#exemplo na main()

#h = Horario(25, 10)
#if not h.valido:
#   print("Horário inválido!")


#A construtora geralmente não pode ser sobrecarregada em Python, mas podemos fazer 
#uma "sobrecarga", ao colocar os valores default (0)

#exemplo

class Horario:
    def __init__(self, hora=0, min=0):
        self.valido = self.setHora(hora) and self.setMin(min)
