#include<bits/stdc++.h>

typedef unsigned long long ull;
using namespace std;
ull modpow(ull p, ull n, ull m) {
  ull w = 1;
  for (ull i = 1ULL << (sizeof(ull)*8-1); i != 0; i >>= 1) {
    if ((n & i) == 0) {
      w *= w;
    } else {
      w *= w * p;
    }
    w %= m;
  }
  return w;
}
int main()
{
	int n,k,mod,t,T,sum,C=1,num;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&mod);
		num=(k*modpow(n,k-1,mod))%mod;
		sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			sum=(sum+(t%mod))%mod;
		}
		printf("Case %d: %d\n",C++,(sum*num)%mod);
	}

}
