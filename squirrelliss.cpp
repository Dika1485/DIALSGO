#include <iostream>
#include <algorithm>
using namespace std;
int a[100000],n,dp[100000];
int f(int index,int tes){
	if(index==n) return 0;
	else{
		int temp=0;
		if(dp[index]==-1){
			if(__gcd(a[index],tes)>1) temp=f(index+1,a[index])+1;
			dp[index]=max(temp,f(index+1,tes));
		}
		return dp[index];
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		dp[i]=-1;
	}
	cout<<f(0,0)<<"\n";
	return 0;
}
