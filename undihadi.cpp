#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
	int n,x,mi=-1;
	cin>>n>>x;
	int num[n];
	for(int i=0;i<n;i++){
		cin>>num[i];
		if(mi==-1) mi=abs(x-num[i]);
		else if (mi>abs(x-num[i])) mi=abs(x-num[i]);
	}
	sort(num,num+n);
	for(int i=0;i<n;i++){
		if(abs(x-num[i])==mi){
			if(num[i]<10000){
				int temp=num[i];
				while(temp<10000){
					cout<<0;
					temp*=10;
				}
			}
			cout<<num[i]<<endl;
		}
	}
	return 0;
}
