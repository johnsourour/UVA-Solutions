#include<bits/stdc++.h>
using namespace std;
vector<int> vessels;
int n,m;
bool can(int c)
{
	int cnt=1,cur=c;
	for(int v:vessels)
	{
		if (v > c)
            return false;
        if(v>cur)
        {
         	if(cnt==m)return false;
         	cnt++;
         	cur=c;
         	
        }
        cur-=v;
	}
	return true;
}
int main()
{
	int t,s,e,mid,ans;

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		vessels.clear();
		vessels.resize(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			vessels[i]=t;
		}
		s=1;
		e=1000000000;
		while(abs(s-e)>1)
		{
			mid=(s+e)/2;
			if(can(mid))
			{
				ans=mid;
				e=mid;
			}
			else
			{
				s=mid;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
