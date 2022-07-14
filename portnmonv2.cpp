#include <cstring>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main(){
	int a,b,ans=0,n,k,link=0;
	vector<pair<int,int> >tero;
	cin>>n>>k;
	int sar[n],hasil[n],lis[20];
	memset(hasil,0,sizeof hasil);
	memset(lis,-1,sizeof lis);
	for(int i=0;i<n;i++){
		cin>>sar[i];
	}
	for(int i=0;i<k;i++){
		cin>>a>>b;
		if(a<b) tero.push_back(make_pair(a-1,b-1));
		else tero.push_back(make_pair(b-1,a-1));
	}
	sort(tero.begin(),tero.end());
	for(int i=0;i<k;i++){
		a=tero[i].first;
		b=tero[i].second;
		if(lis[a]==-1){
			if(lis[b]==-1){
				lis[b]=link;
				hasil[link]+=sar[b];
				link++;
			}
			lis[a]=lis[b];
			hasil[lis[a]]+=sar[a];
		}
		else if(lis[b]==-1){
			lis[b]=lis[a];
			hasil[lis[b]]+=sar[b];
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

