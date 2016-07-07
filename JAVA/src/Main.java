import java.text.DecimalFormat;
import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            BigInteger num = cin.nextBigInteger();
            if (num.mod(BigInteger.valueOf(3)) != BigInteger.ZERO) {
                System.out.println("-1");
                continue;
            }
            BigInteger ans = num.divide(BigInteger.valueOf(3));
            System.out.println(ans + " " + ans + " " + ans);
        }
    }
}