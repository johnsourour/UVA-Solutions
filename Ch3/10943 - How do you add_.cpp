#include<bits/stdc++.h>
using namespace std;
#define mod 1000000

long long T[101][101];
long long DP(int N, int K)
{
	if(K==1)return 1;
	if(T[N][K]!=-1)return T[N][K];
	long long ans=0;
	for(int i=0;i<=N;i++)
		ans+=(DP(N-i,K-1)%mod);
	T[N][K]=ans%mod;
	return T[N][K];
}

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	while(N||K)
	{
		memset(T,-1,sizeof T);
		printf("%d\n",(DP(N,K)%1000000));
		scanf("%d%d",&N,&K);
	}
	return 0;
}
