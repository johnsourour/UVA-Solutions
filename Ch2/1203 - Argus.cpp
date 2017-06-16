#include <bits/stdc++.h>
using namespace std;
struct Argus
{
	int period;
	int qnum;
	long long cperiod;
	bool operator<(const Argus &b)const
	{
		if(cperiod>b.cperiod)return true;
		else if(cperiod<b.cperiod) return false;
		else return qnum>b.qnum;
	}
};
int gcd ( int a, int b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}
int main() {
	priority_queue<Argus>pq;
	int qnum,period,inc=1;
	char reg[10];
	Argus e;
	scanf("%s",&reg[0],sizeof reg);
	while(reg[0]!='#')
	{
		
		scanf("%d%d",&qnum,&period);
		e.qnum=qnum;
		e.cperiod=period;
		e.period=period;
		pq.push(e);
		scanf("%s",&reg[0],sizeof reg);
		if(inc==-1)inc=period;
		else inc=gcd(inc,period);
	}
	int t=0,c=0;
	int k;

	scanf("%d",&k);
	while(c<k)
	{
		while(pq.top().cperiod==t && c<k)
		{
			e=pq.top();
			printf("%d\n",e.qnum);
			pq.pop();
			e.cperiod+=e.period;
			pq.push(e);
			c++;
		}
		
		t+=inc;
	}
	return 0;
}
