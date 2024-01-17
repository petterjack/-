#include <stdio.h>

/*李四翻笔记时打翻了墨水, 但他忘记了这段之前写的什么内容了. 小伙伴们快帮帮他吧. 
用正确的代码替换[墨水] 

功能: 交换两个指针指向的整数值 
参数: 
[墨水] a: [墨水] 
[墨水] b: [墨水] 
返回值: 
void 
*/ 
void swap(int *a,int *b){ 
 	int c=*a;
 	*a=*b;
 	*b=c;
} 
//测试样例: 
int main(){ 
int a = 3, b = 4; 
swap(&a, &b); 
printf("%d,%d\n",a,b); //此处应打印4,3 
}
