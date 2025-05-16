public class ExPessoa {

  public void executar() {
    Pessoa p1, p2;

    p1 = new Pessoa();
    p2 = new Pessoa();

    p1.setNome("Isaac Newton");
    p1.setDataDeNascimento(4, 1, 1643);

    p2.setNome("Albert Einstein");
    p2.setDataDeNascimento(14, 3, 1879);

    p1.calculaIdade(30, 9, 2010);
    p2.calculaIdade(30, 9, 2010);

    int idadeP1 = p1.getIdade();
    int idadeP2 = p2.getIdade();
    
    System.out.println("Idade de p1: " + idadeP1);
    System.out.println("Idade de p2: " + idadeP2);
  }
}