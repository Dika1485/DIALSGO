// m = (y2-y1) / (x2-x1)
// y = mx + c
//   = mx + y1 - mx1
//   = (y2-y1) / (x2-x1) * (x-x1) + y1
// c = y1 - (m * x1)

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int x,y,n,hasil=0;//posisi iron man
	cin>>x>>y;//5 8
	x+=5000;
	y+=5000;
	cin>>n;//jml ultron
	int ultron[n][2];
	for(int i=0;i<n;i++){
		cin>>ultron[i][0]>>ultron[i][1];
		ultron[i][0]+=5000;
		ultron[i][1]+=5000;
	}
	int l,a,b,c,d; // jml sisi bangunan
	cin>>l;
	int sisi[1001][1001];
	memset(sisi,0,sizeof sisi);
	for (int i = 0; i < l; i++){
		cin>>a>>b>>c>>d;//3 5 3 3
		sisi[c][d]=1;
		for(int j=a;j!=c;a<c?j++:j--){
			if(c==a){
				for(int k=b;k!=d;b<d?k++:k--){
					sisi[j][k]=1;
				}
			}
			else sisi[j][(d-b) / (c-a) * (j-a) + b]=1;
		}
	}
	for(int i=0;i<n;i++){
		bool termasuk=1;
		for(int j=x;j!=ultron[i][0];x<ultron[i][0]?j++:j--){
			if(ultron[i][0]==x){
				for(int k=y;k!=ultron[i][1];y<ultron[i][1]?k++:k--){
					if(sisi[j][k]){
						termasuk=0;
						break;
					}
				}
			}
			else if(sisi[j][(ultron[i][1]-y) / (ultron[i][0]-x) * (j-x) + y]) termasuk=0;
			if(!termasuk) break;
		}
		if(termasuk) hasil++;
	}
	cout<<hasil<<endl;
	return 0;
}
