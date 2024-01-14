#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<conio.h>//���ܼ��̵�����
#include<stdbool.h>//ʹ�÷���ֵbool���͵ĺ���
#include<easyx.h>
#include<windows.h>//��������������Ϊ��ʵ�ֲ������ֹ��ܶ������ͷ�ļ�
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
//ȫ�ֱ��� 
ExMessage msg = { 0 };
int level = 0;//��ʾ�ؿ�
bool isArea(int mx, int my, int x, int y, int w, int h) {
	if (mx > x && mx<x + w && my>y && my < y + h) {
		return 1;
	}
	return 0;
}//�ж�������Ƿ�������Ƶİ�����Χ��
bool button(int x, int y, int w, int h, const char* text) {
	//����һ����ť�������ж��Ƿ񱻷���
	if (isArea(msg.x, msg.y, x, y, w, h))
		setfillcolor(RGB(66, 66, 66));
	else
		setfillcolor(RGB(46, 46, 46));
	//���ư�ť

	fillrectangle(x, y, x + w, y + h);
	//�����ı�
	int hspace = (w - textwidth(text)) / 2;
	int vspace = (h - textheight(text)) / 2;
	settextcolor(WHITE);
	settextstyle(20, 0, "����");
	outtextxy(x + hspace, y + vspace, text);
	//�ж��Ƿ񱻵��
	if (msg.message == WM_LBUTTONDOWN && isArea(msg.x, msg.y, x, y, w, h)) {
		return 1;
	}
	return 0;
}//���ư�ť���жϱ������
//�����ɫ
bool buttontwo(int x, int y, int w, int h, const char* text) {
	//����һ����ť�������ж��Ƿ񱻷���
	if (isArea(msg.x, msg.y, x, y, w, h))
		setfillcolor(BLUE);
	else
		setfillcolor(BROWN);
	//���ư�ť

	fillrectangle(x, y, x + w, y + h);
	//�����ı�
	int hspace = (w - textwidth(text)) / 2;
	int vspace = (h - textheight(text)) / 2;
	settextcolor(YELLOW);
	settextstyle(20, 0, "�����п�");
	outtextxy(x + hspace, y + vspace, text);
	//�ж��Ƿ񱻵��
	if (msg.message == WM_LBUTTONDOWN && isArea(msg.x, msg.y, x, y, w, h)) {
		return 1;
	}
	return 0;
}//���ư�ť���жϱ������
//�п���ɫ
int i, k;//��������������ѭ����ѭ��������
enum elements{ space, wall, dest, box, player};//ö�٣�ʹ�����ִ������ַ�������ʾ
int map[3][10][10] = {
{
{7,7,7,7,7,7,7,7,7,7},
{7,7,7,1,1,1,7,7,7,7},
{7,7,7,1,2,1,1,1,1,7},
{7,1,1,1,3,3,0,2,1,7},
{7,1,2,3,4,0,1,1,1,7},
{7,1,1,1,1,3,1,7,7,7},
{7,7,7,7,1,2,1,7,7,7},
{7,7,7,7,1,1,1,7,7,7},
{7,7,7,7,7,7,7,7,7,7},
{7,7,7,7,7,7,7,7,7,7},
},

{
{8,8,8,8,8,8,8,8,8,8},
{8,8,8,8,8,8,8,8,8,8},
{8,8,8,1,1,1,1,1,1,8},
{8,1,1,1,0,0,0,0,1,8},
{1,1,2,0,3,1,0,0,1,1},
{1,2,2,3,0,3,0,0,4,1},
{1,2,2,0,3,0,3,0,1,1},
{1,1,1,1,1,1,0,0,1,8},
{8,8,8,8,8,8,1,1,1,8},
{8,8,8,8,8,8,8,8,8,8},
},
{
{0,0,1,1,0,0,1,1,0,0},
{0,1,0,0,1,1,0,0,1,0},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,3,0,0,3,3,0,1},
{1,2,2,3,4,0,0,2,2,1},
{1,2,0,3,1,0,0,3,2,1},
{0,1,0,0,1,0,0,0,1,0},
{0,0,1,0,0,0,0,1,0,0},
{0,0,0,1,0,0,1,0,0,0},
{0,0,0,0,1,1,0,0,0,0},
}
};//��һ�ص�ͼ
//�յ�0,space ǽ1,wall Ŀ�ĵ�2,dest ����3,box ���4,player ������Ŀ�ĵ�5,box+dest �����Ŀ�ĵ�6player+dest(ͼƬ����ҵ�ͼƬһ��)
IMAGE img_all[12];//������Ҫ�õ���ͼƬ���ܹ�11����space, wall, dest, box, player��box+dest��player+dest,7��ԭ��ͼ��8�ҽ���ͼ��11�����ԭ
//----------------------------------service---------------------------------------------

