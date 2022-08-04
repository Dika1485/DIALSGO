#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int untung=0,n;
    bool mark=0;
    cin>>n;
    int h[n];
    cin>>h[0];
    for(int i=1;i<n;i++){
        cin>>h[i];
        if(mark){
        	if(h[i]<h[i-1]){
        		mark=!mark;
        		untung+=h[i-1];
        	}
        	else if(i+1==n){
        		mark=!mark;
        		untung+=h[i];
        	}
        }
        else{
        	if(h[i]>h[i-1]){
        		untung-=h[i-1];
        		mark=!mark;
        		if(i+1==n){
        			mark=!mark;
        			untung+=h[i];
        		}
        	}
        }
    }
    cout<<untung<<endl;
    return 0;
}
