#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t,prev,cur,mx,ind,K=1;
	scanf("%d",&n);
	vector<vector<int> >bags;
	vector<int> in;
	while(n)
	{
		prev=mx=cur=0;
		bags.clear();
		in.clear();
		in.resize(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			in[i]=t;
		}
		sort(in.begin(),in.end());
		prev=in[0];
		for(int i=1;i<n;i++)
		{
			t=in[i];
			if(t==prev)cur++;
			else cur=0;
			mx=max(mx,cur);
			prev=t;
		}
		mx++;
		bags.resize(mx);
		ind=0;
		for(int i=0;i<n;i++)
		{
			bags[ind].push_back(in[i]);
			ind=(ind+1)%mx;
		}
		printf("%d\n",mx);
		for(vector<int> vi:bags)
		{
			if(vi.size()>1)
			{
				for(int i=0;i<vi.size()-1;i++)printf("%d ",vi[i]);
				printf("%d\n",vi[vi.size()-1]);
			}
			else printf("%d\n",vi[0]);
			
		}
		scanf("%d",&n);
		if(n)printf("\n");
		K++;
	}
	return 0;
}
