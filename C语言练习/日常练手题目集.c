#include <stdio.h>

/*super家养了一对刚出生的兔子, 兔子出生第3月开始每月都会生一对小兔子, 小兔子出生后同样第3月开
始也会每月生一对兔子
super想知道 如果兔子不死 n月后家里会有多少对兔子
设计一个程序: 输入n, 输出兔子数量   0 1 2 3*/

//int main(){
//	int n;
//	scanf("%d",&n);
//	int a=1,b=1,t;
//	for(int i=3;i<=n;i++){
//		t=a+b;
//		a=b;
//		b=t;
//	}
//	printf("%d",t);
//	return 0;
//}

//int main(){
//	int a,b,c;
//	scanf("%d%d%d",&a,&b,&c);
//	int max=a;
//	if(max<b){
//		max=b;
//	}
//	if(max<c){
//		max=c;
//	}
//	printf("%d",max);
//	return 0;
//}

//struct point {
//	int x;
//	int y;
//};
//
//void getStruct(struct point);
//void output(struct point);
//
//int main() {
//	struct point y = {0, 0};
//	getStruct(y);
//	output(y);
//}
//
//void getStruct(struct point p) {
//	scanf("%d", &p.x);
//	scanf("%d", &p.y);
//	printf("%d,%d", p.x, p.y);
//}
//
//void output(struct point p) {
//	printf("%d,%d", p.x, p.y);
//}



//int main(){
//	int x=0,i=0,n;
//	scanf("%d",&n);
//	int a[n];
//	for(int j=0;j<n;j++){
//		scanf("%d",&a[j]);
//	}
//	for(i=0;i<n;i++){
//		if(a[i]==0){
//			break;
//		}
//	}
//	
//	if(i==n){
//		x++;
//	}
//	
//	for(int i=0;i<n;i++){
//		for(int j=i+1;j<n;j++){
//			if(a[i]==a[j]){
//				a[j]=0;
//			}
//			
//		}
//	}
//	
//	for(int i=0;i<n;i++){
//		if(a[i]==0&&x==0){
//			printf("%d ",a[i]);
//			x++;
//		}
//		if(a[i]!=0){
//		    printf("%d ",a[i]);
//		}
//	}
//	return 0;
//}

//int main(){
//	int n,a[100000],x;
//	scanf("%d",&n);
//	
//	for(int i=0;i<n;i++){
//		scanf("%d",&x);
//		if(a[x]==0){
//			printf("%d ",x);
//		}
//		a[x]++;
//	}
//	return 0;
//}

//int main(){
//	int a[10]={a[0]=1};
//	for(int i=0;i<10;i++){
//		for(int j=0;j<=i;j++){
//			if(j<10){
//				int t=a[j]+a[j+1];
//				a[j+1]=t;
//			}
//			if(a[i]!=0){
//				printf("%d ",a[i]);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main(){
//	int n,sum=0;
//	scanf("%d",&n);
//	if(n>20){
//		sum+=n-20+10*6+10*2;
//	}
//	else if(n>10){
//		sum+=(n-10)*2+10*6;
//	}
//	else if(n>0){
//		sum+=n*6;
//	}
//	printf("%d",sum);
//	return 0;
//}

//int main(){
//	int n;
//	scanf("%d",&n);
//	float walk,bike;
//	walk=n/1.2;
//	bike=n/3+50;
//	if(walk==bike){
//		printf("All");
//	}
//	else if(bike>walk){
//		printf("Walk");
//	}
//	else printf("Bike");
//	return 0;
//}

//int main(){
//	int L,m,u,v,a[10000]={0};
//	scanf("%d %d",&L,&m);
//	
//	for(int i=0;i<m;i++){
//		scanf("%d %d",&u,&v);
//		for(int j=u;j<=v;j++){
//			a[j]=1;
//		}
//	}
//	int sum=0;
//	for(int i=0;i<=L;i++){
//		if(a[i]==0){
//			sum++;
//		}
//	}
//	printf("%d",sum);
//	return 0;
//}


//int main(){
//    int n,i,j;
//    double sum=0,sn=1;
//    scanf("%d",&n);
//    for(i=1;i<=n;i++){
//        for(j=1;j<=i;j++){
//            sn*=j;
//        }
//        sum+=1/sn;
//        sn=1;
//    }
//    printf("%.10lf",sum+1);
//    return 0;
// }

