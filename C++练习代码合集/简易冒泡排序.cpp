#include <iostream>
using namespace std;

int main(){
	
	int a[10]={2,5,3,7,8,9,9,4,5,2};
	for(int i=0;i<10-1;i++){
		for(int j=0;j<10-i-1;j++){
			if(a[j]>a[j+1]){
				int t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	
	for(int i=0;i<10;i++){
		cout<<a[i]<<endl;
	}
	system("pause");
	return 0;
}
