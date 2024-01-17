#include <stdio.h>
#include <stdio.h>
//int main()
//{
//	int number;
//	int sum=0;
//	int count=0;
////	scanf("%d",&number);
////	while(number != -1){
////		sum+=number;
////		count++;
////		scanf("%d",&number);
////	}
////	printf("平均数为%f",1.0*sum/count);
////方法二
//    do{
//		scanf("%d",&number);
//		if(number!=-1){
//			sum+=number;
//			count++;
//		}
//	}while(number!=-1);
//    printf("平均数为%f",1.0*sum/count);
//	return 0;
//}

//for阶乘
//int main(){
//	int n;
//	int x=1;
//	scanf("%d",&n);
//	int i;
//	for(i=1;i<=n;i++){
//		x *= i;
//		printf("i=%d\n",i);
//	}
//	printf("i=%d\n",i);
//	
//	printf("%d!=%d",n,x);
//	
////一个等价的while循环
//    int i=1;
//    while(i<=n){
//		x *=i;
//		i++;
//		printf("i=%d\n",i);
//	}
//	printf("%d!=%d i=%d",n,x,i);
//	
//	return 0;
//}

//素数
//int main()
//{
//	int x;
//	scanf("%d",&x);
//	int i;
////	int y=1;
//	for(i=2;1<x;i++){      //除1和他本身没有其他数可以整除这个数，为素数。
//		if (x%i==0){
////			y=0;
//			break;
//		}
//	}
//	//当离开这个循环时，若[2,x)没能整除x则i=x。
//	if(i<x){                //如果i=x意味着x只有在i=x的情况下被整除，已经满足了素数的定义
//		printf("不是素数");
//	}
//	else{
//		printf("是素数");
//	}
//	return 0;
//}

//整数分解

//int main()
//{
//	int x;
//	int mask=1;
//	scanf("%d",&x);
//	//判断输入了几位数
//	int t=x;
//	while(t>9){
//		t /=10;
//		mask *= 10;
//	}
//	//整数分解
//	do{
//		int d=x / mask;   //正序分解
//		printf("%d",d);
//		if(mask>9){
//			printf(" ");
//		}
//		x %= mask;       //去除最高位的数
//		mask /= 10;      
//	}while(mask>0);      //若mask=0意味着已经分解完
//	
//	return 0;
//}

//整数求逆
//int main(){
//	int x;
//	scanf("%d",&x);
//    int ret=0;
//    int d;
//    while(x>0){
//		d = x%10;
//		ret = ret*10+d;
//		x/=10;
//	}
//	printf("%d",ret);
//	
//	return 0;
//}

//辗转相除法求最大公约数
//原理
/*如果b等于0，计算结束，a就是最大公约数；
否则，计算a除以b的余数，让a等于b，而b等于那个余数；
回到第一步。

a  b  t
12 18 12
18 12 6
12 6  0
6  0 */

//int main(){
//	int a,b;
//	scanf("%d %d",&a,&b);
//	int t;
//	while(b!=0){
//		t =a % b;
//		a=b;
//		b=t;
//	}
//	printf("%d",a);
//}


//int main(){
//	int a;
//	scanf("%d",&a);
//	int i,j,k;
//	i=a;
//	int cont=0;
//	while(i<=a+3){
//		j=a;
//		while(j<=a+3){
//			k=a;
//			while(k<=a+3){
//				if(i!=j){
//					if(j!=k){
//						if(i!=k){
//							printf("%d%d%d",i,j,k);
//							cont++;
//							if(cont%6==0){
//								printf("\n");
//								cont=0;
//							}
//							else{
//								printf(" ");
//							}
//							
//						}
//					}
//				}
//				k++;
//			}
//			j++;
//		}
//		i++;
//	}
//	return 0;
//}

//等价的for循环
//int main(){
//	int a;
//	scanf("%d",&a);
//	int i,j,k;
//	int cont = 0;
//	for(i=a;i<=a+3;i++){
//		for(j=a;j<=a+3;j++){
//			for(k=a;k<=a+3;k++){
//				if(i!=j){
//					if(j!=k){
//						if(i!=k){
//							printf("%d%d%d",i,j,k);
//							cont++;
//							if(cont%6==0){
//								printf("\n");
//							}
//							else{
//								printf(" ");
//							}
//						}
//					}
//				}
//				
//			}
//		}
//	}
//	
//	return 0;
//}

