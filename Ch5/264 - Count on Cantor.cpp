#include<bits/stdc++.h>
using namespace std;
#define MAX 10000007
typedef pair<int,int> ii;

ii A[MAX];
void generate()
{
	int mx=1,f=1,s=1,dir=1;
	for(int i=1;i<=MAX;i++)
	{
		A[i]=ii(f,s);
		//cout<<f<<" "<<s<<" "<<dir<<endl;
		if(dir)
		{
			
			if(f==1)
			{
				dir=0;
				mx++;
			}
			else f--;
			s++;
		
		}
		else
		{
			if(s==1)
			{
				dir=1;
				mx++;
			}
			else s--;
			f++;
		}
	}
}
int main()
{
	int N;
	generate();
	while(scanf("%d",&N)!=EOF)
	{
		printf("TERM %d IS %d/%d\n",N,A[N].first,A[N].second);
	}

}
