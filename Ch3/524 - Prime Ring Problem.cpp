#include<bits/stdc++.h>
using namespace std;
vector<int> cur;
vector<bool> v;
int n;
bool isprime(int c)
{
	if(c<=1)return false;
	if(c<=3)return true;
	if(c%3==0 || c%2==0)return false;
	for(int i=5;i*i<=c;i++)
	if(c%i==0 || c%(i+2)==0)return false;
	return true;
}
void backtrack(int c)
{
	
		if (cur.size() == n) 
		{ 
			if(!isprime(cur[n-1]+cur[0]))return;
			for(int i=0;i<n-1;i++)
			{
				printf("%d ",cur[i]);
			}
			printf("%d\n",cur[n-1]);
			return; 
		} 
		for (int r = 1; r <=n ; r++) 
		{
			if(isprime(c+r) && !v[r-1])
			{
				cur.push_back(r);
				v[r-1]=true;
				backtrack(r);
				v[r-1]=false;
				cur.pop_back();
				
			}
		}
		
		
}
int main()
{
	int K=1;
	while(scanf("%d",&n)!=EOF)
	{
		if(K>1)printf("\n");
		printf("Case %d:\n",K);
		cur.clear();
		cur.push_back(1);
		v.clear();
		v.resize(n);
		v[0]=true;
		backtrack(1);
		K++;
		
	}
	return 0;
}
