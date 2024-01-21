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
/*���Ա�ĵ�����洢�ṹ*/
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;	//���嵥��������

/*��ȡ�����е�i��Ԫ��*/
Status GetElem(LinkList L, int i, ElemType* e) {

	int j=1;
	LinkList p;
	p = L->next;//ָ���һ��Ԫ��
	while(p&&j<i) {		//�޷���ǰ��֪��Ҫִ�ж��ٴ�ѭ��������while
		p = p->next;
		j++;
	}
	if (!p||j>i) {
		return ERROR;
	}
	*e = p->data;
	return OK;
}

//������i��λ��֮ǰ�����µ�Ԫ��e
Status ListInsert(LinkList* L, int i, ElemType e) {
	int j;
	LinkList p, s;
	p = *L;
	j = i;
	while (p && j < i) {		//�ҳ�i��λ��
		p = p->next;
		j++;
	}
	if (!p || j > i) {
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(Node));		//���ڴ��п���λ�ô洢s
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//ɾ�������е�i������Ԫ��
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

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨�� */
void CreateListHead(LinkList* L, int n)
{
	LinkList p;
	int i;
	srand(time(0));                         /* ��ʼ����������� */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  �Ƚ���һ����ͷ���ĵ����� */
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); /*  �����½�� */
		p->data = rand() % 100 + 1;             /*  �������100���ڵ����� */
		p->next = (*L)->next;
		(*L)->next = p;						/*  ���뵽��ͷ */
	}
}

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList* L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));                      /* ��ʼ����������� */
	*L = (LinkList)malloc(sizeof(Node)); /* LΪ�������Ա� */
	r = *L;                                /* rΪָ��β���Ľ�� */
	for (i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node)); /*  �����½�� */
		p->data = rand() % 100 + 1;           /*  �������100���ڵ����� */
		r->next = p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = NULL;                       /* ��ʾ��ǰ������� */
}


