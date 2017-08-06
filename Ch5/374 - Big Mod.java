
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	static int MAX = 1001;
	static String mem[]=new String[MAX];
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger B,P,M;
		while(sc.hasNext())
		{
			B=sc.nextBigInteger();
			P=sc.nextBigInteger();
			M=sc.nextBigInteger();
			System.out.println(B.modPow(P,M));
		}
		
	
	}
	
}
