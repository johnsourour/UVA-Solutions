#include<bits/stdc++.h>
using namespace std;
int N;
struct range
{
	int f,t,w;
};
vector<range> r;

int count(range t,int i)
{
	int cnt=1,ans=1;
	i++;
	while(i<N && cnt<t.w)
	{
		if(r[i].f>t.f)
		{
			t.f=r[i].f;
		}
		if(r[i].t<t.t)
		{
			t.t=r[i].t;
		}
		t.w=t.t-t.f;
		i++;
		cnt++;
		ans=max(ans,min(t.w,cnt));
	}
	return ans;
}
int main()
{
	int  M, t, Q, L, U;
	vector<int>::iterator x, y;
	vector<vector<int> > H;
	scanf("%d%d",&N,&M);
	while (N || M)
	{
		H.clear();
		H.resize(N);
		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j<M; j++)
			{
				scanf("%d",&t);
				H[i].push_back(t);
			}
			
		}
		scanf("%d",&Q);
		int cur;
		while (Q--)
		{
			scanf("%d%d",&L,&U);
		r.clear();
			for (int i = 0; i<N; i++)
			{
				range tmp;
				x=lower_bound(H[i].begin(),H[i].end(),L);
				y=upper_bound(H[i].begin(),H[i].end(),U);
				tmp.f=x-H[i].begin();
				tmp.t=y-H[i].begin();
				tmp.w=tmp.t-tmp.f;
				r.push_back(tmp);
			}
			cur=0;
			for (int i = 0; i<N; i++)
			{
				if(r[i].w!=0)
				cur=max(cur,count(r[i],i));
			}
			printf("%d\n", cur);
		}
		printf("-\n");
		scanf("%d%d", &N, &M);
	}
	return 0;
}
