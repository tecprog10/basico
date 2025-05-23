#Feito pelo Monitor Voluntario Washington Ying Ye Wu  - 16/05/2025
#Versao do Python Utilizada Python 3
#Mat�ria T�cnicas de Programa��o - Prof. Jean Marcelo Simao

#Exercicio 2   
#M�todo 1 : Se um dos valores n�o for v�lido, vai gerar um erro notificaando que n�o � v�lido
class Horario:
    def __init__(self,hora,min):
        #inicializacao pela construtora, realizamos a verificacao por aqui
        if not self.setHora(hora) or not self.setMin(min):
            raise ValueError("Hora ou minuto inv�lido.")

    def setHora(self,hora):
       if 0 <= hora < 24:      #retorna True ou False se for v�lido ou n�o
            self.hora = hora
            return True
       return False

    def setMin(self, min):      #retorna True ou False se for v�lido ou n�o
        if 0 <= min < 60:
            self.min = min
            return True
        return False

#M�todo 2 : A classe vai ter um atributo que verifica se o hor�rio � v�lido ou n�o, e vai retornar o valor True ou False
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
#   print("Hor�rio inv�lido!")


#A construtora geralmente n�o pode ser sobrecarregada em Python, mas podemos fazer 
#uma "sobrecarga", ao colocar os valores default (0)

#exemplo

class Horario:
    def __init__(self, hora=0, min=0):
        self.valido = self.setHora(hora) and self.setMin(min)
