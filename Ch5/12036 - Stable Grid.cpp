#include<bits/stdc++.h>
using namespace std;
int cnt[100000];
int main()
{
	int T,n,k,cur,K=1;
	bool stable;
	map<int,int> m;
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof cnt);
		stable=true;
		cur=0;m.clear();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&k);
				if(m.find(k)==m.end())m.insert(make_pair(k,cur++));
				if(++cnt[m[k]]>n)stable=false;
				
			}
		}
		printf("Case %d: ",K++);
		if(stable)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
