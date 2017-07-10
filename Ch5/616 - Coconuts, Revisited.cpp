#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,cur,rem;
	bool found;
	scanf("%d",&N);
	while(N>=0)
	{
		found=false;
		for(cur=ceil(log(N));cur>=2 && !found;cur--)//min required coconuts = n^n <=> poeple = ceil(ln (n))
		{
			rem=N;
			for(int i=0;i<cur;i++)
			{
				if(rem%cur!=1){
					rem=cur+1;break;
				}
				rem-=((rem/cur )+(rem%cur));
			}
			if(rem%cur==0)found=true;
		}
		printf("%d coconuts, ",N);
		if(found)
		printf("%d people and 1 monkey\n",cur+1);
		else printf("no solution\n");
		scanf("%d",&N);
	}
	return 0;	
}
