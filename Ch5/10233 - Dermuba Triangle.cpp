#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> ii;
ii pos(int k)
{
	int level=sqrt(k);
	int col=k-pow(level,2);
	double x=0.5*(level-col);
	double y=level;
	if((k + level) % 2 == 0)
		y += (2.0/3.0);
	
	else
		y += (1.0/3.0);
	
	y*=sin(M_PI/3.0);
	return ii(x,y);
}
int main()
{
//	generate();
	int n,m;
	ii f,s;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		f=pos(n);
		s=pos(m);
		printf("%.3f\n",hypot(f.first-s.first,f.second-s.second));
	}
}
