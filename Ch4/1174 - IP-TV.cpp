#include<bits/stdc++.h>
using namespace std;
vector<int> p;
vector<int> r;
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
struct edge
{
	int f,t,w;
};
struct comp
{
	bool operator()(const edge &e1, const edge &e2)
	{
		return e1.w<e2.w;
	}
};
map<string,int> mp;
vector<string> cities;
vector<edge> edgeList;
int main()
{
	int T,n,m,w,cnt;
	cin>>T;
	string s1,s2;
	while(T--)
	{
		cin>>n>>m;
		mp.clear();
		init(n);
		cnt=0;
		cities.clear();
		edgeList.clear();
		edgeList.resize(m);
		for(int i=0;i<m;i++)
		{
			cin>>s1>>s2>>w;
			if(mp.find(s1)==mp.end())
			{
				cities.push_back(s1);
				mp.insert(make_pair(s1,cnt++));
			}
			if(mp.find(s2)==mp.end())
			{
				cities.push_back(s2);
				mp.insert(make_pair(s2,cnt++));
			}
			edgeList[i].f=mp[s1];
			edgeList[i].t=mp[s2];
			edgeList[i].w=w;
		}
		sort(edgeList.begin(),edgeList.end(),comp());
		int mst_cost = 0;
		for (int i = 0; i < m; i++) { 
			edge front = edgeList[i];
			if (!isSameSet(front.f, front.t))
			{ 
				mst_cost += front.w; 
				unionSet(front.f, front.t); 
			} 
		} 
		cout<<mst_cost<<endl;
		if(T)cout<<endl;
	}
}
