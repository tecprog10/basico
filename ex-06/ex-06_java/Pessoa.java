


public class Pessoa
{

    private String nome;    
    private int idade;
    private int dia;
    private int mes;
    private int ano;

    public Pessoa(String n,int d, int m, int a)
    {
        nome = n;
        idade = -1;
        dia = d;
        mes = m;
        ano = a;
    }
    
    public void calculaIdade(int d, int m, int a)
    {
        int n = a-ano;
        if(m < mes)
        {
            n--;
        }
        else if(m == mes && d < dia)
        {
            n--;
        }
        
        idade = n;
    }

    public int getIdade()
    {
        return idade;
    }
    
    public String getNome()
    {
        return nome;
    }
    
}
