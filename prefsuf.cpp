#include <iostream>
#include <algorithm>
using namespace std;
string rev(string s){
	reverse(s.begin(),s.end());
	return s;
}
int main(){
	string s;
	cin>>s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,d;
		char c;
		cin>>a>>b;
		if(a){
			cin>>c;
			s[b]=c;
		}
		else{
			int jaw=0;
			cin>>d;
			for(int j=d-b+1;j>=0;j--){
				string si=s.substr(b,j);
				string sj=s.substr(d-j+1,j);
				if(si==rev(sj)){
					jaw=j;
					break;
				}
			}
			cout<<jaw<<"\n";
		}
	}
}
