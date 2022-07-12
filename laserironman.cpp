// m = (y2-y1) / (x2-x1)
// c = y1 - (m * x1)
// y = mx + c
//   = mx + y1 - mx1
//   = m(x-x1) + y1
//   = (y2-y1) / (x2-x1) * (x-x1) + y1
// y = y
// (d-b) / (c-a) * (x-a) + b = (y2-y1) / (x2-x1) * (x-x1) + y1
// (d-b) * (x-a) + b * (c-a) = (y2-y1) / (x2-x1) * (x-x1) * (c-a) + y1 * (c-a)
// ((d-b) * (x-a) + b * (c-a)) * (x2-x1) = ((y2-y1) * (x-x1) + y1 * (x2-x1)) * (c-a)

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
	bool tembak[n];
	memset(tembak,1,sizeof tembak);
	for (int i = 0; i < l; i++){
		cin>>a>>b>>c>>d;
		for(int j=0;j<n;j++){
			if(tembak[j]){
				for(int k=x;k!=ultron[j][0];x<ultron[j][0]?k++:k--){
					if(((d-b) * (k-a) + b * (c-a)) * (ultron[j][0]-x) == ((ultron[j][1]-y) * (k-x) + y * (ultron[j][0]-x)) * (c-a)){
						tembak[j]=0;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(tembak[i]) hasil++;
	}
	cout<<hasil<<endl;
	return 0;
}
