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
	int f,t,w;
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
	int V,E;
	scanf("%d%d",&V,&E);
	while(V||E)
	{
		init(V);
		EdgeList.clear();
		for (int i = 0; i < E; i++)
		{
			Edge tmp;
			scanf("%d %d %d", &tmp.f, &tmp.t, &tmp.w);
			EdgeList.push_back(tmp); 
		}
		bool found=false;
		sort(EdgeList.begin(), EdgeList.end(),comp());
		for (int i = 0; i < E; i++) {
			Edge front = EdgeList[i];
			if (!isSameSet(front.f, front.t))
			{ 			
				unionSet(front.f, front.t); // link them
			} 
			else 
			{
				if(found)printf(" %d",front.w);
				else{
					found=true;
					printf("%d",front.w);
				}
			}
			
		}
		if(found)printf("\n");
		else printf("forest\n");
		scanf("%d%d",&V,&E);
	}
	return 0;
}
