#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	int T,n;
	scanf("%d",&T);
	vector<long> coins;
	while(T--)
	{
		scanf("%d",&n);
		coins.clear();
		coins.resize(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&coins[i]);
		}
		long long sum = 1,num = coins.size()>1? 2:1;
        for (int i = 1; i < coins.size()-1;i++)
            if (sum + coins[i] < coins[i + 1])
            {
                sum += coins[i];
                ++num;
            }

	      printf("%d\n",num);
    }
	return 0;
}
