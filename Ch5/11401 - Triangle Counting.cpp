#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
typedef long long ll;
ll cnt[MAX];
void init()
{
	cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
	ll cur=0,prev=0,tot=0,cc=1;
	for(int i=4;i<MAX;i++)
	{
		prev+=cc;
		cnt[i]=prev;
		cnt[i]+=cnt[i-1];
		cur++;
		if(cur==2)
		{
			cur=0;cc++;
		}
	
	}
}
int main()
{
	init();
	int N;
	while(true)
	{
		scanf("%d",&N);
		if(N<3)break;
		printf("%lld\n",cnt[N]);
	}
	return 0;
}
