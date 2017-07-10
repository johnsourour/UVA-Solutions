#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,T,tot[10],cur;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		memset(tot, 0, sizeof tot);
		for(int i=0;i<=N;i++)
		{
			cur=i;
			while(cur)
			{
				tot[cur%10]++;
				cur/=10;
			}
		}
		for(int i=0;i<10;i++)
		{
			if(i)printf(" ");
			printf("%d",tot[i]);
		}
		printf("\n");
	}
	return 0;	
}
