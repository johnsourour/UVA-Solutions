#include<bits/stdc++.h>
using namespace std;
vector<int> cur,num;
set<vector<int> > sol;
int t,n,sum;
void backtrack(int c)
{
	sum+=num[c];
	cur.push_back(num[c]);
	if(sum==t)
	{
		if(!sol.count(cur))sol.insert(cur);
	}
	for(int i=c+1;i<n;i++)
	{
		if(sum+num[i]<=t)
		{
			backtrack(i);
		}
	}
	sum-=num[c];
	cur.pop_back();
	for(int i=c+1;i<n;i++)
	{
		if(sum+num[i]<=t)
		{
			backtrack(i);
		}
	}
}
int main()
{
	int p;
	scanf("%d%d",&t,&n);
	while(t || n)
	{
		printf("Sums of %d:\n",t);
		cur.clear();
		sum=0;
		num.clear();
		sol.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&p);
			num.push_back(p);
		}
		backtrack(0);
		if(!sol.size())printf("NONE\n");
		else 
		for(set<vector<int> >::reverse_iterator i=sol.rbegin();i!=sol.rend();i++)
		{
			for(int j=0;j<(*i).size()-1;j++)
			{
				printf("%d+",(*i)[j]);
			}
			printf("%d\n",(*i)[(*i).size()-1]);
		}
		scanf("%d%d",&t,&n);
	}
	return 0;
}