//--------------------------������������----------------------------------------------------
/*
�����ˣ�С�ֱ���
���ܣ���ӡ�˵����������ʼ��Ϸ����Ϸ˵�������ã��˳���Ϸ�ĸ���ť
�����ʼ��Ϸ���Խ���gameview()�������Ϸ˵�����Խ�����Ϸ˵��gamerule()
����˳���Ϸ�����˳����򣬵�����ý���gameset()
������void
����ֵ��void
*/void menuview();



/*
�����ˣ��׷�
���ܣ�չʾ��Ϸ�����Լ�������Ա�����з�����ҳ��ť��������Է�����ҳmenuview()
������void
����ֵ��void
*/ void gamerule();



/*
������:�����
���ܣ���ӡ���ý��棬�������ֿ��غͷ�����ҳ��ť��������ֻᲥ�����֣����������ҳ��ť�᷵����ҳmenuview()
������void
����ֵ��void
*/ void gameset();


/*
������:�׷�
���ܣ�������Ϸ��ͼ�����õ��ĵ�ͼƬ��loadimage���ص�ͼ����ͼƬ
������void
����ֵ��void
*/ void pictureload();



/*
������:�׷�
���ܣ���ӡ��Ϸ���棬�����а���������ҳ������ɽ�����Ϸ�˵�menuview()
������void
����ֵ��void
*/ void mapdraw();



/*
������:�׷�
���ܣ��ж���Ϸ�Ƿ�Ӯ�ˣ�Ӯ�˾ͽ�����Ϸʤ������gamewinprint()
������void
����ֵ��true or false
*/ bool wingame();



/*
������:����
����:_getch()������Ұ��µļ�����Ұ����ĸ����������Ӧλ���ƶ�
����:void
����ֵ:void
*/ void gamemove();



/*
������:����
����:��ӡ��Ϸʤ�����棬���з�����ҳ��ť������Է��ز˵�menuview()
����:void
����ֵ:void
*/ void gamewinprint();



/*
������:��Ҷ
����:���ܱ���Ϸ�����ı�������,��������л���һ��ͼƬ�����һ��ͼƬ���������ҳ���Իص��˵���
����:void
����ֵ:void
*/ void gamestory();



 
/*
������:�׷�
����:
while(1)
	{pictureload()��//����ͼƬ
		mapdraw();
		if (wingame())//�ж��Ƿ�ʤ��������ֵΪtrue,��Ӯ�˴�ӡʤ������
		{
		if(level>2)
		�ؿ�����2��ʱ��Ҳ���Ǵ��ص����һ�ص�ʱ����ӡʤ������
		������ʤ������
		gamewinprint();
		}
		gamemove();��������ƶ�

}
����:void
����ֵ:void
*/
void gameview();





//-------------------------------------------------------������-----------------------------------------------------------


int main()
{
	initgraph(10 * 75, 10 * 75);//����easyx����
	pictureload();
	BeginBatchDraw();
	menuview();
	EndBatchDraw();
	gameview();
	return 0;
}


