#include<cstdio>
using namespace std;
int sum1[25],sum2[25];//a和b的系数
int main(){
	int a,n,m,x;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	sum1[2]=1,sum1[3]=2;//初始化
	for(int i=4;i<n;i++){//遍历（必须从4开始，前面没有规律）
		sum1[i]=sum1[i-1]+sum1[i-2]-1;//计算系数，见上
		sum2[i]=sum2[i-1]+sum2[i-2]+1;
	}
	int b=(m-a*sum1[n-1])/sum2[n-1];//公式
	printf("%d",a*sum1[x]+b*sum2[x]);
	return 0;//华丽结束
}
