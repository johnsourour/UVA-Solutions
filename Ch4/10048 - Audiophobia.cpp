#include<bits/stdc++.h>
using namespace std;
//Disjoint Set
vector<int> p,r;
vector<bool> V;
void init(int n)
{
	r.clear();
	p.clear();
	r.resize(n);
	p.resize(n);
	for(int i=0;i<n;i++)p[i]=i;
}
int findSet(int i)
{
	if(p[i]==i)return i;
	else return findSet(p[i]);
}
bool isSameSet(int i,int j)
{
	return findSet(i)==findSet(j);
}
void unionSet(int i, int j)
{
	if(!isSameSet(i,j))
	{
		int x=findSet(i);
		int y=findSet(j);
		if(r[x]>r[y])p[y]=x;
		else {
			p[x]=y;
			if(r[x]==r[y])r[y]++;
		}
	}
}
//Edge
struct Edge
{
	int f,t,w;
};
struct comp
{
	bool operator()(const Edge &e1,const Edge &e2)
	{
		return e1.w<e2.w;
	}
};
vector<vector<pair<int,int> > >adjList;
int dfs(int s, int d, int mx)
{
	
	V[s]=true;
	if(s==d)return mx;
	int ans=0;
	for(pair<int,int> x:adjList[s])
	{
		if(!V[x.first])
		{
			ans=max(ans,dfs(x.first,d,max(mx,x.second)));
		}
		
	}
	return ans;
}
int main()
{

	vector<Edge> EdgeList;
	int C,S,Q,K=1,f,t;
	scanf("%d%d%d",&C,&S,&Q);
	while(C||S||Q)
	{
		EdgeList.clear();
		adjList.clear();
		adjList.resize(C);
		init(C);
		for(int i=0;i<S;i++)
		{
			Edge tmp;
			scanf("%d%d%d",&tmp.f,&tmp.t,&tmp.w);
			tmp.t--;tmp.f--;
			EdgeList.push_back(tmp);
		}
		sort(EdgeList.begin(),EdgeList.end(),comp());
		for(Edge e: EdgeList)
		{
			if(!isSameSet(e.f,e.t))
			{
				unionSet(e.f,e.t);
				adjList[e.f].push_back(make_pair(e.t,e.w));
				adjList[e.t].push_back(make_pair(e.f,e.w));
			}
		}
		if(K>1)printf("\n");
		printf("Case #%d\n",K++);
		for(int i=0;i<Q;i++)
		{
			V.clear();
			V.resize(C);
			scanf("%d%d",&f,&t);f--;t--;
			if(isSameSet(f,t))
			printf("%d\n",dfs(f,t,0));
			else printf("no path\n");
		}
		
		scanf("%d%d%d",&C,&S,&Q);
	}
	
	return 0;
}
