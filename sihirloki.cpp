#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
using namespace std;
unsigned long long sto(string s){
	unsigned long long temp=0;
	while(s.length()>0){
		temp+=(int)s[0]-'0';
		s.erase(0,1);
		temp*=10;
	}
	temp/=10;
	return temp;
}
unsigned long long conv(string s){
	int ip=s.find('e');
	int iq=s.find('+');
	if(s.find('e')>=0){
		unsigned long long p=sto(s.substr(ip+1,iq-ip-1));
		s.erase(0,iq+1);
		unsigned long long q=sto(s);
		return pow(10,p)+q;
	}
	else{
		return sto(s);
	}
}
int main(){
	int n,q;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	cin>>q;
	for(int i=0;i<q;i++){
		int k,a,b;
		string si;
		unsigned long long l;
		cin>>k>>si;
		l=conv(si);
		l%=k;
		int list[n][k];
		int to[n];
		for(int ii=0;ii<n;ii++){
			list[ii][0]=ii;
			to[ii]=ii;
		}
		for(int j=0;j<k;j++){
			scanf("%d -> %d",&a,&b);
			to[a-1]=b-1;
		}
		for(int ii=1;ii<k;ii++){
			for(int j=0;j<n;j++){
				list[to[j]][ii]=list[j][ii-1];
			}
		}
		for(int ii=0;ii<n;ii++){
			cout<<s[list[ii][l]];
			if(ii+1!=n) cout<<" ";
			else cout<<"\n";
		}
	}
	return 0;
}
