#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main()
{
	int N,cur,g;
	while(true)
	{
		scanf("%d",&N);
		cur=0,g=0;
		if(!N)break;
		while(true)
		{
			if(!cur)cur=N;
			else if(g)	g=gcd(N-cur,g);
			else g=N-cur;
			
			//cout<<g<<" "<<N-cur<<endl;
			scanf("%d",&N);
			if(!N)break;
		}
		printf("%d\n",abs(g));
	}
}
