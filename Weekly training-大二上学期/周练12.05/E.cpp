import java.math.BigInteger;  
import java.util.Scanner;  
  
public class Main {  
    public static void main(String[] args) {    
        BigInteger dp[] = new BigInteger[810];  
        dp[1]=BigInteger.ZERO;  
        dp[2]=BigInteger.ONE;  
        for (int i=3; i<=800;i++)  
            dp[i] = (dp[i-2].add(dp[i-1])).multiply(BigInteger.valueOf(i-1));  
        Scanner in = new Scanner(System.in);  
        int n;  
        while (true) {  
            n = in.nextInt();  
            if (n == -1)  
                break;  
            System.out.println(dp[n]);  
        }  
    }  
}  
