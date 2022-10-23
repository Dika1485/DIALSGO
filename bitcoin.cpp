#include <iostream>
using namespace std;
int main(){
	int n,jaw=0;
	bool beli=1;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i>0){
			if(beli){
				if(a[i]>a[i-1]){
					jaw-=a[i-1];
					beli=!beli;
				}
			}
			if(!beli){
				if(a[i]<a[i-1]){
					jaw+=a[i-1];
					beli=!beli;
				}
				else if(i==n-1) jaw+=a[i];
			}
		}
	}
	cout<<jaw<<endl;
}
