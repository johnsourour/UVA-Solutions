#include<bits/stdc++.h>
using namespace std;
vector<int> rungs;
int n,m;
bool can(int c)
{
	int tmp,cur=rungs[0];
	if(cur>c)return false;
	if(cur==c)c--;
	for(int i=1;i<rungs.size();i++)
	{
		tmp=rungs[i]-cur;
		if (tmp > c)
            return false;
        else if(tmp==c)
        c--;
        cur=rungs[i];
	}
	return true;
}
int main()
{
	int T,t,s,e,mid,ans,K=1;
scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		rungs.clear();
		rungs.resize(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			rungs[i]=t;
		}
		s=1;
		e=10000000;
		while(s<=e)
		{
			mid=(s+e)/2;
			if(can(mid))
			{
				ans=mid;
				e=mid-1;
			}
			else
			{
				s=mid+1;
			}
		}
		printf("Case %d: %d\n",K,ans);
		K++;
	}
	return 0;
}