//水仙花数
//int main(){
//	int n;
//	scanf("%d",&n);
//	int first=1;
//	int i=1;
//	while(i<=n){
//		first *= 10;
//		i++;
//	}
//	//遍历所有的n位数
//	i=first/10;
//	while(i<first){
//		int t=i;       //因为水仙花数的定义，在拆解i的时候会破坏i，所以需要定义t来存储i
//		int sum=0;
//		do{
//			int d=t%10;
//			t/=10;
//			int p=d;
//			int j=1;
//			while(j<n){
//				p *=d;
//				j++;
//			}
//			sum +=p;
//		}while(t>0);
//		if(sum==i){
//			printf("%d\n",sum);
//		}
//		i++;
//	}
//	return 0;
//}

//九九乘法表
//whlie版本
//int main(){
//	int i=1;
//	int t;
//	scanf("%d",&t);
//	while(i<=t){
//		int j=1;
//		while(j<=i){
//			printf("%d*%d=%d",j,i,j*i);
//			if(i*j<10){
//				printf("    ");
//			}
//			else{
//				printf("   ");
//			}
//			
//			if(i==j){
//				printf("\n");
//			}
//			j++;
//		}
//		i++;
//	}
//	
//	return 0;
//}

//for版
//int main(){
//	int i;
//	int t=9;
//	for(i=1;i<=t;i++){
//		int j=1;
//		for(j=1;j<=i;j++){
//			printf("%d*%d=%d",j,i,j*i);
//			if(i*j<10){
//				printf("    ");
//			}
//			else{
//				printf("   ");
//			}
//						
//			if(i==j){
//			    printf("\n");
//			}
//		}
//	}
//	return 0;
//}

//水仙花数再复习
//int main(){
//	int n;
//	scanf("%d",&n);
//	int i=1;
//	int first =1;
//	while(i<=n){
//		first *=10;
//		i++;
//	}
//	for(i=first/10;i<first;i++){
//		int t = i;
//		int sum=0;
//		do{
//			int d = t%10;
//			int p = d;
//			int j=1;
//			while(j<n){
//				p *=d;
//				j++;
//			}
//			sum += p ;
//			t /=10;
//		}while(t>0);
//		if(sum==i){
//			printf("%d\n",sum);
//		}
//	}
//	return 0;
//}

//统计素数并求和
//int main(){
//	int m,n;
//	scanf("%d %d",&m,&n);
//	int cnt=0;
//	int sum=0;
//	for(;m<=n;m++){
//		int i;
//		for(i=2;i<=m;i++){
//			if(m%i==0){
//				if(i<m){
//					break;
//				}
//				else{
//					cnt++;
//					sum +=m;
//				}
//			}
//		}
//	}
//	printf("%d %d",cnt,sum);
//	return 0;
//}

//猜数游戏（for的自娱自乐版）
//int main(){
//	int number,n;
//	int inp;
//	int cnt = 1;
//	scanf("%d %d",&number,&n);
//	for(;cnt<=n;cnt++){
//		scanf("%d",&inp);
//		if(inp<number){
//			printf("Too sumall\n");
//		}
//		else if(inp>number){
//			printf("Too big\n");
//		}
//		else{
//			if(cnt==1){
//				printf("Bingno!\n");
//				return 0;
//			}
//			else if(cnt<=3){
//				printf("Lucky you!\n");
//				return 0;
//			}
//			else{
//				printf("Good Guess!\n");
//				return 0;
//			}
//		}
//	}
//	printf("Game over!");
//	return 0;
//}

//求特定数量前n项和
//int main(){
//	int n;
//	scanf("%d",&n);
//	int i=1;
//	double j=2,k=1,sum=0.0,t;
//	for(;i<=n;i++){
//		sum += j/k;
//		t=j;
//		j=j+k;
//		k=t;	
//	}
//	printf("%.2f",sum);
//	return 0;
//}

//数组逆序输出
//int main(){
//	int n;
//	scanf("%d",&n);
//	int number[n];
//	int i=0;
//	for(;i<n;i++){
//		scanf("%d",&number[i]);
//	}
//	i-=1;
//	for(;i>=0;i--){
//		printf("%d ",number[i]);
//	}
//	return 0;
//}

