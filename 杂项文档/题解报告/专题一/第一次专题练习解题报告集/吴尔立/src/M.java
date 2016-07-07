import java.text.DecimalFormat;
import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        for (int ca = 1; ca <= t; ca++) {
            String s = cin.next();
            int cnt = 0;
            char c = 's';
            int tt = 0;
            int flag = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '[') {
                    flag = 1;
                    continue;
                }
                if (flag == 1) {
                    c = s.charAt(i);
                    break;
                }
            }
            int n = 0;
            if (c == 'B') n = 0;
            else if (c == 'K') n = 1;
            else if (c == 'M') n = 2;
            else if (c == 'G') n = 3;
            else if (c == 'T') n = 4;
            else if (c == 'P') n = 5;
            else if (c == 'E') n = 6;
            else if (c == 'Z') n = 7;
            else if (c == 'Y') n = 8;
//            System.out.println(n);
            BigDecimal a = BigDecimal.ONE;
            BigDecimal b = BigDecimal.ONE;
            DecimalFormat formatter = new DecimalFormat("#.00");
            for (int i = 0; i < n; i++) {
                a = a.multiply(BigDecimal.valueOf(1000));
                b = b.multiply(BigDecimal.valueOf(1024));
            }
            BigDecimal ans = a.divide(b);
            ans = BigDecimal.ONE.subtract(ans);
            ans = ans.multiply(BigDecimal.valueOf(100));
            System.out.print("Case #" + ca + ": ");
            if (n == 0) System.out.print("0.00");
            else System.out.print(formatter.format(ans.doubleValue()));
            System.out.println("%");
        }
    }
}