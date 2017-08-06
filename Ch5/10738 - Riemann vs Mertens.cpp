#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000001 
int diffPF[MAX],mu[MAX],M[MAX];
bool sqr[MAX];

void gen()
{
	int cur=1;
	mu[1]=M[1]=cur;
	for(int i=2;i<MAX;i++)
	{
		if(sqr[i])
		{
			mu[i]=0;
		}
		else
		{
			if(diffPF[i]%2==1)mu[i]=-1;
			else mu[i]=1;
		}
		cur+=mu[i];
		M[i]=cur;
	}
}
void sieve() 
{ 
	for (ll i = 2; i < MAX; i++) 
	if (!diffPF[i]) 
	{
		for (ll j = i; j <MAX; j += i) 
		{
			if(j%(i*i)==0){
				sqr[j]=true;
			}
			else 
			{
				diffPF[j]++;
			}
		}
	
	}
	gen();
}
int main()
{
	int n;
	memset(diffPF, 0,sizeof diffPF);
	memset(sqr, false,sizeof sqr);
	sieve();
	while(scanf("%d",&n)!=EOF && n)
	{
		printf("%8d%8d%8d\n",n,mu[n],M[n]);
	}
}
