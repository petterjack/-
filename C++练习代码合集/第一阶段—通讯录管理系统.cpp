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
			cout << "欢迎您下次使用" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}

//菜单界面
void ViewMenu() {
	cout << "\t****************************" << endl;
	cout << "\t*\t1.添加联系人\t   *" << endl;
	cout << "\t*\t2.显示联系人\t   *" << endl;
	cout << "\t*\t3.删除联系人\t   *" << endl;
	cout << "\t*\t4.查找联系人\t   *" << endl;
	cout << "\t*\t5.修改联系人\t   *" << endl;
	cout << "\t*\t6.清空联系人\t   *" << endl;
	cout << "\t*\t0.退出通讯录\t   *" << endl;
	cout << "\t****************************" << endl;
}

//添加联系人
void addPeron(Books* abs) {
	if (abs->size == 1000) {
		cout << "通讯录已满" << endl;
	}
	else {
		cout << "请输入姓名:";
		cin >> abs->Array[abs->size].Name;

		cout << "请输入性别:" << endl;
		cout << "1——男" << endl;
		cout << "2——女" << endl;
		cin >> abs->Array[abs->size].Sex;

		cout << "请输入练习电话：";
		cin >> abs->Array[abs->size].Phone;

		abs->size++;
		cout << "添加成功" << endl;

		system("pause");
		system("cls");
	}
}

//显示联系人
void viewPreson(Books *abs) {
	if (abs->size == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->size; i++) {
			cout << "姓名"<<abs->Array[i].Name<<"\t";
			cout << "性别" <<( abs->Array[i].Sex == 1 ?"男": "女") << "\t";
			cout << "电话"<< abs->Array[i].Phone << "\t";
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在
int check(Books* s, string name) {
	for (int i = 0; i < s->size; i++) {
		if (s->Array[i].Name == name) {
			return i;
		}
	}
	return -1;
}

//删除指定联系人
void Delete(Books* abs) {
	cout << "请输入删除联系人姓名：";
	string name;
	cin >> name;
	if (check(abs, name) == -1) {
		cout << "查无此人" << endl;
	}
	else {
		for (int i = check(abs, name); i < abs->size; i++) {
			abs->Array[i] = abs->Array[i + 1];
		}
		abs->size--;
		cout << "删除成功" << endl;
	}
}

//查找联系人
void find(Books *abs) {
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	if (check(abs, name) == -1) {
		cout << "抱歉查无此人" << endl;
	}
	else {
		cout << "姓名" << abs->Array[check(abs, name)].Name << "\t";
		cout << "性别" << abs->Array[check(abs, name)].Sex << "\t";
		cout << "电话" << abs->Array[check(abs, name)].Phone << "\t";
	}
	system("pause");
	system("cls");
}

//修改联系人
void abc(Books* abs) {
	cout << "请输入您要修改的联系人：";
	string name;
	cin >> name;
	if (check(abs, name) == -1) {
		cout << "抱歉查无此人" << endl;
	}
	else {
		cout << "请输入姓名：";
		cin>>abs->Array[check(abs, name)].Name;
		cout << "请输入性别:";
		cin>>abs->Array[check(abs, name)].Sex;
		cout << "请输入电话";
		cin>>abs->Array[check(abs, name)].Phone;
	}
}