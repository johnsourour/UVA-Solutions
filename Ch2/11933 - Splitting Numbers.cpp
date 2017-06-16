#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n,a,b,nn;
	scanf("%d",&n);
	while(n)
	{
		a=0;
		b=0;
		nn=0;
		bool flag=false;
	    while(nn<32)
	    {
	    	if((n>>nn) & 1 )
	    	{
	    		if(!flag)
	    		{
	    			//int s=pow(2,nn);
	    			a=(a | (1 << nn)); 
	    			flag=true;
	    		}
	    		else flag=false;
	    	}
			nn++;		
	    }
	    b=n^a;
	    printf("%d %d\n",a,b);
		scanf("%d",&n);
	}
	return 0;
}
