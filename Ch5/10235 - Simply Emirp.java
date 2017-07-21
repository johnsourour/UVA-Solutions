
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int n;
		BigInteger B,R;
		while(sc.hasNext())
		{
			B = sc.nextBigInteger();
			if(!B.isProbablePrime(10))
				System.out.println(B +" is not prime.");
			else 
			{
				R = new BigInteger((new StringBuffer(B.toString())).reverse().toString());
				if(!R.isProbablePrime(10) || R.equals(B))
					System.out.println(B +" is prime.");
				else 
					System.out.println(B +" is emirp.");
			}
			
			
		}
	}
	
}
