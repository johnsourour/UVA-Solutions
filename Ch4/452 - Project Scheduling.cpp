#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,cur,from;
	string s,num;
	scanf("%d",&T);
	getline(cin,s);
	getline(cin,s);
	int inDeg[28],dist[28],w[28];
	vector<vector<int> > adjList;
	while(T--)
	{
		adjList.clear();
		adjList.resize(28);
		priority_queue<int> Q;
		while(getline(cin,s) && s!="")
		{
			cur=s.at(0)-'A';
			s.erase(0,2);num="";
			while(s.length()>0 && s.at(0)!=' ')
			{
				num+=s.at(0);
				s.erase(0,1);
			}
			dist[cur]=w[cur]=stoi(num);
			inDeg[cur]=0;
			if(s.length()>=2)
			{
				s.erase(0,1);
				while(s.length()>0 && s.at(0)!=' ')
				{
					from=s.at(0)-'A';
					adjList[from].push_back(cur);
					inDeg[cur]++;
					s.erase(0,1);
				}
			}
			else Q.push(-cur);
		}
		int ans=-1e9;
		while(Q.size())
		{
			int v = -Q.top(); Q.pop();
			for(int i : adjList[v])
			{
				dist[i]=max(dist[i],w[i]+dist[v]);
				if(--inDeg[i] == 0)
					Q.push(-i);
			}
			ans=max(ans,dist[v]);
		}
		printf("%d\n",ans);
		if(T)printf("\n");
		
	
	}
	
	return 0;
}
