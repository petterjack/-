#include<cstdio>
using namespace std;
int sum1[25],sum2[25];//a��b��ϵ��
int main(){
	int a,n,m,x;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	sum1[2]=1,sum1[3]=2;//��ʼ��
	for(int i=4;i<n;i++){//�����������4��ʼ��ǰ��û�й��ɣ�
		sum1[i]=sum1[i-1]+sum1[i-2]-1;//����ϵ��������
		sum2[i]=sum2[i-1]+sum2[i-2]+1;
	}
	int b=(m-a*sum1[n-1])/sum2[n-1];//��ʽ
	printf("%d",a*sum1[x]+b*sum2[x]);
	return 0;//��������
}
