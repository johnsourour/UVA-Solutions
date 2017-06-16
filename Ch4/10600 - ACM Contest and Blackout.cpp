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
	int f,t, w;
};
struct comp
{
	bool operator()(const Edge &e1,const Edge &e2)
	{
		return e1.w<e2.w;
	}
};
int main()
{

	vector<Edge> EdgeList;
	vector<int> taken;
	
	int	N,M,K=1,f,t,T,cost1,cost2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		cost1=0;
		cost2=1e9;
		EdgeList.clear();
		init(N);
		for(int i=0;i<M;i++)
		{
			Edge tmp;
			scanf("%d%d%d",&tmp.f,&tmp.t,&tmp.w);
			tmp.f--;tmp.t--;
			EdgeList.push_back(tmp);
		}
		taken.clear();
		sort(EdgeList.begin(),EdgeList.end(),comp());
		for(int i=0;i<EdgeList.size();i++)
		{
			Edge e=EdgeList[i];
			if(!isSameSet(e.f,e.t))
			{
				unionSet(e.f,e.t);
				cost1+=e.w;
				taken.push_back(i);
			}
		}
		int cur;
		V.clear();V.resize(M);
		for(int i=0;i<taken.size();i++)
		{
			cur=0;
			V[taken[i]]=true;
			init(N);
			int cnt=1;
			for(int k=0;k<EdgeList.size();k++)
			{
				Edge e=EdgeList[k];
				if(!isSameSet(e.f,e.t) && !V[k])
				{
					unionSet(e.f,e.t);
					cur+=e.w;
					cnt++;
				}
			}
			
			V[taken[i]]=false;
			if(cnt==N)cost2=min(cost2,cur);
		}
		printf("%d %d\n",cost1,cost2);
		
	}
	
	return 0;
}
