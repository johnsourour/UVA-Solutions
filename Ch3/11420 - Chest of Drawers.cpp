#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 66
int n;
ll mem[MAX][MAX][2];
ll numWays(int pos, int rem, bool prev){
	if(rem<0 || pos>n)return 0;
	if(pos>=n)return rem==0;
	if(mem[pos][rem][prev]==-1){
		ll ans=0;
		if(prev){
			ans+=numWays(pos+1,rem-1,1)+numWays(pos+1,rem,0);
		}
		else{
			ans+=numWays(pos+1,rem,1)+numWays(pos+1,rem,0);
		}
		 mem[pos][rem][prev]=ans;
	}
	return mem[pos][rem][prev];
}
int main()
{
	int s;
	while(scanf("%d%d",&n,&s)!=EOF && (s>=0 && n>=1)){
		memset(mem, -1, sizeof mem);
		printf("%lld\n", numWays(0,s,1));
	}
}
