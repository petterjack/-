#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//多项式的线性表实现
#define MAXSIZE 1000	//多项式可能达到的最大长度

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

Status visit(ElemType c)
{
	cout << c.e;
	return OK;
}

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

Status ListEmpty(SqList L) {
	if (L.length == 0)
		return TRUE;
	else
		return ERROR;
}

//补充——清空线性表
void ClearList(SqList& L) {
	L.length = 0;
}

//求线性表的长度
int GetLength(SqList& L) {
	return (L.length);
}


//【算法2.2】顺序表的取值
Status GetElem(SqList L, int i, ElemType& e) {
	if (i<0 || i>L.length)return ERROR;

	e = L.elem[i - 1];
	return OK;
}

//【算法2.4】顺序表插入数据
Status ListInsert(SqList& L ,int i, ElemType e) {
	int k;
	if (L.length == MAXSIZE ) {
		return ERROR;
	}
	if (i<1 || i>L.length+1) {
		return ERROR;
	}
	if (i <= L.length) {		//判断数据插入的位置是否在线性表的末端
		for (k = L.length; k > +i; k--) {		//腾出位置，供新的数据存放
			L.elem[k + 1] = L.elem[k];
		}
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

//【算法2.5】线性表的删除操作
Status ListDelete(SqList& L, int i, ElemType &e) {

	int k;
	if (L.length == 0) {
		return ERROR;
	}
	if (i<1 || i>L.length) {
		return ERROR;
	}
	e = L.elem[i-1];
}

int LocateElem(SqList L, ElemType e)
{
	int i;
	if (L.length == 0)
		return 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.elem[i].p == e.p)//由于该顺序表中elem存储了2个数据，所以要精确到某一数据。
			break;
	}
	if (i >= L.length)
		return 0;

	return i + 1;
}

Status ListTraverse(SqList L) {
	int i;
	for (i = 0; i < L.length; i++) {
		visit(L.elem[i]);
		cout << "\n";
	}
	return OK;
}

/*将所有的在线性表Lb中但不在La中的数据元素插入到La中*/
void unionL(SqList* La, SqList Lb)
{
	int La_len, Lb_len, i;
	ElemType e;                        /*声明与La和Lb相同的数据元素e*/
	La_len = GetLength(*La);            /*求线性表的长度 */
	Lb_len = GetLength(Lb);
	for (i = 1; i <= Lb_len; i++)
	{
		GetElem(Lb, i, e);              /*取Lb中第i个数据元素赋给e*/
		if (!LocateElem(*La, e))        /*La中不存在和e相同数据元素*/
			ListInsert(*La, ++La_len, e); /*插入*/
	}
}

