#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
using namespace std;

bool check1(int x) {	//检查位数，有偶数位的回文数（除了11）必然不是质数
	if ((1000 <= x && x <= 9999) || (100000 <= x && x <= 999999))
		return 0;
	return 1;
}

bool check(int x) {		//检查回文数
	int a [15],flag = 1;
	while (x>0) {
		a[flag] = x % 10;
		flag++;
		x /= 10;
	}
	for (int i = 1; i < flag/2; i++) {
		if (a[i] != a[flag - i])
			return 0;
	}
	return 1;
}

bool check3(int x)//检查是否为质数 
{
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0) return 0;
	return 1;
}

int main() {
	int a, b;
	cin >> a >> b;
	if (a % 2 == 0) a++;
	b = min(9999999, b);
	for (int i = a; i < b; i += 2) {
		if (check1(i) == 0)continue;
		if (check(i) == 0)continue;
		if (check3(i) == 0)continue;
		printf("%d\n", i);
	}
	return 0;
}
	