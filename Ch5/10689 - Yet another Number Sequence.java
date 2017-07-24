
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	static int MAX=15005;
	static BigInteger fib[]=new BigInteger[MAX+1];
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt(),n, m;
		BigInteger a,b,ans;
		gen();
		while(t-- > 0)
		{
			a = sc.nextBigInteger();
			b = sc.nextBigInteger();
			n = sc.nextInt();
			m = sc.nextInt();
			if(m==1)
				while(n>=60)n-=60;
		
			else if(m==2)
				while(n>=300)n-=300;
		
			else if(m==3)
				while(n>=1500)n-=1500;
			
			else
				while(n>=15000)n-=15000;
			if(n==0)
				ans= a;
			else
			{
				ans = fib[n-1].multiply(a);
				ans = ans.add(fib[n].multiply(b));
			}
			System.out.println(ans.mod(BigInteger.valueOf((int)Math.pow(10,m))));
		}
	
	}
	static void gen()
	{
		fib[0]=BigInteger.ZERO;
		fib[1]=BigInteger.ONE;
		for(int i=2;i<MAX;i++)
		{
			fib[i]=(fib[i-1].add(fib[i-2])).mod(BigInteger.valueOf(10000));
		}
	}
	
}
