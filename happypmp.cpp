#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n],index[n+1],temp;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>temp;
		index[temp]=i;
	}
	for(int i=0;i<n;i++){
		a[i]=index[a[i]];
	}
	temp=0;
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			temp=n-i-1;
			break;
		}
	}
	cout<<temp<<"\n";
	return 0;
}
