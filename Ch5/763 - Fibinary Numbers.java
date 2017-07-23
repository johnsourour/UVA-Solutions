
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	static int MAX = 101;
	static BigInteger fib[] = new BigInteger[MAX];
	public static void main (String[] args)
	{
		gen();
		Scanner sc = new Scanner(System.in);
		String f,s;
		BigInteger n1,n2;
		while(sc.hasNext())
		{
			f=sc.next();
			s=sc.next();
			n1=val(f);
			n2=val(s);
		//	System.out.println(n1+ " "+ n2);
			n1 = n1.add(n2);
			output(n1);
		
			if(sc.hasNext())	System.out.println("");
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
	static BigInteger val(String s)
	{
		BigInteger tot= BigInteger.ZERO;
		for(int i=s.length()-1;i>=0;i--)
		{
			if(s.charAt(i)=='1')
			{
				tot = tot.add(fib[s.length()-1-i]);
			}
		}
		return tot;
	}
	static void output(BigInteger n)
	{
		Vector v = new Vector(0,1);
		int ind;
		BigInteger cur = n;
		boolean ok =false;
	//	System.out.println(n);
		for(int i=MAX-1;i>=0;i--)
		{
			if(fib[i].compareTo(cur)<=0)
			{
				cur = cur.subtract(fib[i]);
				System.out.print('1');
				ok=true;
			}
			else if(ok)System.out.print('0');
		}
		if(!ok)System.out.print("0");
			System.out.println("");
	}
	
}
