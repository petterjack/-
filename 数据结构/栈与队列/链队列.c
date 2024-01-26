#define _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;

typedef int QElemType;

typedef struct QNode	/* ���ṹ */
{
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct			/* ���е�����ṹ */
{
	QueuePtr front, rear; /* ��ͷ����βָ�� */
}LinkQueue;

Status visit(QElemType c)
{
	printf("%d ", c);
	return OK;
}

/* ����һ���ն���Q */
Status InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}

/* ��Q��Ϊ�ն��� */
Status ClearQueue(LinkQueue* Q)
{
	QueuePtr p, q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}

/* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
Status QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* ����еĳ��� */
int QueueLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr p;
	p = Q.front;
	while (Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/* �����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR */
Status GetHead(LinkQueue Q, QElemType* e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}

/* ����Ԫ��eΪQ���µĶ�βԪ�� */
Status EnQueue(LinkQueue* Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s) /* �洢����ʧ�� */
		exit(OVERFLOW);
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;	/* ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ�� */
	Q->rear = s;		/* �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s */
	return OK;
}

/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
Status QueueTraverse(LinkQueue Q)
{
	QueuePtr p;
	p = Q.front->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}