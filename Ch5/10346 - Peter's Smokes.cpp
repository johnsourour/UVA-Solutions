#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,K,cnt,tot;
	while(scanf("%d%d",&N,&K)!=EOF)
	{
		tot=cnt=0;
		while(N)
		{
			tot+=N;
			cnt+=N;
			N=cnt/K;
			cnt=cnt%K;
		}
		printf("%d\n",tot);
	}
	return 0;	
}
