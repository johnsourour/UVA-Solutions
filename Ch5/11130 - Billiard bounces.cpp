#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,v,A,s,t,d,vx,vy,px,py;
	bool found;
	scanf("%lf%lf%lf%lf%lf",&a,&b,&v,&A,&s);
	while(a && b && v && s)
	{
		a*=2.0;
		b*=2.0;
		vx=v*cos(A*(M_PI/180));
		vy=v*sin(A*(M_PI/180));
		px=(vx*s)/a;
		py=(vy*s)/b;
		printf("%.0lf %.0lf\n",px,py);
		scanf("%lf%lf%lf%lf%lf",&a,&b,&v,&A,&s);
	}
	return 0;	
}
