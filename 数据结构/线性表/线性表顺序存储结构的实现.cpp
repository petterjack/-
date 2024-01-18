#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//多项式的线性表实现
#define MAXSIZE 1000;	//多项式可能达到的最大长度

typedef struct {
	float p;	//多项式的系数
	int e;		//多项式的指数
}Polynomial;

typedef struct {
	Polynomial* elem;	//存储空间的基地址
	int length;			//多项式当中前项的个数
}SqList;

//函数结果状态代码
#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef Polynomial ElemType;

//【算法2.1】初始化线性表（1.18）
Status lnitList_Sq(SqList& L) {
	L.elem = new ElemType[1000];
	if (!L.elem)exit(OVERFLOW);
	L.length = 0;
	return OK;
}

//补充——销毁线性表
void DestoryList(SqList& L) {
	if (L.elem) delete L.elem;	//释放空间
}

//补充——清空线性表
void ClearList(SqList& L) {
	L.length = 0;
}

//求线性表的长度
int GetLength(SqList& L) {
	return (L.length);
}

int IsEmpty(SqList& L) {
	if (L.length == 0)return 0;
	else return 0;
}

//【算法2.2】顺序表的取值
int GetElem(SqList L, int i, ElemType& e) {
	if (i<0 || i>L.length)return ERROR;

	e = L.elem[i - 1];
	return OK;
}