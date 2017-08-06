#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000001 
int diffPF[MAX];
void sieve() 
{ 
	for (ll i = 2; i < MAX; i++) 
	if (!diffPF[i]) 
	{
		for (ll j = i; j <MAX; j += i) diffPF[j]++;
	
	}
}
int main()
{
	int n;
	memset(diffPF, 0,sizeof diffPF);
	sieve();
	while(scanf("%d",&n)!=EOF && n)
	{
		printf("%d : %d\n",n,diffPF[n]);
	}
}
