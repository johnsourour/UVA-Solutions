
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int T= sc.nextInt();
		BigInteger n,k,sum,t;
		while(T-- > 0)
		{
			n = sc.nextBigInteger();
			k = sc.nextBigInteger();
			sum = BigInteger.ZERO;
			int num = k.intValue();
			if(num> 0)
			{
				while(num-->0)
				{
					t = sc.nextBigInteger();
				//	System.out.println(t);
					sum = sum.add(t);
				}
				
			}
			
			n = n.subtract(sum);
			
			System.out.println(sol(n.add(BigInteger.ONE),k));
		}
	
	}
	static BigInteger sol(BigInteger n, BigInteger k)
	{
		//n = n.add(BigInteger.ONE);
		
			//System.out.println(n+ " "+k);
		if(n.compareTo(k)<0)return BigInteger.ZERO;
		BigInteger tmp = n.subtract(k);
		if(k.compareTo(tmp)>0)k=tmp;
		BigInteger prod = BigInteger.ONE;
		k=k.add(BigInteger.ONE);
		for (BigInteger i = BigInteger.ONE; i.compareTo(k)<0; i=i.add(BigInteger.ONE))
			prod = prod.multiply(n.subtract(i).add(BigInteger.ONE));
		for (BigInteger i = BigInteger.valueOf(2); i.compareTo(k)<0; i=i.add(BigInteger.ONE))
			prod =prod.divide(i);
		return prod;
	}
	
}
