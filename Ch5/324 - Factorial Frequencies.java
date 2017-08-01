
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	static int MAX = 367;
	static int mem[][]=new int[MAX][10];
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		gen();
		int n;
		while(true)
		{
			n=sc.nextInt();
			if(n==0)break;
			else
			{
				System.out.println(String.format("%d! --",n));

				for(int i=0;i<5;i++)
				{
					if(i!=0)System.out.print(" ");
					System.out.print(String.format("   (%d)%5d",i,mem[n][i]));
				}
				System.out.println("");
				for(int i=5;i<10;i++)
				{
					if(i!=5)System.out.print(" ");
					System.out.print(String.format("   (%d)%5d",i,mem[n][i]));
				}
				System.out.println("");
			}
		}
		
	
	}
	static void gen()
	{
		BigInteger cur=BigInteger.ONE;
		String s;
		for(int i=1;i<MAX;i++)
		{
			cur=cur.multiply(BigInteger.valueOf(i));
			s= cur.toString();
			for(int k=0;k<s.length();k++)
			{
				mem[i][s.charAt(k)-'0']++;
			}
		}
	}
	
}
