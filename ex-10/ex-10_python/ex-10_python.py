#Feito pelo Monitor Voluntario Washington Ying Ye Wu  - 4/07/2025
#Versao do Python Utilizada Python 3
#Matéria Técnicas de Programação - Prof. Jean Marcelo Simao

#exercicio 10

class Colaborador:
    def __init__(self,nome,tipovinculo): #inicializacao da classe e dos atributos
        self.nome=nome
        self.tipovinculo=tipovinculo
        self.valorhoratrabalho=0
        self.numerohoras=0
        self.temposervico = 0
    def setvalor_horatrabalho(self,valorhoratrabalho): #metodo setter
        self.valorhoratrabalho=valorhoratrabalho

    def setnumero_horas(self,numerohoras):#metodo setter
        self.numerohoras=numerohoras

    def settempo_servico(self,temposervico):#metodo setter
        self.temposervico= temposervico

    def getnome(self): #metodo getter
        return self.nome 
    
    def getvinculo(self):#metodo getter
        return self.tipovinculo
    
    def getvalorhoratrabalho(self):#metodo getter
        return self.valorhoratrabalho
    
    def getnumero_horas(self):#metodo getter
        return self.numerohoras
    
    def gettempo_servico(self):#metodo getter
        return self.temposervico
    
    def calculaRendimentos(self): #calcula rendimento
        rendimento = 0
        
        if self.tipovinculo == "estagiario": #tipo estagiario
            rendimento = self.getvalorhoratrabalho() * 80
            
        elif self.tipovinculo == "empregado":#tipo empregado
            rendimento = self.getvalorhoratrabalho()
            for i in range(0,self.gettempo_servico()):
                rendimento = rendimento *1.1
            if self.getnumero_horas()>144:
                rendimento = rendimento *1.5
            
            rendimento = rendimento * self.getnumero_horas()
        
        elif self.tipovinculo == "socio": #tipo socio
            rendimento = self.getvalorhoratrabalho() * self.getnumero_horas()
        

        else: #quando nao é nenhum dos tres
            print(f"erro, ele nao tem tipo valido")

        return rendimento
    def calculacusto(self): #retorna custo calculado
        if self.getvinculo()== "empregados": #tipo empregado
            return float(self.calculaRendimentos() * 1.8 )
        elif self.getvinculo()=="socio" or self.getvinculo()== "estagiario": #outros dois tipos
            return float(self.calculaRendimentos())
        else:
            return 0.0
        
if __name__ == "__main__":
    pedro = Colaborador("pedro","estagiario") #cria tres colaboradores
    ana = Colaborador("ana","empregado")
    luiz = Colaborador("luiz","socio")

    pedro.setvalor_horatrabalho(10) #seta valor da horatrabalho
    ana.setvalor_horatrabalho(20)
    luiz.setvalor_horatrabalho(30)

    ana.settempo_servico(2) #estagiario ja tem padrao 80h e socio nao tem foi utilizado tempo de servico
                            #mas poderia ser atribuido
    ana.setnumero_horas(138)    #mesmo caso 
    luiz.setnumero_horas(140)

    colaboradores = [pedro,ana,luiz] #atribuido numa lista por facilidade

    maiorrendimento = 0.0
    maiorrendimentonome = ""
    maiorcusto = 0.0
    maiorcustonome= ""

    for i in colaboradores: #comparacao
        if i.calculaRendimentos() > maiorrendimento:
            maiorrendimento=i.calculaRendimentos()
            maiorrendimentonome=i.getnome()
        if i.calculacusto() > maiorcusto:
            maiorcusto= i.calculacusto()
            maiorcustonome=i.getnome()
    
    print(f"maior rendimento : {maiorrendimentonome} - {maiorrendimento} e maior custo : {maiorcustonome} - {maiorcusto} ") #informa quem tem mais rendimento e maiorcusto







