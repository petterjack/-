# include <iostream>
using namespace std;

/*����һ�����ֹ��ɵľ���, �����ε�ֵ����ת�ú��ӡ
��һ�� ������n(1<n<10), ��ʾ����ı߳� 
�������һ������
*/
int main(){
	
	//���
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



