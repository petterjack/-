#include <stdio.h>
//
//int main(){
//	int a,b,f;
//	char c;
//	scanf("%d %d %c %d",&a,&b,&c,&f);
//	if(f==0){//输出空心
//		for(int i=0;i<b;i++){
//			printf("%c",c);
//		}
//		printf("\n");
//		for(int i=1;i<=a-2;i++){
//			printf("%c",c);
//			for(int j=1;j<=b-2;j++){
//				printf(" ");
//			}
//			printf("%c\n",c);
//		}
//		for(int i=0;i<b;i++){
//			printf("%c",c);
//		}
//		printf("\n");
//	}
//	else{
//		for(int i=1;i<=a;i++){
//			for(int j=1;j<=b;j++){
//				printf("%c",c);
//			}
//			printf("\n");
//		}
//	}
//    return 0;	
//}

//int main(){
//	int n;
//	long long sum=0;
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++){
//		sum +=(long long)i;			
//		printf("%lld\n",sum);
//	}
//	return 0;
//}

//int main(){
//	int n,k,cnt=0;
//	scanf("%d %d",&n ,&k);
//	for(int i=1;i<=n;i++){
//		int t;
//		scanf("%d",&t);
//		if(k==t){
//			cnt++;
//		}
//		
//	}
//	printf("%d",cnt);
//	return 0;
//}

//int main(){
//	int n,k;
//	long long sum=0;
//	scanf("%d %d",&n,&k);
//	for(int i=1,x;i<=n;i++){
//		scanf("%d",&x);
//		if(i==k){
//			sum -=x;
//		}
//		else sum+=x;
//	}
//	printf("%lld\n",sum);
//	return 0;
//}

//int main(){
//	int i=8,*p;
//	p=&i;
//	printf("i=%d\n*p=%d",i,*p);
//	
//	return 0;
//}

//int main(){
//	int T,n,x,cnt=1;
//	
//	scanf("%d",&T);
//
//	while(T--){
//		scanf("%d",&n);
//		int a[n];
//		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
//		for(int j=1;j<=n;j++){
//			x=a[j];
//			if(x==0){
//				printf("yes");
//				cnt=0;
//				break;
//			}
//		}
//		if(cnt){
//			printf("no");
//		}
//	}
//	return 0;
//}

//int main(){
//	double e,sum=1,s=1.1;
//	int n=1;
//	scanf("%lf",&e);
//	while(2*sum<=e){
//		n++;
//		s=s*(n-1)/(2*n-1);
//		sum +=s;
//	}
//	printf("%.6lf",sum-s);
//	return 0;
//}

//int main(){
//	int n,a,sn=1,j=1,Sn;
//	scanf("%d %d",&n,&a);
//	sn=Sn=a;
//	for(int i=1;i<n;i++){
//		j*=10;
//		sn+=a*j;
//		printf("sn=%d\n",sn);
//		Sn+=sn;
//		printf("Sn=%d\n",Sn);
//	}
//	printf("%d",Sn);
//	return 0;
//}

/*输入一行字符，统计出其中数字字符的个数。*/
//int main(){
//	int i=0,j=0;
//	char a[255];
//	gets(a);
//	puts(a);
//	for(;i<255;i++){
//		if(a[i]<='9'&&a[i]>='0'){
//			j++;
//		}
//	}
//	printf("%d",j);
//	return 0;
//}

//


//int main() {    
//	int n;       
//	scanf("%d", &n);    
//	int a = 1, b = 1;    
//	for (int i = 3; i <= n; i++) {        
//		int temp = a + b;        
//		a = b;        
//		b = temp;    
//	}    
//	printf("%d月后家里会有%d对兔子。\n", n, b);
//	return 0;
//}


//int main(){
//	int a,b,c;
//	scanf("%d %d %d",&a,&b,&c);
//	int max=a;
//	
//	if(b>max){
//		max=b;
//	}
//	if(c>max){
//		max=c;
//	}
//	
//	printf("%d",max);
//	return 0;
//}


//int main(){
//	int n,a,sn,t=1,Sn;
//	scanf("%d %d",&n,&a);
//	Sn=sn=a;
//	for(int i=1;i<n;i++){
//		t*=10;
//		sn+=a*t;
//		Sn+=sn;
//	}
//	printf("%d",Sn);
//	return 0;
//}








//int main(){
//	int n ;
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=n-i;j++){
//			printf(" ");
//		}
//		for(int k=1;k<=2*i-1;k++){
//			printf("*");
//		}
//		printf("\n");
//	}
//}







