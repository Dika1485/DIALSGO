#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> tero[100000];
int sar[100000],hasil[100000];
bool jelajah[100000];
void teleport(int node,int link){
	for(int i=0;i<tero[node].size();i++){
		if(!jelajah[tero[node][i]]){
			jelajah[tero[node][i]]=1;
			hasil[link]+=sar[tero[node][i]];
			teleport(tero[node][i],link);
		}
	}
}
int main(){
	int a,b,ans=0,n,k,link=0;
	cin>>n>>k;
	memset(hasil,0,sizeof hasil);
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
		if(!jelajah[i]){
			jelajah[i]=1;
			hasil[link]+=sar[i];
			teleport(i,link);
			link++;
		}
	}
	sort(hasil,hasil+link);
	reverse(hasil,hasil+link);
	for(int i=0;i<link;i++){
		ans+=(i+1)*hasil[i];
	}
	cout<<ans<<endl;
	return 0;
}
