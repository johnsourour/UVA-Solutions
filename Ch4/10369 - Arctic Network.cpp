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
int main()
{

	vector<Edge> EdgeList;
	int	OP,CH,K=1,f,t,T;
	vector<double> mx;
	vector<pair<double,double> > pts;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&CH,&OP);
		pts.clear();
		pts.resize(OP);
		mx.clear();
		EdgeList.clear();
		init(OP);
		for(int i=0;i<OP;i++)
		{
			scanf("%lf%lf",&pts[i].first,&pts[i].second);
		}
		for(int i=0;i<OP;i++)
		{
			for(int j=i+1;j<OP;j++)
			{
				Edge tmp;
				tmp.f=i;
				tmp.t=j;
				tmp.w=sqrt(pow(pts[i].first-pts[j].first,2)+pow(pts[i].second-pts[j].second,2));
			//	cout<<tmp.w<<endl;
				EdgeList.push_back(tmp);
			}
		}
		
		sort(EdgeList.begin(),EdgeList.end(),comp());
		for(Edge e: EdgeList)
		{
			if(!isSameSet(e.f,e.t))
			{
				unionSet(e.f,e.t);
				mx.push_back(e.w);
			}
		}
		sort(mx.begin(),mx.end(),greater<double>());
	//	for(double dd:mx)cout<<dd<<endl;
		if(CH>mx.size())printf("0.00\n");
		else printf("%.2f\n",mx[CH-1]);
		
		
		
	}
	
	return 0;
}
