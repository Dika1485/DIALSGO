#include <iostream>
using namespace std;
int main(){
	int n,m,q,x1,x2,y1,y2;
	cin>>n>>m>>q;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<q;i++){
		int temp=0;
		cin>>x1>>y1>>x2>>y2;
		for(int j=x1-1;j<x2;j++){
			for(int k=y1-1;k<y2;k++){
				temp+=a[j][k];
			}
		}
		cout<<temp<<"\n";
	}
}