//-------------------------------------------------------�������岿��-----------------------------------------------------
void menuview() {
	IMAGE img_start;
	loadimage(&img_start, "./images/�����ӿ�ʼ����1.jpg",750,750);
	putimage(0, 0, &img_start);
	setbkmode(TRANSPARENT);
	while (1) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		if (button(295, 350, 150, 30, "��ʼ��Ϸ")) {
			mciSendString("open ./images/musci_6.mp3 alias f", NULL, 0, NULL);
			mciSendString("play f from 0", NULL, 0, NULL);//ԭ��������Ч
			break;
		}
		if (buttontwo(295, 400, 150, 30, "��Ϸ˵��")) {
			mciSendString("open ./images/musci_8.mp3 alias h", NULL, 0, NULL);
			mciSendString("play h from 0", NULL, 0, NULL);//ԭ������Ҳ��ԭ��
			gamerule();
		}
		if (buttontwo(295, 450, 150, 30, "��Ϸ����")) {
			mciSendString("open ./images/musci_9.mp3 alias k", NULL, 0, NULL);
			mciSendString("play k from 0", NULL, 0, NULL);//ԭ������Ҳ��ԭ��
			gameset();
		}
		if (buttontwo(295, 500, 150, 30, "��Ϸ����")) {
			mciSendString("open ./images/musci_8.mp3 alias h", NULL, 0, NULL);
			mciSendString("play h from 0", NULL, 0, NULL);//ԭ������Ҳ��ԭ��
			gamestory();
		}
		if (button(295, 550, 150, 30, "�˳���Ϸ")) {
			exit(0);
		}
		EndBatchDraw();
	}

}
void pictureload()
{
	for (i = 0; i < 12; i++)
	{
		char file[40] = "";
		sprintf(file, "./images/%d.bmp", i);
		loadimage(img_all + i, file, 64, 64);
	}
}
void mapdraw()
{
	
	for(i = 0; i < 10; i++)
	{   
		for (k = 0; k < 10; k++)
		{
			int x =( k+1)* 64; int  y = (i+1) * 64;//�õ�ͼ����Ļ�м��ӡ
			if (level == 0)//��1��
			{
				switch (map[level][i][k])
				{
				case space: putimage(x, y, img_all); break;
				case wall:putimage(x, y, img_all + 1); break;
				case dest:putimage(x, y, img_all + 2); break;
				case box:putimage(x, y, img_all + 3); break;
				case player:putimage(x, y, img_all + 4); break;
				case player + dest:putimage(x, y, img_all+4); break;
				case box + dest:putimage(x, y, img_all + 5); break;
				case 7:putimage(x, y, img_all + 7); break;
				
				}
			}
				if (level == 1)//��2��
				{
					switch (map[level][i][k])
					{
					case space: putimage(x, y, img_all); break;
					case wall:putimage(x, y, img_all + 1); break;
					case dest:putimage(x, y, img_all + 2); break;
					case box:putimage(x, y, img_all + 3); break;
					case player:putimage(x, y, img_all + 9); break;
					case player + dest:putimage(x, y, img_all+9); break;
					case box + dest:putimage(x, y, img_all + 10); break;
					case 8:putimage(x, y, img_all + 8); break;
					}
				}
					if (level == 2)//��3��
					{
						switch (map[level][i][k])
						{
						case space: putimage(x, y, img_all+11); break;
						case wall:putimage(x, y, img_all + 1); break;
						case dest:putimage(x, y, img_all + 2); break;
						case box:putimage(x, y, img_all + 3); break;
						case player:putimage(x, y, img_all + 10); break;
						case player + dest:putimage(x, y, img_all+10); break;
						case box + dest:putimage(x, y, img_all + 9); break;
						}
			        }
		   }
	     }
	
}


