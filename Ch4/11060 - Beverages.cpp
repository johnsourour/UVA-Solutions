#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,M,u,v,K=1;
	map<string,int> m;
	vector<string> B;
	vector<int> inDeg,ts;
	vector<vector<int> >adjList;
	char c[51];
	string s,ss;
	while(scanf("%d",&N)!=EOF)
	{
		m.clear();
		B.clear();
		ts.clear();
		inDeg.clear();
		inDeg.resize(N+1,0);
		adjList.clear();
		adjList.resize(N+1);
		for(int i=1;i<=N;i++)
		{
			scanf("%s",&c[0],sizeof c);
			s=c;
			m.insert(make_pair(s,i));
			B.push_back(s);
		}
		scanf("%d",&M);
		for(int i=1;i<=M;i++)
		{
			scanf("%s",&c[0],sizeof c);
			s=c;
			scanf("%s",&c[0],sizeof c);
			ss=c;
			adjList[m[s]].push_back(m[ss]);
			inDeg[m[ss]]++;
		}
		priority_queue<int> q;
		for(int i=1;i<=N;i++)
		{
			if(inDeg[i]==0)q.push(-i);
		}
		while(!q.empty())
		{
			int u=-q.top();q.pop();
			ts.push_back(u-1);
			for(int x:adjList[u])
			{
				inDeg[x]--;
				if(inDeg[x]==0)q.push(-x);
			}
		}
		printf("Case #%d: Dilbert should drink beverages in this order: ",K++);

	for(int i=0;i<N-1;i++)printf("%s ",B[ts[i]].c_str());
	printf("%s.\n\n",B[ts[N-1]].c_str());
	}
	
	return 0;	
}
