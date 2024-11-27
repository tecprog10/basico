public class Horario
{
    //vamos utilizar um tipo adequado
    //para hora de 0 a 23 -> byte -> 8 bits, 
    //-128 a 127
    //para min de 0 a 59 -> idem
    private byte hora;
    private byte min;

    //getters e setters
    public boolean setHora(byte h) {
        if(h >= 0 && h <= 23)
        {
            hora = h;
            return true;
        }
        return false;
    }

    public boolean setMin(byte m) {
        if(m >= 0 && m <= 59)
        {
            min = m;
            return true;
        }
        return false;
    }
    
    
    public byte getHora() { return hora; }
    public byte getMin() { return min; }
    
    public int calcularIntervalo(Horario horario)
    {
        //calcula o intervalo entre os horarios "deste"
        //objeto e o horário do objeto h
        int intervalo = (horario.getHora()*60 + horario.getMin()) - (hora*60 + min);
        //se for negativo quer dizer que mudou de dia
        if (intervalo < 0)
        {
            //soma o tempo de 1 dia
            intervalo = intervalo + 1440;
        }
        return intervalo;
        
    }
    
}
