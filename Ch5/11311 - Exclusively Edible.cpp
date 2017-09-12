#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n1,n2,m,n,r,c;
	cin>>t;
	while(t--)
	{
		cin>>m>>n>>r>>c;
		n1=m-r-1;
		n2=n-c-1;
		if((n1^n2^c^r)==0)cout<<"Hansel\n";
		else cout<<"Gretel\n";
	}
}
