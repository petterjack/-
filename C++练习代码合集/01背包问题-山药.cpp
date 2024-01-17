#include <iostream>
using namespace std;

int main(){
	//数据是有限制的
	
	int T,M;	//T为拥有的时间，相当于01背包问题里的背包容量；M为山洞中拥有的草药数量。
	cin>>T>>M;
//	int i=M,j=T;
	int bag[100][1000];//bag[i][j],对于前i个草药，在时间j条件下获得的最大价值
	int ti[100],pi[100];
	
	for(int i=1;i<=M;i++){	//存储每一株草药花费的时间和对应的价值
		cin>>ti[i]>>pi[i];
		for(int j=1;j<=T;j++){
			bag[i][j]=bag[i-1][j];
			if(j>ti[i]){
				bag[i][j]<bag[i-1][j-ti[i]]+pi[i]?bag[i][j]=bag[i-1][j-ti[i]]+pi[i]:1;
			}
		}
	}
	cout<<bag[M][T];
	
	return 0;
}
