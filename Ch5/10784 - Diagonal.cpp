#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll n)
{
	double ans=3+sqrt(9+(8*n));
	return ceil(ans/2.0);
}
int main()
{
	ll N,K=1;
	while(true)
	{
		scanf("%lld",&N);
		if(!N)break;
		printf("Case %d: %lld\n",K++,solve(N));
	}
	return 0;
}
