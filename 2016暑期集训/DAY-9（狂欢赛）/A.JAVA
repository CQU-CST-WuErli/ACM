import java.text.DecimalFormat;
import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner cin = new Scanner(System.in);
        BigInteger n = cin.nextBigInteger();
        BigInteger lb = BigInteger.valueOf(-922337203);
        BigInteger rb = BigInteger.valueOf(922337203);
        int[] a = new int[11];
        a[1] = 6; a[2] = 8; a[3] = 5; a[4] = 4; a[5] = 7;
        a[6] = 7; a[7] = 5; a[8] = 8; a[9] = 0; a[10] = 8;
        for (int i = 1; i <= 10; i++) {
            lb = lb.multiply(BigInteger.TEN);
            lb = lb.subtract(BigInteger.valueOf(a[i]));
            rb = rb.multiply(BigInteger.TEN);
            rb = rb.add(BigInteger.valueOf(a[i]));
        }
        rb = rb.subtract(BigInteger.ONE);
//        System.out.println(lb);
//        System.out.println(rb);
        if (BigInteger.valueOf(-128).compareTo(n) <= 0 && n.compareTo(BigInteger.valueOf(127)) <= 0)
            System.out.println("byte");
        else if (BigInteger.valueOf(-32768).compareTo(n) <= 0 && n.compareTo(BigInteger.valueOf(32767)) <= 0)
            System.out.println("short");
        else if (BigInteger.valueOf(-2147483648).compareTo(n) <= 0 && n.compareTo(BigInteger.valueOf(2147483647)) <= 0)
            System.out.println("int");
        else if (lb.compareTo(n) <= 0 && n.compareTo(rb) <= 0) System.out.println("long");
        else System.out.println("BigInteger");
    }
}