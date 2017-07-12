#include<bits/stdc++.h>
using namespace std;
#define MAX 5000000
vector<int> p2;
void construct()
{
	for(int i=1;i<MAX;i*=2)
	{
		p2.push_back(i);
	}
}
int main()
{
	int N;
	vector<int>::iterator it;
	construct();
	scanf("%d",&N);
	while(N)
	{
		it=lower_bound(p2.begin(),p2.end(),N);
		printf("%d\n",*it-((*it-N)*2));
		scanf("%d",&N);
	}

}
