#include<bits/stdc++.h>
using namespace std;
double T[501][501];
double p;
double DP(int g_left, int best)
{
	if(g_left==0)return best;
	
	if(T[g_left][best]==-1.0)
	{
		double cr=1;
		double ans=0.0;
		for(int k=0;k<g_left;k++)
		{ans+=(cr*(1-p)*DP(g_left-k-1,max(k,best)));cr*=p;}
		ans+=cr*DP(0,max(g_left,best));
		T[g_left][best]=ans;
	}
	return T[g_left][best];
}
int main()
{
   int n;
   while(cin>>n>>p && n )
   {
   	for(int i=0;i<501;i++)
   	for(int j=0;j<501;j++)T[i][j]=-1.0;
	double cnt=DP(n,0);
	printf("%0.10lf\n",cnt);
   	
   }
}
