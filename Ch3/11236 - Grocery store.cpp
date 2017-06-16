#include <bits/stdc++.h>
using namespace std;

int main() {
	long long prod,sum;
	int l;
	for(int i=1;(4*i)<=2000;i++)
	{
		for(int j=i;(3*j)<=2000-i;j++)
		{	
			for(int k=j;(2*k)<=2000-i-j;k++)
			{	
				
				sum=(i+j+k);
				prod=(long long)(i*j*k);
				if (prod <= 1000000) continue;
				if(((sum*1000000)%(prod-1000000))!=0)continue;
				l=(sum*1000000)/(prod-1000000);
				if(k>l || sum+l>2000)continue;
			printf("%.2f %.2f %.2f %.2f\n",(double)i/100.0,(double)j/100.0,(double)k/100.0,(double)l/100.0);
			}
		}
	}
	return 0;
}
