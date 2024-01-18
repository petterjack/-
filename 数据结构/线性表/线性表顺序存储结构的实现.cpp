#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//����ʽ�����Ա�ʵ��
#define MAXSIZE 1000;	//����ʽ���ܴﵽ����󳤶�

typedef struct {
	float p;	//����ʽ��ϵ��
	int e;		//����ʽ��ָ��
}Polynomial;

typedef struct {
	Polynomial* elem;	//�洢�ռ�Ļ���ַ
	int length;			//����ʽ����ǰ��ĸ���
}SqList;

//�������״̬����
#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef Polynomial ElemType;

//���㷨2.1����ʼ�����Ա�1.18��
Status lnitList_Sq(SqList& L) {
	L.elem = new ElemType[1000];
	if (!L.elem)exit(OVERFLOW);
	L.length = 0;
	return OK;
}

//���䡪���������Ա�
void DestoryList(SqList& L) {
	if (L.elem) delete L.elem;	//�ͷſռ�
}

//���䡪��������Ա�
void ClearList(SqList& L) {
	L.length = 0;
}

//�����Ա�ĳ���
int GetLength(SqList& L) {
	return (L.length);
}

int IsEmpty(SqList& L) {
	if (L.length == 0)return 0;
	else return 0;
}

//���㷨2.2��˳����ȡֵ
int GetElem(SqList L, int i, ElemType& e) {
	if (i<0 || i>L.length)return ERROR;

	e = L.elem[i - 1];
	return OK;
}