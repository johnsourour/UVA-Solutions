#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 5844
vector<ll> s;
void generate()
{
	int i=0;
	int num[]={2,3,5,7};
	int pos[]={0,0,0,0};
	ll cur[]={1,1,1,1};
	s.push_back(1);
	vector<int> ind;
	while(s.size()<MAX)
	{
		ll mn=1e15;
		for(int i=0;i<4;i++)
		{
			cur[i]=num[i]*s[pos[i]];
			if(cur[i]<mn)
			{
				ind.clear();
				ind.push_back(i);
				mn=cur[i];
			}
			else if(cur[i]==mn)ind.push_back(i);
		}
		for(int k:ind)pos[k]++;
		s.push_back(mn);
		
	}
}
int main()
{
	generate();
	int n;
	scanf("%d",&n);
	while(n)
	{
		printf("The %d",n);
		if(n%10==1 && n%100!=11)printf("st");
		else if(n%10==2 && n%100!=12)printf("nd");
		else if(n%10==3 && n%100!=13)printf("rd");
		else printf("th");
		printf(" humble number is %d.\n",s[n-1]);
		scanf("%d",&n);
	}
}
