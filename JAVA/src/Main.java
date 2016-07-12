import java.text.DecimalFormat;
import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static int[][] a = new int[1010][1010];
    public static BigInteger[][] L = new BigInteger[1010][1010];
    public static BigInteger[][] R = new BigInteger[1010][1010];
    public static BigInteger[][] U = new BigInteger[1010][1010];
    public static BigInteger[][] D = new BigInteger[1010][1010];
    public static BigInteger[][] LU = new BigInteger[1010][1010];
    public static BigInteger[][] RU = new BigInteger[1010][1010];
    public static BigInteger[][] LD = new BigInteger[1010][1010];
    public static BigInteger[][] RD = new BigInteger[1010][1010];
    public static int n;
    void gao() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] == 0 || j == 1) L[i][j] = BigInteger.ZERO;
                else {
                    if (a[i][j - 1] == 0) L[i][j] = BigInteger.valueOf(a[i][j]);
                    else L[i][j] = L[i][j - 1].multiply(BigInteger.valueOf(a[i][j]));
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

            }
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner cin = new Scanner(System.in);
        n = cin.nextInt();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = 0;
            }
        }

    }
}