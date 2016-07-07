import java.math.*;
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
 	  	BigInteger f[] = new BigInteger[10010];
 	  	f[0] = BigInteger.valueOf(0);
		f[1] = BigInteger.valueOf(1);
		int i = 2;
		int k=1;
		while(i <= 10000){
			BigInteger add = BigInteger.valueOf(1).shiftLeft(k);
			for(int j=0; j<k+1 && i<=10000; ++j){
				f[i] = f[i-1].add(add);
				++i;
			}
			++k;
		}
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			int n = cin.nextInt();
			System.out.println(f[n]);
		}
	}
}
