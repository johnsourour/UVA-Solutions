#include<bits/stdc++.h>
using namespace std;
#define MAX 401
typedef long long ll;
ll cnt[MAX];
void init()
{
	ll num=0;
	for(int i=2;i<MAX;i++)
	{
		num+=(i-1);
		cnt[i]=(num/(i-1));
	}
}
int main()
{
	init();
	int N,K=1;
	while(true)
	{
		scanf("%d",&N);
		if(!N)break;
		printf("Case %d: %lld\n",K++,cnt[N]);
	}
	return 0;
}
