#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		double lo,hi;
		int cur=log10(N) + 2;
		int ans;
		while(1)
		{
			lo=(log(N)+(log(10)*cur))/log(2);
			hi=(log(N+1)+(log(10)*cur))/log(2);
			
			//cout<<cur<<" "<<lo<<" "<<hi<<endl;
			if(ceil(lo)==floor(hi))
			{
				ans=(int)hi;
				break;
			}
			cur++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
