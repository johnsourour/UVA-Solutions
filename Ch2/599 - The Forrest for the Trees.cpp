#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	string s;
	char in[60];
	scanf("%d",&n);
	int e,v,ac;
	bitset<26> bs;
	while(n--)
	{
		scanf("%s",&in[0],sizeof in);
		s=in;
		e=0;
		ac=0;
		v=0;
		bs.reset();
		while(s.at(0)!='*')
		{
			bs[s.at(1)-'A']=1;
			bs[s.at(3)-'A']=1;
			
			scanf("%s",&in[0],sizeof in);
			s=in;
			e++;
		}
		scanf("%s",&in[0],sizeof in);
		s=in;
		
		
		for(int i=0;i<s.length();i+=2)
		{
			v++;
			if(bs[s.at(i)-'A']==0)ac++;
		}
		printf("There are %d tree(s) and %d acorn(s).\n",v-e-ac,ac);
		
		
	}
	return 0;
}
