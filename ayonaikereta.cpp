#include <cmath>
#include <iostream>
using namespace std;
int main(){
	int n, c, p;
	unsigned long long k;
	cin >> n >> k >> c >> p;
	int biaya_masuk[n];
	int biaya_keluar[n];
	for (int i = 0; i < n; i++) {
		cin >> biaya_masuk[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> biaya_keluar[i];
	}
	for(int i=0;i<n;i++){
		int space;
		int jarak=0;
		unsigned long long sisa=k;
		unsigned long long biaya_total;
		for(int j=max(n-i-1,i);j>=0;j--){
			if(j+i<n){
				space=abs(i-(j+i))+1;
				biaya_total=biaya_masuk[i]+biaya_keluar[j+i]+c*pow(abs(i-(j+i)),p);
				if(biaya_total<=k){
					jarak=space;
					sisa=k-biaya_total;
				}
			}
			if(j<=i){
				space=abs(i-(i-j))+1;
				biaya_total=biaya_masuk[i]+biaya_keluar[i-j]+c*pow(abs(i-(i-j)),p);
				if(biaya_total<=k){
					if(space==jarak) sisa=max(sisa,k-biaya_total);
					else{
						jarak=space;
						sisa=k-biaya_total;
					}
				}
			}
			if(jarak>0) break;
		}
		cout<<jarak<<" "<<sisa<<endl;
	}
	return 0;
}
