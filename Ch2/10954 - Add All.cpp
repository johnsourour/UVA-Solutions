#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int> pq;
	int n,t,n1,n2;
	long long total,cost;
	scanf("%d",&n);
	while(n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			pq.push(-t);
		}
		total=0;
		
		while(pq.size()>1)
		{
			cost=0;
			cost+=-pq.top();
			pq.pop();
			cost+=-pq.top();
			pq.pop();
			total+=cost;
			pq.push(-cost);
		}
			pq.pop();
		printf("%d\n",total);
		scanf("%d",&n);
	}
	return 0;
}
