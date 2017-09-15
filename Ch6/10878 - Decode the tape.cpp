#include<bits/stdc++.h>
using namespace std;
int bindec(string s)
{
	int ret=0;int cur=1;
	for(int i=s.length()-1;i>=0;i--)
	{
		if(s.at(i)=='1')ret+=cur;
		cur*=2;
	}
	return ret;
}
int main()
{
	string in,out="";
	bool b=false;
	while(getline(cin,in))
	{
  if(in.at(2)=='_')continue;
		int val=0;string s="";
		for(int j=1;j<in.length()-1;j++)
		{
			
			if(in.at(j)=='o')s+='1';
			else if(in.at(j)==' ')s+='0';
				
			
		}
		val=bindec(s);
		out+=(char)val;
	}
		cout<<out;
}
