


public class Pessoa
{

    private String nome;    
    private int idade;
    private int dia;
    private int mes;
    private int ano;

    public Pessoa()
    {
        nome = "-1";
        idade = -1;
        dia = -1;
        mes = -1;
        ano = -1;
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
    
    public void setNome(String s)
    {
        nome = s;
    }
    
    public void setDataDeNascimento(int d, int m, int a)
    {
        dia = d;
        mes = m;
        ano = a;
    }
    
    
}
