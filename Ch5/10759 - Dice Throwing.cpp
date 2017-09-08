#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T[25][24*6];
int x;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll DP(int d_left, int cur)
{
	if(d_left==0)return cur>=x;
	if(T[d_left][cur]==-1)
	{
		ll ans=0;
		for(int i=1;i<=6;i++)
		{
			ans+=DP(d_left-1,cur+i);
		}
		T[d_left][cur]=ans;
	}
	return T[d_left][cur];
}
int main()
{
   int n;
   while(cin>>n>>x && (n || x))
   {
   	memset(T,-1,sizeof T);
   	ll cnt=DP(n,0);
   	ll all=pow(6,n);
   	ll g=gcd(all,cnt);
   	if(all==cnt)printf("1\n");
   	else if(cnt==0)printf("0\n");
   	else
   	printf("%lld/%lld\n",cnt/g,all/g);
   	
   }
}
