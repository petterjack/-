#include <iostream>
using namespace std;

int main(){
	//�����������Ƶ�
	
	int T,M;	//TΪӵ�е�ʱ�䣬�൱��01����������ı���������MΪɽ����ӵ�еĲ�ҩ������
	cin>>T>>M;
//	int i=M,j=T;
	int bag[100][1000];//bag[i][j],����ǰi����ҩ����ʱ��j�����»�õ�����ֵ
	int ti[100],pi[100];
	
	for(int i=1;i<=M;i++){	//�洢ÿһ���ҩ���ѵ�ʱ��Ͷ�Ӧ�ļ�ֵ
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
