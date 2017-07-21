
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	static int MAX=10001;
	static Vector primes = new Vector(0,1);
	static int count[] = new int[MAX];
	public static void main (String[] args)
	{
		gen();
		calc();
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		while(n>0)
		{
			System.out.println(count[n]);
			n = sc.nextInt();
			
			
		}
	}
	static void gen()
	{
		for(int i=0;i<MAX;i++)
		{
			BigInteger b = BigInteger.valueOf(i);
			if(b.isProbablePrime(10))primes.addElement(i);
		}
	}
	static void calc()
	{
		int sum;
		for(int i=0;i<primes.size();i++)
		{
			sum=0;
			for(int j=i;j<primes.size();j++)
			{
				sum=sum+(int)primes.elementAt(j);
				if(sum>=MAX)break;
               //                 System.out.println(sum+ " " + MAX);
				count[sum]++;
			}
		}
	}
	
}
