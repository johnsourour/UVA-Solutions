
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger n,k,ans;
		while(sc.hasNext())
		{
			n = sc.nextBigInteger();
			k = sc.nextBigInteger();
			System.out.println(cnt(n,k));
		}
	
	}
	static int cnt(BigInteger n, BigInteger k)
	{
		BigInteger tmp = n.subtract(k);
 		if(k.compareTo(tmp)>0)k=tmp;
		BigInteger prod = BigInteger.ONE;
		k=k.add(BigInteger.ONE);
		for (BigInteger i = BigInteger.ONE; !i.equals(k); i=i.add(BigInteger.ONE))
			prod = prod.multiply(n.subtract(i).add(BigInteger.ONE));
		for (BigInteger i = BigInteger.valueOf(2); !i.equals(k); i=i.add(BigInteger.ONE))
			prod =prod.divide(i);
		return prod.toString().length();
	}
	
}
