#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class cub {
	/*���Ҫ��
		1.�г��������
		��Ϊ����ȡ�������������ͱ����
		�ֱ�����ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����*/
private:
	int L;
	int H;
	int W;
public:
	/*���ó�*/
	void setL(int l) {
		L = l;
	}

	/*��ȡ��*/
	int getL() {
		return L;
	}
	/*���ø�*/
	void setH(int h) {
		H = h;
	}
	/*��ȡ��*/
	int getH() {
		return H;
	}

	/*���ÿ�*/
	void setW(int w) {
		W = w;
	}
	/*��ȡ��*/
	int getW() {
		return W;
	}

	/*��ȡ���*/
	int getV() {
		return L * H * W;
	}

	/*��ȡ���*/
	int getS() {
		return 2 * L * W + 2 * L * H + 2 * W * H;
	}


};

int main() {
	cub c1;
	c1.setH(10);
	c1.setL(10);
	c1.setW(10);

	cout << "c1�����Ϊ" << c1.getS() << endl;
	cout << "c1�����Ϊ" << c1.getV() << endl;

	return 0;
}