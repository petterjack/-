#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;
typedef int SElemType;

typedef struct {
	SElemType data[MAXSIZE];
	int top;
}SqStack;

Status visit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

/*ջ�ĳ�ʼ��*/
Status InitStack(SqStack* S) {
	S->top = -1;
	return OK;
}

/*���ջ*/
Status ClearStack(SqStack* S) {
	S->top = -1;
	return OK;
}

/*�ж�ջ�Ƿ�Ϊ��*/
Status StackEmpty(SqStack S) {
	if (S.top = -1)
		return TRUE;
	else
		return FALSE;
}

/*�ж�ջ�ĳ���*/
int StackLength(SqStack S) {
	return S.top + 1;
}

/*����ջ��Ԫ��*/
Status GetTop(SqStack S, SElemType* e) {
	if (S.top == -1)
		return ERROR;
	else
		*e = S.data[S.top];
	return OK;
}

/*����Ԫ��e��ջ��*/
Status Push(SqStack* S, SElemType e) {
	if (S->top == MAXSIZE - 1)/*����*/
		return ERROR;
	S->top++;
	S -> data[S->top] = e;
	return OK;
}

/*ɾ������*/
Status Pop(SqStack* S, SElemType* e) {
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}

/*��ʾջ�е�ÿһ��Ԫ��,�ӵײ�����*/
Status StackTraverse(SqStack S) {
	int i = 0;
	while (i <= S.top) {
		visit(S.data[i++]);
	}
	printf("\n");
	return OK;
}
