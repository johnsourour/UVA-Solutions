#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define MAX 44725
vector<int> T;
void construct()
{
	int cur=1,diff=0;
	T.resize(MAX+1);

	for(int i=1;i<=MAX;i++)
	{
		T[i]=cur;
		diff+=2;
		cur+=diff;
		
	}
}
int main()
{
	int N;
	scanf("%d",&N);
	construct();
	vector<int>::iterator it;
	while(N)
	{
		it=lower_bound(T.begin(),T.end(),N);
		int ind=it-T.begin();
		if(abs(T[ind]-N)<=abs(T[ind-1]-N))
		{
			if(ind%2==1)printf("%d %d\n",ind,ind-abs(T[ind]-N));
			else printf("%d %d\n",ind-abs(T[ind]-N),ind);
		}
		else
		{
			ind--;
			if(ind%2==0)printf("%d %d\n",ind,ind-abs(T[ind]-N));
			else printf("%d %d\n",ind-abs(T[ind]-N),ind);
		}
		scanf("%d",&N);
	}

}
