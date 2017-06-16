#include<bits/stdc++.h>
using namespace std;
int A[1000000],L[1000000],L_id[1000000],P[1000000];
void printList(int i)
{
	if(i<0)return;
	printList(P[i]);
	printf("%d\n",A[i]);
}
int main()
{	
	int t,N=0,lis = 0, lis_end = 0;

	while(scanf("%d",&t)!=EOF)
	{
		A[N]=t;
		N++;
	}
	for(int i=0;i<N;i++)
	{
		int pos = lower_bound(L, L + lis, A[i]) - L;
	    L[pos] = A[i];
	    L_id[pos] = i;
	    P[i] = pos ? L_id[pos - 1] : -1;
	    if (pos + 1 > lis) {
	      lis = pos + 1;
	      lis_end = i;
		}
	}
	printf("%d\n-\n",lis);
	printList(lis_end);
	return 0;
}
