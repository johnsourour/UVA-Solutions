#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int K=1,t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int sum=0,cnt3=0;
		for(char c:s)
		{
			sum+=(c-'0');
			if((c-'0')%3==0 && c!='0')cnt3++;
		
		}
		bool can=false;
		if(sum%3==0)can=(cnt3%2!=0);
		else 
		{
			bool flag=false;
			for(char c:s)if((sum-(c-'0'))%3==0)flag=true;
			can=(flag) && (cnt3%2==0);
		}
		printf("Case %d: %c\n",K++,can? 'S':'T');
	}
}