void gamemove()
{//�ҵ����
	
	for (i = 0; i < 10; i++)
	{
		for (k = 0; k < 10; k++)
		{
			if (map[level][i][k] == player|| map[level][i][k] ==player+dest)
			{
				goto end;
			}
		}
	}

end:;
	char ch = _getch();
		
	switch (ch)
	{
	case 72:
	case'w':
	case'W'://��ͬ�ؿ����Ų�ͬ����Ч����������ͬ��
		if (level == 0)
		{
			mciSendString("open ./images/musci_4.mp3 alias d", NULL, 0, NULL);
			mciSendString("play d from 0", NULL, 0, NULL);
		}//ʵ�������ƶ�����Ч���� 
		if (level == 1)
		{
			mciSendString("open ./images/musci_5.mp3 alias e", NULL, 0, NULL);
			mciSendString("play e from 0", NULL, 0, NULL);
		}
		if (level == 2)
		{
			mciSendString("open ./images/musci_7.mp3 alias g", NULL, 0, NULL);
			mciSendString("play g from 0", NULL, 0, NULL);
		}
		if (map[level][i - 1][k] == space || map[level][i - 1][k] == dest)
		{
			map[level][i - 1][k] += player;
			map[level][i][k] -= player;
			
		}
		else if (map[level][i - 1][k] == box || map[level][i - 1][k] == box + dest)
		{
			if (map[level][i - 2][k] == space || map[level][i - 2][k] == dest)
			{
				map[level][i - 2][k] += box;//�����ƶ���ǰ��һ��λ��
				map[level][i - 1][k] = map[level][i - 1][k] - box + player;//������ԭ����λ�ü�ȥ���Ӽ������
				map[level][i][k] -= player;//���ԭ����λ�������ʧ
			}
		}
		
		break;
	case 80:
	case's':
	case'S':if (level == 0)
	{
		mciSendString("open ./images/musci_4.mp3 alias d", NULL, 0, NULL);
		mciSendString("play d from 0", NULL, 0, NULL);
	}//ʵ�������ƶ�����Ч���� 
	if (level == 1)
	{
		mciSendString("open ./images/musci_5.mp3 alias e", NULL, 0, NULL);
		mciSendString("play e from 0", NULL, 0, NULL);
	}
	if (level == 2)
	{
		mciSendString("open ./images/musci_7.mp3 alias g", NULL, 0, NULL);
		mciSendString("play g from 0", NULL, 0, NULL);
	}
		if (map[level][i + 1][k] == space || map[level][i + 1][k] == dest)
	{
		map[level][i + 1][k] += player;
		map[level][i][k] -= player;
	}
		   else if (map[level][i + 1][k] == box || map[level][i + 1][k] == box + dest)
	{
		if (map[level][i + 2][k] == space || map[level][i + 2][k] == dest)
		{
			map[level][i + 2][k] += box;//�����ƶ���ǰ��һ��λ��
			map[level][i + 1][k] = map[level][i + 1][k] - box + player;//������ԭ����λ�ü�ȥ���Ӽ������
			map[level][i][k] -= player;//���ԭ����λ�������ʧ
		}
	}
		   break;
	case 75:
	case'a':
	case'A':if (level == 0)
	{
		mciSendString("open ./images/musci_4.mp3 alias d", NULL, 0, NULL);
		mciSendString("play d from 0", NULL, 0, NULL);
	}//ʵ�������ƶ�����Ч���� 
		   if (level == 1)
		   {
			   mciSendString("open ./images/musci_5.mp3 alias e", NULL, 0, NULL);
			   mciSendString("play e from 0", NULL, 0, NULL);
		   }
		   if (level == 2)
		   {
			   mciSendString("open ./images/musci_7.mp3 alias g", NULL, 0, NULL);
			   mciSendString("play g from 0", NULL, 0, NULL);
		   }
		if (map[level][i][k - 1] == space || map[level][i][k - 1] == dest)
	{
		map[level][i][k - 1] += player;
		map[level][i][k] -= player;
	}
		   else if (map[level][i][k - 1] == box || map[level][i][k - 1] == box + dest)
	{
		if (map[level][i][k - 2] == space || map[level][i][k - 2] == dest)
		{
			map[level][i][k - 2] += box;//�����ƶ���ǰ��һ��λ��
			map[level][i][k - 1] = map[level][i][k - 1] - box + player;//������ԭ����λ�ü�ȥ���Ӽ������
			map[level][i][k] -= player;//���ԭ����λ�������ʧ
		}
	}
		   break;
	case 77:
	case'd':
	case'D':if (level == 0)
	{
		mciSendString("open ./images/musci_4.mp3 alias d", NULL, 0, NULL);
		mciSendString("play d from 0", NULL, 0, NULL);
	}//ʵ�������ƶ�����Ч���� 
		   if (level == 1)
		   {
			   mciSendString("open ./images/musci_5.mp3 alias e", NULL, 0, NULL);
			   mciSendString("play e from 0", NULL, 0, NULL);
		   }
		   if (level == 2)
		   {
			   mciSendString("open ./images/musci_7.mp3 alias g", NULL, 0, NULL);
			   mciSendString("play g from 0", NULL, 0, NULL);
		   }
		if (map[level][i][k + 1] == space || map[level][i][k + 1] == dest)
	{
		map[level][i][k + 1] += player;
		map[level][i][k] -= player;
	}
		   else if (map[level][i][k + 1] == box || map[level][i][k + 1] == box + dest)
	{
		if (map[level][i][k + 2] == space || map[level][i][k + 2] == dest)
		{
			map[level][i][k + 2] += box;//�����ƶ���ǰ��һ��λ��
			map[level][i][k + 1] = map[level][i][k + 1] - box + player;//������ԭ����λ�ü�ȥ���Ӽ������
			map[level][i][k] -= player;//���ԭ����λ�������ʧ
		}
	}
		break;
	}
}




void gameview()
{
	IMAGE img_start;
	loadimage(&img_start, "./images/�����ӿ�ʼ����1.jpg", 750, 750);
	putimage(0, 0, &img_start);
	while (true)
	{
		mapdraw();
		
		if (wingame())
		{
			level++;
			if (level > 2)
			{
				mciSendString("open ./images/musci_10.mp3 alias l", NULL, 0, NULL);
				mciSendString("play l from 0", NULL, 0, NULL);//ʤ����Ч
				gamewinprint();
				
			}
		}
		gamemove();
	}
	
}



bool wingame()
{
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (map[level][i][k] == box)
			{
				return false;
			}
		}

	}

	return true;
}



