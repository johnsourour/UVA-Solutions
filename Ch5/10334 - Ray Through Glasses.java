
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	static int MAX = 1001;
	static BigInteger fib[] = new BigInteger[MAX];
	public static void main (String[] args)
	{
		gen();
		Scanner sc = new Scanner(System.in);
		int n;
		while(sc.hasNext())
		{
			n = sc.nextInt();
			System.out.println(fib[n]);
		}
	
	}
	static void gen()
	{
		fib[0]= BigInteger.ONE;
		fib[1]=fib[0].add(BigInteger.ONE);
		for(int i=2;i<MAX;i++)
		{
			fib[i]=fib[i-1].add(fib[i-2]);
		}
	}
	
}
