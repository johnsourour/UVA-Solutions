#include <bits/stdc++.h>
using namespace std;
vector<int> A;
long long val(int n)
{
	long long sum=0;
	for(int i=A.size()-1;i>=0;i--)
	{
		sum=sum*n+A[i];
	}
	return sum;
}
int main() 
{
	int C,d,k,j,t;
	scanf("%d",&C);
	while(C--)
	{
		
		A.clear();
		scanf("%d",&j);
		for(int i=0;i<=j;i++)
		{
			scanf("%d",&t);
			A.push_back(t);
		}
		scanf("%d%d",&d,&k);
		long long count=0,p=1,cd,cv;
		
		while(count<k)
		{
			cv=val(p);
			cd=p*d;
			p++;
			count+=cd;	
		}
		printf("%lld\n",cv);
	}
	return 0;
}
