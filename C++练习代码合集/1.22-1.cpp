#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int m,t,s;
	cin>>m>>t>>s;				
	/*��3��������ۣ�����һ��ƻ��ֻ��0min����ȥ��ʱ�������
	ȫ����ƻ������Ҫ��ʱ�䣬����ʱ��С����ȫ����ƻ������Ҫ��ʱ��*/
	if(t==0){
		cout<<0;
	}
	else if(m*t<=s){
		cout<<0<<endl;
	}
	else{
		cout<<s%t==0?m-s/t:m-s/t-1;
	}
	return 0;
}
