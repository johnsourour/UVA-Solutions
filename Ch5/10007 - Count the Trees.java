
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		BigInteger F,C;
		while(true)
		{
			int N = sc.nextInt();
			if(N==0)break;
			F=fact(N);
			C=cat(N);
			System.out.println(F.multiply(C));
		}
	
	}
	static BigInteger cat(int n)
	{
		BigInteger tn = fact(n*2);
		BigInteger fn = fact(n);
		fn = fn.multiply(fn).multiply(BigInteger.valueOf(n+1));
		return tn.divide(fn);
	}
	static BigInteger fact(int n)
	{
		BigInteger prod = BigInteger.ONE;
		for(int i=2;i<=n;i++)
		{
			prod = prod.multiply(BigInteger.valueOf(i));
		}
		return prod;
	}
	
}
