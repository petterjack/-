#include <iostream>
#include <cmath>
using namespace std;

int init[101][101];
int final[101][101];


int main(){
	int n,m;
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>init[i][j];
			final[i][j]=init[i][j];
		}
	}
	
	for(i=2;i<n;i++){
		for(j=2;j<m;j++){
			final[i][j]=round((init[i][j]+init[i-1][j]+init[i+1][j]+init[i][j-1]+init[i][j+1])/5.0);
				
		}
	}
	
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cout<<final[i][j]<<ends;
			}
			cout<<"\n";
		}
	
	return 0;
}
