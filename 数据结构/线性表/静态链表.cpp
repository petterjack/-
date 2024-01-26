#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2
typedef int ElemType;
typedef int Status;
#define MAXSIZE 1000

typedef struct {
	ElemType data;
	int cur;		/*�α꣬Ϊ0ʦ��ʾ��ָ��*/
}Component,StaticLinkList[MAXSIZE];

Status visit(ElemType c)
{
	printf("%c ", c);
	return OK;
}

/*��̬�����ʼ��*/
Status InitList(StaticLinkList space) {
	int i;
	for (i = 0; i < MAXSIZE - 1; i++) {
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
	return OK;
}

/*��̬����Ķ�̬�ڴ����*/
int Malloc_SSL(StaticLinkList space) {
	int i = space[0].cur;
	if (space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}

/*��̬�����Ȳ���*/
int ListLength(StaticLinkList L)
{
	int i = L[MAXSIZE - 1].cur,j=0;
	while (L[i].cur) {
		i = L[i].cur;
		j++;
	}
	return i;
}




/*��̬����������*/
Status ListInsert(StaticLinkList L, int i, ElemType e) {
	int j, k,l;
	k = MAXSIZE - 1;
	if (i<1 || i>ListLength(L) + 1)
		return ERROR;
	j = Malloc_SSL(L);
	if (j) {
		L[j].data = e;
		for (l = 1; l <= i - 1; l++) {
			k = L[k].cur;		/*�ҵ���i��Ԫ��֮ǰ��λ��*/
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}

/*  ���±�Ϊk�Ŀ��н����յ��������� */
void Free_SSL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;    /* �ѵ�һ��Ԫ�ص�curֵ����Ҫɾ���ķ���cur */
	space[0].cur = k;               /* ��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur */
}

/*��̬����ɾ������*/
Status ListDelete(StaticLinkList L, int i)
{
	int j, k;
	if (i < 1 || i > ListLength(L))
		return ERROR;
	k = MAXSIZE - 1;
	for (j = 1; j <= i - 1; j++)
		k = L[k].cur;
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L, j);
	return OK;
}

Status ListTraverse(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		visit(L[i].data);
		i = L[i].cur;
		j++;
	}
	return j;
	printf("\n");
	return OK;
}