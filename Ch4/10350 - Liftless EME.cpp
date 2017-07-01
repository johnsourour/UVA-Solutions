#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int dist[120][15];
int main()
{
	int n,m,t;
	string name;
	char ss[15];
	while(scanf("%s",&ss[0],sizeof ss)!=EOF)
	{
		name=ss;
		scanf("%d%d",&n,&m);
		for(int j=0;j<m;j++)dist[0][j]=0;
		for(int i=1;i<n;i++)for(int j=0;j<m;j++)dist[i][j]=1e9;
		for(int f=1;f<n;f++)
		{
			for(int h=0;h<m;h++)
			{
				for(int j=0;j<m;j++)
				{
					scanf("%d",&t);
					dist[f][j]=min(t+dist[f-1][h]+2,dist[f][j]);
				}
			}
			
		
		}
		int ans=1e9;
		for(int i=0;i<m;i++)ans=min(ans,dist[n-1][i]);
	
		printf("%s\n%d\n",name.c_str(),ans);
		
	
	}
	
	return 0;
}
