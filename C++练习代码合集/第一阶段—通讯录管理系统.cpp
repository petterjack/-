#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
void ViewMenu();


int main() {
	ViewMenu();
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
