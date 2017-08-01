
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
		gen();
		int n;
		while(sc.hasNext())
		{
			n=sc.nextInt();
			System.out.println(n+"!");
			System.out.println(mem[n]);
		}
		
	
	}
	static void gen()
	{
		BigInteger cur=BigInteger.ONE;
		mem[0]="1";
		for(int i=1;i<MAX;i++)
		{
			cur=cur.multiply(BigInteger.valueOf(i));
			mem[i]=cur.toString();
		}
	}
	
}
