#include<bits/stdc++.h>
using namespace std;
long long  T[51][51],m;
long long DP(int n, int k)
{
	if(k>n || n<0 || k<0)return 0;
	if(k==0)return n==0;
	if(n==0)return k==0;
	
	long long  &v=T[n][k];
	if(v==-1)
	{
		v=0;
		for(int i=1;i<=m;i++)
		{
			v+=DP(n-i,k-1);
		}
	}
	return v;
}


int main()
{
	int n,k;
	while(scanf("%d%d%d",&n,&k,&m)!=EOF)
	{
		memset(T,-1,sizeof T);
		printf("%lld\n",DP(n,k));
	}
	return 0;
}
