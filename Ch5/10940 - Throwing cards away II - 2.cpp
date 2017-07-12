#include<bits/stdc++.h>
using namespace std;
#define MAX 5000002
int ans[MAX];
void construct()
{
	int max=2,cur=2;
	ans[1]=1;
	for(int i=2;i<MAX;i++)
	{
		ans[i]=cur;
		cur+=2;
		if(cur>max)
		{
			max*=2;
			cur=2;
		}
	
	}
}
int main()
{
	int N;
	construct();
	
	scanf("%d",&N);
	while(N)
	{
		printf("%d\n",ans[N]);
		scanf("%d",&N);
	}

}
