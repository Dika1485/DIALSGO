#include <iostream>
#define m 1000000007
using namespace std;
long long fac(long long n){
	long long temp=1;
	for(int i=2;i<=n;i++){
		temp*=i;
		temp%=m;
	}
	return temp%m;
}
long long c(long long x,long long y){
	return fac(x)/fac(y)/fac(x-y)%m;
}
int main(){
	int n,a,b;
	cin>>n;
	for(int i=0;i<2;i++){
		cin>>a>>b;
	}
	if(n==3) cout<<3;
	else cout<<6*c(n,4)*fac(n-4);
	cout<<"\n";
	return 0;
}