void gamewinprint()
{
	IMAGE img_end;
	loadimage(&img_end, "./images/OIP-C.jpg",750,750);
	putimage(0, 0, &img_end);
	while (1) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		if (button(295, 350, 150, 70, "�˳���Ϸ")) {
			 goto end5;
		}
		EndBatchDraw();
	}
end5: exit(0);
}



void gameset() {
	IMAGE img_rules;
	loadimage(&img_rules, "./images/set.png", 10 * 75, 10 * 75);
	putimage(0, 0, &img_rules);//���Ʊ���
	int x = 250, y1 = 100, y2 = 250, y3 = 400;
	int wx = 250, wy = 100;
	int m = 1, n = 1;
	int q = 1;
	while (true) {
		msg.message = 0;
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		if (button(x, y1, wx, wy, "������ҳ")) {
			menuview();
			break;
		}
		if (button(x, y2, wx, wy, "����1��/��") && m == 1) {
			mciSendString("open ./images/musci_1.mp3 alias a", NULL, 0, NULL);
			mciSendString("play a ", NULL, 0, NULL);
			m = 0;
			msg.message = 0;
		}
		if (button(x, y2, wx, wy, "����1��/��") && m == 0) {
			mciSendString("stop a", NULL, 0, NULL);
			m = 1;
			msg.message = 0;
		}
		if (buttontwo(x, y3, wx, wy, "����2��/��") && n == 1) {
			mciSendString("open ./images/musci_2.mp3 alias b", NULL, 0, NULL);
			mciSendString("play b", NULL, 0, NULL);
			n = 0;
			msg.message = 0;
		}
		if (buttontwo(x, y3, wx, wy, "����2��/��") && n == 0) {
			mciSendString("stop b", NULL, 0, NULL);
			n = 1;
			msg.message = 0;
		}
		if (buttontwo(x,550, wx, wy, "����3��/��") && q == 1) {
			mciSendString("open ./images/musci_3.mp3 alias c", NULL, 0, NULL);
			mciSendString("play c", NULL, 0, NULL);
			q = 0;
			msg.message = 0;
		}
		if (buttontwo(x,550, wx, wy, "����3��/��") && q == 0) {
			mciSendString("stop c", NULL, 0, NULL);
			q= 1;
			msg.message = 0;
		}
		EndBatchDraw();
	}
	
}



void gamerule() {
	IMAGE img_rules;
	cleardevice();
	loadimage(&img_rules, "./images/pi.png", 10 * 75, 10 * 75);
	putimage(0, 0, &img_rules);//���Ʊ���
	int x = 400, y = 500;
	int wx = 200, wy = 100;
	while (true) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		if (button(x, y, wx, wy, "������ҳ")) {
			menuview();
			break;
		}
		EndBatchDraw();
		
	}
	
}




void gamestory()
{
	IMAGE img_a;
	loadimage(&img_a, "./images/0.jpg",750,750);
	putimage(0, 0, &img_a);
	IMAGE img[5];
	for (i = 1; i < 5; i++)
	{
		char file[40] = "";
		sprintf(file, "./images/%d.jpg", i);
		loadimage(img + i, file, 750, 750);
	}
	while (1) {
		peekmessage(&msg, EX_MOUSE);

		BeginBatchDraw();
		
		if (button(295, 550, 150, 30, "����")) {
			
				putimage(0, 0, img + 1);
				msg.message = 0;	
				goto two;
		}
		EndBatchDraw();
	}

two:;
	cleardevice();
	putimage(0, 0, img + 1);
	while (1) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();

		if (button(295, 550, 150, 30, "����")) {

			putimage(0, 0, img + 2);
			msg.message = 0;
			goto three;
			
		}
		EndBatchDraw();
	}
three:;
	cleardevice();
	putimage(0, 0, img + 2);
	while (1) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();

		if (button(295, 550, 150, 30, "����")) {

			putimage(0, 0, img + 3);
			msg.message = 0;
			goto four;
		}
		EndBatchDraw();
	}
four:;
	cleardevice();
	putimage(0, 0, img + 3);
	while (1) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();

		if (button(295, 550, 150, 30, "����")) {

			putimage(0, 0, img + 4);
			msg.message = 0;
			goto five;

		}
		EndBatchDraw();
	}
five:;
	cleardevice();
	putimage(0, 0, img + 4);
	while (1) {
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		if (button(295, 550, 150, 30, "������ҳ")) {
			putimage(0, 0, img + 5);
			msg.message = 0;
			goto six;
		}
		EndBatchDraw();
	}
six:menuview();
}