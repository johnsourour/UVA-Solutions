
import java.util.Scanner;
import java.math.BigInteger;

class Main
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger num1,num2,sum;
		StringBuffer sb1,sb2,sumsb;
		int T = sc.nextInt();
		while(true)
		{
			sb1 = new StringBuffer(sc.next());
			sb2 = new StringBuffer(sc.next());
			sb1 = sb1.reverse();
			sb2 = sb2.reverse();
			num1 = new BigInteger(sb1.toString());
			num2 = new BigInteger(sb2.toString());
			
			sum = num1.add(num2);
			sumsb = new StringBuffer(sum.toString());
			sumsb = sumsb.reverse();
			sum =  new BigInteger(sumsb.toString());
			System.out.println(sum);
			T--;
			if(T==0)break;
		}
	}
}
