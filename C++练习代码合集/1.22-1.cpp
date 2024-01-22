#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int m,t,s;
	cin>>m>>t>>s;				
	/*分3种情况讨论，吃完一个苹果只用0min，过去的时间大于完
	全吃完苹果所需要的时间，花费时间小于完全吃完苹果所需要的时间*/
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
