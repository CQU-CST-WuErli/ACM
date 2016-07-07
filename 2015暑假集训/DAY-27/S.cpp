improt java.math.*;
import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		BigInteger f[]=new BigInteger[10010];
		f[3]=BigInteger.valueOf(4);
		f[4]=BigInteger.valueOf(7);
		for (int i=5;i<=10000;i++) {
			f[i]=f[i-1].add(f[i-2]);
		}
		Scanner cin=new Scanner (System.in);
		while (cin.hasNext()){
			int n=cin.nextInt();
			System.out.println(f[n]);
		}
	}
}
