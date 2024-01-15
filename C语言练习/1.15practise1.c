#include <stdio.h>

/*矩形进行转置
第一行 正整数n(1<n<10), 表示矩阵的边长 
随后输入一个矩阵
*/
int main(){
	
	int n;	//矩阵的边长
	scanf("%d",&n);
	int a[10][10]={0};	//由题知，n不会超过10，所以直接初始化二维数数组a[][10]={0}
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
