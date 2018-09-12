#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iostream>

using namespace std;

int main(){
	int  V, V0, mxDiscs;
	double mxDiameter, D, cur;
	while (scanf("%d%d", &V, &V0) && V &&V0){
		mxDiameter = mxDiscs = 0;
		for (int i = 1;i <= V; i++){
			cur = (double)V / i;
			if (cur <= V0)break;
			D = 0.3*sqrt(cur - V0);
			
			cur = D*i;
			if (abs(mxDiameter - cur) < 0.00000001){
				mxDiscs = 0;
				break;
			}
			else if (mxDiameter < cur){
				mxDiameter = cur;
				mxDiscs = i;
			}
			
		}
		printf("%d\n", mxDiscs);
	}
	return 0;
}