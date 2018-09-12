#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<string>

#define MAX 9876543210LL
using namespace std;
bool unique(long long n){
	vector<char> c;
	c.assign(10, 0);
	string s = to_string(n);
	for (char cc : s)if (++c[cc - '0'] > 1)return false;

	return true;
}
int main(){
	int T;
	long long N, s1, s2;
	scanf("%d", &T);
	while (T--){
		scanf("%lld", &N);
		for (long long i = 1; N*i <= MAX; i++){
			long long num = N*i;
			if (unique(num) && unique(i)){
				printf("%lld / %lld = %lld\n", num, i, N);
			}
		}
		if (T)printf("\n");
	}
	return 0;
}