#include<bits/stdc++.h>
using namespace std;
int arit(int a, int r)
{
	return (r*((2*a)+r-1))/2;
}
int main()
{
	int n,i,j;
	bool found;
	scanf("%d",&n);
	while(n>0)
	{
		found=false;
		for(i=sqrt(2*n);i>0;i--)
		{
			if(((2*n) + i - (i*i))%(2*i)==0)
			{
				j=((2*n) + i - (i*i))/(2*i);
				break;
			}
		}
		printf("%d = %d + ... + %d\n",n,j,j+i-1);
		scanf("%d",&n);
	}

}
