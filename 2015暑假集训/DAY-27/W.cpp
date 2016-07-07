import java.math.*;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        BigInteger f[]=new BigInteger[1010];
        f[1]=BigInteger.ZERO;
        f[2]=BigInteger.valueOf(1);
        f[3]=BigInteger.valueOf(1);
        for (int i=4;i<=1000;i++) {
            if (i%2==1) 
                f[i]=f[i-1].shiftLeft(1).subtract(BigInteger.ONE);
            else 
                f[i]=f[i-1].shiftLeft(1).add(BigInteger.ONE);
        }
        Scanner cin=new Scanner (System.in);
        while (cin.hasNext()){
            int n=cin.nextInt();
            System.out.println(f[n]);
        }
    }
}
