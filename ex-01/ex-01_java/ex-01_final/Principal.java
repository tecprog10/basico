public class Principal
{
    /*
     * Sem Main, código feito no BlueJ
     * Autor da classe Principal: Daniel Zagroba
     * (Houveram algumas modificações menores em Horario)
     */
    
    Horario chegada;
    Horario saida;

    public Principal(byte entradahora, byte entradamin, byte saidahora, byte saidamin)
    {
        chegada = new Horario();
        saida = new Horario();
        if(chegada.setHora(entradahora) == false)
        {
            System.out.println("Valor inválido.");
            System.exit(1);
        } 
        if(chegada.setMin(entradamin) == false)
        {
            System.out.println("Valor inválido.");
            System.exit(1);
        }
        if(saida.setHora(saidahora) == false)
        {
            System.out.println("Valor inválido.");
            System.exit(1);
        }
        if(saida.setMin(saidamin) == false)
        {
            System.out.println("Valor inválido.");
            System.exit(1);
        }
        
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
