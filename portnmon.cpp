#include <cstring>
#include <math.h>
#include <iostream>
using namespace std;
bool jelajah[20];
int sar[20],n,k;
bool tero[20][20];

int teleport(int node,int tenaga,int hasil){
	int temp=-1,ans=-1;
	for(int i=0;i<n;i++){
		if(!jelajah[i]){
			if(tero[node][i]){
				jelajah[i]=1;
				temp=teleport(i,tenaga,hasil+(sar[i]*tenaga));
				jelajah[i]=0;
			}
			else{
				jelajah[i]=1;
				temp=teleport(i,tenaga+1,hasil+(sar[i]*(tenaga+1)));
				jelajah[i]=0;
			}
		}
		if(ans==-1) ans=temp;
		ans=min(temp,ans);
	}
	if(ans==-1) ans=hasil;
	return ans;
}

int main(){
	int a,b,ans=-1;
	cin>>n>>k;
	memset(jelajah,0,sizeof jelajah);
	memset(tero,0,sizeof tero);
	for(int i=0;i<n;i++){
		cin>>sar[i];
	}
	for(int i=0;i<k;i++){
		cin>>a>>b;
		tero[a-1][b-1]=1;
		tero[b-1][a-1]=1;
	}
	for(int i=0;i<n;i++){
		jelajah[i]=1;
		if(ans==-1) ans=teleport(i,1,sar[i]);
		else ans=min(ans,teleport(i,1,sar[i]));
		jelajah[i]=0;
	}
	cout<<ans<<endl;
	return 0;
}
