#include <cmath>
#include <utility>
#include <queue>
#include <iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, c, p;
	unsigned long long k;
	cin >> n >> k >> c >> p;
	int biaya_masuk[n];
	int biaya_keluar;
	priority_queue<pair<int,unsigned long long>> biaya_total[n];
	for (int i = 0; i < n; i++) {
		cin >> biaya_masuk[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> biaya_keluar;
		for(int j=0;j<n;j++){
			unsigned long long cost=biaya_masuk[j]+biaya_keluar+c*pow(abs(i-j),p);
			if(cost<=k) biaya_total[j].push(make_pair(abs(i-j)+1,k-cost));
		}
	}
	for(int i=0;i<n;i++){
		int jarak=0;
		unsigned long long sisa=k;
		if(!biaya_total[i].empty()){
			jarak=biaya_total[i].top().first;
			sisa=biaya_total[i].top().second;
			biaya_total[i].pop();
			if(!biaya_total[i].empty()){
				if(biaya_total[i].top().first==jarak) sisa=max(sisa,biaya_total[i].top().second);
				biaya_total[i].pop();
			}
		}
		cout<<jarak<<" "<<sisa<<"\n";
	}
	return 0;
}
