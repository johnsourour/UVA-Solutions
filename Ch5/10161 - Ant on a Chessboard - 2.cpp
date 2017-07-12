#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	while(N)
	{
		int ind=ceil(sqrt(N));
		int num=ind*ind - ind +1;
		if(N<num)
		{
			if(ind%2==1)printf("%d %d\n",ind,ind-abs(num-N));
			else printf("%d %d\n",ind-abs(num-N),ind);
		}
		else
		{
			if(ind%2==0)printf("%d %d\n",ind,ind-abs(num-N));
			else printf("%d %d\n",ind-abs(num-N),ind);
		}
		scanf("%d",&N);
	}

}
