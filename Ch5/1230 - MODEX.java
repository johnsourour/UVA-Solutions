
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
		BigInteger x,y,n;
		while(t-- > 0)
		{
			x = sc.nextBigInteger();
			y = sc.nextBigInteger();
			n = sc.nextBigInteger();
			System.out.println(x.modPow(y,n));
		}
		n=sc.nextBigInteger();
	}
	
}
