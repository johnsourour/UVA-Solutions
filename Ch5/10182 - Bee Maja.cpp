#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define MAX 100000
ii A[MAX];
int dr[]={ -1, 0, 1, 1, 0, -1};
int dc[]={ 0, -1, -1, 0, 1, 1};
int cnt[]={ 1, 1, 1, 1, 2, 1};
void generate()
{
	A[0]=ii(0,0);
	A[1]=ii(0,1);
	int ind=0,cc=0,px=0,py=1;
	for(int i=2;i<MAX;i++)
	{
		//cout<<px<<" "<<py<<" "<<ind<<endl;
		px+=dr[ind];
		py+=dc[ind];
		A[i]=ii(px,py);
		cc++;
		if(cc==cnt[ind])
		{
			cnt[ind]++;
			cc=0;
			ind=(ind+1)%6;
		}
	}
}
int main()
{
	generate();
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		printf("%d %d\n",A[N-1].first,A[N-1].second);
	}
}
