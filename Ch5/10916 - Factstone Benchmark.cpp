#include<bits/stdc++.h>
using namespace std;
#define start 1960
vector<int> mx;
int main()
{
	int N,bits;
  double tot,mx;
	scanf("%d",&N);
	while(N)
	{
		bits=4;
		N-=(N%10);
		bits= bits << ((N-start)/10);
		int cur=1;
		tot=log(cur);
		mx=bits*log(2);
		while(tot<=mx)
		{
			cur++;
			tot+=log(cur);
		}
		printf("%d\n",cur-1);
		scanf("%d",&N);
	}
	return 0;
}
