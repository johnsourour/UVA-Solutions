
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigDecimal;

class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		BigDecimal tot,cur;
		while(t-- > 0)
		{
			tot = BigDecimal.ZERO;
			cur = sc.nextBigDecimal();
			while(!cur.equals(BigDecimal.ZERO))
			{
				tot = tot.add(cur);
				cur = sc.nextBigDecimal();
			}
			
			System.out.println(tot.stripTrailingZeros().toPlainString());
		}
	}
	
}
