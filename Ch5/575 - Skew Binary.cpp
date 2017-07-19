#include<bits/stdc++.h>
using namespace std;
int solve(string n)
{
	int add=0,tot=0,mul=2,cur;
	reverse(n.begin(),n.end());
	for(int i=0;i<n.length();i++)
	{
		char c=n.at(i);
		cur=c-'0';
		tot+=cur*(mul-1);
		mul*=2;
		//cout<<tot<<endl;
	}
	return tot;
}
int main()
{
	string s;
	char c[100];
	scanf("%s",&c[0],sizeof c);
	s=c;
	while(s!="0")
	{
		printf("%d\n",solve(s));
		scanf("%s",&c[0],sizeof c);
		s=c;
	}
	
	return 0;
}
