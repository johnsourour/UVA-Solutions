#include<bits/stdc++.h>
using namespace std;
vector<int> buttons;
bool V[10005];
#define mod 10000
int BFS(int s, int d)
{
	queue<pair<int,int> >q;
	q.push(make_pair(s,0));
	V[s]=true;
	while(!q.empty())
	{
		pair<int,int> f=q.front();q.pop();
		for(int i:buttons)
		{
			int nv=(f.first+i)%mod;
			if(!V[nv])
			{
				if(nv==d)return f.second+1;
				V[nv]=1;
				q.push(make_pair(nv,f.second+1));
			}
		}
		
	}
	
	return -1;
}
int main()
{
	int L,R,U,K=1;
	scanf("%d%d%d",&L,&R,&U);
	while(L||R||U)
	{
		buttons.clear();
		buttons.resize(U);
		memset(V, false, sizeof V);
		for(int i=0;i<U;i++)scanf("%d",&buttons[i]);
		int ans= BFS(L,R);
		printf("Case %d: ",K++);
		if(ans==-1) printf("Permanently Locked\n");
		else printf("%d\n",ans);
		scanf("%d%d%d",&L,&R,&U);
	}
}
