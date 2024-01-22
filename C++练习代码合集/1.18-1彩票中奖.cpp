#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//题目来源网址https://www.luogu.com.cn/problem/P2550

int main() {
	int n,ans[7],myans,cnt=0;
	int win[7] = {};
	cin >> n;
	for (int i = 0; i < 7; i++)
		cin >> ans[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> myans;
			for (int k = 0; k < 7; k++) {
				if (myans == ans[k]) {
					cnt++;
					break;
				}
			}
		}
		win[cnt-1]++;
		cnt = 0;
	}

	for (int i = 6; i >= 0 ; i--) {
		cout << win[i]<<" "  ;
	}

	return 0;
}

