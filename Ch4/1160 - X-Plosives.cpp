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
typedef pair<int,int> ii;
vector<ii> incoming;
map<int,int> mp;
vector<int> nums;
int main()
{
	int n1,n2,cnt=0;
	while(cin>>n1)
	{
		nums.clear();
		incoming.clear();
		mp.clear();
		cnt=0;
		while(n1!=-1)
		{
			if(mp.find(n1)==mp.end())
			{
				nums.push_back(n1);
				mp.insert(ii(n1,cnt++));
			}
			cin>>n2;
			if(mp.find(n2)==mp.end())
			{
				nums.push_back(n2);
				mp.insert(ii(n2,cnt++));
			}
			incoming.push_back(ii(mp[n1],mp[n2]));
			
			
			cin>>n1;
		}
		init(cnt);
		int skipped=0;
		for(ii p:incoming)
		{
			if (isSameSet(p.first, p.second))
				skipped++;
			unionSet(p.first, p.second);
		}
		cout<<skipped<<endl;
	}
}
