#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
/*班里转来一位新同学，班主任老师安排这位同学坐在小张这一组，输出安排好新同学座位后小张所在小组每位同学的学号。
输入格式:四行，第一行为一个整数n(O<n< 60)代表小张同学这一组的同学人数第二行为n个整数代表小张同学所在小组每位学生的学号，第三行为一个整数k代表新来同学的学号，第四行两个整数第一个整数p，第二个整数位m, 若p为1,则新同学坐在第m个同学的前面，若p为0, 则新同学坐在第m个同学的后面。
输出格式:一行，新同学安排好后,，小张所在小组每位同学的学号。输入用例：
5
7 1 3 14 5
56
0 2
输出用例：
7 1 56 3 14 5*/

int main() {
	int arr[61];
	int n;
	int m;
	int k;
	int p;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> k>>p>>m;
	int count = 0;
	if (p == 1) {
		for (int i = 1; i <= n; i++) {
			if (i == m&&count==0) {
				cout << k << " ";
				count++;
				i;
			}
			cout << arr[i] << " ";

		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (i == m+1  && count == 0) {
				cout << k << " ";
				count++;
				i;
			}
			cout << arr[i] << " ";

		}
	}
	return 0;
}