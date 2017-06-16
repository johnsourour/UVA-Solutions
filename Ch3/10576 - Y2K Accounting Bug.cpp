#include<bits/stdc++.h>
using namespace std;
long long mx,d,s,cur;
int month[12];
bool check5(int m)
{
	if(m<=5)return true;
	int tot=0,i=m;
	while(i>m-5)
	{
		tot+=month[i];
		i--;
		
	}
	if(tot<0)return true;
	else return false;
}
void backtrack(int m)
{
	
	if(m==12)
	{
		mx=max(cur,mx);
		return;
	}
	
	month[m]=s;
	cur+=s;
	if(!check5(m)){month[m]=0;cur-=s;return;}
	backtrack(m+1);
	month[m]=-d;
	cur-=s;
	cur-=d;
	if(!check5(m)){month[m]=0;cur+=d;return;}
	backtrack(m+1);
	cur+=d;
	month[m]=0;
	
    

}
int main()
{
	while(scanf("%lld%lld",&s,&d)!=EOF)
	{
		mx=-1e9;
		cur=0;
		backtrack(0);
		if(mx>=0)printf("%d\n",mx);
		else printf("Deficit\n");
	}
	return 0;
}
