#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 2000001
ll EP[MAX],D[MAX];
ll DP(int n)
{
	if(D[n]==-1)
	{
		D[n]=D[EP[n]]+1;
	}
	return D[n];
}
void sieve() 
{ 
	for(int i=2;i<MAX;i++)EP[i]=i;
	for (int i = 2; i < MAX; i++) 
	if (EP[i]==i) 
	{
		for (int j = i; j <MAX; j += i) EP[j]-=(EP[j]/i);
	
	}
	for(int i=2;i<MAX;i++)DP(i);
	for(int i=3;i<MAX;i++)D[i]+=D[i-1];
}
int main()
{
	int n,m,T;
	scanf("%d",&T);
	memset(D,-1 ,sizeof D);
	D[0]=D[1]=0;
	sieve();
	while(T--)
	{
		scanf("%d%d",&m,&n);
		printf("%lld\n",D[n]-D[m-1]);
	}
}
