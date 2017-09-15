#include<bits/stdc++.h>
using namespace std;
string in[10];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string ans="";
		for(int i=0;i<10;i++)cin>>in[i];
		for(int j=1;j<in[0].length()-1;j++)
		{
			int val=0;
			for(int i=9;i>0;i--)
			{
				val=val<<1;
				if(in[i].at(j)!='/')val=val|1;	
			}
			
			ans+=(char)val;
		}
		cout<<ans<<endl;
	
	}
}
