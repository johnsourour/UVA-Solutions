#include <bits/stdc++.h>
using namespace std;

int main() {
	long long N,M,t,tot;
	set<long long> cds;
	scanf("%lld%lld",&N,&M);
	while(N || M)
	{
		tot=0;
		cds.clear();
		for(int i=0;i<N;i++)
		{
			scanf("%lld",&t);
			cds.insert(t);
		}
		
		for(int i=0;i<M;i++)
		{
			scanf("%lld",&t);
			if(cds.find(t)!=cds.end())tot++;
		}
		printf("%lld\n",tot);
		scanf("%lld%lld",&N,&M);
	}
	return 0;
}
