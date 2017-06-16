#include<bits/stdc++.h>
using namespace std;
vector<int> st,A,v,start;
int n;
void build(int p, int L, int R)
{
	if(L==R) st[p]=L;
	else { 
		build(p<<1 , L , (L + R) / 2);
		build((p<<1) +1, (L + R) / 2 + 1, R );
		int p1 = st[(p<<1) +1], p2 = st[p<<1];
		st[p] = (A[p1] >= A[p2]) ? p1: p2;
    }
}
int rmq(int p, int L, int R, int i, int j)
{
	if (i > R || j < L) return -1; 
	if (L >= i && R <= j) return st[p];
	int p1 = rmq(p<<1 , L , (L+R) / 2, i, j);
	int p2 = rmq((p<<1)+1, (L+R) / 2 + 1, R , i, j);
	if (p1 == -1) return p2; 
	if (p2 == -1) return p1; 
	
	return (A[p1] >= A[p2]) ? p1:p2; 

}
int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
int main() {
	int q,t,x,y;
	scanf("%d",&n);
	map<int,pair<int,int> > m;
	while(n)
	{
		scanf("%d",&q);
		A.clear();
		A.resize(n);
		v.clear();
		v.resize(n);
		start.clear();
		start.resize(n);
		st.clear();
		st.resize(4*n);
		m.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			v[i]=t;
			if(m.find(t)==m.end())m.insert(make_pair(t,make_pair(i,1)));
			else m[t].second++;
		}
		for(int i=0;i<n;i++)
		{
			A[i]=m[v[i]].second;
			start[i]=m[v[i]].first;
		}
		build(1,0,n-1);
		for(int i=0;i<q;i++)
		{
			scanf("%d%d",&x,&y);
			y--;
			x--;
			int cnt1=A[x]+start[x]- x;
			int cnt2=y - start[y] + 1;
			int r1=start[x]+A[x],r2=start[y]-1;
			int cnt3=(r1<=r2)?A[rmq(r1,r2)]:0;
			int ans=(v[x]==v[y])? y-x+1:max(cnt1,max(cnt2,cnt3));
			 printf("%d\n",ans); 
		}
	
		scanf("%d",&n);
	}
	return 0;
}
