#include <iostream>
using namespace std;
int ans[1001];
int main(){
	
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i/2;j++){
			ans[i]+=ans[j];
		}
		ans[i]++;
	}
	cout<<ans[n];
	return 0;
}
