#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,tot;
	scanf("%d",&N);
	printf("PERFECTION OUTPUT\n");
	while(N)
	{
		tot=0;
		for(int i=1;i<=sqrt(N);i++)
		{
			if(N%i==0 && i!=N)
			{
				tot+=i;
				if(i!=sqrt(N) && i!=1)tot+=(N/i);
			}
		}
		printf("%*d  ",5,N);
		if(tot==N)printf("PERFECT\n");
		else if(tot<N) printf("DEFICIENT\n");
		else
		printf("ABUNDANT\n");
		scanf("%d",&N);
	}
	printf("END OF OUTPUT\n");
	return 0;	
}
