#include <cstring>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
bool jelajah[100000];
int sar[100000],n,k;
vector<int> tero[100000];

int teleport(int node,int tenaga,int hasil){
	int temp=-1,ans=-1;
	bool adatero=0;
	for(int i=0;i<tero[node].size();i++){
		if(!jelajah[tero[node][i]]){
			jelajah[tero[node][i]]=1;
			temp=teleport(tero[node][i],tenaga,hasil+(sar[tero[node][i]]*tenaga));
			jelajah[tero[node][i]]=0;
			adatero=1;
		}
		if(ans==-1) ans=temp;
		ans=min(temp,ans);
	}
	if(!adatero){
		for(int i=0;i<n;i++){
			if(!jelajah[i]){
				jelajah[i]=1;
				temp=teleport(i,tenaga+1,hasil+(sar[i]*(tenaga+1)));
				jelajah[i]=0;
			}
			if(ans==-1) ans=temp;
			ans=min(temp,ans);
		}
	}
	if(ans==-1) ans=hasil;
	return ans;
}

int main(){
	int a,b,ans=-1;
	cin>>n>>k;
	memset(jelajah,0,sizeof jelajah);
	for(int i=0;i<n;i++){
		cin>>sar[i];
	}
	for(int i=0;i<k;i++){
		cin>>a>>b;
		tero[a-1].push_back(b-1);
		tero[b-1].push_back(a-1);
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

