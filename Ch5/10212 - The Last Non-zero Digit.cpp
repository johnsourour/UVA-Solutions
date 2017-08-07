#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000000;
typedef long long ll;
void keep(ll &n)
{
	while(n%10==0)n/=10;
	n%=MOD;
}
int main()
{
	ll N,M;
	while(scanf("%lld%lld",&N,&M)!=EOF)
	{
		ll cur=1;
		for(ll i=N;i>=N-M+1;i--)
		{
			cur*=i;
			keep(cur);
		}
		printf("%lld\n",cur%10);
	}
}
