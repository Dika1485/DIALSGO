// m = (y2-y1) / (x2-x1)
// m = m
// (d-b) / (c-a) = (y2-y1) / (x2-x1)
// (d-b) * (x2-x1) = (y2-y1) * (c-a)
// m1 * m2 = -1
// (d-b) / (c-a) * (y2-y1) / (x2-x1) = -1
// (d-b) * (y2-y1) = - ((c-a)*(x2-x1))
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
	cin>>n;//jml ultron
	int ultron[n][2];
	for(int i=0;i<n;i++){
		cin>>ultron[i][0]>>ultron[i][1];
	}
	int l,a,b,c,d; // jml sisi bangunan
	cin>>l;
	bool tembak[n];
	memset(tembak,1,sizeof tembak);
	for (int i = 0; i < l; i++){
		cin>>a>>b>>c>>d;
		for(int j=0;j<n;j++){
			if(tembak[j]){
				if((d-b) * (ultron[j][0]-x) == (ultron[j][1]-y) * (c-a)){
					if(x==a){
						if(((b>y)&&(b<ultron[j][1]))||((b<y)&&(b>ultron[j][1]))) tembak[j]=0;
					}
					else if(y==b){
						if(((a>x)&&(a<ultron[j][0]))||((a<x)&&(a>ultron[j][0]))) tembak[j]=0;
					}
				}
				else{
					if(ultron[j][0]==x){
						if(((a>=x)&&(c<=x))||(a<=x)&&(c>=x)){
							double y1=(d-b) / (c-a) * (x-a) + b;
							if(((y1<=y)&&(y1>=ultron[j][1]))||((y1>=y)&&(y1<=ultron[j][1]))) tembak[j]=0;
						}
					}
					else if(c==a){
						if(((x>=a)&&(ultron[j][0]<=a))||(x<=a)&&(ultron[j][0]>=a)){
							double y1=(ultron[j][1]-y) / (ultron[j][0]-x) * (a-x) + y;
							if(((y1<=b)&&(y1>=d))||((y1>=b)&&(y1<=d))) tembak[j]=0;
						}
					}
					else{
						double temp1=0,temp2=0;
						for(int k=x;k!=ultron[j][0];x<ultron[j][0]?k++:k--){
							double y1=(ultron[j][1]-y) / (ultron[j][0]-x) * (k-x) + y;
							double y2=(d-b) / (c-a) * (k-a) + b;
							if(((a>=k)&&(c<=k))||(a<=k)&&(c>=k)){
								if(y1==y2){
									tembak[j]=0;
									break;
								}
								else{
									if(((temp1<temp2)&&(y1>y2))||((temp1>temp2)&&(y1<y2))){
										tembak[j]=0;
										break;
									}
								}
							}
							temp1=y1;
							temp2=y2;
						}
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(tembak[i]){
			hasil++;
		}
	}
	cout<<hasil<<endl;
	return 0;
}
