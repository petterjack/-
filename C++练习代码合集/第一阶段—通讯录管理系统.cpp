#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;
typedef struct {
	string Name;
	int Sex;
	string Phone;
}Person;

typedef struct {
	Person Array[1000];
	int size;
}Books;


void ViewMenu();
void addPeron(Books* abs);
int check(Books* s, string name);
void viewPreson(Books* abs);
void find(Books* abs);
void abc(Books* abs);

int main() {
	ViewMenu();
	Books abs;
	abs.size = 0;
	int n;
	cin >> n;
	while (1) {
		switch (n) {
		case 1:
			addPeron(&abs);
			break;
		case 2:
			viewPreson(&abs);
			break;
		case 3: {
			Delete(& abs);
			break;
		}
		case 4:
			find(&abs);
			break;
		case 5:
			abc(&abs);
			break;
		case 6:
			abs.size = 0;
			break;
		case 0:
			cout << "��ӭ���´�ʹ��" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}

//�˵�����
void ViewMenu() {
	cout << "\t****************************" << endl;
	cout << "\t*\t1.�����ϵ��\t   *" << endl;
	cout << "\t*\t2.��ʾ��ϵ��\t   *" << endl;
	cout << "\t*\t3.ɾ����ϵ��\t   *" << endl;
	cout << "\t*\t4.������ϵ��\t   *" << endl;
	cout << "\t*\t5.�޸���ϵ��\t   *" << endl;
	cout << "\t*\t6.�����ϵ��\t   *" << endl;
	cout << "\t*\t0.�˳�ͨѶ¼\t   *" << endl;
	cout << "\t****************************" << endl;
}

//�����ϵ��
void addPeron(Books* abs) {
	if (abs->size == 1000) {
		cout << "ͨѶ¼����" << endl;
	}
	else {
		cout << "����������:";
		cin >> abs->Array[abs->size].Name;

		cout << "�������Ա�:" << endl;
		cout << "1������" << endl;
		cout << "2����Ů" << endl;
		cin >> abs->Array[abs->size].Sex;

		cout << "��������ϰ�绰��";
		cin >> abs->Array[abs->size].Phone;

		abs->size++;
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");
	}
}

//��ʾ��ϵ��
void viewPreson(Books *abs) {
	if (abs->size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			cout << "����"<<abs->Array[i].Name<<"\t";
			cout << "�Ա�" <<( abs->Array[i].Sex == 1 ?"��": "Ů") << "\t";
			cout << "�绰"<< abs->Array[i].Phone << "\t";
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ����
int check(Books* s, string name) {
	for (int i = 0; i < s->size; i++) {
		if (s->Array[i].Name == name) {
			return i;
		}
	}
	return -1;
}

//ɾ��ָ����ϵ��
void Delete(Books* abs) {
	cout << "������ɾ����ϵ��������";
	string name;
	cin >> name;
	if (check(abs, name) == -1) {
		cout << "���޴���" << endl;
	}
	else {
		for (int i = check(abs, name); i < abs->size; i++) {
			abs->Array[i] = abs->Array[i + 1];
		}
		abs->size--;
		cout << "ɾ���ɹ�" << endl;
	}
}

//������ϵ��
void find(Books *abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	if (check(abs, name) == -1) {
		cout << "��Ǹ���޴���" << endl;
	}
	else {
		cout << "����" << abs->Array[check(abs, name)].Name << "\t";
		cout << "�Ա�" << abs->Array[check(abs, name)].Sex << "\t";
		cout << "�绰" << abs->Array[check(abs, name)].Phone << "\t";
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void abc(Books* abs) {
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�";
	string name;
	cin >> name;
	if (check(abs, name) == -1) {
		cout << "��Ǹ���޴���" << endl;
	}
	else {
		cout << "������������";
		cin>>abs->Array[check(abs, name)].Name;
		cout << "�������Ա�:";
		cin>>abs->Array[check(abs, name)].Sex;
		cout << "������绰";
		cin>>abs->Array[check(abs, name)].Phone;
	}
}