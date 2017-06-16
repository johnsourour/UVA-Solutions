#include<bits/stdc++.h>
using namespace std;
int main()
{
long long N,M,S,L,U,tmp,ans;
	while(scanf("%lld%lld%lld",&N,&L,&U)!=EOF)
	{
		int i=32;
		ans=0;
		S=0x80000000;
		while(i--)
		{
			tmp=ans+S;
			if((N&S) && tmp<=L)ans+=S;
			if (!(N&S) && tmp<=U)ans+=S;
			S=S>>1;
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
