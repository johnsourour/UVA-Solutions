
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int fbase,tbase;
		boolean err;
		String s;
		BigInteger f;
		while(sc.hasNext())
		{
			s = sc.next();
			fbase = sc.nextInt();
			tbase = sc.nextInt();
			err=false;
			try{
				f = new BigInteger(s,fbase);
				
				int len=f.toString(tbase).toUpperCase().length();
				if(len>7)err=true;
				else System.out.println(String.format("%7s",f.toString(tbase).toUpperCase()));
			}
			catch(Exception E)
			{
				err=true;
				
			}
			if(err)System.out.println("  ERROR");
			
			
		}
	}
}
