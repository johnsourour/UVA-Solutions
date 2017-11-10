#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	int T;
	scanf("%d",&T);
	char in[55];
	string s;
	while(T--)
	{
		scanf("%s",&in[0],sizeof in);
		s=in;
		bool me,valid;
		int M,E;
		me=valid=true;
		for(int i=0;i<s.length() && valid;i++)
		{
			if(s[i]!='?' && s[i]!='M' &&s[i]!='E')valid=false;
			if(s[i]=='E')E=i;
			if(s[i]=='M')M=i;
		}
		if(M>E || !valid || !M || M==E-1)me=false;
		else
		{
			int before=E-1;
			int after=s.length()-E-1;
		//	cout<<before<<" "<<after<<endl;
			if(before!=after)me=false;
		}
		
		
		
		if(!me)printf("no-");
		printf("theorem\n");
		
	}
}
