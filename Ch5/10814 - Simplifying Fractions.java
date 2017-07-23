
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		BigInteger x,y,g;
		String s;
		while(t-- > 0)
		{
			x = sc.nextBigInteger();
			s = sc.next();
			y = sc.nextBigInteger();
			g = x.gcd(y);
			System.out.println(x.divide(g)+" / "+y.divide(g));
		}
	}
	
}
