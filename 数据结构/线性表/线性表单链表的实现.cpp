#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
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

Status visit(ElemType c) {
	 cout<< c;
	 return OK;
}

/*初始化单链表*/
Status InitList(LinkList* L) {
	*L = new Node[1];
	if (!(*L))
			return ERROR;
	(*L)->next == NULL;

	return OK;
}

/*在链表L已经存在的情况下，检测L是否为空*/
Status ListEmpty(LinkList L) {
	if (L->next)
		return FALSE;
	else
		return TRUE;
}


/*重置为空表*/
Status ClearList(LinkList* L) {
	LinkList p, q;
	p = (*L)->next;
	while (p) {
		q = p->next;	/*  p指向第一个结点 */
		delete[]p;		/*  没到表尾 */
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

/*链式线性表长度*/
int ListLength(LinkList L) {
	int i = 0;
	LinkList p = L->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

int LocateElem(LinkList L, ElemType e) {
	int i = 0;
	LinkList p = L->next;
	while (p) {
		i++;
		if (p->data == e)
			return i;
		p = p->next;
	}
	return 0;
}

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

Status ListTraverse(LinkList L) {
	LinkList p = L->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	cout << "\n";
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

int main()
{        
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("第%d个元素的值为%d\n",k,j);
            else
                    printf("没有值为%d的元素\n",j);
    }
    

    k=ListLength(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* 删除第j个数据 */
            if(i==ERROR)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverse(L); 

    i=ClearList(&L);
    printf("\n清空L后：ListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("整体创建L的元素(头插法)：");
    ListTraverse(L); 
    
    i=ClearList(&L);
    printf("\n删除L后：ListLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("整体创建L的元素(尾插法)：");
    ListTraverse(L); 


    return 0;
}