//int main(){
//	float M,x=0,h;
//	int N,i;
//	scanf("%f %d",&M,&N);
//	for(i=0;i<N;i++){
//		x+=M;
//		M*=(float)1/2;
//		x+=M;
//	}
//	printf("%f %f",M,x);
//	return 0;
//}

//#define P 3.14
//int main(){
//	float h,r,x=0,L=20000;
//	scanf("%f %f",&h,&r);
//	
//	while(L>0){
//		L-=h*r*r*P;
//		x++;
//	}
//	printf("%f",x);
//	
//	return 0;
//}

//int main(){
//	int n;
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++){
//		for(int j=n;j>=i;j--){
//			printf(" ");
//		}
//		for(int j=0;j<2*i-1;j++){
//			printf("*");
//		}
//		printf("\n");
//	}
//	
//	for(int i=n-1;i>0;i--){
//		for(int j=n;j>=i;j--){
//			printf(" ");
//		}
//		for(int j=0;j<2*i-1;j++){
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main(){
//	for(int i=1;i<=9;i++){
//		for(int j=1;j<=i;j++){
//			printf("%d*%d=%d\t",j,i,j*i);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int ismax(int x,int y);
//int main(){
//	int x,y,n,max;
//	scanf("%d",&n);
//	int a[n];
//	for(int i=0;i<n;i++) a[i]=0;  //初始化
//	for(int i=2;i<=n;i++){      //将所有的小于n的数存到数组种
//		for(int j=2 ,k=0;j<=i;j++,k++){
//			if(i%j==0){
//				if(j==i){
//					a[k]=i;
//				}
//				else break;
//			}
//		}
//	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			if(a[i]!=0&&a[j]!=0){
//				if(a[j]*a[i]==n){
//					x=a[i];
//					y=a[j];
//				}
//			}
//		}
//	}
//	max=ismax(x,y);
//	printf("%d",max);
//}
//
//int ismax(int x,int y){
//	int max=x;
//	if(max<y){
//		max=y;
//	} 
//	return max;
//}

//int main(){
//	int n,i,b;
//	scanf("%d",&n);
//	for(i=2;i<n;i++){
//		if(n%i==0){
//			b=n/i;
//			break;
//		}
//	}
//	printf("%d",b);
//	return 0;
//}

//int main(){
//	int a[10000]={0},n,Ni;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++){
//		scanf("%d",&Ni);
//		if(a[Ni]==0){
//			printf("%d ",Ni);
//			a[Ni]=1;
//		}
//	}
//	return 0;
//}

//int main(){
//	int t,n;
//	scanf("%d",&n);
//	int a[n];
//	for(int i=0;i<n;i++){
//		scanf("%d",&a[i]);
//	}
//	for(int i=0,p=n-1;i<n/2;i++,p--){
//		t=a[i];                  
//		a[i]=a[p];
//		a[p]=t;
//	}
//	for(int i=0;i<n;i++){
//		printf("%2d",a[i]);
//	}
//	return 0;
//}

//int main(){
//	int n,sum=0,t;
//	scanf("%d",&n);
//	int a[1000];
//	scanf("%d",&a[0]);
//	for(int i=1;i<n;i++){
//		scanf("%d",&t);
//		if(a[i-1]==t){
//			n--;i--;continue;
//		}
//		a[i]=t;
//	}
//	for(int i=2;i<n;i++){
//		if(a[i-2]>a[i-1]&&a[i-1]<a[i]){
//			sum++;
//		}
//	}
//	printf("%d",sum);
//	return 0;
//}

//int main(){
//	int n;
//	scanf("%d",&n);
//	int a[n],b[n];
//	for(int i=0;i<n;i++){
//		scanf("%d",&a[i]);
//	}
//	int m;
//	scanf("%d",&m);
//	int j=m;
//	for(int i=0;i<n;i++){
//		if(m>0){
//			b[i]=a[n-m];
//			m--;
//		}
//		else {
//			b[i]=a[i-j];
//		}
//	}
//	for(int i=0;i<n;i++){
//		printf("%d ",b[i]);
//	}
//	return 0;
//}

//int main(){
//	int n,m;
//	scanf("%d %d",&n,&m);
//	int a[n][m],b[n][m];
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			scanf("%d",&a[i][j]);
//		}
//			
//	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			scanf("%d",&b[i][j]);
//		}
//				
//	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			printf("%d ",a[i][j]+b[i][j]);
//		}
//		printf("\n");		
//	}
//
//}



























