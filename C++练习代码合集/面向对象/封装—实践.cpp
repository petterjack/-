#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

/*ʵ�����ݣ�����һ��ѧ���࣬��������ѧ�š����ҿ��Զ���������*/
class studen {

	//����Ȩ�ޣ�����
public:
	//����
	string name;
	int number;

	//��Ϊ
	void view() {
		cout << "������" << name << "ѧ�ţ�" << number << endl;
	}
};

int main() {
	studen first;
	first.name = "����";
	first.number = 1112235;

	first.view();

	return 0;
}