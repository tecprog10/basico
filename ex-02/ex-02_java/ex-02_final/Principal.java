public class Principal
{
    /*
     * Sem Main, código feito no BlueJ
     * Autor da classe Principal: Daniel Zagroba
     * (Houveram algumas modificações menores em Horario)
     */
    
    
    /*  Qual(is) é(são) a(s) alternativa(s)
     *  para efetuar a validação dentro da construtora e retornar o status (sucesso ou
     *  erro)? Uma delas é fazer como na classe horário em que os métodos setHora e setMin interrompem a execução do programa se houver falhas
     * 
     * Esta construtora poderia ser sobrecarregada de alguma forma?
     * Pode, por exemplo outra construtora que recebe somente hora de entrada e valor padrão para minutos é 0.
     */
    
    Horario chegada;
    Horario saida;

    public Principal(byte entradahora, byte entradamin, byte saidahora, byte saidamin)
    {
        chegada = new Horario(entradahora, entradamin);
        saida = new Horario(saidahora, saidamin);
        
        int tempo = chegada.calcularIntervalo(saida);
        System.out.println("O tempo é de " + tempo/60 + " horas e " + tempo%60 + " minutos.");
        System.out.println("O preço é de: " + calculaPreco(tempo) + " reais.");
    }
    
    public float calculaPreco(int minutos)
    {
        if(minutos<180)
        {
            return (float)4.5;
        }
        else if(minutos <= 720)
        {
            return (float)(4.5+ ((minutos-180)/15) * 0.75);
        }
        else
        {
            return (float)33;
        }
    }

}
