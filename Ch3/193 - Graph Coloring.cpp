#include<bits/stdc++.h>
using namespace std;
int n,mx;
vector<vector<int> > adjList;
vector<int> sol,cur;
vector<bool> v;
bool found(int k)
{
	for(int s:adjList[k])
	{
		if(s==k || v[s])
		return true;
	}
	return false;
}
void backtrack(int i)
{
	if(i==n)
	{
		if(cur.size()>=mx)
		{
			mx=cur.size();
			sol=cur;
		}
		return;
	}
	if((n-i)+cur.size()<=sol.size())return;
	if(!found(i))
	{
		v[i]=true;
		cur.push_back(i);
		backtrack(i+1);
		cur.pop_back();
		v[i]=false;
	}
//	
	backtrack(i+1);
	
}
int main()
{
	int t,k,n1,n2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		adjList.clear();
		adjList.resize(n);
		v.clear();
		v.resize(n);
		mx=0;
		cur.clear();
		sol.clear();
		for(int i=0;i<k;i++)
		{
			scanf("%d%d",&n1,&n2);
			adjList[n1-1].push_back(n2-1);
			adjList[n2-1].push_back(n1-1);
		}
		backtrack(0);
		printf("%d\n",sol.size());
		for(int i=0;i<sol.size()-1;i++)printf("%d ",sol[i]+1);
		printf("%d\n",sol[sol.size()-1]+1);
		
	}
	return 0;
}
