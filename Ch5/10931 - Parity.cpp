#include<bits/stdc++.h>
using namespace std;
string s;
int num(int n)
{
	bitset<32> bs(n);
	int cnt=0;
	s="";
	int last;
	for(int i=0;i<32;i++)
	{
		if(bs.test(i))
		{
			s+='1';
			cnt++;
			last=i;
		}
		else s+='0';
		
	}
	if(s.length()>last+1)s.erase(last+1,s.length()-last-1);
	reverse(s.begin(),s.end());
	return cnt;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		printf("The parity of %s is %d (mod 2).\n",s.c_str(),num(n));
		scanf("%d",&n);
	}
	
	return 0;
}
