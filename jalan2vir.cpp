#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n,m,mi,mj;
	cin>>n;
	for(int i=0;i<n;i++){
		int x=0,y=0;
		cin>>m;
		m*=2;
		mi=sqrt(m);
		if(mi*(mi+1)>m) mi--;
		mj=(m-mi*(mi+1))/2;
		if(mi%4==0){
			x=-2*(mi/4);
			y=x;
			x+=mj;
		}
		else if(mi%4==1){
			x=2*(mi/4)+1;
			y=-2*(mi/4);
			y+=mj;
		}
		else if(mi%4==2){
			x=2*(mi/4)+1;
			y=2*(mi/4)+2;
			x-=mj;
		}
		else{
			x=-2*(mi/4)-2;
			y=2*(mi/4)+2;
			y-=mj;
		}
		cout<<x<<" "<<y<<"\n";
	}
	return 0;
}
