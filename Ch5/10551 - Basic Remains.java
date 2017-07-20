
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int b;
		BigInteger m,p;
		while(true)
		{
			b= sc.nextInt();
			if(b==0)break;
			p = new BigInteger(sc.next(),b);
			m = new BigInteger(sc.next(),b);
			System.out.println(p.mod(m).toString(b));
			
			
		}
	}
}
