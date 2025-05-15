
import p1.C1;
import p2.C3;

public class ExPacotes
{
    public ExPacotes()
    {
    
    }

    public void main()
    {
        C1 objc1 = new C1(30);
        C3 objc3 = new C3();
        System.out.println("Valor de obj c1 criado: " + objc1.geta1());
        objc1.seta1(20);
        System.out.println("Valor de obj c1 depois de um set: " + objc1.geta1());
        objc3.executar();
    }
}

//Respondendo a "Pergunta: caso a classe C1 tenha acesso padrão (ou seja, não público), que efeitos isso causa na compilação ou execução do programa?"
//C1 não pode ser acessado pelo import