//统计患者占比
//int main(){
//	int n;
//	scanf("%d",&n);
//	int age[n];
//	for(int i=0;i<n;i++){
//		scanf("%d",&age[i]);
//	}
//	
//	int number[4];
//	for(int j=0;j<4;j++){
//		number[j]=0;
//	}
//	for(int k = 0;k<n;k++){
//		int x =age[k];
//		if(x<=18&&x>0){
//			number[0]++;
//		}
//		else if(x>=19&&x<=35){
//			number[1]++;
//		}
//		else if(x>=36&&x<=60){
//			number[2]++;
//		}
//		else if (x>=61){
//			number[3]++;
//		}
//	}
//	for(int m=0;m<4;m++){
//		float y = number[m];
//		printf("%.2f%%\n",y/n*100);
//	}
//	return 0;
//}

//向量点积计算
//int main(){
//	int n;
//	scanf("%d",&n);
//	int a[n];
//	int b[n];
//	int sum=0;
//	for(int i1=0;i1<n;i1++){
//		scanf("%d",&a[i1]);
//	}
//	for(int i2=0;i2<n;i2++){
//		scanf("%d",&b[i2]);
//	}
//	for(int j=0;j<n;j++){
//		int x=a[j];
//		int y=b[j];
//		sum += x*y;
//		
//	}
//	printf("%d",sum);
//	return 0;
//}

//白细胞计数
//#include <stdio.h>
//#include <math.h>
//int main(){
//	int n, x=0, y=0;
//	scanf("%d",&n);
//	double samples[n],max=-1,min=99999999,sum=0;
//	for(int i =0;i<n;i++){
//		scanf("%lf",&samples[i]);
//
//		
//		if(samples[i]>max){
//			max=samples[i];
//			x=i;
//		}
//		
//		if(samples[i]<min){
//			min=samples[i];
//			y=i;
//		}
//		sum +=samples[i];
//	}
//	sum -= min+max;
//	double p=sum/(n-2);
//	max=-1;
//	printf("%.2lf ",p);
//	for(int i=0;i<n;i++)
//	{
//		if(i!=x&&i!=y)//排除最大值和最小值
//		{
//		  	if(fabs(samples[i]-p)>max)
//		     	max=fabs(samples[i]-p);//调用绝对值函数，求与最大值之差的绝对值的最大值
//		}
//	}
//		printf("%.2lf",max);
//    
//	return 0;
//}

//数组去重
//int main(){
//	int n;
//	scanf("%d",&n);
//	int number[100000];
//    int t[100000]={0};
//    for(int i=0;i<n;i++){
//		scanf("%d",&number[i]);
//	}
//    for(int i=0;i<n;i++){
//		if(t[number[i]]==0){
//			printf("%d ",number[i]);
//			t[number[i]]++;
//		}
//	}
//	return 0;
//}

//教材题目
//int main(){
//	int i,j;
//	for(i=7;i>=1;i--){
//		for(j=1;j<=7-i;j++){
//			printf(" ");
//		}
//		for(j=1;j<=i;j++){
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main() {
//    int i, j, n;
//    printf("请输入锥形的行数：");
//    scanf("%d", &n);
//    for (i = 1; i <= n; i++) {   // 外层循环控制行数
//        for (j = 1; j <= n - i; j++) {   // 输出空格
//            printf(" ");
//        }
//        for (j = 1; j <= 2 * i -1; j++) {   // 输出*号
//            printf("*");
//        }
//        printf("\n");   // 换行
//    }
//    
//    for (i = n - 1; i >= 1; i--) {   // 内层循环控制行数
//        for (j = 1; j <= n - i; j++) {   // 输出空格
//            printf(" ");
//        }
//        for (j = 1; j <= 2 * i - 1; j++) {   // 输出*号
//            printf("*");
//        }
//        printf("\n");   // 换行
//    }
//    return 0;
//}

//int main(){
//	int i,j;
//	for(i=1;i<=4;i++){
//		for(j=1;j<=4-i;j++){
//			printf(" ");
//		}
//		for(j=1;j<=2*i-1;j++){
//			printf("*");
//		}
//		printf("\n");
//	}
//	
//	for(i=3;i>0;i--){
//		for(j=1;j<=4-i;j++){
//			printf(" ");
//		}
//		for(j=1;j<=2*i-1;j++){
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//指针
//int main(){
//	int i;
//	i=8;
//	int *p=&i;
//	printf("i=%d\np=%d",i,*p);
//	return 0;
//}

int main()
{
	int a,b,f;
	char c;
	scanf("%d %d %c %d",&a,&b,&c,&f);
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(i != 0 && i != a - 1 && j != 0 && j != b - 1){
				
				printf("%c",f==0?' ':c);
			}
			else
			{
				printf("%c",c);
			}
			}
					printf("\n");
		}
	return 0;
}














