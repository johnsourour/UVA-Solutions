#include<bits/stdc++.h>
using namespace std;
int N,t,sum;
vector<int> tracks,sol,cur;
void backtrack(int s, int tot)
{

	if(tot>sum || tot==N)
	{
		sol=cur;
		sum=tot;
	}
	for(int i=s;i<t;i++)
	{
		if(tot+tracks[i]<=N)
		{
			tot+=tracks[i];
			cur.push_back(tracks[i]);
			backtrack(i+1,tot);
			tot-=tracks[i];
			cur.pop_back();
		}
	}

}
int main()
{
	int p;
	while(scanf("%d",&N)!=EOF)
	{
		tracks.clear();
		sol.clear();
		cur.clear();
		sum=0;
		scanf("%d",&t);
		for(int i=0;i<t;i++)
		{
			scanf("%d",&p);
			tracks.push_back(p);
		}
		backtrack(0,0);
		for(int i:sol)printf("%d ",i);
		printf("sum:%d\n",sum);
	}
	return 0;
}
