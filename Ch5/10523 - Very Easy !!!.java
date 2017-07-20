
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger cur,tot,N, A;
		while(sc.hasNext())
		{
			N = sc.nextBigInteger();
			A = sc.nextBigInteger();
			N = N.add(BigInteger.ONE);
			tot = BigInteger.ZERO;
			cur = new BigInteger(A.toString());
			for(BigInteger i=BigInteger.ONE;!i.equals(N);i=i.add(BigInteger.ONE))
			{
				tot=tot.add(cur.multiply(i));
				cur=cur.multiply(A);
			}
			System.out.println(tot);
			
		}
	}
}
