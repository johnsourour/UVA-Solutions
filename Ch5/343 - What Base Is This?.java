
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		String X,Y;
		BigInteger x1,x2;
		while(sc.hasNext())
		{
			X = new String(sc.next());
			Y = new String(sc.next());
			boolean found=false;
			for(int i = 2; i <= 36 && !found; i++)
			{
				try
				{
					x1=new BigInteger(X,i);
				}
				catch(Exception e){
					continue;
				}
				
				for(int j = 2; j <= 36 && !found; j++)
				{
					try
					{
						x2=new BigInteger(Y,j);
					}
					catch(Exception e){
						continue;
					}
				
					//System.out.println(x1 + " " + x2);
					if(x1.equals(x2))
					{
						found=true;
						System.out.println(X+" (base "+i+") = "+Y+" (base "+j+")");
					}
				}
			}
			if(!found)System.out.println(X +" is not equal to "+ Y +" in any base 2..36");
		}
	}
}
