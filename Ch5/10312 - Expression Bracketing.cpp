#include<bits/stdc++.h>
using namespace std;
#define MAX 27

typedef long long ll;
typedef vector<ll> vi;
vi Cat, SCat;
void init()
{
	Cat.resize(MAX);
	ll prev=1,tn;
	Cat[0]=Cat[1]=1;
	for(ll i=2;i<MAX;i++)
	{
		tn=(i-2)*2;
		Cat[i]=(prev*(tn+2)*(tn+1))/(i*(i-1));
		prev=Cat[i];
	}
		SCat.resize(MAX);
	SCat[1]=SCat[2]=1;
	for(ll i=3;i<MAX;i++)
	{
		SCat[i]=((((6*i)-9)*SCat[i-1])-((i-3)*SCat[i-2]))/i;
	}
}
int main()
{
	init();
	int N;
	bool f=true;
	while(scanf("%d",&N)!=EOF)
	{
		printf("%lld\n",SCat[N]-Cat[N]);
	}
	return 0;
}
