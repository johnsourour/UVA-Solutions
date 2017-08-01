#include<bits/stdc++.h>
using namespace std;
#define MAX 21
#define ML 27
typedef long long ll;
int rep[ML];
ll mem[MAX];
void gen()
{
	mem[0]=mem[1]=1;
	ll cur=1;
	for(int i=2;i<MAX;i++)
	{
		cur*=(ll)i;
		mem[i]=cur;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	gen();
	char c[22];
	int K=1;
	string s;
	while(T--)
	{
		memset(rep, 0 ,sizeof rep);
		scanf("%s",&c[0],sizeof c);
		s=c;
		for(int i=0;i<s.length();i++)
		{
			rep[s.at(i)-'A']++;
		}
		ll ans=mem[s.length()];
		for(int i=0;i<ML;i++)
		{
			ans/=mem[rep[i]];
		}
		printf("Data set %d: %lld\n",K++,ans);
	}
	
}
