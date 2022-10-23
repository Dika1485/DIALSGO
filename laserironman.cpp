#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int x,y,n,hasil=0;
	cin>>x>>y;
	cin>>n;
	int ultron[n][2];
	for(int i=0;i<n;i++){
		cin>>ultron[i][0]>>ultron[i][1];
	}
	int l,a,b,c,d;
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
						if(((a>=x)&&(c<=x))||((a<=x)&&(c>=x))){
							double y1=1.00*(d-b) / (c-a) * (x-a) + b;
							if(((y1<=y)&&(y1>=ultron[j][1]))||((y1>=y)&&(y1<=ultron[j][1]))) tembak[j]=0;
						}
					}
					else if(c==a){
						if(((x>=a)&&(ultron[j][0]<=a))||((x<=a)&&(ultron[j][0]>=a))){
							double y1=1.00*(ultron[j][1]-y) / (ultron[j][0]-x) * (a-x) + y;
							if(((y1<=b)&&(y1>=d))||((y1>=b)&&(y1<=d))) tembak[j]=0;
						}
					}
					else{
						double m1=1.00*(d-b) / (c-a);
						double m2=1.00*(ultron[j][1]-y) / (ultron[j][0]-x);
						double c1=b - (m1 * a);
						double c2=y - (m2 * x);
						double x1=(c2-c1) / (m1-m2);
						if(((x1>=x)&&(x1<=ultron[j][0]))||((x1<=x)&&(x1>=ultron[j][0]))){
							if(((x1>=a)&&(x1<=c))||((x1<=a)&&(x1>=c))){
								tembak[j]=0;
							}
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
