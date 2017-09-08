#include<bits/stdc++.h>
using namespace std;
int main()
{
   double cars, cows, shown;
   while(cin>>cows>>cars>>shown)
   {
   	double cow_first=(cows/(cows+cars))*(cars/(cars+cows-shown-1));
   	double car_first=(cars/(cows+cars))*((cars-1)/(cars+cows-shown-1));
   	printf("%.5lf\n",cow_first+car_first);
   }
   return 0;
}
