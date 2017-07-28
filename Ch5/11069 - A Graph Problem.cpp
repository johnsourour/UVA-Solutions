#include<bits/stdc++.h>
using namespace std;
#define MAX 77
int cnt[MAX];
void init()
{
	cnt[1]=1;
	cnt[2]=2;
	cnt[3]=2;
	for(int i=4;i<MAX;i++)
		cnt[i]=cnt[i-2]+cnt[i-3];
}
int main()
{
	int N;
	init();
	while(scanf("%d",&N)!=EOF)
		printf("%d\n",cnt[N]);
	
	return 0;
}
