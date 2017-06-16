#include<bits/stdc++.h>
using namespace std;
double const eps=1e-9;
int p,q,r,s,t,u;
double solve(double x)
{
	double ret;
	ret=(p * exp(-x)) + (q * sin(x)) + (r * cos(x)) + (s * tan(x)) + (t*x*x) + u;
	return ret;

}
int main()
{
	double a,b,cur,mid;
	int i;
	bool found;
	while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!=EOF)
	{
		a=0.0000;
		b=1.0000;
		found=false;
		i=0;
		while(i<50 &&!found)
		{
			mid=(a+b)/2.0;
			cur=solve(mid);
			if(abs(cur)<=1e-10)found=true;
			else if(cur<0.0)
			{
				b=mid;
			}
			else
			{
				a=mid;
			}
			i++;
		}
		if(!found)printf("No solution\n");
		else printf("%.4f\n",mid);
	
		
	}
	
	return 0;
}
