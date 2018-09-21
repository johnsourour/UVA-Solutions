#include <bits/stdc++.h>
using namespace std;
#define MAX 25
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
vector<vector<int> > answers, adjList;
vector<int> cur;
bool vis[MAX], rep[MAX][MAX];
void dfs(int u, int end){
	vis[u]=1;
	cur.push_back(u);
	if(u==end){
		answers.push_back(cur);
		
	}
	else for(int x: adjList[u]){
		if(!vis[x])	dfs(x,end);
	}
	vis[u]=0;
	cur.pop_back();
}
int main(){
	
	vector<long long> vs;
	int target,e1,e2,K=0;
	while(scanf("%d",&target)!=EOF){
		adjList.clear();
		answers.clear();
		adjList.resize(MAX);
		init(MAX);
		memset(vis, 0, sizeof vis);
		memset(rep, 0, sizeof rep);
		while(scanf("%d%d",&e1,&e2)!=EOF && e1 && e2){
			if(rep[e1][e2])continue;
			adjList[e1].push_back(e2);
			adjList[e2].push_back(e1);
			unionSet(e1,e2);
			rep[e1][e2]=rep[e2][e1]=true;
		}
		printf("CASE %d:\n",++K);
		if(isSameSet(1,target)){
			dfs(1,target);
			sort(answers.begin(),answers.end());
			for(vector<int> v:answers){
				printf("%d",v[0]);
				for(int x=1;x<v.size();x++)printf(" %d",v[x]); printf("\n");
			}
		}
		printf("There are %d routes from the firestation to streetcorner %d.\n",(int)answers.size(),target);
		
	}
	
	
}