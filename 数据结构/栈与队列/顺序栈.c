#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

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

/*栈的初始化*/
Status InitStack(SqStack* S) {
	S->top = -1;
	return OK;
}

/*清空栈*/
Status ClearStack(SqStack* S) {
	S->top = -1;
	return OK;
}

/*判断栈是否为空*/
Status StackEmpty(SqStack S) {
	if (S.top = -1)
		return TRUE;
	else
		return FALSE;
}

/*判断栈的长度*/
int StackLength(SqStack S) {
	return S.top + 1;
}

/*返回栈顶元素*/
Status GetTop(SqStack S, SElemType* e) {
	if (S.top == -1)
		return ERROR;
	else
		*e = S.data[S.top];
	return OK;
}

/*插入元素e到栈顶*/
Status Push(SqStack* S, SElemType e) {
	if (S->top == MAXSIZE - 1)/*满了*/
		return ERROR;
	S->top++;
	S -> data[S->top] = e;
	return OK;
}

/*删除操作*/
Status Pop(SqStack* S, SElemType* e) {
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}

/*显示栈中的每一个元素,从底部网上*/
Status StackTraverse(SqStack S) {
	int i = 0;
	while (i <= S.top) {
		visit(S.data[i++]);
	}
	printf("\n");
	return OK;
}
