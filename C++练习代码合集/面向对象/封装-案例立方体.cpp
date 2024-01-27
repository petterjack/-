#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class cub {
	/*设计要求：
		1.有长宽高属性
		行为：获取立方体的体积，和表面积
		分别利用全局函数和成员函数判断两个立方体是否相等*/
private:
	int L;
	int H;
	int W;
public:
	/*设置长*/
	void setL(int l) {
		L = l;
	}

	/*获取长*/
	int getL() {
		return L;
	}
	/*设置高*/
	void setH(int h) {
		H = h;
	}
	/*获取高*/
	int getH() {
		return H;
	}

	/*设置宽*/
	void setW(int w) {
		W = w;
	}
	/*获取宽*/
	int getW() {
		return W;
	}

	/*获取体积*/
	int getV() {
		return L * H * W;
	}

	/*获取面积*/
	int getS() {
		return 2 * L * W + 2 * L * H + 2 * W * H;
	}


};

int main() {
	cub c1;
	c1.setH(10);
	c1.setL(10);
	c1.setW(10);

	cout << "c1的面积为" << c1.getS() << endl;
	cout << "c1的体积为" << c1.getV() << endl;

	return 0;
}