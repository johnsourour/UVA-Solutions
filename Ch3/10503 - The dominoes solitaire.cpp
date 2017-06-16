#include<bits/stdc++.h>
using namespace std;
pair<int,int> f,l;
vector<pair<int,int> > dom;
int n,m,cur;
vector<bool> v;
bool found;
void backtrack(int c)
{
	if(found)return;
	if(cur==n)
	{
		if(c==l.first)found=true;
		return;
	}
	for(int i=0;i<dom.size();i++)
	{
		if(found)break;
		if(!v[i])
		{
			if(dom[i].first==c)
			{
				v[i]=true;
				cur++;
			
				backtrack(dom[i].second);
				cur--;
				v[i]=false;
			}
			else if(dom[i].second==c)
			{
				v[i]=true;
				cur++;
				backtrack(dom[i].first);
				cur--;
				v[i]=false;
			}
		}
	}
}
int main()
{
	int p1,p2;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d",&m);
		scanf("%d",&p1);
		scanf("%d",&p2);
		f=make_pair(p1,p2);
		scanf("%d",&p1);
		scanf("%d",&p2);
		l=make_pair(p1,p2);
		dom.clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d",&p1);
			scanf("%d",&p2);
			dom.push_back(make_pair(p1,p2));
		}
		v.clear();
		v.resize(m);
		found=false;
		cur=0;
		backtrack(f.second);

		if(found)printf("YES\n");
		else printf("NO\n");
		scanf("%d",&n);
	}
	return 0;
}
