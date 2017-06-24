#include<bits/stdc++.h>
using namespace std;
typedef pair<string,int> si;
#define INF 1e9
int adjMat[51][51];
vector<string> names;
map<string,int> mp;
int main()
{
	int n,r,K=1,cnt;
	string f,t;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d",&r);
		cnt=0;
		mp.clear();
		names.clear();
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		{
			if(i!=j)adjMat[i][j]=INF;
			else adjMat[i][j]=0;
		}
		for(int i=0;i<r;i++)
		{
			cin>>f>>t;
			if(mp.find(f)==mp.end()){
				mp.insert(si(f,cnt++));
				names.push_back(f);
			}
			if(mp.find(t)==mp.end()){
				mp.insert(si(t,cnt++));
				names.push_back(t);
			}
			adjMat[mp[f]][mp[t]]=adjMat[mp[t]][mp[f]]=1;
		}
		
		
		for(int k=0;k<n ;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					adjMat[i][j]=min(adjMat[i][j],(adjMat[i][k]+ adjMat[k][j]));
				}
		int mx=-1e9;
		bool disc=false;
		for(int i=0;i<n && !disc;i++)
				for(int j=i+1;j<n && !disc;j++)
				{
					if(adjMat[i][j]==INF ||adjMat[j][i]==INF){
						disc=true;
					}
					else
					{
						mx=max(mx,max(adjMat[i][j],adjMat[j][i]));
					}
				}
		printf("Network %d: ",K++);
		if(disc)printf("DISCONNECTED\n\n");
		else printf("%d\n\n",mx);
		scanf("%d",&n);
	}
	
}
