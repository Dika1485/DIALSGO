#include <iostream>
#include <math.h>
using namespace std;
int getpangkat(int x){
	int temp=0;
	while(x>1){
		x/=2;
		temp++;
	}
	return temp;
}
int main(){
	int n,temp,p,q,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p>>q>>m;
		if(p>q){
			temp=getpangkat(p/q);
			p/=pow(2,temp);
			m-=temp;
			p/=pow(2,m/2);
			q/=pow(2,m/2);
			if(m%2!=0) p/=2;
		}
		else{
			temp=getpangkat(q/p);
			q/=pow(2,temp);
			m-=temp;
			p/=pow(2,m/2);
			q/=pow(2,m/2);
			if(m%2!=0) q/=2;
		}
		cout<<(p>q?p:q)<<" "<<(p>q?q:p)<<"\n";
	}
	return 0;
}
