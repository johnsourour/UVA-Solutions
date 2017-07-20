#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll H(int n)
{
	if(n<0)return 0;
	ll res=0,prev=-1;
	for(int i=1;i<=sqrt(n);i++)
	{
		ll cur=n/i;
		res+=cur;
		if(prev!=-1)res+=(prev-cur)*(i-1);
		prev=cur;
	}
	int sq=sqrt(n);
	res+=sq*(prev-sq);
	return res;
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%lld\n",H(n));
	}
	return 0;
}
