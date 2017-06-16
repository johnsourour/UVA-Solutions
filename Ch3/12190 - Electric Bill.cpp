#include<bits/stdc++.h>
using namespace std;
int bill(int num)
{
	int tot;
	if(num<101)tot=2*num;
	else if(num<10001)tot=200+((num-100)*3);
	else if(num<1000001)tot=29900+((num-10000)*5);
	else tot=4979900+((num-1000000)*7);
	return tot;
}
int cons(int num)
{
	
	int tot;
	if(num<201)tot=num/2;
	else if(num<29901)tot=100+((num-200)/3);
	else if(num<4979901)tot=10000+((num-29900)/5);
	else tot=1000000+((num-4979900)/7);
	return tot;
}
int diff(int x, int y)
{
	return bill(y)-bill(x);
}
int main()
{
	int A,B,x1,x2,k,hi,lo,mid,tot;
	scanf("%d%d",&A,&B);

	while(A||B)
	{
		lo=0;
		hi=cons(A);
		tot=hi;
		while(lo<hi)
		{
			mid=(hi+lo)/2;
			k=bill(tot-mid)-bill(mid);
			if(k==B)break;
			else if(k<B)hi=mid;
			else lo=mid;
		}
		printf("%d\n",bill(mid));
		scanf("%d%d",&A,&B);
	}
	return 0;
}
