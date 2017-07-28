#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll cnt,N,M;
	while(scanf("%lld%lld",&N,&M)!=EOF && N || M)
	{
		ll cnt;
		cnt=(M*(N-1)*N);
		cnt+=(N*(M-1)*M);
		ll mn=N<M?N:M,d=cnt;
		ll mx=N>M?N:M;
		for(ll i=2;i<mn;i++)
		{
			cnt+=4*(i*(i-1));
		}
		cnt+=2*(mx-mn+1)*(mn*(mn-1));
		d=cnt-d;
		printf("%lld\n",cnt);
	}
	
	return 0;
}
