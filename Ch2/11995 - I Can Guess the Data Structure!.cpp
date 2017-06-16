#include <bits/stdc++.h>
using namespace std;

int main() {
	queue<int> q;
	priority_queue<int> pq;
	stack<int> s;
	bool PQU,QU,ST;
	int n,t,v;
	while(scanf("%d",&n)!=EOF)
	{
		PQU=true;
		ST=true;
		QU=true;
		while(!s.empty())s.pop();
		while(!pq.empty())pq.pop();
		while(!q.empty())q.pop();
		int i=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&t,&v);
			if(t==1)
			{
				s.push(v);
				pq.push(v);
				q.push(v);
			}
			else
			{
				if((!s.empty() && v!=s.top()) || s.empty())ST=false;
				else s.pop();
				if((!pq.empty() && v!=pq.top()) || pq.empty())PQU=false;
				 else	pq.pop();
				if((!q.empty() && v!=q.front()) || q.empty())QU=false;
				else q.pop();
			}
		}
		if(ST && !PQU && !QU)printf("stack\n");
		else if(!ST && !PQU && QU)printf("queue\n");
		else if(!ST && PQU && !QU)printf("priority queue\n");
		else if(!ST && !PQU && !QU)printf("impossible\n");
		else printf("not sure\n");
		
	}
	return 0;
}
