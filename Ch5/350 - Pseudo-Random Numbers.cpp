#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int I,M,Z;
int f(int N){
	return (Z*N + I)%M;
}
ii floydCycleFinding(int x0) 
{
	int tortoise = f(x0), hare = f(f(x0)); 
	while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
	int mu = 0; hare = x0;
	while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++;}
	int lambda = 1; hare = f(tortoise);
	while (tortoise != hare) { hare = f(hare); lambda++; }
	return ii(mu, lambda);
}
int main()
{
	int L,K=1;
	while(cin>>Z>>I>>M>>L && (Z||I||M||L))
	{
		printf("Case %d: %d\n",K++,floydCycleFinding(L).second);
	}
}
