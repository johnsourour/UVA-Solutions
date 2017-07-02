#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000007
ll dist[105][105],n;
ll getDist(int i, int j, int f)
{
	if(i<0||i>=n||j<0||j>=n)return 0;
	if(dist[i][j]==-1)
	{
		if(f==1)return getDist(i+1,j+1,0);
		else if(f==2) return getDist(i+1,j-1,0);
		else return 0;
	}
	return dist[i][j];
}
int main()
{
	char c;
	int T,K=1, start,row;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
			{
				scanf(" %c",&c);
				if(c=='W')
				{
					dist[i][j]=1;start=j;row=i;
				}
				else if(c=='.')dist[i][j]=0;
				else dist[i][j]=-1;
			}
		}	
		for(int i=row-1;i>=0;i--)
		{
			for(int j=0;j<n;j++)
			{
				if(dist[i][j]==0)
				dist[i][j]+=(getDist(i+1,j-1,2)%MOD)+(getDist(i+1,j+1,1)%MOD);
			}
		}
		ans=0;
		for(int j=0;j<n;j++)if(dist[0][j]>0)ans=(ans+dist[0][j])%MOD;
	
		printf("Case %d: %lld\n",K++,ans%MOD);
	}
	
	return 0;
}
