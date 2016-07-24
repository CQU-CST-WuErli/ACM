import java.text.DecimalFormat;
import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        int n;
        Scanner cin = new Scanner(System.in);
        n = cin.nextInt();
        if (n == 2) {
            System.out.println(-1);
        }
        else {
            BigInteger fac = BigInteger.ONE;
            BigInteger[] a = new BigInteger[n + 1];
            for (int i = 1; i <= n; i++)
                fac = fac.multiply(BigInteger.valueOf(i));
            a[n] = fac;
            fac = fac.subtract(BigInteger.ONE);
            for (int i = 1; i < n; i++) {
                a[i] = fac.multiply(BigInteger.valueOf(i + 1));
            }
            for (int i = 1; i <= n; i++) {
                System.out.println(a[i]);
            }
        }
    }
}