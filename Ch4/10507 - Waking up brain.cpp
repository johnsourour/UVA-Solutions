#include <bits/stdc++.h>
using namespace std;
vector<int> p;
vector<int> r;
vector<int> s;
int n;
void init()
{
	r.clear();
	p.clear();
	s.clear();
	s.resize(n);
	r.resize(n);
	p.resize(n);
	for(int i=0;i<n;i++){p[i]=i;s[i]=1;}
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
		int tot=s[x]+s[y];
		if(r[x]>r[y])p[y]=x;
		else {
			p[x]=y;
		
			if(r[x]==r[y])r[y]++;
		
		}
		s[x]=s[y]=tot;
	}
}
int main() {
	int i,m;
	vector<vector<int> >adjList;
	char c1,c2,c3;
	map<char,int> ba;
	while(scanf("%d",&n)!=EOF)
	{
		ba.clear();
		i=0;
		adjList.clear();
		adjList.resize(n);
		init();
		scanf("%d",&m);
		scanf(" %c %c %c",&c1,&c2,&c3);
		if(ba.find(c1)==ba.end()){ba.insert(make_pair(c1,i++));r[i-1]=0;}
		if(ba.find(c2)==ba.end()){ba.insert(make_pair(c2,i++));r[i-1]=0;}
		if(ba.find(c3)==ba.end()){ba.insert(make_pair(c3,i++));r[i-1]=0;}
		p[ba[c3]]=p[ba[c2]]=ba[c1];
		s[ba[c1]]=3;
		while(m--)
		{
			scanf(" %c %c",&c1,&c2);
			if(ba.find(c1)==ba.end()){ba.insert(make_pair(c1,i++));}
			if(ba.find(c2)==ba.end()){ba.insert(make_pair(c2,i++));}
			if(ba[c1]>2)adjList[ba[c1]].push_back(ba[c2]);
			if(ba[c2]>2)adjList[ba[c2]].push_back(ba[c1]);
		
		}
		int k=0;
		int hrs=0;
		while(k<n && s[findSet(0)]<n)
		{
			vector<int> awake;
			
			for(int x=3;x<adjList.size();x++)
			{
				if(isSameSet(x,0))continue;
				if(adjList[x].size()<3)break;
				int adj=0;
				for(int h:adjList[x])
				{
					if(isSameSet(h,0))adj++;
				}
				if(adj>=3)awake.push_back(x);
			}
			for(int x:awake)unionSet(x,0);
			hrs++;
			k++;
		}
		if(s[findSet(0)]<n)printf("THIS BRAIN NEVER WAKES UP\n");
		else printf("WAKE UP IN, %d, YEARS\n",hrs);
	}
	return 0;
}
