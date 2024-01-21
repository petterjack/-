#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2
typedef int ElemType;
typedef int Status;
/*线性表的单链表存储结构*/
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;	//定义单链表类型

/*提取链表中第i个元素*/
Status GetElem(LinkList L, int i, ElemType* e) {

	int j=1;
	LinkList p;
	p = L->next;//指向第一个元素
	while(p&&j<i) {		//无法提前获知需要执行多少次循环，就用while
		p = p->next;
		j++;
	}
	if (!p||j>i) {
		return ERROR;
	}
	*e = p->data;
	return OK;
}

//在链表i个位置之前插入新的元素e
Status ListInsert(LinkList* L, int i, ElemType e) {
	int j;
	LinkList p, s;
	p = *L;
	j = i;
	while (p && j < i) {		//找出i的位置
		p = p->next;
		j++;
	}
	if (!p || j > i) {
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(Node));		//在内存中开辟位置存储s
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//删除链表中第i个数据元素
Status ListDelete(LinkList* L,int i,ElemType* e) {
	int j = 1;
	LinkList p, q;
	p = *L;
	while (p->next && j < i) {
		p = p->next;
		j++;
	}

	if (!(p->next) || j > i) {
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(LinkList* L, int n)
{
	LinkList p;
	int i;
	srand(time(0));                         /* 初始化随机数种子 */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  先建立一个带头结点的单链表 */
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = rand() % 100 + 1;             /*  随机生成100以内的数字 */
		p->next = (*L)->next;
		(*L)->next = p;						/*  插入到表头 */
	}
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList* L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));                      /* 初始化随机数种子 */
	*L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
	r = *L;                                /* r为指向尾部的结点 */
	for (i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = rand() % 100 + 1;           /*  随机生成100以内的数字 */
		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = NULL;                       /* 表示当前链表结束 */
}


