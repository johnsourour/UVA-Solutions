#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> prime;
bool isPrime(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)return false;
	}
	return true;
}

int sumD(int n)
{
	int tot=0;
	while(n)
	{
	 tot+=n%10;
	 n/=10;
	}
	return tot;
}
int sumP(int n)
{
	int tot=0;
	int i=2,num=n;
	while(i*i<=num)
	{
		if(num%i==0)
		{
			tot+=sumD(i);
			num/=i;
		//	cout<<i<<endl;
		}
		else i++;
	}
//	cout<<num<<endl;
	return tot+sumD(num);
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		n++;
		while(isPrime(n) || sumD(n)!=sumP(n))n++;
		printf("%d\n",n);
	}
}
