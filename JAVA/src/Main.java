import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner cin = new Scanner(System.in);
        BigInteger a = BigInteger.valueOf(256);
        a = a.multiply(a);
        BigInteger b = a.multiply(a);
//        System.out.println(b);
        while (cin.hasNext()) {
            BigInteger n = cin.nextBigInteger();
            if (n.compareTo(b) >= 0) System.out.println("TAT");
            else {
                if (n.compareTo(BigInteger.ONE) == 0) System.out.println("0");
                else if (n.compareTo(BigInteger.valueOf(4)) < 0) System.out.println("1");
                else if (n.compareTo(BigInteger.valueOf(16)) < 0) System.out.println("2");
                else if (n.compareTo(BigInteger.valueOf(256)) < 0) System.out.println("3");
                else if (n.compareTo(a) < 0) System.out.println("4");
                else if (n.compareTo(b) < 0) System.out.println("5");
            }
        }
    }
}