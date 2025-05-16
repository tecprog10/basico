public class ExPessoa {

  public void executar() {
    Pessoa p1, p2;

    p1 = new Pessoa("Isaac Newton", 4, 1, 1643);
    p2 = new Pessoa("Albert Einstein", 14, 3, 1879);

    p1.calculaIdade(30, 9, 2010);
    p2.calculaIdade(30, 9, 2010);

    int idadeP1 = p1.getIdade();
    int idadeP2 = p2.getIdade();
    
    System.out.println("Idade de p1: " + idadeP1);
    System.out.println("Idade de p2: " + idadeP2);
  }
}