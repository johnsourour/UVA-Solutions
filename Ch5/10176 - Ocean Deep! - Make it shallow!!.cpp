#include<bits/stdc++.h>
using namespace std;
#define MOD 131071;
typedef long long ll;

int main()
{
	string cur;
	char c;
	ll ans;
	while(scanf(" %c",&c)!=EOF)
	{
	//	cout<<K++<<endl;
		int num=0;
		while(c!='#')
		{	num= num<<1;
			num+=c-'0';
			num=num%MOD;
			scanf(" %c",&c);
		}
		if(num)printf("NO\n");
		else printf("YES\n");
		
	}
}
