package p2;


import p1.C1;
import p1.C2;

public class C3
{

    public C3() {
        
    }
    
    public void executar()
    {
        C1 objc1 = new C1(30);
        C2 objc2 = new C2(40);
        C4 objc4 = new C4(50);
        System.out.println("Valor de obj c1 criado: " + objc1.geta1());
        objc1.seta1(20);
        System.out.println("Valor de obj c1 depois de um set: " + objc1.geta1());
        System.out.println("Valor de obj c2 criado: " + objc2.geta2());
        objc2.seta2(20);
        System.out.println("Valor de obj c2 depois de um set: " + objc2.geta2());
        System.out.println("Valor de obj c4 criado: " + objc4.geta4());
        objc4.seta4(20);
        System.out.println("Valor de obj c4 depois de um set: " + objc4.geta4());


    }

}
