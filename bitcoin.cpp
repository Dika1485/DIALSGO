#include <iostream>
#include <math.h>
using namespace std;
int main(){
	long long h,n,untung=0,g=0;
	cin>>n;
	cin>>h;
	g=h;
	for(long long i=1;i<n;i++){
		cin>>h;
		untung=max(untung,h-g);
		g=min(g,h);
	}
	cout<<untung<<endl;
	return 0;
}
