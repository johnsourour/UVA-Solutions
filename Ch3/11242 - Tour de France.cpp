#include <bits/stdc++.h>
using namespace std;

int main() {
	int f,r,t;
	double mx;
	vector<int> sp;
	vector<double> ratios;
	scanf("%d",&f);
	while(f)
	{
		sp.clear();
		ratios.clear();
		scanf("%d",&r);
		for(int i=0;i<f;i++)
		{
			scanf("%d",&t);
			sp.push_back(t);
		}
		for(int i=0;i<r;i++)
		{
			scanf("%d",&t);
			for(int j=0;j<f;j++)
			{
				ratios.push_back((double)t/(double)sp[j]);
			}
		}
		sort(ratios.begin(),ratios.end());
		mx=-1e9;
		for(int i=0;i<ratios.size()-1;i++)
		{
			mx=max(mx,(ratios[i+1]/ratios[i]));
		}
		printf("%.2f\n",mx);
		scanf("%d",&f);
	}
	return 0;
}
