#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	int n,d,r,ov,tmp;
	scanf("%d%d%d",&n,&d,&r);
	vector<int> mo,ni;
	while(n || d || r)
	{
		ov=0;
		ni.clear();
		ni.resize(n);
		mo.clear();
		mo.resize(n);
		for(int i=0;i<n;i++)scanf("%d",&mo[i]);
		for(int i=0;i<n;i++)scanf("%d",&ni[i]);
		sort(mo.begin(),mo.end());
		sort(ni.begin(),ni.end());
		for(int i=0;i<n;i++)
		{
			tmp=mo[i]+ni[n-1-i];
			if(tmp>d)ov+=tmp-d;
		}
		printf("%d\n",ov*r);
		scanf("%d%d%d",&n,&d,&r);
    }
	return 0;
}
