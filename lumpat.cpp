#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int main(){
	int p,l;
	cin>>p>>l;
	char a[p][l];
	bool b[p][l],lumpat=0,cari=0;
	queue<pair<int,int>>list;
	for(int i=0;i<p;i++){
		for(int j=0;j<l;j++){
			cin>>a[i][j];
			b[i][j]=0;
			if(a[i][j]=='C'){
				list.push(make_pair(i,j));
				b[i][j]=1;
			}
		}
	}
	cout<<p<<endl;
	while(!list.empty()){
		cout<<1<<endl;
		int x=list.front().first,y=list.front().second;
		if(lumpat&&cari) break;
		if((x==0)||(x+1==p)||(y==0)||(y+1==l)) lumpat=1;
		else{
			if((a[x][y+1]=='D')||(a[x][y-1]=='D')||(a[x-1][y]=='D')||(a[x+1][y]=='D')) cari=1;
			if((a[x][y+1]==' ')&&(!b[x][y+1])){
				list.push(make_pair(x,y+1));
				b[x][y+1]=1;
			}
			if((a[x][y-1]==' ')&&(!b[x][y-1])){
				list.push(make_pair(x,y-1));
				b[x][y-1]=1;
			}
			if((a[x+1][y]==' ')&&(!b[x+1][y])){
				list.push(make_pair(x+1,y));
				b[x+1][y]=1;
			}
			if((a[x-1][y]==' ')&&(!b[x-1][y])){
				list.push(make_pair(x-1,y));
				b[x-1][y]=1;
			}
		}
		list.pop();
	}
	if(cari) cout<<"Dawala bertemu Cepot\n";
	else cout<<"Dawala tidak bertemu Cepot\n";
	if(lumpat) cout<<"ada jalan Cepot lumpat\n";
	else cout<<"tidak ada jalan Cepot lumpat\n";
	return 0;
}
