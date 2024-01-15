# include <iostream>
using namespace std;

/*输入一个数字构成的矩形, 将矩形的值进行转置后打印
第一行 正整数n(1<n<10), 表示矩阵的边长 
随后输入一个矩阵
*/
int main(){
	
	//输出
	int n;
	cin>>n;
	int a[10][10]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	cout<<"\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[j][i]<<ends;
		}
		cout<<"\n";
	}	
	
	
	system("pause");
	return 0;
}



