
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger N,rem;
		BigInteger five = new BigInteger("5");
		BigInteger sev = new BigInteger("17");
		BigInteger ten =new BigInteger("10");
		while(true)
		{
			N = sc.nextBigInteger();
			if(N.equals(BigInteger.ZERO))break;
		
			rem = N.mod(ten);
			N = N.divide(ten);
			N = N.subtract(rem.multiply(five));
			if(N.mod(sev)==BigInteger.ZERO)System.out.println(1);
			else System.out.println(0);
			
		}
	}
}
