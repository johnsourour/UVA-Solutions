#include<bits/stdc++.h>
using namespace std;
#define MAX 11
typedef vector<int> vi;
vi Cat;
void init()
{
	Cat.resize(MAX);
	int prev=1,tn;
	Cat[0]=1;
	for(int i=1;i<MAX;i++)
	{
		tn=(i-1)*2;
		Cat[i]=(prev*(tn+2)*(tn+1))/(i*(i+1));
		prev=Cat[i];
	}
}
int main()
{
	init();
	int N;
	bool f=true;
	while(scanf("%d",&N)!=EOF)
	{
		if(!f)printf("\n");
		f=false;
		printf("%d\n",Cat[N]);
	}
	return 0;
}
