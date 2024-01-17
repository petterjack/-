#include <iostream>
#include<iomanip>
using namespace std;

int main(){
	
	int n,k,Asum=0,Bsum=0,A=0,B=0;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){		//i分为A、B两类
		if(i%k==0){
			Asum+=i;
			A++;
		}
		else{
			Bsum+=i;
			B++;
		}
	}
	cout<<setprecision(1)<<fixed<<(float)Asum/A<<" "<<(float)Bsum/B<<endl;
	
	return 0;
}
