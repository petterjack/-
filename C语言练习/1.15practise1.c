#include <stdio.h>

/*���ν���ת��
��һ�� ������n(1<n<10), ��ʾ����ı߳� 
�������һ������
*/
int main(){
	
	int n;	//����ı߳�
	scanf("%d",&n);
	int a[10][10]={0};	//����֪��n���ᳬ��10������ֱ�ӳ�ʼ����ά������a[][10]={0}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[j][i]);
		}
		printf("\n");
	}	

	return 0;
	
}
