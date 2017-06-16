#include<bits/stdc++.h>
using namespace std;
//Disjoint Set
vector<int> p,r;
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
	int f,t;
	double w;
};
struct comp
{
	bool operator()(const Edge &e1,const Edge &e2)
	{
		return e1.w<e2.w;
	}
};
vector<Edge> EdgeList;
int main()
{
	int V,T,x,y,states,K=1;
	double lim,rails,roads;
	long long tot,mn;
	vector<pair<int,int> > pts;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lf",&V,&lim);
		
		init(V);
		pts.clear();
		EdgeList.clear();
		for (int i = 0; i < V; i++)
		{
			scanf("%d %d", &x, &y);
			x+=10000;
			y+=10000;
			pts.push_back(make_pair(x,y)); 
		} 
		for (int i = 0; i < V; i++)
		{
			for (int j = i+1; j < V; j++)
			{
				Edge tmp;
				tmp.f=i;
				tmp.t=j;
				tmp.w=sqrt(pow(pts[i].first-pts[j].first,2)+pow(pts[i].second-pts[j].second,2));
				EdgeList.push_back(tmp); 
			}
		} 
		sort(EdgeList.begin(), EdgeList.end(),comp());
		states=1;
		roads=rails=0.0;
		for (int i = 0; i < EdgeList.size(); i++) {
			Edge front = EdgeList[i];
			if (!isSameSet(front.f, front.t))
			{ 
				if(front.w>=lim){
					states++;
					rails+=front.w;
				}
				else roads+=front.w;
				unionSet(front.f, front.t); // link them
			} 
		}
		printf("Case #%d: %d %.0f %.0f\n",K++,states,roads,rails);
	}
	return 0;
}
