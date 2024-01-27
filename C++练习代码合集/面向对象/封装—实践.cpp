#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

/*实践内容：创建一个学生类，有姓名和学号、并且可以对其进行输出*/
class studen {

	//访问权限：公共
public:
	//属性
	string name;
	int number;

	//行为
	void view() {
		cout << "姓名：" << name << "学号：" << number << endl;
	}
};

int main() {
	studen first;
	first.name = "张三";
	first.number = 1112235;

	first.view();

	return 0;
}