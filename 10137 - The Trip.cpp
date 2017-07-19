#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	double tot,avg,ans;
	vector<double> p;
	while(n)
	{
		p.clear();
		p.resize(n);
		tot=ans=0.0;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&p[i]);
			tot+=p[i];
		}
		avg=tot/(double)n;
		double pos,neg;
		pos=neg=0.0;
		for(double d:p)
		{
			double tmp=(double)(int)((avg-d)*100.0)/100.0;
			if(tmp>0)
			{
				pos+=tmp;
			}
			else
			{
				neg+=tmp;
			}
			
		}
	//	cout<<pos<<" "<<neg<<endl;
	
		printf("$%.2lf\n",max(pos,-neg));
		scanf("%d",&n);
	}
	
	return 0;
}
