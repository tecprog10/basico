package p1;

public class C2 {
    
    private int a2;

    public C2(int aa) {
        a2 = aa;
    }

    public void seta2(int aa) {
        a2 = aa;
    }

    public int geta2() {
        return a2;
    }
    
    public void acessar()
    {
        C1 objc1 = new C1(10);
        System.out.println("Valor de obj c1 criado: " + objc1.geta1());
        objc1.seta1(20);
        System.out.println("Valor de obj c1 depois de um set: " + objc1.geta1());
    }
}
